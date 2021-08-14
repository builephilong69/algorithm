#include<iostream>

using namespace std;

int main()
{
    int** array = new int*[3];
    int d[4] = {0,1,3,6};

    for(auto i = 0; i<=3;++i )
        array[i] = new int[8];

    for(int i = 0 ; i <=3 ; i++)
        for(int j = 0; j <= 8 ; j++)
                array[i][j]=0;




    for(int i = 1 ; i <=3 ; i++)
        for(int j = 1; j <= 8 ; j++)
            {
                if(i==1)
                {
                    array[i][j]=array[i][j-d[i]]+1;
                }
                else if(j < d[i])
                {
                    array[i][j] = array[i-1][j];
                }
                else
                {
                    array[i][j] = min(array[i-1][j],array[i][j-d[i]]+1);
                }
            }

    for(int i = 0 ; i <=3 ; i++)
    {
            for(int j = 0; j <= 8 ; j++)
            {
                cout<<array[i][j] << " ";
            }
    cout<<endl;
    }
    int** other = array;

    for(int i = 0 ; i <=3 ; i++)
    {
            for(int j = 0; j <= 8 ; j++)
            {
                cout<<other[i][j] << " ";
            }
    cout<<endl;
    }

}
