#ifndef REGRESION_MODEL_H
#define REGRESION_MODEL_H

#include "Models/Model.h"

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES, int K>
	class RegressionModel : public Model<X, INPUTS, Y, OUTPUTS, SAMPLES>
	{
	public:

		RegressionModel();
		~RegressionModel() = default;

		virtual void Train(const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data) override;
		virtual DataVector<Y, OUTPUTS> Predict(const DataVector<X, INPUTS>& data) override;

		virtual void SetModelParams(float learningRate, float gradientThreshold, int iterations);

	private:

		float learningRate_ = 0.0001;
		float gradientThreshold_ = 0.001;
		int iterations_ = 10000;

		std::array<std::array<DataVector<X, INPUTS>, OUTPUTS>, K> weights_;
		std::array<X, OUTPUTS> offsetWeights;
	};
}

#include "Models/RegressionModel_T.cpp"

#endif