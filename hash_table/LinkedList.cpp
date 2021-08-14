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
int main()
{
        // Debug Linked List

        LinkedList* Original = NULL;
        Original=Insert(Original,1);
        Original=Insert(Original,2);
        Original=Insert(Original,3);
        Original=Insert(Original,4);
        PrintList(Original);
        Original=Delete(Original,3);
        cout<<Search(Original,3)<<endl;
        PrintList(Original);

}
