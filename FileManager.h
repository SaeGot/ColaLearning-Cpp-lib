#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>


using namespace std;

class FileManager
{
public:
	enum class Type
	{
		Real,
		String
	};
	FileManager() {};
	/**
	 * ��� Ÿ���� �����ϰ� ������ ����.
	 *
	 * \param file_Name : ���� �̸�
	 * \param data_Type : ������ Ÿ��
	 */
	FileManager(string file_Name, Type data_Type = Type::Real);
	/**
	 * ������ Į���� Ÿ���� �����Ͽ� ������ ����.
	 * 
	 * \param file_Name : ���� �̸�
	 * \param data_TypeList : ������ Ÿ��
	 */
	FileManager(string file_Name, vector<Type> data_Types);
	~FileManager();
	/**
	 * �ش� ��� ������ ��������.
	 * 
	 * \param row : ��
	 * \param column : ��
	 * \return ������
	 */
	double GetData(int row, int column);
	/**
	 * �ش� �� ������ ��������.
	 * 
	 * \param row : ��
	 * \return �� ������
	 */
	vector<double> GetData(int row);
	/**
	 * ǥ ���·� �б�.
	 * 
	 * \param file_Name : ���� �̸�
	 * \return 
	 */
	vector<vector<string>> GetTable(string file_Name);

private:
	struct Data
	{
		string columnName;
		Type type = Type::Real;
		// <��, ��>
		map<int, double> value;
	};
	// <��, ��>
	map<int, Data> data;

	/**
	 * Į���� ����.
	 * 
	 * \param line : ù ��
	 * \return Į����
	 */
	vector<string> SetColumnName(string first_line);
	/**
	 * ��� Ÿ���� �����ϰ� ����.
	 * 
	 * \param column_Names : Į����
	 * \param data_Type : ������ Ÿ��
	 */
	vector<Type> SetDataType(vector<string> column_Names, Type data_Type);
	/**
	 * �� Į���� Ÿ���� ������� ����.
	 * 
	 * \param column_Names : Į����
	 * \param data_TypeList : ������ Ÿ��
	 */
	vector<Type> SetDataType(vector<string> column_Names, vector<Type> data_Types);
	/**
	 * ������ ����.
	 * 
	 * \param row : �� �ε���
	 * \param line : �� ������
	 */
	map<int, double> SetData(int row, string line, int column_Count);
};

