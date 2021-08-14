#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long int String2Number(char input[4])
{
    long int result=0;
    for(int i=0 ; i<4;i++)
    {
        int temp = input[i];
        result = temp*pow(128,3-i);
    }
    return result%100;
}
void HashTable_Insert_LinearProbing(int T[100],char input[4])
{

    int value = String2Number(input);
    int index=0;
    for(int i = 0; i<100;i++)
    {
        index = (value+i)%100;
        if(T[index]==0)
        {
            T[index]=value;
            break;
        }
        if(i==99)
        {
            cout<<"Not enough space"<<endl;
            break;
        }
    }

}
bool HashTable_Search(int T[100],char input[4])
{
    int key = String2Number(input);
    for(int i=0;i<100;i++)
    {
        if(T[(key+i)%100]==key)
            return 1;
    }
    return 0;
}
void HashTable_Delete(int T[100],char input[4])
{
    int key = String2Number(input);
    int index = key;
    for(int i = 0; i<100;i++)
    {
        if(T[(index+i)%100]==key)
        {
            T[(index+i)%100]=0;
        }
    }
}
int main()
{
    // Debug Insert_LinearProbing_Hash

          int T[100];
        for(int i = 0 ; i <100;i++)
        {
            T[i]=0;
        }
        for(int i = 0 ; i<98;i++)
        {
            HashTable_Insert_LinearProbing(T,"CLRS");
        }
        HashTable_Insert_LinearProbing(T,"ABCD");
        HashTable_Insert_LinearProbing(T,"LMAO");

        cout<<"Before delete: "<<endl;
        for(int i =0 ; i<100;i++)
        {
            cout<<i<<" "<<T[i]<<endl;
        }
        HashTable_Delete(T,"CLRS");
        cout<<"After delete: "<<endl;
        for(int i =0 ; i<100;i++)
        {
            cout<<i<<" "<<T[i]<<endl;
        }
        cout<<HashTable_Search(T,"CLRS");




}
