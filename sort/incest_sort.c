#include<stdio.h>


void insert_sort(int* array)
{
    int n = 5;
    int i , j,key;
    for( i =1; i < n; i++)
    {
        key = array[i];
        j = i -1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=key;
    }

}

int main()
{
    int array[]= {2,5,3,1,4};
    insert_sort(array);
    for(int i = 0 ; i<5;i++ )
        printf("%d \t",array[i]);
}
