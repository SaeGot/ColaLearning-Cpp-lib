#pragma once
#include "NeuralNetwork.h"
#include <string>


class ReinforcementLearning
{
public:
	enum class EpisodeEndCondition
	{
		State,
		Reward
	};
	struct EpsilonGreedy
	{
		float beginningValue;
		// �� ���� ���� ������ �����ϴ��� ����. 0 ���ϴ� 1�� ����
		int interval;
		// ������
		float gamma;
	};

protected:
	struct SARS
	{
		string currentState;
		string action;
		double reward;
		string nextState;
	};
	EpisodeEndCondition episodeEndCondition;
	string stateEndCondition;
	double rewardEndCondition[2];
	string currentState;
	double cumulativeReward;
	// i : ���Ǽҵ�, j : ����
	vector<vector<SARS>> sarsList;
};
