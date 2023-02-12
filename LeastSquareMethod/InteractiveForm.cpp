#include "InteractiveForm.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>  
#include <vector>
#include <stdlib.h> // ����� ��� ������ ������� rand(), srand()
#include <time.h>

using namespace System;
using namespace System::Windows::Forms;

std::ofstream logFile("log.txt");

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LeastSquareMethod::InteractiveForm form;
	Application::Run(% form);

}

System::Void LeastSquareMethod::InteractiveForm::Btn_close_Click(System::Object^ sender, System::EventArgs^ e)
{
	logFile.close();
	Application::Exit();
}

double LeastSquareMethod::InteractiveForm::GetRandomNumberFloat(double min, double max, int precision)
{
	// ���������� ��������� �����
	//srand(time(NULL));

	double value;

	// �������� ��������� ����� ��� ����� ����� � �������� precision
	value = rand() % (int)pow(10, precision);

	// �������� ������������ �����
	value = min + (value / pow(10, precision)) * (max - min);

	return value;
}

void outputChangeMatrix(int countOfVariables, double** matrixA, double* matrixB)
{
	for (int i = 0; i < countOfVariables; i++)
	{
		for (int j = 0; j < countOfVariables; j++)
			logFile << std::setprecision(3) << matrixA[i][j] << " ";
		logFile << std::setprecision(3) << matrixB[i] << std::endl;
	}
	logFile << std::endl;
}

double* methodGaussa(double** matrixA, double* matrixB, int countOfVariables)
{
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
				logFile << "\n Max(matrixA " << i + 1 << " " << indexVarMatrix + 1 << ")=" << maxElementMartix << std::endl;
			}
		}
		if (maxElementMartix <= eps)
		{
			for (int i = indexVarMatrix; i < countOfVariables; i++)
				matrixA[i][indexVarMatrix] = 0.0;
			rangMatrixAB = indexVarMatrix;
			if (matrixB[indexVarMatrix] != 0)
				rangMatrixAB++;
			indexVarMatrix++; // ����������� ������� ����
			outputChangeMatrix(countOfVariables, matrixA, matrixB);
			continue;
		}

		//������ ������� ������
		if (indexLineMaxElm != indexVarMatrix) //��������� "���� �� ����"
		{
			for (int j = 0; j < countOfVariables; j++)
			{
				if (matrixA[indexVarMatrix][j] == 0 && matrixA[indexLineMaxElm][j] == 0) // ���� ���� �� �����
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
		assert(fabs(maxElementMartix) > eps); // ���� �� ������ ��� ��� �����������, ����� ������ � ���������

		for (int i = indexVarMatrix + 1; i < countOfVariables; i++)
		{
			double temp = (-matrixA[i][indexVarMatrix]) / maxElementMartix;

			matrixA[i][indexVarMatrix] = 0.0;//����� ��������� ������� ��������� ����� ���������� , ����� ������ �� ���� ���� ����������� 0
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
		logFile << " ���� ����������� ������� ������ ����� \n������������ ������� ";
		MessageBox::Show("���� ����������� ������� ������ ����� \n ������������ �������", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		for (int i = 0; i < countOfVariables; i++)
			varaibles[i] = 1.0;
		return varaibles;
	}
	else
	{
		if (rangMatrixAB == rang && rangMatrixAB < countOfVariables)
		{
			logFile << " ������� ����������� ���������. \n���������� ���������� ������ ,"
				"���������� ����� , ������ ��������� ���������� " << std::endl;
			MessageBox::Show("������� ����������� ���������. \n���������� ���������� ������ , ���������� �����", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
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
	return varaibles;

}

double** fillMatrixA(int const &countOfVar,std::vector<double>sumCoordinate,int const & countNumber)
{
	double** matrixA = new double* [5];
	for (int i = 0; i < 5; i++)
		matrixA[i] = new double[5]{ 0 };

	int indexSumCoordinate = 0;
	if (countOfVar == 2)
		indexSumCoordinate = 2;
	else
		indexSumCoordinate = 0;
	for (int i = 0, k = countOfVar == 2 ? 3 : 1; i < countOfVar; i++,k++)
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
	for (int i = 0; i < countOfVar; i++,indexSumCoordinate--)
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

System::Void LeastSquareMethod::InteractiveForm::Btn_action_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElement();
	double** matrixA = new double* [5];
	for (int i = 0; i < 5; i++)
		matrixA[i] = new double[5] { 0 };
	double* matrixB = new double[5];

	double sumFaultLinear = 0, sumFaultPower = 0, sumFaultExponent = 0, sumFaultSquare = 0;

	std::vector<double> sumCoordinate;
	std::vector<double> sumCoordinateLn;
	for (int i = 0; i < 7; i++)
		sumCoordinate.push_back(0);
	for (int i = 0; i < 6; i++)
		sumCoordinateLn.push_back(0);

	int countOfVariables = 0;
	int countNumber = Convert::ToInt32(table_values->ColumnCount.ToString());

	for (int i = 0; i < countNumber; i++)
	{
		double x = Convert::ToDouble(table_values->Rows[0]->Cells[i]->FormattedValue->ToString());
		double y = Convert::ToDouble(table_values->Rows[1]->Cells[i]->FormattedValue->ToString());
		sumCoordinate[0] += x * x * x *x ;
		sumCoordinate[1] += x * x * x;
		sumCoordinate[2] += x * x;
		sumCoordinate[3] += x;
		sumCoordinate[4] += y;
		sumCoordinate[5] += x * y;
		sumCoordinate[6] += x * x * y;
		sumCoordinateLn[0] += log(x) * log(x);
		sumCoordinateLn[1] += log(x);
		sumCoordinateLn[2] += log(y);
		sumCoordinateLn[3] += log(x) * log(y);
		sumCoordinateLn[4] += x * log(y);
	}
	//y=ax+b---------------------------------------------------------------------
	logFile << "y=ax+b \n ";
	countOfVariables = 2;
	matrixA = fillMatrixA(countOfVariables, sumCoordinate, countNumber);
	matrixB = filllMatrixB(countOfVariables, sumCoordinate);

	double* varaibles = methodGaussa(matrixA, matrixB, countOfVariables);
	logFile << "a = " << varaibles[0] << " b = " << varaibles[1] << std::endl;

	logFile << " x  y " << std::endl;
	for (int i = 0; i < countNumber; i++)
	{
		double* coordinateXY = getCoordinate(i);
		double y = varaibles[0] * coordinateXY[0] + varaibles[1];
		this->chart1->Series[0]->Points->AddXY(coordinateXY[0],y);

		logFile << " " << coordinateXY[0] << "  " << y << " " << std::endl;
		sumFaultLinear += (y - coordinateXY[1]) * (y - coordinateXY[1]);
	}
	logFile << " sumFaultLinear = " << sumFaultLinear << std::endl;
	//y=b*x^a---------------------------------------------------------------------
	//Y=beta*x^a---------------------------------------------------------------------
	logFile << "y=beta*x^a \n ";

	matrixA = fillMatrixALn(countOfVariables, sumCoordinateLn, countNumber);
	matrixB = filllMatrixBLn(countOfVariables, sumCoordinateLn);

	varaibles = methodGaussa(matrixA, matrixB, countOfVariables);

	logFile << "a = " << varaibles[0] << " b = " << varaibles[1] << std::endl;

	double beta = exp(varaibles[1]);
	logFile << " beta = " << beta << std::endl;

	logFile << " x  y " << std::endl;
	for (int i = 0; i < countNumber; i++)
	{
		double* coordinateXY = getCoordinate(i);
		double y = beta * pow(coordinateXY[0],varaibles[0]);
		this->chart1->Series[1]->Points->AddXY(coordinateXY[0], y);

		logFile << " " << coordinateXY[0] << "  " << y << " " << std::endl;
		sumFaultPower += (y - coordinateXY[1]) * (y - coordinateXY[1]);
	}
	logFile << " sumFaultPower = " << sumFaultPower << std::endl;
	//Y=aX+b---------------------------------------------------------------------
	//Y=beta*exp(a*x)---------------------------------------------------------------------
	logFile << "y=beta*exp(a*x) \n ";

	matrixA = fillMatrixA(countOfVariables, sumCoordinate, countNumber);
	matrixB[0] = sumCoordinateLn[4];
	matrixB[1] = sumCoordinateLn[2];

	varaibles = methodGaussa(matrixA, matrixB, countOfVariables);

	logFile << "a = " << varaibles[0] << " b = " << varaibles[1] << std::endl;

	beta = exp(varaibles[1]);
	logFile << " beta = " << beta << std::endl;

	logFile << " x  y " << std::endl;
	for (int i = 0; i < countNumber; i++)
	{
		double* coordinateXY = getCoordinate(i);
		double y = beta * exp(varaibles[0]* coordinateXY[0]);
		this->chart1->Series[2]->Points->AddXY(coordinateXY[0], y);

		logFile << " " << coordinateXY[0] << "  " << y << " " << std::endl;
		sumFaultExponent += (y - coordinateXY[1]) * (y - coordinateXY[1]);
	}
	logFile << " sumFaultExponent = " << sumFaultExponent << std::endl;
	//Y=beta*exp(a*x)---------------------------------------------------------------------
	//Y=ax^2+bx+c---------------------------------------------------------------------
	double sumXDegree4 = 0, sumXDegree3 = 0, sumXXY=0;
	logFile << "Y=ax^2+bx+c \n ";

	countOfVariables = 3;
	matrixA = fillMatrixA(countOfVariables, sumCoordinate, countNumber);
	matrixB = filllMatrixB(countOfVariables, sumCoordinate);

	varaibles = methodGaussa(matrixA, matrixB, countOfVariables);
	logFile << "a = " << varaibles[0] << " b = " << varaibles[1] << " c = " << varaibles[2] << std::endl;

	logFile << " x  y " << std::endl;
	for (int i = 0; i < countNumber; i++)
	{
		double* coordinateXY = getCoordinate(i);
		double y = varaibles[0]*coordinateXY[0]*coordinateXY[0] +varaibles[1]*coordinateXY[0]+varaibles[2];
		this->chart1->Series[3]->Points->AddXY(coordinateXY[0], y);

		logFile << " " << coordinateXY[0] << "  " << y << " " << std::endl;
		sumFaultSquare += (coordinateXY[1]-y) * (coordinateXY[1] -y);
	}
	logFile << " sumFaultSquare = " << sumFaultSquare << std::endl;
	//Y=ax^2+bx+c---------------------------------------------------------------------
	//Clean Memory
	for (int i = 0; i < countOfVariables; i++)
		delete[] matrixA[i];
	delete[] matrixA;
	delete[] varaibles;
	delete[] matrixB;

	this->label_sumFaultLinear->Text = " C�� ����������� ��� ������� = " + sumFaultLinear.ToString();
	this->label_sumFaultPower->Text = " C�� ����������� ���� ������� = " + sumFaultPower.ToString();
	this->label_sumFaultExponent->Text = " C�� ����������� ������ ������� = " + sumFaultExponent.ToString();
	this->label_sumFaultSquare->Text = " C�� ����������� ������� ������� = " + sumFaultSquare.ToString();	
}


System::Void LeastSquareMethod::InteractiveForm::Btn_random_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	for (int i = 0; i < Convert::ToInt32(table_values->ColumnCount.ToString()); i++)
	{
		table_values->Rows[0]->Cells[i]->Value = GetRandomNumberFloat(0, 2, 2).ToString();
		table_values->Rows[1]->Cells[i]->Value = GetRandomNumberFloat(0, 2, 2).ToString();
	}
}


