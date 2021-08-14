#include<vector>
#include<iostream>
using namespace std;

#define V 8

int MinQ(int MSTtable[3][V],vector<int>Q)
{
    int MIN = MSTtable[1][Q[0]];
    int index = 0 ;
    for( int i = 0 ;  i <Q.size();i++)
    {
        if(MSTtable[1][Q[i]] < MIN)
        {
            MIN = MSTtable[1][Q[i]];
            index = i;
        }
    }
    return index;
}

bool CheckVinQ(int v, vector<int>Q)
{
    for(int i =  0 ; i < Q.size();i++)
    {
        if(v == Q[i])
            return true;
    }
    return false;
}

void PrintMST(int MSTtable[3][V])
{
    for( int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < V ; j++)
        {
            cout<<MSTtable[i][j] <<'\t';
        }
        cout<<endl;
    }
}

void MST(int graph[V][V])
{
    vector<int>Q;
    int MSTtable[3][V];
    for(int i =0; i <V ; i++)
    {
        MSTtable[0][i] = i;
        MSTtable[1][i] = INT_MAX;
        MSTtable[2][i] = -1;
        Q.push_back(i);
    }
    MSTtable[1][0] = 0;

    while(Q.size()>0)
    {
        int index = MinQ(MSTtable,Q);
        int u = Q[index];
        Q.erase(Q.begin()+index);
        for(int v = 0 ; v< V ; v++)
        {
            if(graph[u][v] && CheckVinQ(v,Q))
            {
                if(graph[u][v] < MSTtable[1][v])
                {
                    MSTtable[1][v] = graph[u][v];
                    MSTtable[2][v] = u;

                }
            }
        }
    }
    PrintMST(MSTtable);
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

    MST(graph);
}
