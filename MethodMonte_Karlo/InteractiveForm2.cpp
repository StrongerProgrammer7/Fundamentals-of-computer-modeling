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

void MethodMonteKarlo::InteractiveForm2::clearInteractiveElementChartArea2()
{
	this->chart1->Series[4]->Points->Clear();
	this->chart1->Series[5]->Points->Clear();
	this->chart1->Series[6]->Points->Clear();
	this->chart1->Series[7]->Points->Clear();
}

System::Void MethodMonteKarlo::InteractiveForm2::Btn_polar_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearInteractiveElementChartArea2();
	double numVar = Convert::ToDouble(this->numericUpDown_numVar->Value);
	int N = Convert::ToInt32(this->numericUpDown_CountPoint->Value);
	bool uniformRND = this->chb_randUniform->Checked;
	double A = 0;
	double B = 0;
	if (numVar <= 10)
	{
		 A = 11 + numVar;
		 B = 11 - numVar;
	}
	else
	{
		 A = 10;
		 B = numVar -10;
	}

	double min_a = 0,max_a=0,min_b=0,max_b=0;

	for (double h = 0; h <= 2.0 * std::_Pi * 2.0; h += 0.1)
	{
		
		double x = functionPolar(A, B, h,false) * cos(h);
		double y = functionPolar(A, B, h,false) * sin(h);
		if (x < min_a)
			min_a = x;
		if (x > max_a)
			max_a = x;
		if (y < min_b)
			min_b = y;
		if (y > max_b)
			max_b = y;
		this->chart1->Series[4]->Points->AddXY( x, y);
	}
	this->chart1->Series[5]->Points->AddXY(min_a, min_b);
	this->chart1->Series[5]->Points->AddXY(min_a, max_b);
	this->chart1->Series[5]->Points->AddXY(max_a, max_b);
	this->chart1->Series[5]->Points->AddXY(max_a, min_b);
	this->chart1->Series[5]->Points->AddXY(min_a, min_b);

	std::vector<double> rnd_x = getRandomPoint(uniformRND, min_a, max_a, N);
	std::vector<double> rnd_y = getRandomPoint(uniformRND, min_b, max_b, N);

	int M = 0;
	for (int i = 0; i < N; i++)
	{
		double r_i = sqrt(rnd_x[i]*rnd_x[i]+rnd_y[i]*rnd_y[i]);
		double phi_i = 0;
		if (rnd_x[i] > 0)
			phi_i = atan(rnd_y[i] / rnd_x[i]);
		else
			if(rnd_x[i]<0)
				phi_i = std::_Pi + atan(rnd_y[i] / rnd_x[i]);
			else
			{
				if (rnd_y[i] > 0)
					phi_i = std::_Pi / 2.0;
				else
					if (rnd_y[i] < 0)
						phi_i = std::_Pi*3.0 / 2.0;
			}

		if (r_i<functionPolar(A,B,phi_i,false))
		{
			this->chart1->Series[6]->Points->AddXY(rnd_x[i], rnd_y[i]);
			M++;
		}
		else
			this->chart1->Series[7]->Points->AddXY(rnd_x[i], rnd_y[i]);
	}

	this->label_squareFigure->Text = "Площадь фигуры " + (M * (max_a * max_b * 4.0) / N).ToString();
	this->label_check1->Text = "PI/2 *(" +A.ToString() + " + " + B.ToString() +") " + ((std::_Pi/2.0) * (A + B)).ToString();
	this->label_checkIntegral->Text = "Интеграл: " +(0.5*(method_Sympsona(0,std::_Pi*2.0,N,numVar,true))).ToString();
	//this->label_checkIntegral->Text += "   LEFT " + (0.5*(method_LeftRectangle(0,std::_Pi*2.0,N))).ToString();
}

System::Void MethodMonteKarlo::InteractiveForm2::Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	int minX1, minY1, maxX1, maxY1;
	minX1 = (int)chart1->ChartAreas[0]->Position->X;
	maxX1 = (int)(chart1->ChartAreas[0]->Position->X + chart1->ChartAreas[0]->Position->Width * chart1->Width / 100);
	minY1 = (int)chart1->ChartAreas[0]->Position->Y;
	maxY1 = (int)(chart1->ChartAreas[0]->Position->Y + chart1->ChartAreas[0]->Position->Height * chart1->Height / 100);
	Point posChart(e->X, e->Y); //Position of the mouse respect to the chart
	
	if (posChart.X >= minX1 && posChart.X <= maxX1 && posChart.Y >= minY1 && posChart.Y <= maxY1)
	{
		double coordX = int((chart1->ChartAreas[0]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
		double coordY = int((chart1->ChartAreas[0]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
		label_X->Text = "X: " + coordX.ToString();
		label_Y->Text = "Y: " + coordY.ToString();
	}
	else
	{
		double coordX = int((chart1->ChartAreas[1]->AxisX->PixelPositionToValue((double)e->X)) * 1000 + 0.5) / 1000.0;
		double coordY = int((chart1->ChartAreas[1]->AxisY->PixelPositionToValue((double)e->Y)) * 1000 + 0.5) / 1000.0;
		label_X2->Text = "X: " + coordX.ToString();
		label_Y2->Text = "Y: " + coordY.ToString();
	}
	
	
}
/*chart1.ChartAreas[0].AxisX.LabelStyle.Format = "{0:0.00}";*/
