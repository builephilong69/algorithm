#include <iostream>
#include <vector>
using namespace std;
#define V 8


int getMinQ(int MstTable[3][V], vector<int> Q)
{
	int index = 0;
	int MIN = MstTable[1][Q[0]];
	for(int i=1; i<Q.size(); i++)
	{
		if(MstTable[1][Q[i]] < MIN)
		{
			MIN = MstTable[1][Q[i]];
			index = i;
		}
	}
	return index;
}
bool CheckVinQ(int v, vector<int> Q)
{
	for(int i=0; i<Q.size(); i++)
	{
		if(v == Q[i])
		{
			return true;
		}
	}
	return false;
}
void PrintMst(int MstTable[3][V])
{
	for(int i=0; i< 3; i++)
	{
		for(int j=0; j<V;j++)
		{
			cout << MstTable[i][j] << "\t";
		}
		cout << endl;
	}
}
void MSTree(int graph[V][V])
{
	//Initializing Table and Q
	int MstTable[3][V];
	vector<int> Q;
	for(int v= 0; v < V;v++)
	{
		MstTable[0][v] = v;
		Q.push_back(v);
		MstTable[1][v] = 999999;
		MstTable[2][v] = -1;
	}
	MstTable[1][0] = 0;
	MstTable[2][0] = -1;
	//-------------------------------------------
	while(Q.size() > 0)
	{
		int idx = getMinQ(MstTable, Q);
		int u = Q[idx];
		Q.erase (Q.begin()+idx);
		for(int v = 0; v < V; v++)
		{
			if(graph[u][v] && CheckVinQ(v, Q))
			{
				if (graph[u][v] < MstTable[1][v])
				{
					MstTable[2][v] = u;
					MstTable[1][v] = graph[u][v];
				}
			}
		}
	}
	//--------------------------------------------
	PrintMst(MstTable);


}
int main()
{
	int graph[V][V] = {  {0,12,5,4,0,0,0,0},
                        { 12,0,9,11,0,0,0,0},
                        { 5,9,0,2,2,4,0,0},
                        { 4,11,2,0,7,0,1,0},
                        { 0,0,2,7,0,0,3,6},
                        { 0,0,4,0,0,0,8,1},
                        { 0,0,0,0,6,1,0,0}, };
    MSTree(graph);
}
