#include "InteractiveForm.h"
#include "include.h"
#include "function.h"
#include "gauss.h"

using namespace System;
using namespace System::Windows::Forms;

std::ofstream logFile;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	std::fstream logFile("log.txt");
	logFile.close();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LeastSquareMethod::InteractiveForm form;
	Application::Run(% form);

}

System::Void LeastSquareMethod::InteractiveForm::Btn_close_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

void LeastSquareMethod::InteractiveForm::clearInteractiveElement()
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	this->chart1->Series[3]->Points->Clear();
	this->label_sumFaultLinear->Text = " ";
	this->label_sumFaultPower->Text = " ";
	this->label_sumFaultExponent->Text = " ";
	this->label_sumFaultSquare->Text = " ";
	this->label_bestFunc->Text = "Лучшая функция: ";

}
double* LeastSquareMethod::InteractiveForm::getCoordinate(int const& ind)
{
	double* coordinate = new double[2];
	coordinate[0] = Convert::ToDouble(table_values->Rows[0]->Cells[ind]->FormattedValue->ToString());
	coordinate[1] = Convert::ToDouble(table_values->Rows[1]->Cells[ind]->FormattedValue->ToString());
	return coordinate;
}



System::Void LeastSquareMethod::InteractiveForm::Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	double coordX = int((chart1->ChartAreas[0]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
	double coordY = int((chart1->ChartAreas[0]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
	label_X->Text = "X: " + coordX.ToString();
	label_Y->Text = "Y: " + coordY.ToString();
}



System::Void LeastSquareMethod::InteractiveForm::Btn_action_Click(System::Object^ sender, System::EventArgs^ e)
{
	logFile.open("log.txt", std::ios_base::out | std::ios_base::app);
	clearInteractiveElement();
	double** matrixA = new double* [5];
	for (int i = 0; i < 5; i++)
		matrixA[i] = new double[5] { 0 };
	double* matrixB = new double[5];

	double sumFaultLinear = 0, sumFaultPower = 0, sumFaultExponent = 0, sumFaultSquare = 0;

	std::vector<double> sumCoordinate;
	std::vector<double> sumCoordinateLn;
	initializeVector(sumCoordinate, 7);
	initializeVector(sumCoordinateLn, 6);

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
	this->dGV_coefficients->Rows[0]->Cells[0]->Value = varaibles[0];
	this->dGV_coefficients->Rows[0]->Cells[1]->Value = varaibles[1];
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
	this->dGV_coefficients->Rows[1]->Cells[0]->Value = beta;// varaibles[0];
	this->dGV_coefficients->Rows[1]->Cells[1]->Value = varaibles[0];
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
	this->dGV_coefficients->Rows[2]->Cells[0]->Value = beta;//varaibles[0];
	this->dGV_coefficients->Rows[2]->Cells[1]->Value = varaibles[0];
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
	this->dGV_coefficients->Rows[3]->Cells[0]->Value = varaibles[0];
	this->dGV_coefficients->Rows[3]->Cells[1]->Value = varaibles[1];
	this->dGV_coefficients->Rows[3]->Cells[2]->Value = varaibles[2];
	//Y=ax^2+bx+c---------------------------------------------------------------------
	//Clean Memory
	for (int i = 0; i < countOfVariables; i++)
		delete[] matrixA[i];
	delete[] matrixA;
	delete[] varaibles;
	delete[] matrixB;

	this->label_sumFaultLinear->Text = " Cум погрешность лин функции = " + sumFaultLinear.ToString();
	this->label_sumFaultPower->Text = " Cум погрешность степ функции = " + sumFaultPower.ToString();
	this->label_sumFaultExponent->Text = " Cум погрешность экспон функции = " + sumFaultExponent.ToString();
	this->label_sumFaultSquare->Text = " Cум погрешность квадрат функции = " + sumFaultSquare.ToString();	

	std::vector<double> sumFault;
	sumFault.push_back(sumFaultLinear);
	sumFault.push_back(sumFaultPower);
	sumFault.push_back(sumFaultExponent);
	sumFault.push_back(sumFaultSquare);
	sort(sumFault.begin(), sumFault.end());
	if (sumFault[0] == sumFaultLinear)
		this->label_bestFunc->Text += " Линейная";
	else
		if (sumFault[0] == sumFaultPower)
			this->label_bestFunc->Text += " Степенная";
		else
			if (sumFault[0] == sumFaultExponent)
				this->label_bestFunc->Text += " Экспоненциальная";
			else
				this->label_bestFunc->Text += " Квадратичная";
	logFile.close();
}


System::Void LeastSquareMethod::InteractiveForm::Btn_random_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	for (int i = 0; i < Convert::ToInt32(table_values->ColumnCount.ToString()); i++)
	{
		table_values->Rows[0]->Cells[i]->Value = getRandomNumberFloat(0, 2, 2).ToString();
		table_values->Rows[1]->Cells[i]->Value = getRandomNumberFloat(0, 2, 2).ToString();
	}
}


