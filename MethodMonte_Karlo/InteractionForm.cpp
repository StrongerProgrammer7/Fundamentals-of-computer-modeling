#include "InteractionForm.h"
#include "function.h"


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


bool MethodMonteKarlo::InteractionForm::isEmptyValuesTable(int const& cell, int const& row)
{
	return Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == NULL || Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == 0.0 ? true : false;
}

void MethodMonteKarlo::InteractionForm::clearInteractiveElementChartArea1()
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	this->chart1->Series[3]->Points->Clear();
}

void MethodMonteKarlo::InteractionForm::clearInteractiveElementChartArea2()
{
	this->chart1->Series[4]->Points->Clear();
	this->chart1->Series[5]->Points->Clear();
	this->chart1->Series[6]->Points->Clear();
}

void MethodMonteKarlo::InteractionForm::fillTable_values(const int& N, std::vector<double> rnd_x, std::vector<double> rnd_y)
{
	if (N < 100)
	{
		for (int i = 0; i < N; i++)
		{
			this->table_values_integral->Rows[2]->Cells[i]->Value = rnd_x[i];
			this->table_values_integral->Rows[3]->Cells[i]->Value = rnd_y[i];
		}
	}
}
System::Void MethodMonteKarlo::InteractionForm::Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	double coordX = int((chart1->ChartAreas[0]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
	double coordY = int((chart1->ChartAreas[0]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
	label_X->Text = "X: " + coordX.ToString();
	label_Y->Text = "Y: " + coordY.ToString();
	coordX = int((chart1->ChartAreas[1]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
	coordY = int((chart1->ChartAreas[1]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
	label_X2->Text = "X: " + coordX.ToString();
	label_Y2->Text = "Y: " + coordY.ToString();
}


System::Void MethodMonteKarlo::InteractionForm::Btn_squareTringle(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElementChartArea1();

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
		this->table_values->Rows[1]->Cells[i]->Value = functionTringle(i, numVar);

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
	 fillTable_values(N,rnd_x, rnd_y);

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
	
	 int M = 0;
	 for (int i = 0; i < N; i++)
	 {
		 double f_xi = 0;
		 if (i >= 0 && i < numVar)
			 f_xi = int((double)(10.0 * rnd_x[i] / numVar) * 100 + 0.5) / 100.0;
		 else
			 f_xi = int((double)(10.0 * ((rnd_x[i] - 20.0) / (numVar - 20.0))) * 100 + 0.5) / 100.0;
		 if(N<100)
			this->table_values->Rows[4]->Cells[i]->Value = f_xi;

		
		 if (insideTringle(triangleVertexCoord, rnd_x[i], rnd_y[i]) == true && rnd_y[i] < f_xi)
		 {
			 this->chart1->Series[2]->Points->AddXY(rnd_x[i], rnd_y[i]);
			 M++;
		 }		 
		 else
			 this->chart1->Series[3]->Points->AddXY(rnd_x[i], rnd_y[i]);
	 }
	 double squareFigure = (M * a * b) / N;
	 this->label_squareTringle->Text = "Площадь: " +  squareFigure.ToString();
}


System::Void MethodMonteKarlo::InteractionForm::Btn_squareIntegral_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElementChartArea2();
	int const numVar = Convert::ToInt32(this->numeric_numVar->Value);
	int const N = Convert::ToInt32(this->numeric_countRNDPointN->Value);
	if (N < 100)
		this->table_values_integral->ColumnCount = N+1;
	else
		this->table_values_integral->ColumnCount = 20;

	std::vector<double> x_integral;
	std::vector<double> y_integral;
	getCoordinateMonteCarloIntegral(x_integral, y_integral,numVar,N);
	double minFunc = 0, maxFunc = 0;
	findMax_MinFuncMonteCarlo(y_integral, maxFunc, minFunc);

	for (int i = 0; i < N; i++)
	{
		if (N < 100)
		{
			this->table_values_integral->Rows[0]->Cells[i]->Value = x_integral[i];
			this->table_values_integral->Rows[1]->Cells[i]->Value = y_integral[i];
		}

		this->chart1->Series[4]->Points->AddXY(x_integral[i],y_integral[i]);
	}
	this->chart1->Series[4]->Points->AddXY(x_integral[x_integral.size()-1], y_integral[y_integral.size()-1]);

	const double a = 5;
	const double b = maxFunc;
	tb_a_int->Text = a.ToString();
	tb_b_int->Text = b.ToString();

	bool uniformRND = cb_randUniform->Checked;
	std::vector<double> rnd_x = getRandomPoint(uniformRND, a, N);
	std::vector<double> rnd_y = getRandomPoint(uniformRND, b, N);
	fillTable_values(N,rnd_x, rnd_y);
	
	int M = 0;

	for (int i = 0; i < N; i++)
	{
		double f_xi = functionIntegral(rnd_x[i],numVar);
		if(N<100)
			this->table_values_integral->Rows[4]->Cells[i]->Value = f_xi;
		if (rnd_y[i] < f_xi && rnd_x[i] <= x_integral[x_integral.size()-1])
		{
			this->chart1->Series[5]->Points->AddXY(rnd_x[i], rnd_y[i]);
			M++;
		}
		else
			this->chart1->Series[6]->Points->AddXY(rnd_x[i], rnd_y[i]);
	}
	double integral = (M * a * b) / N;//M*(b-a)*(maxFunc-minFunc)/N;
	double sum = 0;
	for (int i = 0; i < y_integral.size(); i++)
		sum += y_integral[i];
	this->label_integral->Text = "Интеграл: " + integral.ToString() + " Проверка: " + sum.ToString();
	
}


/*Для отображения более 1000 столбцов и в свойствах грида в строке AutoSizeColoumns задайте вариант AllCellsExceptHeader,
for (int i = 0; i < 1000+; i++)
{
	this->table_values->Columns->Add("col" + i, "colu" + i);
	this->table_values->Columns[i]->FillWeight = 70;
}*/