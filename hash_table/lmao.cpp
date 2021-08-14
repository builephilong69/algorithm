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
    cout<<endl;
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
        }
    }
    return Original;
}
long int String2Number(char input[4])
{
    int char1 =input[0];
    int char2=input[1];
    int char3=input[2];
    int char4=input[3];
    return char1*pow(128,3)+char2*pow(128,2)+char3*pow(128,1)+char4*pow(128,0);
}
int Hash_LinearProbing(char input[4])
{
    long int number= String2Number(input);
    long int m = pow(2,7);
    return number%m;
}
void HashTable_Insert_LinearProbing(int T[100],char input[4])
{

    int value = Hash_LinearProbing(input);
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
            cout<<"Not enough space for collisions"<<endl;
            break;
        }
    }

}
bool HashTable_Search(int T[100],int key)
{
    for(int  i= 0 ;i<100;i++)
    {
        if(T[i]==key)
        {
            return 1;
            break;
        }
        return 0;
    }
}
void HashTable_Delete(int T[100],int key)
{
    for(int i =0;i<100;i++)
    {
        if(T[i]==key)
        {
            T[i]=0;
        }
    }
}
void LinkedList_Insert_Hashtable(LinkedList* T[100],char input[4])
{
    int value = Hash_LinearProbing(input);
    int index = value%100;
    T[index]=Insert(T[index],value);

}
int main()
{
        // Debug Linked List
        /*
        LinkedList* Original = NULL;
        Original=Insert(Original,1);
        Original=Insert(Original,2);
        Original=Insert(Original,3);
        Original=Insert(Original,4);
        PrintList(Original);
        cout<<Search(Original,3)<<endl;
        Original= Delete(Original,1);
        PrintList(Original);
        */

                //Debug hash function
                /*
                char input[] ="CLRS";
                int result = Hash(input);
                int char1=input[0];
                cout<<result;
                */



        // Debug Insert_LinearProbing_Hash


/*
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


        for(int i =0 ; i<100;i++)
        {
            cout<<i<<" "<<T[i]<<endl;
        }
        HashTable_Delete(T,83);
        cout<<HashTable_Search(T,83);



*/

    //Debug Linked List Hash table
    LinkedList* T[100];
    for(int i = 0 ; i <100;i++)
    {
        T[i]=NULL;
    }
    LinkedList_Insert_Hashtable(T,"CLRS");
    LinkedList_Insert_Hashtable(T,"CLRS");
    LinkedList_Insert_Hashtable(T,"LMAO");
    LinkedList_Insert_Hashtable(T,"CLRS");
    LinkedList_Insert_Hashtable(T,"CLRS");
    LinkedList_Insert_Hashtable(T,"CLRS");
    LinkedList_Insert_Hashtable(T,"CLRS");
    for(int i = 0 ; i<100;i++)
    {
        cout<<i<<" : ";
        PrintList(T[i]);
        cout<<endl;
    }

}
