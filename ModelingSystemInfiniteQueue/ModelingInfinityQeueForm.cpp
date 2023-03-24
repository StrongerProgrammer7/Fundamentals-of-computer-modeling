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

std::ofstream logFile("log.txt");

[STAThreadAttribute]
void main(array<String^>^ args)
{
	std::srand(time(NULL));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ModelingSystemInfiniteQueue::ModelingInfinityQeueForm form;
	Application::Run(% form);

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
	
	totalTimeExecutionPC += timeExectuionTaskCurPC;// std::round(listTaskCurPC[0]);//timeExectuionTaskCurPC
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

void calculateTimeInQueue(int const& countTask, int& timeInQueue)
{
	if (countTask > 1)
		timeInQueue++;
}

void checkWorkPC(std::vector<double> & listTaskCurPC, int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask, int& maxQueue, int& timeInQueue, int& timeWait)
{
	if (listTaskCurPC.size() != 0)
	{
		if (timeExectuionTaskCurPC >= std::round(listTaskCurPC[0]))
			completeTask(listTaskCurPC, timeExectuionTaskCurPC, totalTimeExecutionPC, countCompleteTask);
		else
		{
			timeExectuionTaskCurPC++;
			saveSizeQueueIfExists(listTaskCurPC.size(), maxQueue);
			calculateTimeInQueue(listTaskCurPC.size(), timeInQueue);

		}
		//totalTimeExecutionPC++;
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
	int countTask = Convert::ToInt32(numericUpDown1->Text);
	double const startInterrvalGetTask = Convert::ToDouble(tb_startInteervalGetTask->Text->Replace(".", ","));
	double const endInteervalGetTask = Convert::ToDouble(tb_endInteervalGetTask->Text->Replace(".", ","));

	double const probabilityGetTaskFirstPC = Convert::ToDouble(tb_probabilityGetTaskFirst->Text->Replace(".", ","));
	double const probabilityGetTaskSecondPC = Convert::ToDouble(tb_probabilityGetTaskSecond->Text->Replace(".", ","));
	double const probabilityGetTaskThirdPC = std::abs( 1 - (probabilityGetTaskFirstPC + probabilityGetTaskSecondPC));

	double const probabilityGetTaskSecondPCAfterFirstPC = Convert::ToDouble(tb_probabilityGetTaskSecondAfterFirst->Text->Replace(".", ","));
	double const probabilityGetTaskThirdPCAfterFirstPC = Convert::ToDouble(tb_probabilityGetTaskThirdAfterFirst->Text->Replace(".", ","));
	
	//�������� ���������� 1 ���
	double const startIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_startTimeExecutionFirst->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_endTimeExecutionFirst->Text->Replace(".", ","));
	//�������� ���������� 2 ���
	double const startIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_startTimeExecutionSecond->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_endTimeExecutionSecond->Text->Replace(".", ","));
	//�������� ���������� 3 ���
	double const startIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_startTimeExecutionThird->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_endTimeExecutionThird->Text->Replace(".", ","));

	std::vector<double> listTimeExecutionTasksFirstPC; //�������� ����� ���������� ������� ������� 1 ���
	std::vector<double> listTimeExecutionTasksSecondPC; // �������� ����� ���������� ������� ������� 2 ���
	std::vector<double> listTimeExecutionTasksThirdPC; // �������� ����� ���������� ������� ������� 3 ���
	
	//����� ����� ���������� � ���������� 1 ���
	int totalTimeExectuionTasksFristPC = 0;
	int countCompleteTaskFirstPC = 0;
	//����� ����� ���������� � ���������� 2 ���
	int totalTimeExectuionTasksSecondPC = 0;
	int countCompleteSecondPC = 0;
	//����� ����� ���������� � ���������� 3 ���
	int totalTimeExectuionTasksThirdPC = 0;
	int countCompleteThirdPC = 0;

	//����� ����� ������� ������ ���
	int totalTimeWaitFirstPC = 0;
	int totalTimeWaitSecondPC = 0;
	int totalTimeWaitThirdPC = 0;

	//����� ���������� ������ ��� ������ ���
	int currentTimeExecutionFirstPC = 0;
	int currentTimeExecutionSecondPC = 0;
	int currentTimeExecutionThirdPC = 0;

	//����� ����� ������� � ������ ���
	int totalTimeQueueFirstPC = 0;
	int totalTimeQueueSecondPC = 0;
	int totalTimeQueueThirdPC = 0;

	//������������ ����� �������
	int maxTimeQueueFirstPC = 0;
	int maxTimeQueueSecondPC = 0;
	int maxTimeQueueThirdPC = 0;

	//������������ ������� ������ ���
	int maxCountTaskInQueueFirstPC = 0;
	int maxCountTaskInQueueSecondPC = 0;
	int maxCountTaskInQueueThirdPC = 0;
	
	//����� ����� ����������� �����
	double totalTimeReceiptsTasks = 0;
	
	double timeBeforeNextTask = getRandom_uniformRealDistribution(startInterrvalGetTask, endInteervalGetTask);
	double currentTime = 0;//timeBeforeNextTask;
	int totalTimeWork = 0;//std::round(timeBeforeNextTask);
	//label4->Text = "1 task get : " + totalTimeWork.ToString();
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
				calculateTimeInQueue(listTimeExecutionTasksFirstPC.size(), totalTimeQueueFirstPC);
			}
			
		}
		if(listTimeExecutionTasksFirstPC.size() == 0)
			totalTimeWaitFirstPC++;

		checkWorkPC(listTimeExecutionTasksSecondPC, currentTimeExecutionSecondPC, totalTimeExectuionTasksSecondPC, countCompleteSecondPC, maxCountTaskInQueueSecondPC, totalTimeQueueSecondPC, totalTimeWaitSecondPC);
		checkWorkPC(listTimeExecutionTasksThirdPC, currentTimeExecutionThirdPC, totalTimeExectuionTasksThirdPC, countCompleteThirdPC, maxCountTaskInQueueThirdPC, totalTimeQueueThirdPC, totalTimeWaitThirdPC);

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

	/*correctTime(totalTimeWork, totalTimeExectuionTasksFristPC);
	correctTime(totalTimeWork, totalTimeExectuionTasksSecondPC);
	correctTime(totalTimeWork, totalTimeExectuionTasksThirdPC);
*/
	lbl_answer->Text = "����� ����� ������ : " + (totalTimeWork /60).ToString() + " �. " + (totalTimeWork % 60).ToString() + " ���.";

	lbl_answer1->Text = "��� 1: ����� ����� �� ���������� ���� �����: " + (totalTimeExectuionTasksFristPC/60).ToString() + " �. " + (totalTimeExectuionTasksFristPC%  60).ToString() + " ���."
		+ "����� �������: " + (totalTimeWaitFirstPC / 60).ToString() + " �. " + (totalTimeWaitFirstPC % 60).ToString() + " ���. " 
		+"��� ����� �������� � �������: " + (totalTimeQueueFirstPC / 60).ToString() + " �. " + (totalTimeQueueFirstPC % 60).ToString() + " ���. " +
		" ���� �������: " + maxCountTaskInQueueFirstPC.ToString();

	lbl_answer2->Text = "��� 2: ����� ����� �� ���������� ���� �����: " + (totalTimeExectuionTasksSecondPC/60).ToString() + " �. " + (totalTimeExectuionTasksSecondPC % 60).ToString() + " ���." + 
		"����� �������: " + (totalTimeWaitSecondPC / 60).ToString() + " �. " + (totalTimeWaitSecondPC % 60).ToString() + " ���"
		+" ��� ����� �������� � �������: " + (totalTimeQueueSecondPC / 60).ToString() + " �. " + (totalTimeQueueSecondPC % 60).ToString() + " ���. " +
		" ���� �������: " + maxCountTaskInQueueSecondPC.ToString();

	lbl_answer3->Text = "��� 3: ����� ����� �� ���������� ���� �����: " + (totalTimeExectuionTasksThirdPC/60).ToString() + " �. " + (totalTimeExectuionTasksThirdPC% 60).ToString() + " ���. " + 
		"����� �������: " + (totalTimeWaitThirdPC / 60).ToString() + " �. " + (totalTimeWaitThirdPC % 60).ToString() + " ���"
		+" ��� ����� �������� � �������: " + (totalTimeQueueThirdPC / 60).ToString() + " �. " + (totalTimeQueueThirdPC % 60).ToString() + " ���. " +
		" ���� �������: " + maxCountTaskInQueueThirdPC.ToString();

	lbl_answer4->Text = "��� ����� � �������: " + ((totalTimeQueueFirstPC+totalTimeQueueSecondPC+totalTimeQueueThirdPC)/60).ToString() + " �. " + ((totalTimeQueueFirstPC + totalTimeQueueSecondPC + totalTimeQueueThirdPC)  % 60).ToString() + " ���.";
	lbl_answer5->Text = "��� ����� � �������: " + ((totalTimeWaitFirstPC+totalTimeWaitSecondPC+totalTimeWaitThirdPC)/ 60).ToString() + " �. " + ((totalTimeWaitFirstPC + totalTimeWaitSecondPC + totalTimeWaitThirdPC) % 60).ToString() + " ���.";
	lbl_answer6->Text = "��� ����� ����������� �����: " + (((int)std::round(totalTimeReceiptsTasks)) / 60).ToString() + " �. " + (static_cast<int>(std::round(totalTimeReceiptsTasks)) % 60).ToString() + " ���.";
	logFile.close();
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

