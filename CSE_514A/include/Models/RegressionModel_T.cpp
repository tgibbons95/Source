#include "Models/RegressionModel.h"
#include <cassert>
#include <thread>
#include <mutex>

#define NUM_COMPUTING_THREADS 4

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES, int K>
	RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, K>::RegressionModel()
		: offsetWeights()
	{
		for (int i = 0; i < OUTPUTS; i++)
		{
			offsetWeights[i] = 0;
		}
	}

	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES, int K>
	void RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, K>::Train(const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data)
	{
		bool smallGradient = false;
		std::thread myThreads[NUM_COMPUTING_THREADS];

		int index = 0;  // protected by index_mutex
		std::mutex index_mutex;
		for (int iter = 0; iter < iterations_ && !smallGradient; iter++)
		{
			std::array<std::array<std::array<DataVector<X, INPUTS>, OUTPUTS>, K>, NUM_COMPUTING_THREADS> partialWeightGradients;
			std::array<std::array<DataVector<X, INPUTS>, OUTPUTS>, K> weightGradients;
			std::array<std::array<X, OUTPUTS>, NUM_COMPUTING_THREADS> partialOffsetWeightGradients;
			std::array<X, OUTPUTS> offsetWeightGradients;
			for (int i = 0; i < OUTPUTS; i++)
			{
				offsetWeightGradients[i] = 0;
				for (int t = 0; t < NUM_COMPUTING_THREADS; t++) {
					partialOffsetWeightGradients[t][i] = 0;
				}
			}

			index = 0;

			auto exec = [this, data]
			(int threadNum, 
				std::array<std::array<std::array<DataVector<X, INPUTS>, OUTPUTS>, K>, NUM_COMPUTING_THREADS>* partialWeightGradients,
				std::array<std::array<X, OUTPUTS>, NUM_COMPUTING_THREADS>* partialOffsetWeightGradients,
				int* index,
				std::mutex* mutex)
			{
				// Compute Gradients
				int start = threadNum * SAMPLES / NUM_COMPUTING_THREADS;
				int stop = (threadNum + 1) * SAMPLES / NUM_COMPUTING_THREADS;
				while(*index < SAMPLES)
				{
					(*mutex).lock();
					++(*index);
					int j = (*index);
					(*mutex).unlock();
					if (j < SAMPLES)
					{
						auto predictions = Predict(data->GetFeatures(j));
						auto observations = data->GetObservations(j);

						// Train separate weights for each output
						for (int i = 0; i < OUTPUTS; i++)
						{
							auto& prediction = predictions.GetAttribute(i);
							auto& observation = observations.GetAttribute(i);

							(*partialOffsetWeightGradients)[threadNum][i] += (prediction - observation);
							for (int k = 0; k < K; k++)
							{
								auto& weightGradient = (*partialWeightGradients)[threadNum][k][i];
								auto& weight = weights_[k][i];

								for (int l = 0; l < INPUTS; l++)
								{
									weightGradient.SetAttribute(l, weightGradient.GetAttribute(l) + (prediction - observation) * static_cast<X>(::pow(data->GetFeatures(j).GetAttribute(l), k + 1)));
								}
							}
						}
					}
				}
			};

			for (int t = 0; t < NUM_COMPUTING_THREADS; t++) {
				myThreads[t] = std::thread(exec, t, &partialWeightGradients, &partialOffsetWeightGradients, &index, &index_mutex);
			}

			for (int t = 0; t < NUM_COMPUTING_THREADS; t++) {
				myThreads[t].join();
			}

			for (int t = 0; t < NUM_COMPUTING_THREADS; t++) {
				for (int i = 0; i < OUTPUTS; i++)
				{
					offsetWeightGradients[i] += partialOffsetWeightGradients[t][i];
					for (int k = 0; k < K; k++)
					{
						for (int l = 0; l < INPUTS; l++)
						{
							weightGradients[k][i].SetAttribute(l, weightGradients[k][i].GetAttribute(l) + partialWeightGradients[t][k][i].GetAttribute(l));
						}
					}
				}
			}

			// Update weights
			for (int i = 0; i < OUTPUTS; i++)
			{
				smallGradient = true;
				offsetWeights[i] = offsetWeights[i] - learningRate_ * offsetWeightGradients[i];
				for (int k = 0; k < K; k++)
				{
					auto& weightGradient = weightGradients[k][i];
					auto& weight = weights_[k][i];

					if (iter % 1000 == 0)
					{
						std::cout << "\n" << iter << " K=" << k + 1 << ": (" << offsetWeightGradients[i] << ")"<< weightGradient;
					}
					for (int j = 0; j < INPUTS; j++)
					{
						weight.SetAttribute(j, weight.GetAttribute(j) - learningRate_ * weightGradient.GetAttribute(j));
						smallGradient = smallGradient && ::fabs(weightGradient.GetAttribute(j)) < gradientThreshold_;
					}
				}
			}
		}
	}

	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES, int K>
	DataVector<Y, OUTPUTS> RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, K>::Predict(const DataVector<X, INPUTS>& data)
	{
		DataVector<Y, OUTPUTS> result;
		for (int i = 0; i < OUTPUTS; i++)
		{
			Y prediction = static_cast<Y>(offsetWeights[i]);
			for (int k = 0; k < K; k++)
			{
				auto& weight = weights_[k][i];

				for (int j = 0; j < INPUTS; j++)
				{
					prediction += (weight.GetAttribute(j) * ::pow(data.GetAttribute(j), k + 1));
				}
			}
			result.SetAttribute(i, prediction);
		}
		return result;
	}

	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES, int K>
	void RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, K>::SetModelParams(float learningRate, float gradientThreshold, int iterations)
	{
		gradientThreshold_ = gradientThreshold;
		learningRate_ = learningRate;
		iterations_ = iterations;
	}
}