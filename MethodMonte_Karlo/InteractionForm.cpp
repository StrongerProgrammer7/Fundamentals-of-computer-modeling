#include "InteractionForm.h"
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace System;
using namespace System::Windows::Forms;

//std::ofstream logFile("log.txt");

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MethodMonteKarlo::InteractionForm form;
	Application::Run(% form);

}

//Частотный тест
bool differLittle_MX_DX(double const& coord, int const& a)
{
	double M_X = a / 2.0;
	double D_X = (a * a) / 12.0;
	double standardDeviation = sqrt(D_X);
	return (coord > M_X - standardDeviation && coord < M_X + standardDeviation);
}

bool MethodMonteKarlo::InteractionForm::isEmptyValuesTable(int const &cell, int const& row)
{
	return Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == NULL || Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == 0.0 ? true : false;
}

void MethodMonteKarlo::InteractionForm::clearInteractiveElement()
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	this->chart1->Series[3]->Points->Clear();

}

std::vector<double> getRandomPoint(bool const uniform, double const& end_rectangle, int const& countPoint)
{
	std::vector<double> vector;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, end_rectangle);
	for (int i = 0; i < countPoint; i++)
	{
		double coord = int((double)dist(gen) * 100 + 0.5) / 100.0;
		if (uniform == true && differLittle_MX_DX(coord, end_rectangle) == true)
			vector.push_back(coord);
		else
			if (uniform == false)
				vector.push_back(coord);
			else
				i--;

	}
	return vector;
}

bool insideTringle(std::map<std::string, double> triangleVertexCoord, double x, double y)
{
	double tempa = (triangleVertexCoord["xa"] - x) * (triangleVertexCoord["yb"] - triangleVertexCoord["ya"]) - 
		(triangleVertexCoord["xb"] - triangleVertexCoord["xa"]) * (triangleVertexCoord["ya"] - y);
	double tempb = (triangleVertexCoord["xb"] - x) * (triangleVertexCoord["yc"] - triangleVertexCoord["yb"])
		- (triangleVertexCoord["xc"] - triangleVertexCoord["xb"]) * (triangleVertexCoord["yb"] - y);
	double tempc = (triangleVertexCoord["xc"] - x) * (triangleVertexCoord["ya"] - triangleVertexCoord["yc"]) 
		- (triangleVertexCoord["xa"] - triangleVertexCoord["xc"]) * (triangleVertexCoord["yc"] - y);
	return (tempa < 0 && tempb < 0 && tempc < 0 || tempa > 0 && tempb > 0 && tempc > 0 || tempa == 0 && tempb == 0 && tempc == 0);
}

System::Void MethodMonteKarlo::InteractionForm::Btn_squareTringle(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElement();

	int const numVar = Convert::ToInt32(this->numeric_numVar->Value);
	int const N = Convert::ToInt32(this->numeric_countRNDPointN->Value);
	if (N < 100)
		this->table_values->ColumnCount = N;
	else
		this->table_values->ColumnCount = 20;

	std::vector<double> f_x;
	for (int i = 0; i < 20; i++)
	{
		this->table_values->Rows[0]->Cells[i]->Value = i;
		if (i >= 0 && i < numVar)
			this->table_values->Rows[1]->Cells[i]->Value = int((double)(10.0 * i / numVar) * 100 + 0.5) / 100.0;
		else
			this->table_values->Rows[1]->Cells[i]->Value = int((double)(10.0 * ((i - 20.0) / (numVar - 20.0))) * 100 + 0.5) / 100.0;
		f_x.push_back(Convert::ToDouble(this->table_values->Rows[1]->Cells[i]->Value));
		this->chart1->Series[0]->Points->AddXY(i, f_x[i]);
	}
	this->chart1->Series[1]->Points->AddXY(Convert::ToDouble(this->table_values->Rows[0]->Cells[0]->Value), f_x[0]);
	this->chart1->Series[1]->Points->AddXY(this->table_values->Rows[0]->Cells[19]->Value, this->table_values->Rows[1]->Cells[19]->Value);

	 const double a = 19;
	 const double b = *std::max_element(f_x.begin(), f_x.end());
	 tb_a->Text = a.ToString();
	 tb_b->Text = b.ToString();

	 bool uniformRND = cb_randUniform->Checked;
	 std::vector<double> rnd_x = getRandomPoint(uniformRND, a, N);
	 std::vector<double> rnd_y = getRandomPoint(uniformRND, b, N);
	 if (N < 100)
	 {
		 for (int i = 0; i < N; i++)
		 {
			 this->table_values->Rows[2]->Cells[i]->Value = rnd_x[i];
			 this->table_values->Rows[3]->Cells[i]->Value = rnd_y[i];
		 }
	 }
	 std::map<std::string, double> triangleVertexCoord;
	 triangleVertexCoord["xa"] = Convert::ToDouble(this->table_values->Rows[0]->Cells[0]->Value);
	 triangleVertexCoord["ya"] = Convert::ToDouble(this->table_values->Rows[1]->Cells[0]->Value);
	 triangleVertexCoord["yb"] = Convert::ToDouble(tb_b->Text);
	 for (int i = 0; i < 20; i++)
		 if (Convert::ToDouble(this->table_values->Rows[1]->Cells[i]->Value) == triangleVertexCoord["yb"])
		 {
			 triangleVertexCoord["xb"] = Convert::ToDouble(this->table_values->Rows[0]->Cells[i]->Value);
			 break;
		 }
	 triangleVertexCoord["xc"] = Convert::ToDouble(this->table_values->Rows[0]->Cells[19]->Value);
	 triangleVertexCoord["yc"] = Convert::ToDouble(this->table_values->Rows[1]->Cells[19]->Value);
	
	 for (int i = 0; i < N; i++)
	 {
		 double f_xi = 0;
		 if (i >= 0 && i < numVar)
			 f_xi = int((double)(10.0 * rnd_x[i] / numVar) * 100 + 0.5) / 100.0;
		 else
			 f_xi = int((double)(10.0 * ((rnd_x[i] - 20.0) / (numVar - 20.0))) * 100 + 0.5) / 100.0;
		 if(N<100)
			this->table_values->Rows[4]->Cells[i]->Value = f_xi;

		
		 if (insideTringle(triangleVertexCoord,rnd_x[i],rnd_y[i]) == true && rnd_y[i] < f_xi)
			 this->chart1->Series[2]->Points->AddXY(rnd_x[i], rnd_y[i]);
		 else
			 this->chart1->Series[3]->Points->AddXY(rnd_x[i], rnd_y[i]);
	 }
}

System::Void MethodMonteKarlo::InteractionForm::Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	double coordX = int((chart1->ChartAreas[0]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
	double coordY = int((chart1->ChartAreas[0]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
	double c = chart1->ChartAreas[0]->CursorX->Position;
	label_X->Text = "X: " + c.ToString();
	label_Y->Text = "Y: " + coordY.ToString();
}


/*Для отображения более 1000 столбцов и в свойствах грида в строке AutoSizeColoumns задайте вариант AllCellsExceptHeader,
for (int i = 0; i < 1000+; i++)
{
	this->table_values->Columns->Add("col" + i, "colu" + i);
	this->table_values->Columns[i]->FillWeight = 70;
}*/