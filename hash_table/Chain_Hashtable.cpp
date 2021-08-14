
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct LinkedList
{
    int key;
    LinkedList* Other;
};
LinkedList* MakeNew(int value)
{
    LinkedList* temp = new LinkedList();
    temp->key = value;
    return temp;
}
LinkedList* Insert(LinkedList* Original, int value)
{
    if(Original==NULL)
    {
        Original=MakeNew(value);
    }
    else
    {
        Original->Other =Insert(Original->Other,value);
    }
    return Original;
}
void PrintList(LinkedList* list)
{
    if(list==NULL)
        return;
    else
    {
        cout<<list->key<<" ";
        PrintList(list->Other);
    }
}
bool Search(LinkedList* list,int value)
{
    if(list==NULL)
        return 0;
    else if(list->key==value)
        return 1;
    else
    {
        Search(list->Other,value);
    }

}
LinkedList* Delete(LinkedList* Original, int value)
{
    if(Original==NULL)
        return Original;
    else if(Original->key!= value)
    {
        Original->Other = Delete(Original->Other,value);
    }
    else
    {
        if(Original->Other==NULL)
        {
            delete Original;
            Original = NULL;
        }
        else
        {
            LinkedList* temp = Original;
            Original= Original->Other;
            delete temp;
            if(Original->key == value)
            {
                Original=Delete(Original,value);
            }
        }
    }

    return Original;
} int String2Number(char input[4])
{
    long int result=0;
    for(int i=0 ; i<4;i++)
    {
        int temp = input[i];
        result = temp*pow(128,3-i);
    }
    return result%100;
}
int Hash_Chain(char input[4])
{
    long int number= String2Number(input);
    long int m = pow(2,7);
    return number%m;
}
void LinkedList_Insert_Hashtable(LinkedList* T[100],char input[4])
{
    int value = String2Number(input);
    int index = value%100;
    T[index]=Insert(T[index],value);
}
void LinkedList_Search_Hashtable(LinkedList* T[100],char input[4])
{

    int value = String2Number(input);
    if(Search(T[value],value))
    {
        cout<<"Found"<<endl;
    }
    else
        cout<<"Not found"<<endl;
}
void LinkedList_Delete_Hashtable(LinkedList* T[100],char input[4])
{
    int value= String2Number(input);
    T[value]=Delete(T[value],value);
}
void PrintHashTable(LinkedList* T[100])
{
    for(int i = 0 ; i< 100;i++)
    {
        cout<<i<< " : ";
        PrintList(T[i]);
        cout<<endl;
    }
}
int main()
{
    //Debug Linked List Hash table
    LinkedList* T[100];
    for(int i = 0 ; i <100;i++)
    {
        T[i]=NULL;
    }
    LinkedList_Insert_Hashtable(T,"MOMM");
    cout<<"Before delete: "<<endl;
    PrintHashTable(T);
    LinkedList_Search_Hashtable(T,"MOMM");
    LinkedList_Delete_Hashtable(T,"MOMM");
    cout<<"After delete: " <<endl;
    PrintHashTable(T);

    LinkedList_Search_Hashtable(T,"MOMM");


}
