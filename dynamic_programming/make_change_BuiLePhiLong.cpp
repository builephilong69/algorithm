#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int** Make_Change(int cost, vector<int>currency)
{
    int currency_size = currency.size();
    int** t = new int*[currency_size+1];
    for(auto i = 0 ; i<= currency_size ; ++i)
        t[i] = new int[cost+1];

    for(int i = 0; i<= currency_size;i++)
        for(int j = 0; j<= cost; j++)
            t[i][j]= 0;

    for(int i = 1 ; i <= currency_size;i++)
    {
        for(int j = 1 ; j<=cost;j++)
        {
            if(i==1)
            {
                t[i][j] = t[i][j - currency[i]] +1;
            }
            else if(j<currency[i])
            {
                t[i][j] = t[i-1][j];
            }
            else
            {
                t[i][j] = min( t[i][j-currency[i]]+1,t[i-1][j]);
            }


        }
    }
    cout<<"------------------------------------------"<<endl<<endl;
    int temp_i = currency_size;
    int temp_j = cost;
    int kind_of_coin[currency_size];
    for(int i = 1 ; i< currency_size;i++)
    {
        kind_of_coin[i] = 0;
    }

    while(temp_i >0 && temp_j>0)
    {

        if(t[temp_i][temp_j]!= t[temp_i-1][temp_j])
        {
            kind_of_coin[temp_i]++;

            temp_j-=currency[temp_i];

        }
        else
            temp_i--;
    }
    cout<<"Coin\tValue"<<endl;
    for(int i = 1; i<currency_size;i++)
    {
        cout<<currency[i]<<'\t'<<kind_of_coin[i];
        cout<<endl;
    }


    return t;
}


int main()
{
    vector<int>currency {0,1,5,10,25,100};
    int cost ;
    cout<<"Enter the money value: ";
    cin>>cost;


    int** result = Make_Change(cost,currency);

    /*
    cout<<"The table: "<<endl;

    for(int i = 1; i <= currency.size();i++)
    {
        for(int j = 1; j<= cost;j++)
        {
            cout<< result[i][j] << " ";
        }
        cout<<endl;
    }
    */



    cout<<"Smallest coins to charge is: "<<result[currency.size()][cost];


}
