#ifndef LINEAR_REGRESION_MODEL_H
#define LINEAR_REGRESION_MODEL_H

#include "Models/RegressionModel.h"

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	class LinearRegressionModel : public RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, 1>
	{
	public:

		LinearRegressionModel() = default;
		~LinearRegressionModel() = default;

	private:
	};
}

#endif