#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include<algorithm>

using namespace std;

class Object
{
public:
    int value;
    int weight;
    Object(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
    Object()
    {
        srand(time(NULL));
        int result = rand()%10+1;
        this->weight = result;
    }
    Object(int value)
    {
        this->value = value;
        srand(time(NULL));
        int result = rand()%10+1;
        this->weight = result;
    }

    friend istream &operator>>( istream &input, Object &O)
    {
        input >> O.value;
        return input;
    }
    friend ostream &operator<<(ostream &output, Object &O)
    {
        output<<"Value : "<< O.value << " Weight: " << O.weight;
    }

};

void printList(vector<Object>List_of_Object)
{
    for(int i = 0 ; i< List_of_Object.size() ; i++)
    {
        cout<<"Object " << i+1 << " : "<< List_of_Object[i]<<endl;
    }
}

vector<Object>Create_Object()
{
    vector<Object>result;
    Object temp(0,0);
    result.push_back(temp);

    int object_size;
    cout<<"Enter the object size : ";
    cin>>object_size;

    for(int i = 0 ; i < object_size; i++)
    {
        Object temp;
        cout<<"Enter value: ";
        cin>>temp;
        result.push_back(temp);
    }
    return result;
}


int** KnapSack(vector<Object>n, int C)
{
    int** K = new int*[n.size()+1];
    for( auto i = 0 ; i<n.size();i++)
    {
        K[i] = new int[C+1];
    }
    int v[n.size()];
    int w[n.size()];
    for(int i = 0 ; i < n.size(); i++)
    {
        v[i] = n[i].value;
        w[i]= n[i].weight;
    }




    for(int i = 1 ; i<=n.size();i++)
        K[i][0] = 0;
    for(int j = 0 ; j<=C;j++)
    {
        if(w[1]  <= j)
            K[1][j] = v[1];
        else
            K[1][j] = 0;
    }

    for(int i=2;i<=n.size();i++)
        for(int j = 1 ; j <=C; j++)
            if(j>= w[i])
            {
                K[i][j] = max (K[i-1][j-w[i]+v[i]],K[i-1][j]);
            }
            else
                K[i][j] = K[i-1][j];
    return K;
}

int main()
{
    vector<Object>list_of_objects;
    list_of_objects = Create_Object();
    printList(list_of_objects);

    int** result = KnapSack(list_of_objects,30);

    for(int i = 1; i <= list_of_objects.size();i++)
    {
        for(int j = 1; j<= list_of_objects.size();j++)
        {
            cout<< result[i][j] << " ";
        }
        cout<<endl;
    }
}
