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

	std::vector<double> listTimeExecutionTasksPC; //�������� ����� ���������� ������� ������� ���

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

	//�������� ���������� ���
	double startIntervalTimeExecutionTaskPC = 0;
	double endIntervalTimeExecutionTaskPC = 0;

	
	//����� ����� ���������� ����� � ���������� ���
	int totalTimeExectuionTasksPC = 0;
	int countCompletePC = 0;

	//����� ����� ������� ������ ���
	int totalTimeWaitPC = 0;

	//����� ���������� ������ ��� ������ ���
	int currentTimeExecutionPC = 0;

	//����� ����� ������� � ������ ���
	int totalTimeQueuePC = 0;

	//������������ ����� �������
	int maxTimeQueuePC = 0;

	//����� ��� ������ ��������� ������� ��� ������ ����� ������ �������
	int timeCurrentQueuePC = 0;

	//������������ ������� ������ ���
	int maxCountTaskInQueuePC = 0;

	//���������� ��� ���������
	int countBusyPC = 0;
	int tempTimeWait = 0;

	//���������� ��������
	int countQueuePC = 0;

	//���������� ����� ���������� � �������
	int countTaskInQueueAfterGetAllTaskPC = 0;

	
	void completeTask();
	void saveSizeQueueIfExists(int const& countTask);
	void calculateTimeInQueue(int const& countTask);
	

};

#endif

