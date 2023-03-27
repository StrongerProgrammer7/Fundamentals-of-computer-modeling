#include "ModelingInfinityQeueForm.h"

#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]
void main(array<String^>^ args)
{
	std::srand(time(NULL));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ModelingSystemInfiniteQueue::ModelingInfinityQeueForm form;
	Application::Run(% form);
}


System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::setTextForLabelEveryMachine(System::Windows::Forms::Label^ curLabel, int const& totalTimeExectuionTasksCurPC, int const& totalTimeWaitCurPC, int const& totalTimeQueueCurPC, int const& maxCountTaskInQueueCurPC,int const& maxTimeCurrentQueueCurPC)
{
	curLabel->Text = "Время на выполнение всех задач: " + (totalTimeExectuionTasksCurPC / 60).ToString() + " ч. " + (totalTimeExectuionTasksCurPC % 60).ToString() + " мин.\n"
		+ "Время простоя: " + (totalTimeWaitCurPC / 60).ToString() + " ч. " + (totalTimeWaitCurPC % 60).ToString() + " мин. \n"
		+ "Все время ожидания в очереди: " + (totalTimeQueueCurPC / 60).ToString() + " ч. " + (totalTimeQueueCurPC % 60).ToString() + " мин. \n" 
		+ "Максимальное время очереди: " + (maxTimeCurrentQueueCurPC / 60).ToString() + " ч. " + (maxTimeCurrentQueueCurPC % 60).ToString() + " мин. \n"
		" Макс очередь: " + maxCountTaskInQueueCurPC.ToString();
	if (totalTimeExectuionTasksCurPC == 0)
		curLabel->Text += "\n Эффективность ЭВМ 0%. \nНе используется, рекомендуется повысить\n вероятность попадания.";
	else
	{
		if(totalTimeExectuionTasksCurPC == totalTimeWaitCurPC)
			curLabel->Text += "\n Эффективность ЭВМ 50%. \nИспользуется лишь на половину, \nследует повысить вероятность попадания.";
		else
			if(maxTimeCurrentQueueCurPC > totalTimeExectuionTasksCurPC * 0.3)
				curLabel->Text += "\n Эффективность ЭВМ выше среднего. \nДолгое выполнение, \nрекомендуется понизить вероятность попадания\n или уменьшить время выполнения.";
			else
				if(totalTimeWaitCurPC > totalTimeExectuionTasksCurPC * 0.5)
					curLabel->Text += "\n Эффективность ЭВМ низкая. \nСлишком долгий простой, \nследует повысить вероятность попадания.";
				else
					curLabel->Text += "\n Эффективность ЭВМ нормальная. \nИспользуется в пределах нормы.";
	}
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_startInteervalGetTask_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_endInteervalGetTask_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}



System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskSecondAfterFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskThirdAfterFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_startTimeExecutionFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_endTimeExecutionFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_startTimeExecutionSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_endTimeExecutionSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_startTimeExecutionThird_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_endTimeExecutionThird_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

System::Boolean ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::checkInput(System::Windows::Forms::KeyPressEventArgs^ e)
{
	if ((Char::IsNumber(e->KeyChar) | Char::IsPunctuation(e->KeyChar)) || e->KeyChar == (char)8)
		return false;
	else
		return true;
}


double getRandom_uniformRealDistribution(double const& start, double const& end)
{
	std::mt19937 gen((std::random_device())());
	std::uniform_real_distribution<> nd(start, end);
	double res = std::abs(int((nd(gen)) * 100 + 0.5) / 100.0);
	return res;
}




int giveNumberPC(double const& prob1, double const& prob2)
{
	double random = getRandom_uniformRealDistribution(0.0, 1.0);
	if (random > 0 && random < prob1)
		return 1;
	else
	{
		if (random >= prob1 && random <= prob1 + prob2)
			return 2;
		else
			return 3;
	}
	return 0;
}

void completeTask(std::vector<double>& listTaskCurPC, int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask)
{
	
	totalTimeExecutionPC += timeExectuionTaskCurPC;
	countCompleteTask++;

	std::reverse(listTaskCurPC.begin(), listTaskCurPC.end());
	listTaskCurPC.pop_back();
	if (listTaskCurPC.size() != 0)
		std::reverse(listTaskCurPC.begin(), listTaskCurPC.end());
	if (listTaskCurPC.size() == 0)
		timeExectuionTaskCurPC = 0;
	else
		timeExectuionTaskCurPC = 1;
}

void saveSizeQueueIfExists(int const& countTask, int& maxQueue)
{
	if (countTask > 1 && maxQueue < countTask - 1)
		maxQueue = countTask - 1;
}

void calculateTimeInQueue(int const& countTask, int& timeInQueue,int& timeCurrentQueue ,int& maxTimeCurrentQueueCurPC)
{
	if (countTask > 1)
	{
		timeInQueue++;
		timeCurrentQueue++;
	}
	else
	{
		if (timeCurrentQueue > maxTimeCurrentQueueCurPC)
			maxTimeCurrentQueueCurPC = timeCurrentQueue;
		timeCurrentQueue = 0;
	}
}

void checkWorkPC(std::vector<double> & listTaskCurPC, int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask, int& maxQueue, int& timeInQueue, int& timeWait, int& timeCurrentQueue, int& maxTimeCurrentQueueCurPC)
{
	if (listTaskCurPC.size() != 0)
	{
		if (timeExectuionTaskCurPC >= std::round(listTaskCurPC[0]))
			completeTask(listTaskCurPC, timeExectuionTaskCurPC, totalTimeExecutionPC, countCompleteTask);
		else
		{
			timeExectuionTaskCurPC++;
			saveSizeQueueIfExists(listTaskCurPC.size(), maxQueue);
			calculateTimeInQueue(listTaskCurPC.size(), timeInQueue,timeCurrentQueue,maxTimeCurrentQueueCurPC);

		}
	}
	if(listTaskCurPC.size() == 0)
		timeWait++;

}

void correctTime(int const& totalTimeWork, int& totalTimeWorkCurMachine)
{
	switch (totalTimeWork < totalTimeWorkCurMachine)
	{
	case true:
		totalTimeWorkCurMachine--;
		break;
	case false:
		totalTimeWorkCurMachine++;
		break;
	default:
		break;
	}
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Btn_exectuion_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::ofstream logFile("log.txt");

	int countTask = Convert::ToInt32(numericUpDown1->Text);
	double const startInterrvalGetTask = Convert::ToDouble(tb_startInteervalGetTask->Text->Replace(".", ","));
	double const endInteervalGetTask = Convert::ToDouble(tb_endInteervalGetTask->Text->Replace(".", ","));

	double const probabilityGetTaskFirstPC = Convert::ToDouble(tb_probabilityGetTaskFirst->Text->Replace(".", ","));
	double const probabilityGetTaskSecondPC = Convert::ToDouble(tb_probabilityGetTaskSecond->Text->Replace(".", ","));
	double const probabilityGetTaskThirdPC = std::abs( 1 - (probabilityGetTaskFirstPC + probabilityGetTaskSecondPC));

	double const probabilityGetTaskSecondPCAfterFirstPC = Convert::ToDouble(tb_probabilityGetTaskSecondAfterFirst->Text->Replace(".", ","));
	double const probabilityGetTaskThirdPCAfterFirstPC = Convert::ToDouble(tb_probabilityGetTaskThirdAfterFirst->Text->Replace(".", ","));
	
	//Интервал выполнение 1 ЭВМ
	double const startIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_startTimeExecutionFirst->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_endTimeExecutionFirst->Text->Replace(".", ","));
	//Интервал выполнения 2 ЭВМ
	double const startIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_startTimeExecutionSecond->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_endTimeExecutionSecond->Text->Replace(".", ","));
	//Интервал выполнения 3 ЭВМ
	double const startIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_startTimeExecutionThird->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_endTimeExecutionThird->Text->Replace(".", ","));

	std::vector<double> listTimeExecutionTasksFirstPC; //содержит время выполнения каждого задания 1 ЭВМ
	std::vector<double> listTimeExecutionTasksSecondPC; // содержит время выполнения каждого задания 2 ЭВМ
	std::vector<double> listTimeExecutionTasksThirdPC; // содержит время выполнения каждого задания 3 ЭВМ
	
	//Общее время выполнения задач и количество 1 ЭВМ
	int totalTimeExectuionTasksFristPC = 0;
	int countCompleteTaskFirstPC = 0;
	//Общее время выполнения задач и количество 2 ЭВМ
	int totalTimeExectuionTasksSecondPC = 0;
	int countCompleteSecondPC = 0;
	//Общее время выполнения задач и количество 3 ЭВМ
	int totalTimeExectuionTasksThirdPC = 0;
	int countCompleteThirdPC = 0;

	//общее время простоя каждой ЭВМ
	int totalTimeWaitFirstPC = 0;
	int totalTimeWaitSecondPC = 0;
	int totalTimeWaitThirdPC = 0;

	//время выполнения задачи для каждой ЭВМ
	int currentTimeExecutionFirstPC = 0;
	int currentTimeExecutionSecondPC = 0;
	int currentTimeExecutionThirdPC = 0;

	//общее время очереди в каждой ЭВМ
	int totalTimeQueueFirstPC = 0;
	int totalTimeQueueSecondPC = 0;
	int totalTimeQueueThirdPC = 0;

	//максимальное время очереди
	int maxTimeQueueFirstPC = 0;
	int maxTimeQueueSecondPC = 0;
	int maxTimeQueueThirdPC = 0;

	//Время для каждой отдельной очереди для поиска самой долгой очереди
	int timeCurrentQueueFirstPC = 0;
	int timeCurrentQueueSecondPC = 0;
	int timeCurrentQueueThridPC = 0;

	//Максимальная очередь каждой ЭВМ
	int maxCountTaskInQueueFirstPC = 0;
	int maxCountTaskInQueueSecondPC = 0;
	int maxCountTaskInQueueThirdPC = 0;
	
	//общее время поступления задач
	double totalTimeReceiptsTasks = 0;
	
	double timeBeforeNextTask = getRandom_uniformRealDistribution(startInterrvalGetTask, endInteervalGetTask);
	double currentTime = 0;
	int totalTimeWork = 0;
	while (true)
	{
		if (currentTime >= timeBeforeNextTask && countTask > 0)
		{
			countTask--;
			
			switch (giveNumberPC(probabilityGetTaskFirstPC, probabilityGetTaskSecondPC))
			{
			case 1:
				listTimeExecutionTasksFirstPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskFirstPC, endIntervalTimeExecutionTaskFirstPC));
				break;
			case 2:
				listTimeExecutionTasksSecondPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC));
				break;
			case 3:
				listTimeExecutionTasksThirdPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskThirdPC, endIntervalTimeExecutionTaskThirdPC));
				break;
			default:
				break;
			}

			totalTimeReceiptsTasks += timeBeforeNextTask;
			timeBeforeNextTask = std::round(getRandom_uniformRealDistribution(startInterrvalGetTask, endInteervalGetTask));
			currentTime = 0;
		}
		
		if (listTimeExecutionTasksFirstPC.size() != 0)
		{

			if (currentTimeExecutionFirstPC >= std::round(listTimeExecutionTasksFirstPC[0]))
			{
				completeTask(listTimeExecutionTasksFirstPC, currentTimeExecutionFirstPC, totalTimeExectuionTasksFristPC, countCompleteTaskFirstPC);

				switch (giveNumberPC(probabilityGetTaskSecondPCAfterFirstPC, probabilityGetTaskThirdPCAfterFirstPC))
				{
				case 1:
					listTimeExecutionTasksSecondPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC));
					break;
				case 2:
					listTimeExecutionTasksThirdPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskThirdPC, endIntervalTimeExecutionTaskThirdPC));
					break;
				default:
					break;
				}
			}
			else
			{
				currentTimeExecutionFirstPC++;
				saveSizeQueueIfExists(listTimeExecutionTasksFirstPC.size(), maxCountTaskInQueueFirstPC);
				calculateTimeInQueue(listTimeExecutionTasksFirstPC.size(), totalTimeQueueFirstPC,timeCurrentQueueFirstPC,maxTimeQueueFirstPC);
			}
			
		}
		if(listTimeExecutionTasksFirstPC.size() == 0)
			totalTimeWaitFirstPC++;

		checkWorkPC(listTimeExecutionTasksSecondPC, currentTimeExecutionSecondPC, totalTimeExectuionTasksSecondPC, countCompleteSecondPC, maxCountTaskInQueueSecondPC, totalTimeQueueSecondPC, totalTimeWaitSecondPC,timeCurrentQueueSecondPC,maxTimeQueueSecondPC);
		checkWorkPC(listTimeExecutionTasksThirdPC, currentTimeExecutionThirdPC, totalTimeExectuionTasksThirdPC, countCompleteThirdPC, maxCountTaskInQueueThirdPC, totalTimeQueueThirdPC, totalTimeWaitThirdPC,timeCurrentQueueThridPC,maxTimeQueueThirdPC);

		logFile << " First PC : \n";
		logFile << " totalTimeExectuionTasksFristPC = " << totalTimeExectuionTasksFristPC << " totalTimeWaitFirstPC =  " << totalTimeWaitFirstPC << " currentTimeExecutionFirstPC =" << currentTimeExecutionFirstPC << "\n";
		logFile << " Second PC : \n";
		logFile << " totalTimeExectuionTasksSecondPC = " << totalTimeExectuionTasksSecondPC << " totalTimeWaitSecondPC =  " << totalTimeWaitSecondPC << " currentTimeExecutionSecondPC =" << currentTimeExecutionSecondPC << "\n";
		logFile << " Third PC : \n";
		logFile << " totalTimeExectuionTasksThirdPC = " << totalTimeExectuionTasksThirdPC << " totalTimeWaitThirdPC =  " << totalTimeWaitThirdPC << " currentTimeExecutionThirdPC =" << currentTimeExecutionThirdPC << "\n";
		logFile << "---------------------------------------\n";
		
		if(countTask > 0)
			currentTime+=1;
		totalTimeWork++;
	
		logFile << "totalTimeWork = " << totalTimeWork << "\n---------------------------------------\n";
		if (countTask == 0 && listTimeExecutionTasksFirstPC.size() == 0 && listTimeExecutionTasksSecondPC.size() == 0 && listTimeExecutionTasksThirdPC.size() == 0)
			break;

	}

	
	setTextForLabelEveryMachine(lbl_FirstPC, totalTimeExectuionTasksFristPC, totalTimeWaitFirstPC, totalTimeQueueFirstPC, maxCountTaskInQueueFirstPC,maxTimeQueueFirstPC);
	setTextForLabelEveryMachine(lbl_SecondPC, totalTimeExectuionTasksSecondPC, totalTimeWaitSecondPC, totalTimeQueueSecondPC, maxCountTaskInQueueSecondPC,maxTimeQueueSecondPC);
	setTextForLabelEveryMachine(lbl_ThirdPC, totalTimeExectuionTasksThirdPC, totalTimeWaitThirdPC, totalTimeQueueThirdPC, maxCountTaskInQueueThirdPC,maxTimeQueueThirdPC);

	int maxTimeQueuePC = std::max(maxTimeQueueThirdPC, std::max(maxTimeQueueFirstPC, maxTimeQueueSecondPC));
	int maxTimeWaitPC = std::max(totalTimeWaitFirstPC, std::max(totalTimeWaitSecondPC, totalTimeWaitThirdPC));

	lbl_total->Text = "Общее время работы : " + (totalTimeWork / 60).ToString() + " ч. " + (totalTimeWork % 60).ToString() + " мин.";
	lbl_total->Text += "\nОбщее время ожидания в очереди: " + ((totalTimeQueueFirstPC+totalTimeQueueSecondPC+totalTimeQueueThirdPC)/60).ToString() + " ч. " + ((totalTimeQueueFirstPC + totalTimeQueueSecondPC + totalTimeQueueThirdPC)  % 60).ToString() + " мин.";
	lbl_total->Text += "\nОбщее время в простое: " + ((totalTimeWaitFirstPC+totalTimeWaitSecondPC+totalTimeWaitThirdPC)/ 60).ToString() + " ч. " + ((totalTimeWaitFirstPC + totalTimeWaitSecondPC + totalTimeWaitThirdPC) % 60).ToString() + " мин.";
	lbl_total->Text += "\nВремя поступления задач: " + (((int)std::round(totalTimeReceiptsTasks)) / 60).ToString() + " ч. " + (static_cast<int>(std::round(totalTimeReceiptsTasks)) % 60).ToString() + " мин."; 
	lbl_total->Text += "\nСамое макс время очереди: " + ((maxTimeQueuePC) / 60).ToString() + " ч. " + ((maxTimeQueuePC) % 60).ToString() + " мин.";
	lbl_total->Text += "\nСамое макс время простоя: " + ((maxTimeWaitPC) / 60).ToString() + " ч. " + ((maxTimeWaitPC) % 60).ToString() + " мин.";
	

	

	lbl_total->Text += "\n\n Краткая сводка об эффективности:\n---\n";
	if (maxTimeQueuePC > totalTimeWork * 0.8)
		lbl_total->Text += "Макс время очереди более 80% от всей работы,\n рекомендуется снизить нагрузку\n с нагруженной ЭВМ и повысить на менее\n нагруженную \n(см. сводка для текущей ЭВМ)\n---\n";
	else
		lbl_total->Text += "Макс время очереди занимает менее 80% времени \nот всей работы, в пределах нормы\n---\n";
	if ((totalTimeWaitFirstPC + totalTimeWaitSecondPC + totalTimeWaitThirdPC) > totalTimeWork * 0.3)
		lbl_total->Text += "Общее время простоя более 30% от всей работы, \nЭВМ практически не работают\n---\n";
	else
		lbl_total->Text += "Общее время простоя менее 30% от всей работы \n ЭВМ работают в стабильном режиме\n---\n";

	logFile.close();
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}



