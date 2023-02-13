#include "InteractionForm.h"
#include <random>

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

bool differLittle_MX_DX(double const& coord,int const& a)
{
	double M_X = a / 2.0;
	double D_X = (a * a) / 12.0;
	return (coord + 0.5 >= M_X - 0.5 && (coord + 0.5 <= M_X || coord <= M_X)) && (coord + 0.5 >= D_X - 0.5 && (coord + 0.5 <= D_X || coord <= D_X)) ? true : false;
}

bool MethodMonteKarlo::InteractionForm::isEmptyValuesTable(int const &cell, int const& row)
{
	return Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == NULL || Convert::ToDouble(table_values->Rows[row]->Cells[cell]->Value) == 0.0 ? true : false;
}

void MethodMonteKarlo::InteractionForm::clearInteractiveElement()
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();


}


System::Void MethodMonteKarlo::InteractionForm::Btn_rndPoint_Click(System::Object^ sender, System::EventArgs^ e)
{
	 N = Convert::ToInt32(this->numeric_countRNDPointN->Value);
	 numVar = Convert::ToInt32(this->numeric_numVar->Value);
	 const int a = Convert::ToInt32(this->numeric_a->Value);
	 const int b = Convert::ToInt32(this->numeric_b->Value);

	this->table_values->ColumnCount = N;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist_a(0, a);
	std::uniform_real_distribution<> dist_b(0, b);
	for (int i = 0; i < N; i++)
	{
		double x = int((double)dist_a(gen) * 100 + 0.5) / 100.0;
		double y = int((double)dist_b(gen) * 100 + 0.5) / 100.0;
		if (isEmptyValuesTable(i, 0)) //&& differLittle_MX_DX(x,a) == true)
			this->table_values->Rows[0]->Cells[i]->Value = x;
		if (isEmptyValuesTable(i, 1) )//&& differLittle_MX_DX(y, b) == true)
			this->table_values->Rows[1]->Cells[i]->Value = y;
		if(isEmptyValuesTable(i, 0) || isEmptyValuesTable(i, 1))
			i--;
	}

}
System::Void MethodMonteKarlo::InteractionForm::Btn_createGraph_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElement();

	const int n = Convert::ToInt32(this->numeric_numVar->Value);
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		double x = Convert::ToDouble(this->table_values->Rows[0]->Cells[i]->Value);
		if (x >= 0 && x < n)
			this->table_values->Rows[2]->Cells[i]->Value = int((double)(10.0 * x / n)*100+0.5)/100.0;
		else
			this->table_values->Rows[2]->Cells[i]->Value = int((double)(10.0 * ((x-20.0)/(n-20.0)))*100+0.5)/100.0;
	}

	for (int i = 0; i < N; i++)
	{
		double x = Convert::ToDouble(this->table_values->Rows[0]->Cells[i]->Value);
		double y = Convert::ToDouble(this->table_values->Rows[1]->Cells[i]->Value);
		double f_x = Convert::ToDouble(this->table_values->Rows[2]->Cells[i]->Value);
		this->chart1->Series[0]->Points->AddXY(x, y);
		this->chart1->Series[1]->Points->AddXY(x, f_x);
		if (y < f_x)
			M++;
	}
}


