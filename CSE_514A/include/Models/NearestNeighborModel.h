#ifndef NEAREST_NEIGHBOR_MODEL_H
#define NEAREST_NEIGHBOR_MODEL_H

#include "Models/Model.h"

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	class NearestNeighborModel : public Model<X,INPUTS,Y,OUTPUTS, SAMPLES>
	{
	public:

		NearestNeighborModel() = default;
		~NearestNeighborModel() = default;

		virtual void Train(const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data) override;
		virtual DataVector<Y, OUTPUTS> Predict(const DataVector<X, INPUTS>& data) override;

	private:

		const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data_ = nullptr;
	};
}

#include "Models/NearestNeighborModel_T.cpp"

#endif