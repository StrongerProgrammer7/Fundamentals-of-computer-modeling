#pragma once
#ifndef MODELINGSYSTEMINFINITYQUEUEPC_H
#define MODELINGSYSTEMINFINITYQUEUEPC_H
#include "include.h"

class ModelingSystemInfinityQueuePC
{
public:
	ModelingSystemInfinityQueuePC(int numberPC,double probabilityGetTaskPC, double startIntervalTimeExecutionTaskPC,
		double endIntervalTimeExecutionTaskPC);
	~ModelingSystemInfinityQueuePC();
	
	void computitionPC(ModelingSystemInfinityQueuePC* PCs[]);
	int getTimeExectuinOneTask();
	int getMiddleTimeWorkForOneTask();
	int getMiddleTimeQueueForOneTask();
	int getMiddleTimeBusyPC();
	double probabilityGetTaskSecondPCAfterFirstPC = 0;
	double probabilityGetTaskThirdPCAfterFirstPC = 0;

	std::vector<double> listTimeExecutionTasksPC; //содержит время выполнения каждого задания ЭВМ

	const double& getProbabilityGetTaskPC() const { return probabilityGetTaskPC; }
	const double& getStartIntervalTimeExecutionTaskPC() const { return startIntervalTimeExecutionTaskPC; }
	const double& getEndIntervalTimeExecutionTaskPC() const { return endIntervalTimeExecutionTaskPC; }
	const int& getTotalTimeExectuionTasksPC() const { return totalTimeExectuionTasksPC; }
	const int& getCountCompletePC() const { return countCompletePC; }
	const int& getTotalTimeWaitPC() const { return totalTimeWaitPC; }
	const int& getCurrentTimeExecutionPC() const { return currentTimeExecutionPC; }
	const int& getTotalTimeQueuePC() const { return totalTimeQueuePC; }
	const int& getMaxTimeQueuePC() const { return maxTimeQueuePC; }
	const int& getTimeCurrentQueuePC() const { return timeCurrentQueuePC; }
	const int& getMaxCountTaskInQueuePC() const { return maxCountTaskInQueuePC; }
	const int& getCountBusyPC() const { return countBusyPC; }
	const int& getCountQueuePC() const { return countQueuePC; }
	const int& getCountTaskInQueueAfterGetAllTaskPC() const { return countTaskInQueueAfterGetAllTaskPC; }
private:
	int numberPC = 0;

	double probabilityGetTaskPC = 0;

	//Интервал выполнение ЭВМ
	double startIntervalTimeExecutionTaskPC = 0;
	double endIntervalTimeExecutionTaskPC = 0;

	
	//Общее время выполнения задач и количество ЭВМ
	int totalTimeExectuionTasksPC = 0;
	int countCompletePC = 0;

	//общее время простоя каждой ЭВМ
	int totalTimeWaitPC = 0;

	//время выполнения задачи для каждой ЭВМ
	int currentTimeExecutionPC = 0;

	//общее время очереди в каждой ЭВМ
	int totalTimeQueuePC = 0;

	//максимальное время очереди
	int maxTimeQueuePC = 0;

	//Время для каждой отдельной очереди для поиска самой долгой очереди
	int timeCurrentQueuePC = 0;

	//Максимальная очередь каждой ЭВМ
	int maxCountTaskInQueuePC = 0;

	//Количество раз занятости
	int countBusyPC = 0;
	int tempTimeWait = 0;

	//Количество очередей
	int countQueuePC = 0;

	//Количество задач оставшихся в очереди
	int countTaskInQueueAfterGetAllTaskPC = 0;

	
	void completeTask();
	void saveSizeQueueIfExists(int const& countTask);
	void calculateTimeInQueue(int const& countTask);
	

};

#endif

