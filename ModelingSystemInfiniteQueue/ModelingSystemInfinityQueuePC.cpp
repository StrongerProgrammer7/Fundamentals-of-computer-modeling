#include "ModelingSystemInfinityQueuePC.h"
#include "function.h"


ModelingSystemInfinityQueuePC::ModelingSystemInfinityQueuePC(int numberPC,double probabilityGetTaskPC, double startIntervalTimeExecutionTaskPC,
	double endIntervalTimeExecutionTaskPC)
{
	this->numberPC = numberPC;
	this->probabilityGetTaskPC = probabilityGetTaskPC;
	this->startIntervalTimeExecutionTaskPC = startIntervalTimeExecutionTaskPC;
	this->endIntervalTimeExecutionTaskPC = endIntervalTimeExecutionTaskPC;
}


ModelingSystemInfinityQueuePC::~ModelingSystemInfinityQueuePC()
{
}


int ModelingSystemInfinityQueuePC::getTimeExectuinOneTask()
{
	return countCompletePC!=0 ? totalTimeExectuionTasksPC / countCompletePC : 0;
}

int ModelingSystemInfinityQueuePC::getMiddleTimeWorkForOneTask()
{
	return countCompletePC!=0 ? std::round(totalTimeExectuionTasksPC / countCompletePC) : 0;
}

int ModelingSystemInfinityQueuePC::getMiddleTimeQueueForOneTask()
{
	return countQueuePC != 0 ? std::round(totalTimeQueuePC / countQueuePC) : 0;
}

int ModelingSystemInfinityQueuePC::getMiddleTimeBusyPC()
{
	
	return countBusyPC != 0 ? std::round(totalTimeExectuionTasksPC / countBusyPC) : 0;
}


void ModelingSystemInfinityQueuePC::completeTask()
{

	this->totalTimeExectuionTasksPC += this->currentTimeExecutionPC;
	this->countCompletePC++;

	std::reverse(this->listTimeExecutionTasksPC.begin(), this->listTimeExecutionTasksPC.end());
	this->listTimeExecutionTasksPC.pop_back();
	if (this->listTimeExecutionTasksPC.size() != 0)
		std::reverse(this->listTimeExecutionTasksPC.begin(), this->listTimeExecutionTasksPC.end());
	if (this->listTimeExecutionTasksPC.size() == 0)
		this->currentTimeExecutionPC = 0;
	else
		this->currentTimeExecutionPC = 1;
}

void ModelingSystemInfinityQueuePC::saveSizeQueueIfExists(int const& countTask)
{
	if (countTask > 1 && this->maxCountTaskInQueuePC < countTask - 1)
		this->maxCountTaskInQueuePC = countTask - 1;
}

void ModelingSystemInfinityQueuePC::calculateTimeInQueue(int const& countTask)
{
	if (countTask > 1)
	{
		this->totalTimeQueuePC++;
		this->timeCurrentQueuePC++;
	}
	else
	{
		if (this->timeCurrentQueuePC > this->maxTimeQueuePC)
			this->maxTimeQueuePC = this->timeCurrentQueuePC;
		if (this->timeCurrentQueuePC != 0)
		{
			this->timeCurrentQueuePC = 0;
			this->countQueuePC++;
		}
	}
}


void ModelingSystemInfinityQueuePC::computitionPC(ModelingSystemInfinityQueuePC* PCs[])
{
	if (this->listTimeExecutionTasksPC.size() != 0)
	{
		if (this->tempTimeWait != this->totalTimeWaitPC)
		{
			this->tempTimeWait = this->totalTimeWaitPC;
			this->countBusyPC++;
		}
		if (this->currentTimeExecutionPC >= std::round(this->listTimeExecutionTasksPC[0]))
		{
			completeTask();
			if (this->numberPC == 1)
			{
				switch (giveNumberPC(this->probabilityGetTaskSecondPCAfterFirstPC, this->probabilityGetTaskThirdPCAfterFirstPC))
				{
				case 1:
					PCs[0]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[0]->startIntervalTimeExecutionTaskPC, PCs[0]->endIntervalTimeExecutionTaskPC));
					break;
				case 2:
					PCs[1]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[1]->startIntervalTimeExecutionTaskPC, PCs[1]->endIntervalTimeExecutionTaskPC));
					break;
				default:
					PCs[0]->listTimeExecutionTasksPC.push_back(getRandom_uniformRealDistribution(PCs[0]->startIntervalTimeExecutionTaskPC, PCs[0]->endIntervalTimeExecutionTaskPC));
					break;
				}
			}
		}
		else
		{
			this->currentTimeExecutionPC++;
			saveSizeQueueIfExists(this->listTimeExecutionTasksPC.size());
			calculateTimeInQueue(listTimeExecutionTasksPC.size());

		}
	}
	if (this->listTimeExecutionTasksPC.size() == 0)
		this->totalTimeWaitPC++;

}


