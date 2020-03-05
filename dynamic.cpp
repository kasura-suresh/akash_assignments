/*********************************************************
*
*To Implement dynamic memory allocation
*Author: Akash Kumar Gupta
*Date: 14/2/2020
*
*********************************************************/

#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
	int* ptr, *ptr1, *ptr2;
	int *p = new int[10];
	int n, i;
    cin>> n;
    ptr =(int*)malloc(n * sizeof(int));
    ptr1 =(int*)calloc(n, sizeof(int));
    ptr2 =(int *)realloc(ptr1,n*sizeof(int));
	if (ptr == NULL || ptr1 == NULL ||( ptr2 == NULL)) {
		cout<<"Memory not allocated.\n";
		exit(0);
	}
	else
    {
		cout<<"Memory successfully allocated using malloc & calloc & realloc.\n";
		for (i = 0; i < n; i++) {
			ptr[i] = i+1;
			ptr1[i]= i+1;
			ptr2[i]= i+1;
		}
		cout<<"The elements of the array are: ";
		for (i = 0; i < n; ++i)
			cout<<ptr[i]<<" ";
        cout<<endl;
        cout<<"The elements of the array are: ";
         for(i=0;i<n;i++)
            cout<<ptr1[i]<<" ";
        cout<<endl;
        cout<<"The elements of the array are: ";
        for(i=0;i<n;i++)
            cout<<ptr2[i]<<" ";
	}
     free(ptr);
     free(ptr1);
     free(ptr2);
     delete p;
	return 0;
}
