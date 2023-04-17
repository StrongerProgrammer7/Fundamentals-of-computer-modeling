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

	curLabel->Text = "Время на выполнение всех задач: " + (PC.getTotalTimeExectuionTasksPC() / 60).ToString() + " ч. " + (PC.getTotalTimeExectuionTasksPC() % 60).ToString() + " мин.\n"
		+ "Количество выполненных задач: " + PC.getCountCompletePC() + "\n"
		+ "Количество задач оставшихся в очереди: " + countTaskInQueueAfterTask + "\n "
		+ "Среднее время выполнения : " + (PC.getMiddleTimeWorkForOneTask()/ 60).ToString() + " ч. " + (PC.getMiddleTimeWorkForOneTask() % 60).ToString() + " мин. \n"
		+ "Среднее время в очереди: " + (PC.getMiddleTimeQueueForOneTask() / 60).ToString() + " ч. " + (PC.getMiddleTimeQueueForOneTask() % 60).ToString() + " мин.  "/* + percentQueue.ToString() +*/ "\n"
		+ "Время простоя: " + (PC.getTotalTimeWaitPC() / 60).ToString() + " ч. " + (PC.getTotalTimeWaitPC() % 60).ToString() + " мин. " + percentWait.ToString() + "%\n ---- \n";
	//" Среднее количество задач скопившихся\n в очереди : " + maxCountTaskInQueueCurPC.ToString() + " задач \n ---- \n";

	if (PC.getTotalTimeExectuionTasksPC() == 0)
		curLabel->Text += " Эффективность ЭВМ 0. \nНе используется, рекомендуется повысить\n вероятность попадания.";
	else
	{
		if (PC.getTotalTimeExectuionTasksPC() == PC.getTotalTimeWaitPC())
			curLabel->Text += " Эффективность ЭВМ средняя. \nИспользуется лишь на половину, \nследует повысить вероятность попадания.";
		else
		{
			if (PC.getTotalTimeWaitPC() > PC.getTotalTimeExectuionTasksPC() * 0.3)
				curLabel->Text += " Эффективность ЭВМ низкая. \nСлишком долгий простой, \nследует повысить вероятность попадания.";
			else
			{
				if (PC.getMiddleTimeQueueForOneTask() > PC.getTotalTimeExectuionTasksPC() * 0.05)
				{

					if (PC.getMiddleTimeQueueForOneTask() > PC.getTotalTimeExectuionTasksPC() * 0.2)
					{
						curLabel->Text += " Эффективность ЭВМ низкая. \nЭВМ перегруженна, рекомендуется \nпонизить вероятность попадания\n или уменьшить время выполнения.";
					}
					else
						curLabel->Text += " Эффективность ЭВМ выше среднего. \nДолгое выполнение, рекомендуется \nпонизить вероятность попадания\n или уменьшить время выполнения.";
				}
				else
					curLabel->Text += " Эффективность ЭВМ в пределах нормы.";
			}

			if (countTaskInQueueAfterTask > PC.getCountCompletePC() * 0.25)
			{
				if (countTaskInQueueAfterTask > PC.getCountCompletePC() * 0.5)
					if (countTaskInQueueAfterTask >= PC.getCountCompletePC())
						curLabel->Text += " \nОчень большое количество \nзадач в очереди, следует выполнить \nувеличение скорости выполнения";
					else
						curLabel->Text += " \nКоличество \nзадач в очереди около 50%, следует \nпонизить время выполнения";
				else
					curLabel->Text += " \n Количество \nзадач в очереди (25-50)% рекомендуется \nпонизить время выполнения";
			}
			else
				curLabel->Text += "  \nКоличетсво задач в очереди менее 25%";
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
	
	//Интервал выполнение 1 ЭВМ
	double const startIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_startTimeExecutionFirst->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskFirstPC = Convert::ToDouble(tb_endTimeExecutionFirst->Text->Replace(".", ","));
	//Интервал выполнения 2 ЭВМ
	double const startIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_startTimeExecutionSecond->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskSecondPC = Convert::ToDouble(tb_endTimeExecutionSecond->Text->Replace(".", ","));
	//Интервал выполнения 3 ЭВМ
	double const startIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_startTimeExecutionThird->Text->Replace(".", ","));
	double const endIntervalTimeExecutionTaskThirdPC = Convert::ToDouble(tb_endTimeExecutionThird->Text->Replace(".", ","));

	ModelingSystemInfinityQueuePC PC_1 = ModelingSystemInfinityQueuePC(1, probabilityGetTaskFirstPC, startIntervalTimeExecutionTaskFirstPC, endIntervalTimeExecutionTaskFirstPC);
	PC_1.probabilityGetTaskSecondPCAfterFirstPC = probabilityGetTaskSecondPCAfterFirstPC;
	PC_1.probabilityGetTaskThirdPCAfterFirstPC = probabilityGetTaskThirdPCAfterFirstPC;
	ModelingSystemInfinityQueuePC PC_2 = ModelingSystemInfinityQueuePC(2, probabilityGetTaskSecondPC, startIntervalTimeExecutionTaskSecondPC, endIntervalTimeExecutionTaskSecondPC);
	ModelingSystemInfinityQueuePC PC_3 = ModelingSystemInfinityQueuePC(3, probabilityGetTaskThirdPC, startIntervalTimeExecutionTaskThirdPC, endIntervalTimeExecutionTaskThirdPC);
	
	//общее время поступления задач
	//double totalTimeReceiptsTasks = 0;
	
	//Количество задач оставшихся в очереди
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
			break;//Удалить, если надо продолжить работу после получение всех задач
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
	lbl_total->Text = "Общее время работы : " + (totalTimeWork / 60).ToString() + " ч. " + (totalTimeWork % 60).ToString() + " мин.";
	lbl_total->Text += "\nСреднее время очереди: " + ((middleQueue) / 60).ToString() + " ч. " + ((middleQueue) % 60).ToString() + " мин.";
	lbl_total->Text += "\nСреднее время в простое: " + ((middleWait) / 60).ToString() + " ч. " + ((middleWait) % 60).ToString() + " мин.";
	lbl_total->Text += "\nСреднее время занятости: " + ((int) middleBusyTime / 60).ToString() + " ч. " + ((int) middleBusyTime % 60).ToString() + " мин.";
	lbl_total->Text += "\nCреднее кол раб каналов: " + middleCountWork;
	lbl_total->Text += "\nМакс время очереди одной из ЭВМ: " + ((maxTimeQueuePC) / 60).ToString() + " ч. " + ((maxTimeQueuePC) % 60).ToString() + " мин.";
	lbl_total->Text += "\nМакс время простоя одной из ЭВМ: " + ((maxTimeWaitPC) / 60).ToString() + " ч. " + ((maxTimeWaitPC) % 60).ToString() + " мин.";

	// (lambda / Convert::ToInt32(numericUpDown1->Text))
	//
	//((PC_1.getTimeExectuinOneTask() + PC_2.getTimeExectuinOneTask() + PC_3.getTimeExectuinOneTask()) / 3)
	lbl_total->Text += "\n Абсолютная пропускная способность: " + ((PC_1.getTimeExectuinOneTask() + PC_2.getTimeExectuinOneTask() + PC_3.getTimeExectuinOneTask()) / 3) + "\n";

	lbl_total->Text += "\n Краткая сводка об эффективности:\n---\n";
	if (middleQueue > totalTimeWork * 0.3)
		lbl_total->Text += "Среднее время очереди высокое,\n рекомендуется снизить нагрузку\n с нагруженной ЭВМ и повысить на менее\n нагруженную \n(см. сводка для текущей ЭВМ)\n---\n";
	else
		lbl_total->Text += "Среднее время очереди не большое \n---\n";
	
	if (middleWait > totalTimeWork * 0.3)
		lbl_total->Text += "Среднее время простоя высокое, \nЭВМ практически не работают\n---\n";
	else
		if(middleWait > totalTimeWork * 0.1)
			lbl_total->Text += "Среднее время простоя выше среднего, \nЭВМ частично работает\n---\n";
		else
			lbl_total->Text += "Среднее время простоя низкое\n";
	
	if ((middleWait > totalTimeWork * 0.3  || middleWait > totalTimeWork * 0.1) && middleQueue > totalTimeWork * 0.3)
	{
		lbl_total->Text += " В целом ЭВМ работает плоховато\n";
	}
	else
	{
		if(middleWait > totalTimeWork * 0.3 || middleWait > totalTimeWork * 0.1)
			lbl_total->Text += " В целом ЭВМ работает хорошо,\n но время простоя достаточно велико\n";
		else
			lbl_total->Text += " В целом ЭВМ работает хорошо\n";
	}
	lbl_total->Text += "---";

	//logFile.close();
}

System::Void ModelingSystemInfiniteQueue::ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (checkInput(e))
		e->Handled = true;
}



