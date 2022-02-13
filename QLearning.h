#pragma once
#include "ReinforcementLearning.h"
#include <map>
#include <string>


class QLearning : public ReinforcementLearning
{
public:
	/**
	 * csv ���Ϸ� ���º� �ൿ�� ���� ���� ���� �� ���� ǥ ����. (�� : �ൿ, �� : ����).
	 * ���¿� ���� ���Ǽҵ� ���� ����
	 *
	 * \param state_EndCondition : ���¿� ���� ���Ǽҵ� ���� ����
	 * \param next_StateTable : ���� ���� ǥ
	 * \param reward_Table : ����ǥ
	 */
	QLearning(string state_EndCondition, string next_StateTable, string reward_Table);
	/**
	 * csv ���Ϸ� ���º� �ൿ�� ���� ���� ���� �� ���� ǥ ����. (�� : �ൿ, �� : ����)
	 * ���� ���� ���Ǽҵ� ���� ����
	 * 
	 * \param min_RewardEndCondition : ���� ���� ���Ǽҵ� ���� ���� (0 ������ �ּҰ�, 0�� ��� �� ������ ����)
	 * \param max_RewardEndCondition : ���� ���� ���Ǽҵ� ���� ���� (0 �ʰ��� �ִ밪)
	 * \param next_StateTable : ���� ���� ǥ
	 * \param reward_Table : ����ǥ
	 */
	QLearning(double min_RewardEndCondition, double max_RewardEndCondition, string next_StateTable, string reward_Table);
	/**
	 * ��� ���Ǽҵ� �ʱ�ȭ.
	 * 
	 */
	void Initialize();
	/**
	 * Ư�� ���¿��� �����Ͽ� �ϳ��� ���Ǽҵ带 ���� �� �н�.
	 * 
	 * \param starting_State : ���� ����
	 * \param discount_Factor : ������
	 * \param epsilon_Greedy
	 */
	void Learn(string starting_State, double discount_Factor, EpsilonGreedy& epsilon_Greedy);
	/**
	 * �ൿ �����Ͽ� ���� ���·� ����.
	 * 
	 * \param action : �ൿ
	 */
	void Action(string action = "");
	/**
	 * ���� ���¿��� �����Ͽ� ���� ���� �ൿ���� ��������.
	 * 
	 * \param starting_State : ���� ����
	 * \return ���� �ൿ��
	 */
	vector<string> GetBest(string starting_State);

private:
	struct StateAction
	{
		string state;
		string action;

		bool operator<(const StateAction& rhs) const;
	};
	// �� ���º� �ൿ�� ���� � ���°� �Ǵ����� ���� ǥ
	map<StateAction, string> nextStateTable;
	// �� ���º� �ൿ�� ���� ���� ǥ
	map<StateAction, double> rewardTable;
	// �� ���º� ������ �ൿ
	map<string, vector<string>> enableAction;
	// �� ���º� Q�� ǥ
	map<StateAction, double> QTable;

	/**
	 * nextStateTable ����.
	 * 
	 * \param table : nextStateTable
	 */
	void SetNextStateTable(const vector<vector<string>>& table);
	/**
	 * rewardTable ����.
	 * 
	 * \param table : rewardTable
	 */
	void SetRewardTable(const vector<vector<string>>& table);
	/**
	 * QTable ������Ʈ.
	 * 
	 * \param discount_Factor : ������
	 */
	void UpdateQTable(double discount_Factor);
	/**
	 * ���� ���¿��� ���� ���� �ൿ ��������.
	 * 
	 * \param state : ���� ����
	 * \return ���� �ൿ
	 */
	string GetBestAction(string state);
	/**
	 * �������� ���� ��������.
	 * 
	 * \param epsilon_Greedy : Epsilon Greedy
	 * \param step : ����
	 * \return �������� ����
	 */
	bool GetRandomPolicy(EpsilonGreedy& epsilon_Greedy, size_t step);
	/**
	 * ���� ���� ���� ���� ��������.
	 * 
	 * \param cumulative_Reward : ���� ����
	 * \return ���� ���� ���� ����
	 */
	bool CheckRewardEndCondition(double cumulative_Reward);
};
