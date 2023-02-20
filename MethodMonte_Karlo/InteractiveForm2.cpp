#include "InteractiveForm2.h"
#include "function.h"

using namespace System;
using namespace System::Windows::Forms;

System::Void MethodMonteKarlo::InteractiveForm2::Button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElementChartArea1();
	double R = Convert::ToDouble(this->numericUpDown_numVar->Value);
	int N = Convert::ToInt32(this->numericUpDown_CountPoint->Value);
	bool uniformRND = this->chb_randUniform->Checked;

	//TODO a = смещние координат b = смещение коориданм
	
	this->chart1->Series[0]->Points->AddXY(0, 0);
	this->chart1->Series[0]->Points->AddXY(0, 2*R);
	this->chart1->Series[0]->Points->AddXY(2*R, 2*R);
	this->chart1->Series[0]->Points->AddXY(2*R, 0);
	this->chart1->Series[0]->Points->AddXY(0, 0);

	for (double h = 0; h < 2 * std::_Pi*2.0; h += 0.01)
		this->chart1->Series[1]->Points->AddXY(R+R*cos(h), R + R * sin(h));

	std::vector<double> rnd_x = getRandomPoint(uniformRND, 0,2.0*R, N);
	std::vector<double> rnd_y = getRandomPoint(uniformRND, 0,2.0*R, N);

	double M = 0;
	for (int i = 0; i < N; i++)
	{
							//а			а				b				b
		double f_xi = (rnd_x[i]-R)*(rnd_x[i] - R) + (rnd_y[i] - R)* (rnd_y[i] - R);
		//double f_xi = rnd_x[i] * rnd_x[i] + rnd_y[i] * rnd_y[i]; //if coordStart 0,0
		if (f_xi<=R*R)
		{
			this->chart1->Series[3]->Points->AddXY(rnd_x[i], rnd_y[i]);
			M++;
		}
		else
			this->chart1->Series[2]->Points->AddXY(rnd_x[i], rnd_y[i]);
	}

	double squareSquare = 4 * R * R;
	double squareCicle = 4 * M / N;
	this->label_pi->Text = "ПИ : " + (std::_Pi).ToString();
	this->label_squareSquare->Text = "Площадь квадрата : " + (squareSquare).ToString();
	this->label_squareCicle->Text = "Площадь круга : " + (squareCicle).ToString();
}

void MethodMonteKarlo::InteractiveForm2::clearInteractiveElementChartArea1()
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	this->chart1->Series[3]->Points->Clear();
}

double ro(double A, double B, double phi)
{
	//Acos^2(phi) + BSin^2(phi)
	return std::sqrt(A * (cos(2*phi)+sin(2*phi)) + B * sin(2 * phi));
}
System::Void MethodMonteKarlo::InteractiveForm2::Btn_polar_Click(System::Object^ sender, System::EventArgs^ e)
{
	//clearInteractiveElementChartArea1();
	double numVar = Convert::ToDouble(this->numericUpDown_numVar->Value);
	int N = Convert::ToInt32(this->numericUpDown_CountPoint->Value);
	bool uniformRND = this->chb_randUniform->Checked;

	double A = 11 + numVar;
	double B = 11 - numVar;

	for (double h = 0; h < 2 * std::_Pi * 2.0; h += 0.1)
	{
		//TODO слишком малое значение
		double x = ro(A, B, h) * cos(h);
		double y = ro(A, B, h) * sin(h);
		this->chart1->Series[4]->Points->AddXY( x, y);
	}
		
}
