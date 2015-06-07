#pragma once
#include<vector>
using std::vector;
class SudoAlgorithm
{
public:
	SudoAlgorithm(void);
	~SudoAlgorithm(void);

	//self
public:
	bool scanPos(int pos,int &count);//���ɸ������ֵ��㷨

	bool check(int pos);//�ж��Ƿ�Ϸ�
	char getdata(int i,int j);
	void generRandom(int k);
	void swap(int *a,int i,int j);
	void setdata(char c,int pos);
	bool check1(int pos);
	void reset(int k);
private:
	vector<vector<char> > board;
	char trap[9][9];
	int randm[81];
};

