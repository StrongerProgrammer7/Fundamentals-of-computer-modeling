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


System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::setTextForLabelEveryMachine(System::Windows::Forms::Label^ curLabel, int const& totalTimeExectuionTasksCurPC, int const& totalTimeWaitCurPC, int const& totalTimeQueueCurPC, int const& maxCountTaskInQueueCurPC,int const& maxTimeCurrentQueueCurPC,int const& completeTask,int const& countTaskInQueueAfterTask,int const& countQueue)

{
	int middleTimeWorkForOneTask = 1;
	int middleTimeQueueForOneTask = 1;

	if (completeTask != 0)
	{
		middleTimeWorkForOneTask = std::round(totalTimeExectuionTasksCurPC / completeTask);
	}
	if(countQueue!=0)
		middleTimeQueueForOneTask = std::round(totalTimeQueueCurPC / countQueue);

	curLabel->Text = "Время на выполнение всех задач: " + (totalTimeExectuionTasksCurPC / 60).ToString() + " ч. " + (totalTimeExectuionTasksCurPC % 60).ToString() + " мин.\n"
		+ "Количество выполненных задач: " + completeTask + "\n"
		+ "Количество задач оставшихся в очереди: " + countTaskInQueueAfterTask + "\n "
		+ " Среднее время выполнения \n   на одну задачу : " + (middleTimeWorkForOneTask / 60).ToString() + " ч. " + (middleTimeWorkForOneTask % 60).ToString() + " мин. \n"
		//+ "Все время ожидания в очереди: " + (totalTimeQueueCurPC / 60).ToString() + " ч. " + (totalTimeQueueCurPC % 60).ToString() + " мин. \n" 
		+ "Среднее время в очереди: " + (middleTimeQueueForOneTask / 60).ToString() + " ч. " + (middleTimeQueueForOneTask % 60).ToString() + " мин. \n"
		+ "Время простоя: " + (totalTimeWaitCurPC / 60).ToString() + " ч. " + (totalTimeWaitCurPC % 60).ToString() + " мин. \n ---- \n";
		//" Среднее количество задач скопившихся\n в очереди : " + maxCountTaskInQueueCurPC.ToString() + " задач \n ---- \n";

	if (totalTimeExectuionTasksCurPC == 0)
		curLabel->Text += " Эффективность ЭВМ 0. \nНе используется, рекомендуется повысить\n вероятность попадания.";
	else
	{
		if(totalTimeExectuionTasksCurPC == totalTimeWaitCurPC)
			curLabel->Text += " Эффективность ЭВМ средняя. \nИспользуется лишь на половину, \nследует повысить вероятность попадания.";
		else
			if(maxTimeCurrentQueueCurPC > totalTimeExectuionTasksCurPC * 0.3)
				curLabel->Text += " Эффективность ЭВМ выше среднего. \nДолгое выполнение, рекомендуется \nпонизить вероятность попадания\n или уменьшить время выполнения.";
			else
				if(totalTimeWaitCurPC > totalTimeExectuionTasksCurPC * 0.3)
					curLabel->Text += " Эффективность ЭВМ низкая. \nСлишком долгий простой, \nследует повысить вероятность попадания.";
				else
					curLabel->Text += " Эффективность ЭВМ нормальная. \nИспользуется в пределах нормы.";
	}
	curLabel->Text += "\n ---- \n";
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

void calculateTimeInQueue(int const& countTask, int& timeInQueue,int& timeCurrentQueue ,int& maxTimeCurrentQueueCurPC,int& countQueueCurPC)
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
		if (timeCurrentQueue != 0)
		{
			timeCurrentQueue = 0;
			countQueueCurPC++;
		}
	}
}

void checkWorkPC(std::vector<double> & listTaskCurPC, int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask, int& maxQueue, int& timeInQueue, int& timeWait, int& timeCurrentQueue, int& maxTimeCurrentQueueCurPC,int& countQueueCurPC)
{
	if (listTaskCurPC.size() != 0)
	{
		if (timeExectuionTaskCurPC >= std::round(listTaskCurPC[0]))
			completeTask(listTaskCurPC, timeExectuionTaskCurPC, totalTimeExecutionPC, countCompleteTask);
		else
		{
			timeExectuionTaskCurPC++;
			saveSizeQueueIfExists(listTaskCurPC.size(), maxQueue);
			calculateTimeInQueue(listTaskCurPC.size(), timeInQueue,timeCurrentQueue,maxTimeCurrentQueueCurPC, countQueueCurPC);

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
	/*std::ofstream logFile("log.txt");*/

	int countTask = Convert::ToInt32(numericUpDown1->Text);
	int countTaskTemp = Convert::ToInt32(numericUpDown1->Text);
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
	int countCompleteFirstPC = 0;
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

	//Количество очередй
	int countQueueFirstPC = 0;
	int countQueueSecondPC = 0;
	int countQueueThirdPC = 0;
	
	//общее время поступления задач
	double totalTimeReceiptsTasks = 0;
	
	//Количество задач оставшихся в очереди
	int countTaskInQueueAfterGetAllTaskFirstPC = 0;
	int countTaskInQueueAfterGetAllTaskSecondPC = 0;
	int countTaskInQueueAfterGetAllTaskThirdPC = 0;

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
				listTimeExecutionTasksFirstPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskFirstPC, endIntervalTimeExecutionTaskFirstPC));
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
				completeTask(listTimeExecutionTasksFirstPC, currentTimeExecutionFirstPC, totalTimeExectuionTasksFristPC, countCompleteFirstPC);
				
				switch (giveNumberPC(probabilityGetTaskSecondPCAfterFirstPC, probabilityGetTaskThirdPCAfterFirstPC))
				{
				case 1:
					listTimeExecutionTasksSecondPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC));
					break;
				case 2:
					listTimeExecutionTasksThirdPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskThirdPC, endIntervalTimeExecutionTaskThirdPC));
					break;
				default:
					listTimeExecutionTasksSecondPC.push_back(getRandom_uniformRealDistribution(startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC));
					break;
				}
			}
			else
			{
				currentTimeExecutionFirstPC++;
				saveSizeQueueIfExists(listTimeExecutionTasksFirstPC.size(), maxCountTaskInQueueFirstPC);
				calculateTimeInQueue(listTimeExecutionTasksFirstPC.size(), totalTimeQueueFirstPC,timeCurrentQueueFirstPC,maxTimeQueueFirstPC, countQueueFirstPC);
			}
			
		}
		if(listTimeExecutionTasksFirstPC.size() == 0)
			totalTimeWaitFirstPC++;

		checkWorkPC(listTimeExecutionTasksSecondPC, currentTimeExecutionSecondPC, totalTimeExectuionTasksSecondPC, countCompleteSecondPC, maxCountTaskInQueueSecondPC, totalTimeQueueSecondPC, totalTimeWaitSecondPC,timeCurrentQueueSecondPC,maxTimeQueueSecondPC,countCompleteSecondPC);
		checkWorkPC(listTimeExecutionTasksThirdPC, currentTimeExecutionThirdPC, totalTimeExectuionTasksThirdPC, countCompleteThirdPC, maxCountTaskInQueueThirdPC, totalTimeQueueThirdPC, totalTimeWaitThirdPC,timeCurrentQueueThridPC,maxTimeQueueThirdPC,countCompleteThirdPC);

		//logFile << " First PC : \n";
		//logFile << " totalTimeExectuionTasksFristPC = " << totalTimeExectuionTasksFristPC << " totalTimeWaitFirstPC =  " << totalTimeWaitFirstPC << " currentTimeExecutionFirstPC =" << currentTimeExecutionFirstPC << "\n";
		//logFile << " Second PC : \n";
		//logFile << " totalTimeExectuionTasksSecondPC = " << totalTimeExectuionTasksSecondPC << " totalTimeWaitSecondPC =  " << totalTimeWaitSecondPC << " currentTimeExecutionSecondPC =" << currentTimeExecutionSecondPC << "\n";
		//logFile << " Third PC : \n";
		//logFile << " totalTimeExectuionTasksThirdPC = " << totalTimeExectuionTasksThirdPC << " totalTimeWaitThirdPC =  " << totalTimeWaitThirdPC << " currentTimeExecutionThirdPC =" << currentTimeExecutionThirdPC << "\n";
		//logFile << "---------------------------------------\n";
		
		if(countTask > 0)
			currentTime+=1;
		if (countTask == 0 && countTaskInQueueAfterGetAllTaskFirstPC == 0 && countTaskInQueueAfterGetAllTaskSecondPC == 0 && countTaskInQueueAfterGetAllTaskThirdPC == 0)
		{
			countTaskInQueueAfterGetAllTaskFirstPC = listTimeExecutionTasksFirstPC.size();
			countTaskInQueueAfterGetAllTaskSecondPC = listTimeExecutionTasksSecondPC.size();
			countTaskInQueueAfterGetAllTaskThirdPC = listTimeExecutionTasksThirdPC.size();
		}

		totalTimeWork++;
	
		/*logFile << "totalTimeWork = " << totalTimeWork << "\n---------------------------------------\n";*/
		if (countTask == 0 && listTimeExecutionTasksFirstPC.size() == 0 && listTimeExecutionTasksSecondPC.size() == 0 && listTimeExecutionTasksThirdPC.size() == 0)
			break;

	}

	
	setTextForLabelEveryMachine(lbl_FirstPC, totalTimeExectuionTasksFristPC, totalTimeWaitFirstPC, totalTimeQueueFirstPC, maxCountTaskInQueueFirstPC,maxTimeQueueFirstPC,countCompleteFirstPC,countTaskInQueueAfterGetAllTaskFirstPC,countQueueFirstPC);
	setTextForLabelEveryMachine(lbl_SecondPC, totalTimeExectuionTasksSecondPC, totalTimeWaitSecondPC, totalTimeQueueSecondPC, maxCountTaskInQueueSecondPC,maxTimeQueueSecondPC,countCompleteSecondPC,countTaskInQueueAfterGetAllTaskSecondPC,countQueueSecondPC);
	setTextForLabelEveryMachine(lbl_ThirdPC, totalTimeExectuionTasksThirdPC, totalTimeWaitThirdPC, totalTimeQueueThirdPC, maxCountTaskInQueueThirdPC,maxTimeQueueThirdPC,countCompleteThirdPC,countTaskInQueueAfterGetAllTaskThirdPC,countCompleteThirdPC);

	int maxTimeQueuePC = std::max(maxTimeQueueThirdPC, std::max(maxTimeQueueFirstPC, maxTimeQueueSecondPC));
	int maxTimeWaitPC = std::max(totalTimeWaitFirstPC, std::max(totalTimeWaitSecondPC, totalTimeWaitThirdPC));

	/*lbl_total->Text = "Общее время работы : " + (totalTimeWork / 60).ToString() + " ч. " + (totalTimeWork % 60).ToString() + " мин.";
	lbl_total->Text += "\nОбщее время ожидания в очереди: " + ((totalTimeQueueFirstPC+totalTimeQueueSecondPC+totalTimeQueueThirdPC)/60).ToString() + " ч. " + ((totalTimeQueueFirstPC + totalTimeQueueSecondPC + totalTimeQueueThirdPC)  % 60).ToString() + " мин.";
	lbl_total->Text += "\nОбщее время в простое: " + ((totalTimeWaitFirstPC+totalTimeWaitSecondPC+totalTimeWaitThirdPC)/ 60).ToString() + " ч. " + ((totalTimeWaitFirstPC + totalTimeWaitSecondPC + totalTimeWaitThirdPC) % 60).ToString() + " мин.";
	lbl_total->Text += "\nВремя поступления задач: " + (((int)std::round(totalTimeReceiptsTasks)) / 60).ToString() + " ч. " + (static_cast<int>(std::round(totalTimeReceiptsTasks)) % 60).ToString() + " мин."; 
	*/

	int middleQueue =(totalTimeQueueFirstPC + totalTimeQueueSecondPC + totalTimeQueueThirdPC) / (countQueueFirstPC+ countQueueSecondPC+ countQueueThirdPC);
	int middleWait = (totalTimeWaitFirstPC + totalTimeWaitSecondPC + totalTimeWaitThirdPC)/ 3;
	
	lbl_total->Text = "Общее время работы : " + (totalTimeWork / 60).ToString() + " ч. " + (totalTimeWork % 60).ToString() + " мин.";
	lbl_total->Text += "\nСреднее время очереди: " + ((middleQueue) / 60).ToString() + " ч. " + ((middleQueue) % 60).ToString() + " мин.";
	lbl_total->Text += "\nСреднее время в простое: " + ((middleWait) / 60).ToString() + " ч. " + ((middleWait) % 60).ToString() + " мин.";
	lbl_total->Text += "\n Макс время очереди одной из ЭВМ: " + ((maxTimeQueuePC) / 60).ToString() + " ч. " + ((maxTimeQueuePC) % 60).ToString() + " мин.";
	lbl_total->Text += "\n Макс время простоя одной из ЭВМ: " + ((maxTimeWaitPC) / 60).ToString() + " ч. " + ((maxTimeWaitPC) % 60).ToString() + " мин.";

	int timeExecutionOneTaskFirstPC = (totalTimeExectuionTasksFristPC / countCompleteFirstPC);
	int timeExecutionOneTaskSecondPC = (totalTimeExectuionTasksSecondPC / countCompleteSecondPC);
	int timeExecutionOneTaskThirdPC = (totalTimeExectuionTasksThirdPC / countCompleteThirdPC);
	
	lbl_total->Text += "\n Абсолютная пропускная способность: " + (timeExecutionOneTaskFirstPC + timeExecutionOneTaskSecondPC + timeExecutionOneTaskThirdPC / 3) + "\n";

	lbl_total->Text += "\n\n Краткая сводка об эффективности:\n---\n";
	if (middleQueue > totalTimeWork * 0.4)
		lbl_total->Text += "Среднее время очереди высокое,\n рекомендуется снизить нагрузку\n с нагруженной ЭВМ и повысить на менее\n нагруженную \n(см. сводка для текущей ЭВМ)\n---\n";
	else
		lbl_total->Text += "Среднее время очереди низкое \n, ЭВМ работают хорошо \n---\n";
	
	if (middleWait > totalTimeWork * 0.5)
		lbl_total->Text += "Среднее время простоя высокое, \nЭВМ практически не работают\n---\n";
	else
		if(middleWait > totalTimeWork * 0.3)
			lbl_total->Text += "Среднее время простоя среднее, \nЭВМ частично работает\n---\n";
		else
			lbl_total->Text += "Среднее время простоя небольшое \n ЭВМ работают в стабильном режиме\n---\n";

	//logFile.close();
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}



