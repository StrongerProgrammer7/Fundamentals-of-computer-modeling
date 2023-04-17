#include "ModelingInfinityQeueForm.h"
#include "ModelingSystemInfinityQueuePC.h"
#include "function.h"


using namespace System;
using namespace System::Windows::Forms;

int totalTimeWork = 0;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	std::srand(time(NULL));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ModelingSystemInfiniteQueue::ModelingInfinityQeueForm form;
	Application::Run(% form);
}



System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::setTextForLabelEveryMachine(System::Windows::Forms::Label^ curLabel, ModelingSystemInfinityQueuePC& PC,int countTaskInQueueAfterTask)

{

	double percentMiddleTimeExectuion = 1;

	if (PC.getTotalTimeExectuionTasksPC()!= 0)
		percentMiddleTimeExectuion = (int)(double)(((double)PC.getTotalTimeExectuionTasksPC() / (double)totalTimeWork) * 100.0);

	double percentWait = (int)(double)(((double)PC.getTotalTimeWaitPC() / (double)totalTimeWork) * 100.0);
	//double percentQueue = (int)(double)(((double)totalTimeQueueCurPC / (double)totalTimeExectuionTasksCurPC) * 100.0);

	curLabel->Text = "����� �� ���������� ���� �����: " + (PC.getTotalTimeExectuionTasksPC() / 60).ToString() + " �. " + (PC.getTotalTimeExectuionTasksPC() % 60).ToString() + " ���.\n"
		+ "���������� ����������� �����: " + PC.getCountCompletePC() + "\n"
		+ "���������� ����� ���������� � �������: " + countTaskInQueueAfterTask + "\n "
		+ "������� ����� ���������� : " + (PC.getMiddleTimeWorkForOneTask()/ 60).ToString() + " �. " + (PC.getMiddleTimeWorkForOneTask() % 60).ToString() + " ���. \n"
		+ "������� ����� � �������: " + (PC.getMiddleTimeQueueForOneTask() / 60).ToString() + " �. " + (PC.getMiddleTimeQueueForOneTask() % 60).ToString() + " ���.  "/* + percentQueue.ToString() +*/ "\n"
		+ "����� �������: " + (PC.getTotalTimeWaitPC() / 60).ToString() + " �. " + (PC.getTotalTimeWaitPC() % 60).ToString() + " ���. " + percentWait.ToString() + "%\n ---- \n";
	//" ������� ���������� ����� �����������\n � ������� : " + maxCountTaskInQueueCurPC.ToString() + " ����� \n ---- \n";

	if (PC.getTotalTimeExectuionTasksPC() == 0)
		curLabel->Text += " ������������� ��� 0. \n�� ������������, ������������� ��������\n ����������� ���������.";
	else
	{
		if (PC.getTotalTimeExectuionTasksPC() == PC.getTotalTimeWaitPC())
			curLabel->Text += " ������������� ��� �������. \n������������ ���� �� ��������, \n������� �������� ����������� ���������.";
		else
		{
			if (PC.getTotalTimeWaitPC() > PC.getTotalTimeExectuionTasksPC() * 0.3)
				curLabel->Text += " ������������� ��� ������. \n������� ������ �������, \n������� �������� ����������� ���������.";
			else
			{
				if (PC.getMiddleTimeQueueForOneTask() > PC.getTotalTimeExectuionTasksPC() * 0.05)
				{

					if (PC.getMiddleTimeQueueForOneTask() > PC.getTotalTimeExectuionTasksPC() * 0.2)
					{
						curLabel->Text += " ������������� ��� ������. \n��� ������������, ������������� \n�������� ����������� ���������\n ��� ��������� ����� ����������.";
					}
					else
						curLabel->Text += " ������������� ��� ���� ��������. \n������ ����������, ������������� \n�������� ����������� ���������\n ��� ��������� ����� ����������.";
				}
				else
					curLabel->Text += " ������������� ��� � �������� �����.";
			}

			if (countTaskInQueueAfterTask > PC.getCountCompletePC() * 0.25)
			{
				if (countTaskInQueueAfterTask > PC.getCountCompletePC() * 0.5)
					if (countTaskInQueueAfterTask >= PC.getCountCompletePC())
						curLabel->Text += " \n����� ������� ���������� \n����� � �������, ������� ��������� \n���������� �������� ����������";
					else
						curLabel->Text += " \n���������� \n����� � ������� ����� 50%, ������� \n�������� ����� ����������";
				else
					curLabel->Text += " \n ���������� \n����� � ������� (25-50)% ������������� \n�������� ����� ����������";
			}
			else
				curLabel->Text += "  \n���������� ����� � ������� ����� 25%";
		}
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

void fillList(int& countTask,ModelingSystemInfinityQueuePC* PCs[])
{
	countTask--;

	switch (giveNumberPC(PCs[2]->getProbabilityGetTaskPC(), PCs[0]->getProbabilityGetTaskPC()))
	{
	case 1:
		PCs[2]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[2]->getStartIntervalTimeExecutionTaskPC(), PCs[2]->getEndIntervalTimeExecutionTaskPC()));
		break;
	case 2:
		PCs[0]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[0]->getStartIntervalTimeExecutionTaskPC(), PCs[0]->getEndIntervalTimeExecutionTaskPC()));
		break;
	case 3:
		PCs[1]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[1]->getStartIntervalTimeExecutionTaskPC(), PCs[1]->getEndIntervalTimeExecutionTaskPC()));
		break;
	default:
		PCs[2]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[2]->getStartIntervalTimeExecutionTaskPC(), PCs[2]->getEndIntervalTimeExecutionTaskPC()));
		break;
	}

	
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Btn_exectuion_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*std::ofstream logFile("log.txt");*/

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

	ModelingSystemInfinityQueuePC PC_1 = ModelingSystemInfinityQueuePC(1, probabilityGetTaskFirstPC, startIntervalTimeExecutionTaskFirstPC, endIntervalTimeExecutionTaskFirstPC);
	PC_1.probabilityGetTaskSecondPCAfterFirstPC = probabilityGetTaskSecondPCAfterFirstPC;
	PC_1.probabilityGetTaskThirdPCAfterFirstPC = probabilityGetTaskThirdPCAfterFirstPC;
	ModelingSystemInfinityQueuePC PC_2 = ModelingSystemInfinityQueuePC(2, probabilityGetTaskSecondPC, startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC);
	ModelingSystemInfinityQueuePC PC_3 = ModelingSystemInfinityQueuePC(3, probabilityGetTaskThirdPC, startIntervalTimeExecutionTaskThirdPC, endIntervalTimeExecutionTaskThirdPC);
	
	//����� ����� ����������� �����
	//double totalTimeReceiptsTasks = 0;
	
	//���������� ����� ���������� � �������
	int countTaskInQueueAfterGetAllTaskFirstPC = 0;
	int countTaskInQueueAfterGetAllTaskSecondPC = 0;
	int countTaskInQueueAfterGetAllTaskThirdPC = 0;

	double timeBeforeNextTask = getRandom_uniformRealDistribution(startInterrvalGetTask, endInteervalGetTask);
	double currentTime = 0;
	totalTimeWork = 0;

	int middleCountPCWorking = 0;
	ModelingSystemInfinityQueuePC* PCs[3] = { &PC_2, &PC_3, &PC_1 };
	//double lambda = 0;
	while (true)
	{
		if (currentTime >= timeBeforeNextTask && countTask > 0)
		{
			fillList(countTask, PCs);
			//totalTimeReceiptsTasks += timeBeforeNextTask;
			timeBeforeNextTask = std::round(getRandom_uniformRealDistribution(startInterrvalGetTask, endInteervalGetTask));
			currentTime = 0;
			//lambda += timeBeforeNextTask;
		}
		PC_1.computitionPC(PCs);
		PC_2.computitionPC(NULL);
		PC_3.computitionPC(NULL);
		
	
		//logFile << " First PC : \n";
		//logFile << " totalTimeExectuionTasksFristPC = " << totalTimeExectuionTasksFristPC << " totalTimeWaitFirstPC =  " << totalTimeWaitFirstPC << " currentTimeExecutionFirstPC =" << currentTimeExecutionFirstPC << "\n";
		//logFile << " Second PC : \n";
		//logFile << " totalTimeExectuionTasksSecondPC = " << totalTimeExectuionTasksSecondPC << " totalTimeWaitSecondPC =  " << totalTimeWaitSecondPC << " currentTimeExecutionSecondPC =" << currentTimeExecutionSecondPC << "\n";
		//logFile << " Third PC : \n";
		//logFile << " totalTimeExectuionTasksThirdPC = " << totalTimeExectuionTasksThirdPC << " totalTimeWaitThirdPC =  " << totalTimeWaitThirdPC << " currentTimeExecutionThirdPC =" << currentTimeExecutionThirdPC << "\n";
		//logFile << "---------------------------------------\n";
		
		if(countTask > 0)
			currentTime++;
		if (countTask == 0 && countTaskInQueueAfterGetAllTaskFirstPC == 0 && countTaskInQueueAfterGetAllTaskSecondPC == 0 && countTaskInQueueAfterGetAllTaskThirdPC == 0)
		{
			countTaskInQueueAfterGetAllTaskFirstPC = PC_1.listTimeExecutionTasksPC.size();
			countTaskInQueueAfterGetAllTaskSecondPC = PC_2.listTimeExecutionTasksPC.size();
			countTaskInQueueAfterGetAllTaskThirdPC = PC_3.listTimeExecutionTasksPC.size();
			break;//�������, ���� ���� ���������� ������ ����� ��������� ���� �����
		}

		totalTimeWork++;
	
		/*logFile << "totalTimeWork = " << totalTimeWork << "\n---------------------------------------\n";*/
		if (countTask == 0 && PC_1.listTimeExecutionTasksPC.size() == 0 && PC_2.listTimeExecutionTasksPC.size() == 0 && PC_3.listTimeExecutionTasksPC.size() == 0)
			break;

	}


	setTextForLabelEveryMachine(lbl_FirstPC, PC_1, countTaskInQueueAfterGetAllTaskFirstPC);
	setTextForLabelEveryMachine(lbl_SecondPC, PC_2, countTaskInQueueAfterGetAllTaskSecondPC);
	setTextForLabelEveryMachine(lbl_ThirdPC, PC_3, countTaskInQueueAfterGetAllTaskThirdPC);

	int maxTimeQueuePC = std::max(PC_1.getMaxTimeQueuePC(), std::max(PC_2.getMaxTimeQueuePC(), PC_3.getMaxTimeQueuePC()));
	int maxTimeWaitPC = std::max(PC_1.getTotalTimeWaitPC(), std::max(PC_2.getTotalTimeWaitPC(), PC_3.getTotalTimeWaitPC()));

	int middleQueue = 0;
	if((PC_1.getCountQueuePC() + PC_2.getCountQueuePC() + PC_3.getCountQueuePC()) != 0)
		middleQueue =(PC_1.getTotalTimeWaitPC() + PC_3.getTotalTimeWaitPC() + PC_3.getTotalTimeWaitPC()) / (PC_1.getCountQueuePC()+ PC_2.getCountQueuePC() + PC_3.getCountQueuePC());

	int middleWait = (PC_1.getTotalTimeWaitPC() + PC_3.getTotalTimeWaitPC() + PC_3.getTotalTimeWaitPC())/ 3;
	
	double middleBusyTime = (PC_1.getTotalTimeExectuionTasksPC() + PC_2.getTotalTimeExectuionTasksPC() + PC_3.getTotalTimeExectuionTasksPC()) / 3.0;
	double middleCountWork = (double)(PC_1.getTotalTimeExectuionTasksPC() + PC_2.getTotalTimeExectuionTasksPC() + PC_3.getTotalTimeExectuionTasksPC()) / (double)totalTimeWork;
	middleCountWork = int((middleCountWork) * 10 + 0.5) / 10.0;
	lbl_total->Text = "����� ����� ������ : " + (totalTimeWork / 60).ToString() + " �. " + (totalTimeWork % 60).ToString() + " ���.";
	lbl_total->Text += "\n������� ����� �������: " + ((middleQueue) / 60).ToString() + " �. " + ((middleQueue) % 60).ToString() + " ���.";
	lbl_total->Text += "\n������� ����� � �������: " + ((middleWait) / 60).ToString() + " �. " + ((middleWait) % 60).ToString() + " ���.";
	lbl_total->Text += "\n������� ����� ���������: " + ((int) middleBusyTime / 60).ToString() + " �. " + ((int) middleBusyTime % 60).ToString() + " ���.";
	lbl_total->Text += "\nC������ ��� ��� �������: " + middleCountWork;
	lbl_total->Text += "\n���� ����� ������� ����� �� ���: " + ((maxTimeQueuePC) / 60).ToString() + " �. " + ((maxTimeQueuePC) % 60).ToString() + " ���.";
	lbl_total->Text += "\n���� ����� ������� ����� �� ���: " + ((maxTimeWaitPC) / 60).ToString() + " �. " + ((maxTimeWaitPC) % 60).ToString() + " ���.";

	// (lambda / Convert::ToInt32(numericUpDown1->Text))
	//
	//((PC_1.getTimeExectuinOneTask() + PC_2.getTimeExectuinOneTask() + PC_3.getTimeExectuinOneTask()) / 3)
	lbl_total->Text += "\n ���������� ���������� �����������: " + ((PC_1.getTimeExectuinOneTask() + PC_2.getTimeExectuinOneTask() + PC_3.getTimeExectuinOneTask()) / 3) + "\n";

	lbl_total->Text += "\n ������� ������ �� �������������:\n---\n";
	if (middleQueue > totalTimeWork * 0.3)
		lbl_total->Text += "������� ����� ������� �������,\n ������������� ������� ��������\n � ����������� ��� � �������� �� �����\n ����������� \n(��. ������ ��� ������� ���)\n---\n";
	else
		lbl_total->Text += "������� ����� ������� �� ������� \n---\n";
	
	if (middleWait > totalTimeWork * 0.3)
		lbl_total->Text += "������� ����� ������� �������, \n��� ����������� �� ��������\n---\n";
	else
		if(middleWait > totalTimeWork * 0.1)
			lbl_total->Text += "������� ����� ������� ���� ��������, \n��� �������� ��������\n---\n";
		else
			lbl_total->Text += "������� ����� ������� ������\n";
	
	if ((middleWait > totalTimeWork * 0.3  || middleWait > totalTimeWork * 0.1) && middleQueue > totalTimeWork * 0.3)
	{
		lbl_total->Text += " � ����� ��� �������� ���������\n";
	}
	else
	{
		if(middleWait > totalTimeWork * 0.3 || middleWait > totalTimeWork * 0.1)
			lbl_total->Text += " � ����� ��� �������� ������,\n �� ����� ������� ���������� ������\n";
		else
			lbl_total->Text += " � ����� ��� �������� ������\n";
	}
	lbl_total->Text += "---";

	//logFile.close();
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}



