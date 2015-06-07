#include "StdAfx.h"
#include "SudoAlgorithm.h"
#include "stdlib.h"


SudoAlgorithm::SudoAlgorithm(void)
{
	vector<char> temp(9,'.');
	for(int i=0;i<9;++i)
	{
		board.push_back(temp);
	}
	int a=0;
	scanPos(0,a);
	int q=0;
	generRandom(q);

	/*trap=(char**)malloc(sizeof(char *));
	for(int i=0;i<9;++i)
		trap[i]=(char*)malloc(sizeof(char));*/
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			trap[i][j]=' ';
		}
	}
	int x=0,y=0;
	for(int i=0;i<60;++i)
	{
		x=randm[i]/9;
		y=randm[i]%9;
		trap[x][y]=board[x][y];
	}
}

SudoAlgorithm::~SudoAlgorithm(void)
{
}

bool SudoAlgorithm::scanPos(int pos,int &count)
{
	//pos 0~80: vertical(v) -- pos/9; horizontal(h) -- pos%9
        if(pos == 81)
        {
            count++;
            if(count==1)
            {
               // print(board);
             return false;
            }
            else if(count==5000)
            {
                //print(board);
             return true;
            }
             else
                return false;
        }

        else
        {
            int v = pos/9;
            int h = pos%9;
           if(board[v][h] != '.')
            {
                return scanPos(pos+1,count);
            }
            else
            {

                for(int i = 1; i <= 9; i ++)
                {
                    board[v][h] = '0'+i;
                    if(check(pos))
                    {
                        if(scanPos(pos+1,count))
                            return true;
                    }
                    board[v][h] = '.';
                }

            }
            return false;

        }
}
bool SudoAlgorithm::check1(int pos)
{
	int v = pos/9;
        int h = pos%9;
        char target = trap[v][h];
        //行
        for(vector<char>::size_type st = 0; st < 9; st ++)
        {
            if(st != h)
            {
                if(target == trap[v][st])
                    return false;
            }
        }

        //列
        for(vector<char>::size_type st = 0; st < 9; st ++)
        {
            if(st != v)
            {
                if(target == trap[st][h])
                    return false;
            }
        }

        //宫
        int beginx = v/3*3;
        int beginy = h/3*3;
        for(int i = beginx; i < beginx+3; i ++)
        {
            for(int j = beginy; j < beginy+3; j ++)
            {
                if(i != v && j != h)
                {
                    if(target == trap[i][j])
                        return false;
                }
            }
        }
        return true;
}

bool SudoAlgorithm::check(int pos)
{
	int v = pos/9;
        int h = pos%9;
        char target = board[v][h];
        //行
        for(vector<char>::size_type st = 0; st < 9; st ++)
        {
            if(st != h)
            {
                if(target == board[v][st])
                    return false;
            }
        }

        //列
        for(vector<char>::size_type st = 0; st < 9; st ++)
        {
            if(st != v)
            {
                if(target == board[st][h])
                    return false;
            }
        }

        //宫
        int beginx = v/3*3;
        int beginy = h/3*3;
        for(int i = beginx; i < beginx+3; i ++)
        {
            for(int j = beginy; j < beginy+3; j ++)
            {
                if(i != v && j != h)
                {
                    if(target == board[i][j])
                        return false;
                }
            }
        }
        return true;
}
char SudoAlgorithm::getdata(int i,int j)
	{
		return trap[i][j];
	}

void SudoAlgorithm::setdata(char c,int pos)
{
	int i=pos/9;int j=pos%9;
	trap[i][j]=c;
}
void SudoAlgorithm::swap(int *a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void SudoAlgorithm::generRandom(int k)
{
	
	srand((unsigned) time(NULL));
	for(int i=0;i<81;++i)randm[i]=i;
	for(int j=80;j>0;--j)swap(randm,j,rand()%j);
}

void SudoAlgorithm::reset(int k)
{
	vector<char> temp(9,'.');
	for(int i=0;i<9;++i)
	{
		board.push_back(temp);
	}
	int a=0;
	scanPos(0,a);
	int q=0;
	generRandom(q);

	/*trap=(char**)malloc(sizeof(char *));
	for(int i=0;i<9;++i)
		trap[i]=(char*)malloc(sizeof(char));*/
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			trap[i][j]=' ';
		}
	}
	int x=0,y=0;
	for(int i=0;i<k;++i)
	{
		x=randm[i]/9;
		y=randm[i]%9;
		trap[x][y]=board[x][y];
	}
}
