#include "Assignment1/Assignment1.h"

#include "Models/RegressionModel.h"

#include "Data/DataVector.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono> 

// Specific to assignment
#define TOTAL_SAMPLES 1030
#define TRAINING_SAMPLES 900
#define TEST_SAMPLES (TOTAL_SAMPLES - TRAINING_SAMPLES)
#define DATA_FILE "data/ConcreteCompressiveStrengthData.csv"
#define INPUT_ATTRIBUTES 8
#define OUTPUT_ATTRIBUTES 1

// Tweak to fine tune the regression algorithm
#define LEARNING_RATE 0.0005
#define GRADIENT_THRESHOLD 0.001
#define MAX_REGRESSION_ITERATIONS 100000

#define SECONDS_IN_MINUTE 60
#define MICROSECONDS_IN_SECOND 1000000

namespace CSE_514A_T
{
	void PrintRuntime(const char* title, std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point stop)
	{
		std::cout << "\n----------------------" 
			<< title 
			<< " (" 
			<< std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / (MICROSECONDS_IN_SECOND * SECONDS_IN_MINUTE)
			<< ":"
			<< std::setfill('0') << std::setw(2) << (std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / MICROSECONDS_IN_SECOND) % SECONDS_IN_MINUTE
			<< ")----------------------";

	}

	int MultiVariantLinearRegressionDemo()
	{
		auto start = std::chrono::high_resolution_clock::now();

		// Load data
		DataSet<float, INPUT_ATTRIBUTES, float, OUTPUT_ATTRIBUTES, TRAINING_SAMPLES> trainingDataset;
		DataSet<float, INPUT_ATTRIBUTES, float, OUTPUT_ATTRIBUTES, TEST_SAMPLES> testDataset;

		std::ifstream myFile(DATA_FILE);
		assert(myFile.is_open());

		std::string line;
		std::getline(myFile, line);
		int row = 0;
		while (std::getline(myFile, line) && row < TOTAL_SAMPLES)
		{
			if (row < TRAINING_SAMPLES)
			{
				trainingDataset.SetData(line.c_str(), row++);
			}
			else
			{
				testDataset.SetData(line.c_str(), row - TRAINING_SAMPLES);
				row++;
			}
		}
		auto loadEnd = std::chrono::high_resolution_clock::now();
		PrintRuntime("Load Data", start, loadEnd);

		// Train model
		RegressionModel<float, INPUT_ATTRIBUTES, float, OUTPUT_ATTRIBUTES, TRAINING_SAMPLES, 1> model;
		model.SetModelParams(LEARNING_RATE, GRADIENT_THRESHOLD, MAX_REGRESSION_ITERATIONS);
		model.Train(&trainingDataset);
		auto trainEnd = std::chrono::high_resolution_clock::now();
		PrintRuntime("Train - Linear Regression Model", loadEnd, trainEnd);

		// Predict
		std::cout << "\n";
		for (int i = 0; i < TEST_SAMPLES; i++)
		{
			std::cout << "\n" << testDataset.GetFeatures(i) << "," << testDataset.GetObservations(i) << "," << model.Predict(testDataset.GetFeatures(i));
		}
		auto testEnd = std::chrono::high_resolution_clock::now();
		PrintRuntime("Predict - Linear Regression Model", trainEnd, testEnd);

		std::cout << "\n";

		return 0;
	}
}