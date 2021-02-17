#ifndef QUADRATIC_REGRESION_MODEL_H
#define QUADRATIC_REGRESION_MODEL_H

#include "Models/RegressionModel.h"

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	class QuadraticRegressionModel : public RegressionModel<X, INPUTS, Y, OUTPUTS, SAMPLES, 2>
	{
	public:

		QuadraticRegressionModel() = default;
		~QuadraticRegressionModel() = default;

	private:
	};
}

#endif