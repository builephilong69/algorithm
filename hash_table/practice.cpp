#include<iostream>
#include<cmath>
using namespace std;
struct LinkedList
{
    int data;
    LinkedList* other;
};
LinkedList* MakeNew(int value)
{
    LinkedList* temp = new LinkedList();
    temp->data=value;
    return temp;
}
LinkedList* Insert(LinkedList* Original, int value)
{
    if(Original == NULL)
    {
        Original = MakeNew(value);
    }
    else
    {
        Original->other=Insert(Original->other, value);
    }
    return Original;
}
LinkedList* Delete(LinkedList* Original, int value)
{
    if(Original==NULL)
        return Original;
    else if(Original->data!= value)
        return Delete(Original->other, value);
    else
    {
        if(Original->other==NULL)
        {
            delete Original;
            Original=NULL;
        }
        else
        {
            LinkedList* temp=Original;
            Original=Original->other;
            delete temp;
            temp = NULL;
        }
    }
    if(Original->data == value)
        Original=Delete(Original,value);
    return Original;
}
bool Search(LinkedList* Original, int value)
{
    if(Original == NULL)
        return 0 ;
    else
    {
        if(Original->data != value)
            return Search(Original->other,value);
        else
            return 1;
    }
}
void PrintList(LinkedList* Original)
{
    if(Original == NULL)
        return;
    else
    {
        cout<<Original->data<<" ";
        PrintList(Original->other);
    }
}
long int Char2Numb(char Input[4])
{
    int char1 = Input[0];
    int char2=Input[1];
    int char3= Input[2];
    int char4=Input[3];

    return (char1*pow(128,3)+char2*pow(128,2)+char3*128+char4);
}
int Hash_Chain(char input[4])
{
    long int number= Char2Numb(input);
    long int m = pow(2,8)-1;
    return number%m;
}
void Chain_Hash(LinkedList* T[100], char Input[4])
{
    int value = Hash_Chain(Input);
    int index = value%100;
    T[index]=Insert(T[index],value);
}
void PrintHashTable(LinkedList* T[100])
{
    for(int i = 0 ; i< 100 ; i++)
    {
        cout<< i<< ": ";
        PrintList(T[i]);
        cout<<endl;
    }
}
int main()
{
    LinkedList* T[100];
    for(int i = 0; i<100;i++)
    {
        T[i]=NULL;
    }
    Chain_Hash(T,"CLMM");
    Chain_Hash(T,"CLMM");
    Chain_Hash(T,"CLMM");
    Chain_Hash(T,"CLMN");
    PrintHashTable(T);

}
