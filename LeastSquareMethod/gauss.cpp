#include "InteractiveForm.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>
using namespace System;
using namespace System::Windows::Forms;

std::ofstream log_info;

void outputChangeMatrix(int countOfVariables, double** matrixA, double* matrixB)
{
	log_info.open("log.txt", std::ios_base::out | std::ios_base::app);
	for (int i = 0; i < countOfVariables; i++)
	{
		for (int j = 0; j < countOfVariables; j++)
			log_info << std::setprecision(3) << matrixA[i][j] << " ";
		log_info << std::setprecision(3) << matrixB[i] << std::endl;
	}
	log_info << std::endl;
	log_info.close();
}

double* methodGaussa(double** matrixA, double* matrixB, int countOfVariables)
{
	log_info.open("log.txt", std::ios_base::out | std::ios_base::app);
	int rang = 0, rangMatrixAB = 0;
	double* varaibles = new double[countOfVariables], maxElementMartix;
	int indexVarMatrix = 0, indexLineMaxElm;
	const double eps = FLT_EPSILON;

	outputChangeMatrix(countOfVariables, matrixA, matrixB);

	while (indexVarMatrix < countOfVariables)
	{
		//Search line with maxElementMartix matrixA[i][j]
		maxElementMartix = abs(matrixA[indexVarMatrix][indexVarMatrix]);
		indexLineMaxElm = indexVarMatrix;
		for (int i = indexVarMatrix + 1; i < countOfVariables; i++)
		{
			if (fabs(matrixA[i][indexVarMatrix]) > maxElementMartix)
			{
				maxElementMartix = fabs(matrixA[i][indexVarMatrix]);
				indexLineMaxElm = i;
				log_info << "\n Max(matrixA " << i + 1 << " " << indexVarMatrix + 1 << ")=" << maxElementMartix << std::endl;
			}
		}
		if (maxElementMartix <= eps)
		{
			for (int i = indexVarMatrix; i < countOfVariables; i++)
				matrixA[i][indexVarMatrix] = 0.0;
			rangMatrixAB = indexVarMatrix;
			if (matrixB[indexVarMatrix] != 0)
				rangMatrixAB++;
			indexVarMatrix++; // расширенная матрица ранг
			outputChangeMatrix(countOfVariables, matrixA, matrixB);
			continue;
		}

		//Меняем местами строки
		if (indexLineMaxElm != indexVarMatrix) //исключаем "само на себя"
		{
			for (int j = 0; j < countOfVariables; j++)
			{
				if (matrixA[indexVarMatrix][j] == 0 && matrixA[indexLineMaxElm][j] == 0) // если нули то игнор
					continue;
				double temp = matrixA[indexVarMatrix][j];
				matrixA[indexVarMatrix][j] = matrixA[indexLineMaxElm][j];
				matrixA[indexLineMaxElm][j] = -temp;
			}
			double temp = matrixB[indexVarMatrix];
			matrixB[indexVarMatrix] = matrixB[indexLineMaxElm];
			matrixB[indexLineMaxElm] = -temp;

			outputChangeMatrix(countOfVariables, matrixA, matrixB);
		}

		maxElementMartix = matrixA[indexVarMatrix][indexVarMatrix];
		assert(fabs(maxElementMartix) > eps); // макс дб больше епс для продолжения, иначе ошибка в программе

		for (int i = indexVarMatrix + 1; i < countOfVariables; i++)
		{
			double temp = (-matrixA[i][indexVarMatrix]) / maxElementMartix;

			matrixA[i][indexVarMatrix] = 0.0;//после вычитыния слишком маленькое число получается , чтобы мусора не было явно присваиваем 0
			for (indexLineMaxElm = indexVarMatrix + 1; indexLineMaxElm < countOfVariables; ++indexLineMaxElm)
			{
				matrixA[i][indexLineMaxElm] += temp * matrixA[indexVarMatrix][indexLineMaxElm];
			}
			matrixB[i] += temp * matrixB[indexVarMatrix];

			outputChangeMatrix(countOfVariables, matrixA, matrixB);
		}
		outputChangeMatrix(countOfVariables, matrixA, matrixB);
		rang++;
		++indexVarMatrix;
	}

	if (rang == countOfVariables)
		rangMatrixAB = rang;
	bool  appliedFCR = 0;
	double freeVariables = 0;
	if (rangMatrixAB > rang)
	{
		log_info << " Ранг расширенной матрицы больше ранга \nобыкновенной матрицы ";
		MessageBox::Show("Ранг расширенной матрицы больше ранга \n обыкновенной матрицы", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		for (int i = 0; i < countOfVariables; i++)
			varaibles[i] = 1.0;
		return varaibles;
	}
	else
	{
		if (rangMatrixAB == rang && rangMatrixAB < countOfVariables)
		{
			log_info << " Решений бесконечное множество. \nКоличество переменных больше ,"
				"количества строк , введем свободную переменную " << std::endl;
			MessageBox::Show("Решений бесконечное множество. \nКоличество переменных больше , количества строк", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			//cin >> freeVariables;
			freeVariables = 1.0;
			appliedFCR = 1;
			for (int i = 0; i < countOfVariables; i++)
				varaibles[i] = 1.0;
			return varaibles;
		}
	}


	//Outside
	double* temp = new double[countOfVariables];
	for (int i = 0; i < countOfVariables; i++)
		temp[i] = matrixB[i];
	for (indexVarMatrix = countOfVariables - 1; indexVarMatrix >= 0; indexVarMatrix--)
	{
		double element = 0;
		if (appliedFCR == 1)
		{
			varaibles[indexVarMatrix] = freeVariables;
			appliedFCR = 0;
		}
		else
		{
			if (indexVarMatrix == countOfVariables - 1)
			{

				for (int j = 0; j < countOfVariables; j++)
					if (matrixA[countOfVariables - 1][j] != 0)
						element = matrixA[countOfVariables - 1][j];
				if (element != 0)
					varaibles[indexVarMatrix] = matrixB[indexVarMatrix] / element;
			}
			else
			{
				varaibles[indexVarMatrix] = temp[indexVarMatrix];
			}

		}
		element = 0;
		if (indexVarMatrix < countOfVariables - 1)
		{
			if (matrixA[indexVarMatrix][indexVarMatrix] != 0)
			{
				element = matrixA[indexVarMatrix][indexVarMatrix];
				varaibles[indexVarMatrix] = temp[indexVarMatrix] / element;
			}
		}

		for (int i = 0; i < indexVarMatrix; i++)
		{
			temp[i] = temp[i] - matrixA[i][indexVarMatrix] * varaibles[indexVarMatrix];
		}
	}
	log_info.close();
	return varaibles;
}
