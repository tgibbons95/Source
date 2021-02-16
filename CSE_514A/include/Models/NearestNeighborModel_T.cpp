#include "Models/NearestNeighborModel.h"
#include <cassert>

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	void NearestNeighborModel<X, INPUTS, Y, OUTPUTS, SAMPLES>::Train(const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>* data)
	{
		data_ = data;
	}

	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	DataVector<Y, OUTPUTS> NearestNeighborModel<X, INPUTS, Y, OUTPUTS, SAMPLES>::Predict(const DataVector<X, INPUTS>& data)
	{	 		
		auto min = DataVector<X, INPUTS>::GetDistanceBetweenPoints(data, data_->GetFeatures(0));
		auto returnVal = data_->GetObservations(0);
		for (int i = 1; i < SAMPLES; i++)
		{
			auto newMin = DataVector<X, INPUTS>::GetDistanceBetweenPoints(data, data_->GetFeatures(i));
			if (newMin < min)
			{
				min = newMin;
				returnVal = data_->GetObservations(i);
			}
		}
		return returnVal;
	}
}