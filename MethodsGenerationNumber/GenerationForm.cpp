#include "GenerationForm.h"
#include <fstream>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MethodsGenerationNumber::GenerationForm form;
	Application::Run(% form);

}
System::Void MethodsGenerationNumber::GenerationForm::clearChart(int series)
{
	this->chart1->Series[series]->Points->Clear();
}

System::Void MethodsGenerationNumber::GenerationForm::clearDataGrid_data()
{
	while (this->dg_data->Rows->Count != 0)
		this->dg_data->Rows->RemoveAt(0);
}

void MethodsGenerationNumber::GenerationForm::fillDiagram(int series, int* countPointsInDiapason)
{
	for (int i = 0; i < 10; i++)
	{
		if (countPointsInDiapason[i] != 0)
			fillChart(series, countPointsInDiapason[i]);
	}
}

System::Void MethodsGenerationNumber::GenerationForm::fillChart(int series, int count)
{
	this->chart1->Series[series]->Points->AddY(count);

}
System::Void MethodsGenerationNumber::GenerationForm::fillChart(int series, int* countPointsInDiapason)
{
	this->chart1->Series[series]->Points->AddXY("0.0-0.1", countPointsInDiapason[0]);
	this->chart1->Series[series]->Points->AddXY("0.1-0.2", countPointsInDiapason[1]);
	this->chart1->Series[series]->Points->AddXY("0.2-0.3", countPointsInDiapason[2]);
	this->chart1->Series[series]->Points->AddXY("0.3-0.4", countPointsInDiapason[3]);
	this->chart1->Series[series]->Points->AddXY("0.4-0.5", countPointsInDiapason[4]);
	this->chart1->Series[series]->Points->AddXY("0.5-0.6", countPointsInDiapason[5]);
	this->chart1->Series[series]->Points->AddXY("0.6-0.7", countPointsInDiapason[6]);
	this->chart1->Series[series]->Points->AddXY("0.7-0.8", countPointsInDiapason[7]);
	this->chart1->Series[series]->Points->AddXY("0.8-0.9", countPointsInDiapason[8]);
	this->chart1->Series[series]->Points->AddXY("0.9-1.0", countPointsInDiapason[9]);
}

double expectedValue(std::vector<double> vector_random)
{
	double sum = 0;
	for (int i = 0; i < vector_random.size(); i++)
		sum += vector_random[i];
	return sum / (double)vector_random.size();
}

double dispersion(std::vector<double> vector_random, double expectedValue)
{
	double sum = 0;
	for (int i = 0; i < vector_random.size(); i++)
		sum += (vector_random[i] - expectedValue) * (vector_random[i] - expectedValue);

	return sum / vector_random.size();
}

double standardDeviation(double dispersion)
{
	return std::sqrt(dispersion);
}

System::Void MethodsGenerationNumber::GenerationForm::fillDataGridEquability(int const& method, double expectedValue, double dispersion, double standardDeviation)
{
	this->dg_equability->Rows[method]->Cells[0]->Value = int(expectedValue * 1000 + 0.5) / 1000.0;
	this->dg_equability->Rows[method]->Cells[1]->Value = int(dispersion * 1000 + 0.5) / 1000.0;
	this->dg_equability->Rows[method]->Cells[2]->Value = int(standardDeviation * 1000 + 0.5) / 1000.0;
}

System::Void MethodsGenerationNumber::GenerationForm::fillIntervalTest(int method,double expectedValue, double dispersion, double standart)
{
	double start = int(std::abs(expectedValue - standart) * 10000 + 0.5) / 10000.0;
	double end = int(std::abs(expectedValue + standart) * 10000 + 0.5) / 10000.0;
	double percent = (int((end - start) * 1000 + 0.5) / 1000.0);
	if (percent > 1)
		percent = percent - 1;
	switch (method)
	{
	case 0:
		lbl_intervalTest1->Text = "Интервал частотного теста 1: (" + start + " ; " + end + ")" + percent * 100 + "%";
		break;
	case 1:
		lbl_intervalTest2->Text = "Интервал частотного теста 2: (" + start + " ; " + end + ")" + percent * 100 + "%";
		break;
	case 2:
		lbl_intervalTest3->Text = "Интервал частотного теста 3: (" + start + " ; " + end + ")" + percent * 100 + "%";
		break;
	default:
		break;
	}
}



double cutNumber(int posNumbers,__int64 numbers,int const& start,int const& end)
{
	double R3 = 0;
	int step = 1;
	while (numbers != 0)
	{
		if (posNumbers > start && posNumbers <= end)
		{
			R3 += numbers % 10 * step;
			step *= 10;
		}
		posNumbers--;
		numbers /= 10;
		if (posNumbers == start)
			return R3;
	}
	return R3;
}

std::vector<double> MethodsGenerationNumber::GenerationForm::methodOfMeanSquares(int countPoints,__int64 R0)
{

	std::vector<double> randNumb;
	std::ofstream file("log.txt");
	for (int i = 0; i < countPoints; i++)
	{
		__int64 R1 = R0 * R0;

		double R3 = 0;// cutNumber(8, R1, 2, 6);
		if (R1 > 1000000)
			R3 = cutNumber(8, R1, 2, 6);
		else
			if (R1 > 100000)
				R3 = cutNumber(7, R1, 2, 6);
			else
				if (R1 > 10000)
					R3 = cutNumber(6, R1, 0, 5);
				else
					R3 = R1;
		
		file << i << ": R0 = " << R0 << "; R1" << R1 << "; R3" << R3 << std::endl;
		
		if(i<10)
			fillDataGrid(R0, R1, R3);
		R0 = R3;

		randNumb.push_back(R3/10000.0);

	}
	file.close();
	return randNumb;
}

std::vector<double> MethodsGenerationNumber::GenerationForm::methodOfMult(int const& countPoints, __int64 R0,__int64& R1)
{
	std::vector<double> randNumb;
	for (int i = 0; i < countPoints; i++)
	{
		__int64 R3 = R0 * R1;
		double temp = 0;
		if (R3 > 1000000)
			temp = cutNumber(8, R3, 2, 6);
		else
			if (R3 > 100000)
				temp = cutNumber(7, R3, 2, 6);
			else
				if (R3 > 10000)
					temp = cutNumber(6, R3, 0, 5);
				else
					temp = R3;
		if(i<10)
			fillDataGrid(R1, R3, temp);
		randNumb.push_back(temp / 10000.0);
		R1 = cutNumber(8, R3, 4, 8);
	}
	return randNumb;
}

std::vector<double> MethodsGenerationNumber::GenerationForm::methodLinearCongruent(int const& countPoints, __int64 multiplier, __int64 divisor)
{
	std::vector<double> randNumb;
	__int64 temp = multiplier;
	for (int i = 0; i < countPoints; i++)
	{
		__int64 R3 = multiplier * temp;
		if(i<10)
			fillDataGrid(temp, R3, R3%divisor);
		randNumb.push_back((R3%divisor) / 10000.0);
		temp = R3 % divisor;
	}
	return randNumb;
}

int* countPointBySegment(std::vector<double> vector_randomPoints)
{
	int* countPointByDiapason = new int[11]{ 0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < vector_randomPoints.size(); i++)
	{
		if (vector_randomPoints[i] > 0 && vector_randomPoints[i] < 0.1)
			countPointByDiapason[0]++;
		if (vector_randomPoints[i] >= 0.1 && vector_randomPoints[i] < 0.2)
			countPointByDiapason[1]++;
		if (vector_randomPoints[i] >= 0.2 && vector_randomPoints[i] < 0.3)
			countPointByDiapason[2]++;
		if (vector_randomPoints[i] >= 0.3 && vector_randomPoints[i] < 0.4)
			countPointByDiapason[3]++;
		if (vector_randomPoints[i] >= 0.4 && vector_randomPoints[i] < 0.5)
			countPointByDiapason[4]++;
		if (vector_randomPoints[i] >= 0.5 && vector_randomPoints[i] < 0.6)
			countPointByDiapason[5]++;
		if (vector_randomPoints[i] >= 0.6 && vector_randomPoints[i] < 0.7)
			countPointByDiapason[6]++;
		if (vector_randomPoints[i] >= 0.7 && vector_randomPoints[i] < 0.8)
			countPointByDiapason[7]++;
		if (vector_randomPoints[i] >= 0.8 && vector_randomPoints[i] < 0.9)
			countPointByDiapason[8]++;
		if (vector_randomPoints[i] >= 0.9 && vector_randomPoints[i] < 1.0)
			countPointByDiapason[9]++;
	}

	return countPointByDiapason;
}



System::Void MethodsGenerationNumber::GenerationForm::fillDataGrid(__int64 curNumb, __int64 squareCurNumb, __int64 receivedNumb)
{
	this->dg_data->Rows->Add();
	this->dg_data->Rows[this->dg_data->Rows->Count-1]->Cells[0]->Value = curNumb.ToString();
	this->dg_data->Rows[this->dg_data->Rows->Count-1]->Cells[1]->Value = squareCurNumb.ToString();
	if(receivedNumb <100)
		this->dg_data->Rows[this->dg_data->Rows->Count-1]->Cells[2]->Value = "0,00" + receivedNumb.ToString();
	else
		if(receivedNumb <1000)
			this->dg_data->Rows[this->dg_data->Rows->Count - 1]->Cells[2]->Value = "0,0" + receivedNumb.ToString();
		else
			this->dg_data->Rows[this->dg_data->Rows->Count - 1]->Cells[2]->Value = receivedNumb.ToString();
}

System::Void MethodsGenerationNumber::GenerationForm::Btn_squre_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearChart(0);
	clearDataGrid_data();
	int countStep = Convert::ToInt32(numeric_countPoint->Text);
	if (countStep != 0)
	{
		__int64 R0 = Convert::ToInt64(tb_numb->Text->ToString());
		std::vector<double> randomNumbers = methodOfMeanSquares(countStep, R0);
		int* countPointByDiapason = countPointBySegment(randomNumbers);
		/*fillDiagram(0, countPointByDiapason);*/

		double expectedVal = expectedValue(randomNumbers);
		double dispers = dispersion(randomNumbers, expectedVal);
		double standartDev = standardDeviation(dispers);
		fillDataGridEquability(0, expectedVal, dispers, standartDev);

		fillChart(0, countPointByDiapason);
		fillIntervalTest(0, expectedVal, dispers, standartDev);
	}
	else
	{
		MessageBox::Show("Count point is 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void MethodsGenerationNumber::GenerationForm::Btn_mult_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearChart(1);
	clearDataGrid_data();
	int countPoints = Convert::ToInt32(numeric_countPoint->Text);
	if (countPoints != 0)
	{
		__int64 R0 = Convert::ToInt64(tb_numb->Text->ToString());
		__int64 R1 = Convert::ToInt64(tb_numb2->Text->ToString());
		std::vector<double> randomNumbers = methodOfMult(countPoints, R0,R1);
		int* countPointByDiapason = countPointBySegment(randomNumbers);
		/*fillDiagram(1, countPointByDiapason);*/

		double expectedVal = expectedValue(randomNumbers);
		double dispers = dispersion(randomNumbers, expectedVal);
		double standartDev = standardDeviation(dispers);
		fillDataGridEquability(1, expectedVal, dispers, standartDev);

		fillChart(1, countPointByDiapason);
		fillIntervalTest(1, expectedVal, dispers, standartDev);
	}
	else
	{
		MessageBox::Show("Count point is 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void MethodsGenerationNumber::GenerationForm::Btn_linearCongruentMethod_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearChart(2);
	clearDataGrid_data();
	int countPoints = Convert::ToInt32(numeric_countPoint->Text);
	if (countPoints != 0)
	{
		__int64 R0 = Convert::ToInt64(tb_numb->Text->ToString());
		__int64 R1 = Convert::ToInt64(tb_numb2->Text->ToString());
		std::vector<double> randomNumbers = methodLinearCongruent(countPoints, R0, R1);
		int* countPointByDiapason = countPointBySegment(randomNumbers);
		/*fillDiagram(2, countPointByDiapason);*/

		double expectedVal = expectedValue(randomNumbers);
		double dispers = dispersion(randomNumbers, expectedVal);
		double standartDev = standardDeviation(dispers);
		fillDataGridEquability(2, expectedVal, dispers, standartDev);

		fillChart(2, countPointByDiapason);
		fillIntervalTest(2, expectedVal, dispers, standartDev);
	}
	else
	{
		MessageBox::Show("Count point is 0!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void MethodsGenerationNumber::GenerationForm::Btn_clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < this->chart1->Series->Count; i++)
		this->chart1->Series[i]->Points->Clear();
	clearDataGrid_data();
	for (int i = 0; i < dg_equability->RowCount; i++)
		for (int j = 0; j < dg_equability->Rows[i]->Cells->Count; j++)
			dg_equability->Rows[i]->Cells[j]->Value = "";

}
