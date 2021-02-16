#ifndef DATA_SET_H
#define DATA_SET_H

#include "DataVector.h"
#include "Utility/Macros.h"
#include <cassert>
#include <string>
#include <cmath>
#include <sstream> // std::stringstream

namespace CSE_514A_T
{
	template<typename X, int INPUTS, typename Y, int OUTPUTS, int SAMPLES>
	class DataSet
	{
	public:

		DataSet() = default;

		~DataSet()
		{

		}

		void SetData(int n, X* inputs, Y* outputs)
		{
			assert(n >= 0);
			assert(n < SAMPLES);

			for (int j = 0; j < INPUTS; j++)
			{
				features_[n].SetAttribute(j, inputs[j]);
			}
			for (int j = 0; j < OUTPUTS; j++)
			{
				observations[n].SetAttribute(j, outputs[j]);
			}
		}

		void SetData(const char* data, int sample)
		{
			std::stringstream ss(data);

			X val;
			int column = 0;

			while (ss >> val)
			{
				if (column < INPUTS)
				{
					features_[sample].SetAttribute(column++, val/static_cast<X>(1000));
				}
				else if(column < INPUTS + OUTPUTS)
				{
					observations[sample].SetAttribute((column - INPUTS), val);
					column++;
				}
				if (ss.peek() == ',') ss.ignore();
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const DataSet<X, INPUTS, Y, OUTPUTS, SAMPLES>&data)
		{
			os << "{";
			for (int i = 0; i < SAMPLES; ++i)
			{
				os << "\n   [" << data.features_[i] << "," << data.observations[i] << "]";
			}
			os << "\n}";
			return os;
		}

		const DataVector<X, INPUTS>& GetFeatures(int n) const
		{
			assert(n >= 0);
			assert(n < SAMPLES);

			return features_[n];
		}

		const DataVector<Y, OUTPUTS>& GetObservations(int n) const
		{
			assert(n >= 0);
			assert(n < SAMPLES);

			return observations[n];
		}

	private:

		std::array<DataVector<X, INPUTS>, SAMPLES> features_;
		std::array<DataVector<Y, OUTPUTS>, SAMPLES> observations;
	};
}

#endif