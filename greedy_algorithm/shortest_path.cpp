#include<iostream>
#include<vector>
using namespace std;
#define V 8
int MinDistance(int dist[], bool sptSet[])
{
    int MIN = INT_MAX, index;

    for( int v = 0 ; v<V ;v++)
    {
        if(sptSet[v] == false && dist[v] <MIN)
        {
            MIN = dist[v];
            index = v;
        }
    }
    return index;
}
void PrintSolution(int dist[])
{
    cout<<"Vertext \t Distance from source"<<endl;
    for(int i = 0 ; i < V ; i++)
    {
        cout<<i<<"\t\t"<<dist[i] <<endl;
    }
}

void Dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool sptSet[V];

    for(int i = 0 ; i< V; i++)
    {
        dist[i]= INT_MAX;
        sptSet[i] = false;
    }
    dist[source] = 0;

    for(int count = 0; count < V-1;count++)
    {
        int u = MinDistance(dist,sptSet);
        sptSet[u] = true;

        for(int v= 0 ; v<V; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    PrintSolution(dist);
}


using namespace std;
int main()
{
    int graph[V][V] = {  {0,12,5,4,0,0,0,0},
                        { 12,0,9,11,0,0,0,0},
                        { 5,9,0,2,2,4,0,0},
                        { 4,11,2,0,7,0,1,0},
                        { 0,0,2,7,0,0,3,6},
                        { 0,0,4,0,0,0,8,1},
                        { 0,0,0,0,6,1,0,0}, };


    Dijkstra(graph,1);
}
