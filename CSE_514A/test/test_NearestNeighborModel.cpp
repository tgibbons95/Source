// CSE_514A
#include "Models/NearestNeighborModel.h"
#include "Data/DataVector.h"

// Test
#include "gtest/gtest.h"

// Standard
#include <functional>

namespace CSE_514A_T
{
	TEST(NearestNeighbor, TestCase1)
	{

		const int n = 8;
		const int INPUTS = 2;
		const int OUTPUTS = 1;

		float data[n] = { 1.0f, 1.5f, 2.0f, 2.5f, 5.5f, 6.0f, 6.5f, 7.0f };
		int observations[n] = { 0, 0, 0, 0, 1, 1, 1, 1 };
		DataSet<float, INPUTS, int, OUTPUTS, n> trainingDataset;

		float testData[n] = { 1.0f, 2.0f, 3.0f, 3.5f, 4.2f, 6.0f, 6.6f, 8.0f };
		int testExpectations[n] = { 0, 0, 0, 0, 1, 1, 1, 1 };
		DataSet<float, INPUTS, int, OUTPUTS, n> testDataset;


		DataVector<float, INPUTS> dataset[n];
		for (int i = 0; i < n; ++i)
		{
			float features[INPUTS] = { data[i], data[i] };
			trainingDataset.SetData(i, features, observations);
		}

		NearestNeighborModel<float, INPUTS, int, OUTPUTS, n> model;
		model.Train(&trainingDataset);

		DataVector<float, INPUTS> testDataVector;
		for (int i = 0; i < n; ++i)
		{
			float features[INPUTS] = { testData[i], testData[i] };
			testDataset.SetData(i, features, testExpectations);
			DataVector<int, OUTPUTS> prediction = model.Predict(testDataset.GetFeatures(i));
			for (int j = 0; j < OUTPUTS; j++)
			{
				EXPECT_EQ(testExpectations[j], prediction.GetAttribute(j));
			}
		}
	}
}
