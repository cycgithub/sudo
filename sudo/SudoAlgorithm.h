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
	bool scanPos(int pos,int &count);//生成各个数字的算法

	bool check(int pos);//判断是否合法
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

