#ifndef MODEL_H
#define MODEL_H

#include "Data/DataSet.h"

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	class Model
	{
	public:

		virtual void Train(const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data) = 0;
		virtual DataVector<Y, OUTPUTS> Predict(const DataVector<X, INPUTS>& data) = 0;
	};
}

#endif