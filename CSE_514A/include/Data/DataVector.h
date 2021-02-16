#ifndef DATA_VECTOR_H
#define DATA_VECTOR_H

#include "Utility/Macros.h"
#include <cassert>
#include <string>
#include <cmath>
#include <sstream> // std::stringstream
#include <array>

namespace CSE_514A_T
{
	template<typename X, int DIMENSION>
	class DataVector
	{
	public:

		DataVector()
		{
			std::fill(std::begin(features_), std::end(features_), static_cast<X>(0));
		}

		DataVector(X value)
		{
			for (int i = 0; i < numFeatures_; ++i)
			{
				features_[i] = value;
			}
		}
		DataVector(X* features)
		{
			for (int i = 0; i < numFeatures_; ++i)
			{
				features_[i] = features[i];
			}
		}

		~DataVector()
		{

		}

		void SetData(X* features)
		{
			for (int i = 0; i < numFeatures_; ++i)
			{
				features_[i] = features[i];
			}
		}

		void SetData(const char* data)
		{
			std::stringstream ss(data);

			X val;
			int column = 0;

			while (ss >> val && column < numFeatures_)
			{
				features_[column++] = val;

				if (ss.peek() == ',') ss.ignore();
			}
		}

		static X GetDistanceBetweenPoints(const DataVector<X, DIMENSION>& point1, const DataVector<X, DIMENSION>& point2)
		{
			assert(point1.numFeatures_ == point2.numFeatures_);

			X sum = 0;
			for (int i = 0; i < point1.numFeatures_; ++i)
			{
				sum += (point1.features_[i] - point2.features_[i]) * (point1.features_[i] - point2.features_[i]);
			}
			return ::sqrt(sum);
		}

		friend std::ostream& operator<<(std::ostream& os, const DataVector<X, DIMENSION> &data)
		{
			os << "(";
			if (data.numFeatures_ > 0)
			{
				for (int i = 0; i < data.numFeatures_ - 1; ++i)
				{
					os << data.features_[i] << ", ";
				}
				os << data.features_[data.numFeatures_ - 1];
			}
			os << ")";
			return os;
		}

		const X& GetAttribute(int n) const
		{
			assert(n >= 0);
			assert(n < DIMENSION);

			return features_[n];
		}

		void SetAttribute(int n, const X& val)
		{
			assert(n >= 0);
			assert(n < DIMENSION);

			features_[n] = val;
		}

	private:

		std::array<X, DIMENSION> features_;
		const static int numFeatures_ = DIMENSION;
	};
}

#endif