#include "ModelingWorkForm.h"
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	std::srand(time(NULL));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ModelingWorkMachineWithBreakdowns::ModelingWorkForm form;
	Application::Run(% form);

}

double getTimeBefoeNextTask(double const& lambda)
{
	double u = rand() / (RAND_MAX + 1.0);
	double res = int((-log(1 - u) / lambda) * 100 + 0.5) / 100.0;
	return res;
}

double getTimeBeforeBreakdownMachine(double const& timeBreakDown_M_X, double const& timeBreakdown_StandartDeviation)
{
	std::mt19937 gen((std::random_device())());
	std::normal_distribution<double> nd(timeBreakDown_M_X, timeBreakdown_StandartDeviation);
	double res = int((nd(gen)) * 100 + 0.5) / 100.0;
	return res;
}

double getRandomUniform(double const& start,double const& end)
{
	return ((double)rand()) / RAND_MAX;
}

double getDebugMachine(double const& timeExectuionInterval1, double const& timeExectuionInterval2)
{
	double res = int((getRandomUniform(timeExectuionInterval1, timeExectuionInterval2)) * 100 + 0.5) / 100.0;
	return res;
}

double getTimeExecutionTask(double const& timeExectuionM_X,double const& timeExectuionStandartDeviation)
{
	double res = int((getRandomUniform(timeExectuionM_X, timeExectuionStandartDeviation)) * 100 + 0.5) / 100.0;
	return res;
}

double getTimeRepair(double const& timeTroubleshootinFrom,double const& timeTroubleshootinTo)
{
	double res = int((getRandomUniform(timeTroubleshootinFrom, timeTroubleshootinTo)) * 100 + 0.5) / 100.0;
	return res;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Btn_execution_Click(System::Object^ sender, System::EventArgs^ e)
{
	int countDetails = Convert::ToInt32(numericUpDown1->Text);
	int allDetails = countDetails;
	double const timeExectuionInterval1 = Convert::ToDouble(tb_TimeExecutionInterval1->Text->Replace(".",",")); //наладка станка
	double const timeExectuionInterval2 = Convert::ToDouble(tb_TimeExecutionInterval2->Text->Replace(".", ","));
	double const timeExectuionM_X = Convert::ToDouble(tb_TimeExecutionM_X->Text->Replace(".", ",")); // время вып задания
	double const timeExectuionStandartDeviation = Convert::ToDouble(tb_TimeExecutionStandartDeviation->Text->Replace(".", ","));

	double const timeBreakDown_M_X = Convert::ToDouble(tb_breakdownM_X->Text->Replace(".", ",")); // между поломками интервал
	double const timeBreakdown_StandartDeviation = Convert::ToDouble(tb_breakdownStandartDeviation->Text->Replace(".", ","));

	double const timeTroubleshootinFrom = Convert::ToDouble(tb_troubleshootingFrom->Text->Replace(".", ",")); // время устранения от
	double const timeTroubleshootinTo = Convert::ToDouble(tb_troubleshootingTo->Text->Replace(".", ","));

	double timeBeforeNextTask = getTimeBefoeNextTask(1.0); //время до следующего задания
	double timeToBreakdownMachine = getTimeBeforeBreakdownMachine(timeBreakDown_M_X, timeBreakdown_StandartDeviation); // время до поломки
	
	double totalTimeWorkMachine = 0;
	int brokenDetails = 0;
	double totalTimeRepair = 0;
	while (countDetails > 0)
	{
		if (timeBeforeNextTask > 0)
		{
			totalTimeWorkMachine += timeBeforeNextTask;
			timeBeforeNextTask = 0;
		}

		double setMachine = getDebugMachine(timeExectuionInterval1, timeExectuionInterval2);
		double timeExectuionTask = getTimeExecutionTask(timeExectuionM_X, timeExectuionStandartDeviation);
		double timeDebugExection_oneTask = setMachine + timeExectuionTask;

		if (timeDebugExection_oneTask < timeToBreakdownMachine)
		{
			timeBeforeNextTask += getTimeBefoeNextTask(1.0);
			totalTimeWorkMachine += timeDebugExection_oneTask;
			timeToBreakdownMachine -= timeDebugExection_oneTask;
			countDetails--;
		}
		else
		{
			brokenDetails++;
			totalTimeWorkMachine += timeToBreakdownMachine;
			timeBeforeNextTask -= timeToBreakdownMachine;
			double repairTime = getTimeRepair(timeTroubleshootinFrom, timeTroubleshootinTo);
			//cout repairTime
			totalTimeWorkMachine += repairTime;
			timeBeforeNextTask -= repairTime;
			timeToBreakdownMachine = getTimeBeforeBreakdownMachine(timeBreakDown_M_X, timeBreakdown_StandartDeviation); 
			totalTimeRepair += repairTime;

		}
	}
	int countDetailInQueue = 0;
	while (timeBeforeNextTask < 0)
	{
		timeBeforeNextTask += getTimeBefoeNextTask(1.0);
		countDetailInQueue++;
	}

	lbl_countTask->Text = "Количество деталей: " + allDetails.ToString();
	lbl_CountBreakdown->Text = "Количество поломок: " + brokenDetails.ToString();
	lbl_TimeWork->Text = "Время работы: " + (static_cast<int>(totalTimeWorkMachine)).ToString() +" ч. " + (static_cast<int>((int)totalTimeWorkMachine % 1 * 60)).ToString() +" мин.";
	lbl_DetailInQueue->Text = "Деталей в очереди: " + countDetailInQueue.ToString();
	lbl_TotalTimeRepair->Text = "Общее время ремонта: " + (static_cast<int>(totalTimeRepair)).ToString() + " ч. " + (static_cast<int>((int)totalTimeRepair % 1 * 60)).ToString() + " мин.";
	//return brokenDetails,totalTimeWorkMachine, totalTimeWorkMachine/allDetails,countDetailInQueue,
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_TimeExecutionInterval1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e)== true)
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_TimeExecutionInterval2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_TimeExecutionM_X_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_TimeExecutionStandartDeviation_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_breakdownM_X_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_breakdownStandartDeviation_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_troubleshootingFrom_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingWorkMachineWithBreakdowns::ModelingWorkForm::Tb_troubleshootingTo_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Boolean ModelingWorkMachineWithBreakdowns::ModelingWorkForm::checkInput(System::Windows::Forms::KeyPressEventArgs^ e)
{
	if ((Char::IsNumber(e->KeyChar) | Char::IsPunctuation(e->KeyChar)) || e->KeyChar == (char)8)
		return false;
	else
		return true;
}


