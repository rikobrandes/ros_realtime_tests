/**
* Copyright (C) 2014, BMW Car IT GmbH
* Author: Jonas Sticha (Jonas.Sticha@bmw-carit.de)
*
* This software is licensed under BSD 3-clause License
* (see http://spdx.org/licenses/BSD-3-Clause).
**/

#ifndef MEASUREMENTDATAEVALUATOR_H_
#define MEASUREMENTDATAEVALUATOR_H_

typedef struct {
	long value;
	int index;
} valueWithIndex;

class MeasurementDataEvaluator {
public:
	MeasurementDataEvaluator(int dataSize);
	long getMinValue();
	long getAvgValue();
	long getMaxValue();
	long* getData();
	int getDataSize();
	valueWithIndex* getTopTenValues();
	void analyzeData();
	~MeasurementDataEvaluator();
private:
	long* data;
	int dataSize;
	valueWithIndex* topTenValues; // Big -> small
	long minValue;
	long maxValue;
	long long avgValue;

	void calcMinMaxAvg();
	void findTopTenValues();
	MeasurementDataEvaluator();
};

#endif //MEASUREMENTDATAEVALUATOR_H_
