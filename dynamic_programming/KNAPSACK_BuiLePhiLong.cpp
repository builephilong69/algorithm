#include<iostream>
#include<algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int KnapSack(int W, int* wt, int* val, int n)
{
    int i , w;
    int K[n+1][W+1];

    for(i = 0 ; i <=n ; i++)
    {
        for(w = 0 ;w<=W ; w++)
        {
            if(i==0 || w ==0)
                K[i][w] = 0;
            else if( wt[i-1] <= w)
                K[i][w] = max ( val[i-1] + K[i-1][w - wt[i-1]],
                               K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    // Find out what is in the sack

    cout<<"------------------------------------------"<<endl<<endl;

    int temp_weight = W;
    int temp_index = n;
    while(temp_weight>0&&temp_index>0)
    {
        if(K[temp_index][temp_weight] != K[temp_index-1][temp_weight] )
        {
            cout<< "Sack contain object:  "<<temp_index<<endl;

            temp_weight = temp_weight - wt[temp_index-1];
        }
            temp_index--;
    }



    return K[n][W];
}
int* createValue(int size)
{
    int result[size];
    cout<<"Enter your objects value: "<<endl;
    for(int i = 0 ; i<size; i++)
    {
        cout<<"Object "<<i+1<<" : ";
        cin>> result[i];
    }

    cout<<"Your Objects' value : "<<endl;
    for(int i = 0 ; i <size;i++)
    {
        cout<<"Object "<<i+1<<" : "<< result[i]<<"\t";
    }
    return result;
}
int* createWeight(int size)
{
    int result[size];
    for(int i = 0 ;i<size;i++)
    {
        srand(time(NULL));
        result[i] = rand()%10 +1;
    }

    cout<<"Your Weights' value : "<<endl;
    for(int i = 0 ; i <size;i++)
    {
        cout<<"Object "<<i+1<<" : "<< result[i]<<"\t";
    }
    return result;
}

int main()
{
    int size;
    cout<<"Enter size of object: ";
    cin>>size;
    int val[size];
    cout<<"Enter your objects value: "<<endl;
    for(int i = 0 ; i<size; i++)
    {
        cout<<"Object "<<i+1<<" : ";
        cin>> val[i];
    }

    cout<<"Your Objects' value : "<<endl;
    for(int i = 0 ; i <size;i++)
    {
        cout<<"Object "<<i+1<<" : "<< val[i]<<"\t";
    }
    cout<<endl;

    srand(time(NULL));
    int wt[size];
    for(int i = 0 ;i<size;i++)
    {

        wt[i] = rand()%10 +1;
    }

    cout<<"Your Weights' value : "<<endl;
    for(int i = 0 ; i <size;i++)
    {
        cout<<"Object "<<i+1<<" : "<< wt[i]<<"\t";
    }
    cout<<endl;



    int W;
    cout<<"Enter the Weight of your sack : ";
    cin>>W;
    int n = sizeof(val)/sizeof(val[0]);



    int result = KnapSack(W,wt,val,n);
    cout<<"Maximum value of your Sack: " << result;
}
