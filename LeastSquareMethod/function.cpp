#include <iostream>
#include <vector>

double** fillMatrixA(int const& countOfVar, std::vector<double>sumCoordinate, int const& countNumber)
{
	double** matrixA = new double* [5];
	for (int i = 0; i < 5; i++)
		matrixA[i] = new double[5]{ 0 };

	int indexSumCoordinate = 0;
	if (countOfVar == 2)
		indexSumCoordinate = 2;
	else
		indexSumCoordinate = 0;
	for (int i = 0, k = countOfVar == 2 ? 3 : 1; i < countOfVar; i++, k++)
	{

		for (int j = 0; j < countOfVar; j++, indexSumCoordinate++)
		{
			matrixA[i][j] = sumCoordinate[indexSumCoordinate];
			if (i == countOfVar - 1 && j == countOfVar - 1)
				matrixA[i][j] = countNumber;
		}
		indexSumCoordinate = k;
	}
	return matrixA;
}
double* filllMatrixB(int const& countOfVar, std::vector<double>sumCoordinate)
{
	double* matrixB = new double[countOfVar] { 0 };
	int indexSumCoordinate = countOfVar == 2 ? 5 : 6;
	for (int i = 0; i < countOfVar; i++, indexSumCoordinate--)
		matrixB[i] = sumCoordinate[indexSumCoordinate];
	return matrixB;
}

double** fillMatrixALn(int const& countOfVar, std::vector<double>sumCoordinateLn, int const& countNumber)
{
	double** matrixA = new double* [5];
	for (int i = 0; i < 5; i++)
		matrixA[i] = new double[5]{ 0 };

	int indexSumCoordinate = 0;

	for (int i = 0; i < countOfVar; i++)
	{
		for (int j = 0; j < countOfVar; j++, indexSumCoordinate++)
		{
			matrixA[i][j] = sumCoordinateLn[indexSumCoordinate];
			if (i == countOfVar - 1 && j == countOfVar - 1)
				matrixA[i][j] = countNumber;
		}
		indexSumCoordinate = 1;
	}
	return matrixA;
}
double* filllMatrixBLn(int const& countOfVar, std::vector<double>sumCoordinateLn)
{
	double* matrixB = new double[countOfVar] { 0 };
	int indexSumCoordinate = 3;
	for (int i = 0; i < countOfVar; i++, indexSumCoordinate--)
		matrixB[i] = sumCoordinateLn[indexSumCoordinate];
	return matrixB;
}

void initializeVector(std::vector<double> & vec, int const& size)
{
	for (int i = 0; i < size; i++)
		vec.push_back(0);
}

double getRandomNumberFloat(double min, double max, int precision)
{
	// Установить стартовую точку
	//srand(time(NULL));

	double value;

	// получить случайное число как целое число с порядком precision
	value = rand() % (int)pow(10, precision);

	// получить вещественное число
	value = min + (value / pow(10, precision)) * (max - min);

	return value;
}