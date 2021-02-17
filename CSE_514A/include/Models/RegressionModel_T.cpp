#include "Models/RegressionModel.h"
#include <cassert>

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
		for (int iter = 0; iter < iterations_ && !smallGradient; iter++)
		{
			std::array<std::array<DataVector<X, INPUTS>, OUTPUTS>, K> weightGradients;
			std::array<X, OUTPUTS> offsetWeightGradients;
			for (int i = 0; i < OUTPUTS; i++)
			{
				offsetWeightGradients[i] = 0;
			}

			// Compute Gradients
			for (int j = 0; j < SAMPLES; j++)	
			{
				auto predictions = Predict(data->GetFeatures(j));
				auto observations = data->GetObservations(j);

				// Train separate weights for each output
				for (int i = 0; i < OUTPUTS; i++)
				{
					auto& prediction = predictions.GetAttribute(i);
					auto& observation = observations.GetAttribute(i);

					offsetWeightGradients[i] += (prediction - observation);
					for (int k = 0; k < K; k++)
					{
						auto& weightGradient = weightGradients[k][i];
						auto& weight = weights_[k][i];

						for (int l = 0; l < INPUTS; l++)
						{
							weightGradient.SetAttribute(l, weightGradient.GetAttribute(l) + (prediction - observation) * static_cast<X>(::pow(data->GetFeatures(j).GetAttribute(l), k + 1)));
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