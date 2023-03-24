#include "ModelingInfinityQeueForm.h"

#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

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


double getExponentialRandom(double const& lambda)
{
	double u = rand() / (RAND_MAX + 1.0);
	double res = int((-log(1 - u) / lambda) * 100 + 0.5) / 100.0;
	return res;
}

double getNormalRandom(double const& start, double const& end)
{
	std::mt19937 gen((std::random_device())());
	std::normal_distribution<double> nd(start, end);
	double res = std::abs(int((nd(gen)) * 100 + 0.5) / 100.0);
	return res;
}

double getRandomUniform(double const& start, double const& end)
{
	return ((double)rand()) / RAND_MAX;
}



int giveNumberPC(double const& prob1, double const& prob2)
{
	double random = getNormalRandom(0.0, 1.0);
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

void completeTask(std::vector<double>& listTaskCurPC,int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask)
{
	totalTimeExecutionPC += timeExectuionTaskCurPC;//PC[0];
	countCompleteTask++;

	std::reverse(listTaskCurPC.begin(), listTaskCurPC.end());
	listTaskCurPC.pop_back();
	if (listTaskCurPC.size() != 0)
		std::reverse(listTaskCurPC.begin(), listTaskCurPC.end());
	timeExectuionTaskCurPC = 0;
}

void saveQueueIfExists(int const& countTask, int& maxQueue)
{
	if (countTask > 1 && maxQueue < countTask - 1)
		maxQueue = countTask - 1;
}

void calculateTimeInQueue(int const& countTask, int& timeInQueue)
{
	if (countTask > 1)
		timeInQueue++;
}

void checkWorkPC(std::vector<double>& listTaskCurPC, int& timeExectuionTaskCurPC, int& totalTimeExecutionPC, int& countCompleteTask, int& maxQueue, int& timeInQueue, int& timeWait)
{
	if (listTaskCurPC.size() != 0)
	{
		if (timeExectuionTaskCurPC >= listTaskCurPC[0])
			completeTask(listTaskCurPC, timeExectuionTaskCurPC, totalTimeExecutionPC, countCompleteTask);
		else
		{
			timeExectuionTaskCurPC++;
			saveQueueIfExists(listTaskCurPC.size(), maxQueue);
			calculateTimeInQueue(listTaskCurPC.size(), timeInQueue);

		}

	}
	else
		timeWait++;
}


System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Btn_exectuion_Click(System::Object^ sender, System::EventArgs^ e)
{
	int countTask = Convert::ToInt32(numericUpDown1->Text);
	double const startInteervalGetTask = Convert::ToDouble(tb_startInteervalGetTask->Text->Replace(".", ","));
	double const endInteervalGetTask = Convert::ToDouble(tb_endInteervalGetTask->Text->Replace(".", ","));

	double const probabilityGetTaskFirst = Convert::ToDouble(tb_probabilityGetTaskFirst->Text->Replace(".", ","));
	double const probabilityGetTaskSecond = Convert::ToDouble(tb_probabilityGetTaskSecond->Text->Replace(".", ","));
	double const probabilityGetTaskThird = std::abs( 1 - (probabilityGetTaskFirst + probabilityGetTaskSecond));

	double const probabilityGetTaskSecondAfterFirst = Convert::ToDouble(tb_probabilityGetTaskSecondAfterFirst->Text->Replace(".", ","));
	double const probabilityGetTaskThirdAfterFirst = Convert::ToDouble(tb_probabilityGetTaskThirdAfterFirst->Text->Replace(".", ","));

	//�������� ���������� 1 ���
	double const startTimeExecutionFirst = Convert::ToDouble(tb_startTimeExecutionFirst->Text->Replace(".", ","));
	double const endTimeExecutionFirst = Convert::ToDouble(tb_endTimeExecutionFirst->Text->Replace(".", ","));
	//�������� ���������� 2 ���
	double const startTimeExecutionSecond = Convert::ToDouble(tb_startTimeExecutionSecond->Text->Replace(".", ","));
	double const endTimeExecutionSecond = Convert::ToDouble(tb_endTimeExecutionSecond->Text->Replace(".", ","));
	//�������� ���������� 3 ���
	double const startTimeExecutionThird = Convert::ToDouble(tb_startTimeExecutionThird->Text->Replace(".", ","));
	double const endTimeExecutionThird = Convert::ToDouble(tb_endTimeExecutionThird->Text->Replace(".", ","));

	std::vector<double> timeFirstTask; //�������� ����� ���������� ������� ������� 1 ���
	std::vector<double> timeSecondTask; // �������� ����� ���������� ������� ������� 2 ���
	std::vector<double> timeThirdTask; // �������� ����� ���������� ������� ������� 3 ���
	
	//����� ����� ���������� � ���������� 1 ���
	int totalTimeExectuionFrist = 0;
	int countExectionFirst = 0;
	//����� ����� ���������� � ���������� 2 ���
	int totalTimeExecetuinSecond = 0;
	int countExectionSecond = 0;
	//����� ����� ���������� � ���������� 3 ���
	int totalTimeExectuionThird = 0;
	int countExectionThird = 0;

	//����� ����� ������� ������ ���
	int timeWaitFirst = 0;
	int timeWaitSecond = 0;
	int timeWaitThird = 0;

	//����� ����� ���������� ��� ������ ���
	int timeFirst = 0;
	int timeSecond = 0;
	int timeThird = 0;

	//����� ����� ������� � ������ ���
	int timeQueueFirst = 0;
	int timeQueueSecond = 0;
	int timeQueueThird = 0;

	//������������ ������� ������ ���
	int maxCountTaskQueueFirst = 0;
	int maxCountTaskQueueSecond = 0;
	int maxCountTaskQueueThird = 0;
	
	
	double timeBeforeNextTask = getNormalRandom(startInteervalGetTask, endInteervalGetTask);
	double currentTime = timeBeforeNextTask;
	double totalTimeWork = 0;
	do
	{
		if (currentTime >= timeBeforeNextTask)
		{
			if(countTask > 0)
				countTask--;

			switch (giveNumberPC(probabilityGetTaskFirst, probabilityGetTaskSecond))
			{
			case 1:
				timeFirstTask.push_back(getNormalRandom(startTimeExecutionFirst, endTimeExecutionFirst));
				break;
			case 2:
				timeSecondTask.push_back(getNormalRandom(startTimeExecutionSecond, endTimeExecutionSecond));
				break;
			case 3:
				timeThirdTask.push_back(getNormalRandom(startTimeExecutionThird, endTimeExecutionThird));
				break;
			default:
				break;
			}

			timeBeforeNextTask = getNormalRandom(startInteervalGetTask, endInteervalGetTask);
			currentTime = 1;
		}
		
		//if (timeFirstTask.size() != 0)
		//{

		//	if (timeFirst >= timeFirstTask[0])
		//	{
		//		totalTimeExectuionFrist += timeFirst;//timeFirstTask[0];
		//		countExectionFirst++;

		//		std::reverse(timeFirstTask.begin(), timeFirstTask.end());
		//		timeFirstTask.pop_back();
		//		if (timeFirstTask.size() != 0)
		//			std::reverse(timeFirstTask.begin(), timeFirstTask.end());
		//		timeFirst = 0;
		//		switch (giveNumberPC(probabilityGetTaskSecondAfterFirst, probabilityGetTaskThirdAfterFirst))
		//		{
		//		case 1:
		//			timeSecondTask.push_back(getNormalRandom(startTimeExecutionSecond, endTimeExecutionSecond));
		//			break;
		//		case 2:
		//			timeThirdTask.push_back(getNormalRandom(startTimeExecutionThird, endTimeExecutionThird));
		//			break;
		//		default:
		//			break;
		//		}
		//	}
		//	else
		//	{
		//		timeFirst++;
		//		if (timeFirstTask.size() > 1 && maxCountTaskQueueFirst < timeFirstTask.size() - 1)
		//			maxCountTaskQueueFirst = timeFirstTask.size() - 1;
		//		if (timeFirstTask.size() > 1)
		//		{
		//			timeQueueFirst++;
		//		}
		//	}
		//	
		//}
		//else
		//	timeWaitFirst++;

		checkWorkPC(timeFirstTask, timeFirst, totalTimeExectuionFrist, countExectionFirst, maxCountTaskQueueFirst, timeQueueFirst, timeWaitFirst);

		checkWorkPC(timeSecondTask, timeSecond, totalTimeExecetuinSecond, countExectionSecond, maxCountTaskQueueSecond, timeQueueSecond, timeWaitSecond);
		checkWorkPC(timeThirdTask, timeThird, totalTimeExectuionThird, countExectionThird, maxCountTaskQueueThird, timeQueueThird, timeWaitThird);
		

		currentTime++;
		totalTimeWork += currentTime;

	}while (countTask > 0);

	/*for (int i = 1; i <= countTask; i++)
	{
		double timeGetTask = getNormalRandom(startInteervalGetTask, endInteervalGetTask);
		if (timeBeforeNextTask > 0)
			timeBeforeNextTask = 0;

		double timeExecutinTask = 0;
		switch (giveNumberPC(probabilityGetTaskFirst, probabilityGetTaskSecond))
		{
		case 1:
			timeBeforeNextTask += getNormalRandom(startInteervalGetTask, endInteervalGetTask);
			timeExecutinTask = getNormalRandom(startTimeExecutionFirst, endTimeExecutionFirst);
			totatTimeExecution += timeExecutinTask;
			totalTimeExectuionFrist += timeExecutinTask;
			timeBeforeNextTask -= timeExecutinTask;
			if (giveNumberPCAfterFirst(probabilityGetTaskSecondAfterFirst, probabilityGetTaskThirdAfterFirst) == 2)
				goto second;
			else
				goto third;
			break;
		case 2:
			timeBeforeNextTask += getNormalRandom(startInteervalGetTask, endInteervalGetTask);
			second:
			timeExecutinTask = getNormalRandom(startTimeExecutionSecond, endTimeExecutionSecond);
			totatTimeExecution += timeExecutinTask;
			totalTimeExecetuinSecond += timeExecutinTask;
			timeBeforeNextTask -= timeExecutinTask;
			break;
		case 3:
			timeBeforeNextTask += getNormalRandom(startInteervalGetTask, endInteervalGetTask);
			third:
			timeExecutinTask = getNormalRandom(startTimeExecutionThird, endTimeExecutionThird);
			totatTimeExecution += timeExecutinTask;
			totalTimeExectuionThird += timeExecutinTask;
			timeBeforeNextTask -= timeExecutinTask;
			break;
		default:
			break;
		}
	}
	int countTasklInQueue = 0;
	while (timeBeforeNextTask < 0)
	{
		timeBeforeNextTask += getNormalRandom(startInteervalGetTask, endInteervalGetTask);
		countTasklInQueue++;
	}*/
	lbl_answer->Text = "����� ������ : " + (static_cast<int>(totalTimeWork/60)).ToString() + " �. " + (static_cast<int>((int)totalTimeWork % 60)).ToString() + " ���.";
	lbl_answer1->Text = "����� ������ 1: " + (totalTimeExectuionFrist/60).ToString() + " �. " + (totalTimeExectuionFrist%  60).ToString() + " ���. ���� �������: " + maxCountTaskQueueFirst.ToString();
	lbl_answer2->Text = "����� ������ 2: " + (totalTimeExecetuinSecond/60).ToString() + " �. " + (totalTimeExecetuinSecond % 60).ToString() + " ���.���� �������: " + maxCountTaskQueueSecond.ToString();
	lbl_answer3->Text = "����� ������ 3: " + (totalTimeExectuionThird/60).ToString() + " �. " + (totalTimeExectuionThird% 60).ToString() + " ���. ���� �������: " + maxCountTaskQueueThird.ToString();
	lbl_answer4->Text = "����� � �������: " + ((timeQueueFirst+timeQueueSecond+timeQueueThird)/60).ToString() + " �. " + ((timeQueueFirst + timeQueueSecond + timeQueueThird)  % 60).ToString() + " ���.";
	lbl_answer5->Text = "����� � �������: " + ((timeWaitFirst+timeWaitSecond+timeWaitThird)/ 60).ToString() + " �. " + ((timeWaitFirst + timeWaitSecond + timeWaitThird) % 60).ToString() + " ���.";
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}

