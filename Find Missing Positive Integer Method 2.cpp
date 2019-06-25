#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;

//While traversing the positive elements, mark the element by using the present (element-1) as index as negative, if the element is less than maximum possible index. If all the positive integers are present to (A.size()), all the 
//elements will be negative. If a positive number is missing, the elements at A[element-1] will be positive, thus returning us the number. 
//Please note that the first positive number to be missing can only be a number in 1..A.size(). 

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int findMissing(vector<int> &A)
{
	int j=0;
	for(int i=0; i<A.size(); i++)
	{
		if(A[i]<=0)
		{
			swap(&A[i],&A[j]);
			j++;
		}
	}
	for(int i=j; i<A.size(); i++)
	{
		if((abs(A[i])-1)<A.size()-j) 
		{
			if(A[abs(A[i])-1+j]>0) A[abs(A[i])-1+j]*=(-1);
		}
	}
	int i=j;
	while (i<A.size())
	{
		if(A[i]>0) break;
		else i++;
	}
	return (i-j+1);
}

int main()
{
	cout<<"Enter the number of inputs: \n"; 
	int n; cin>>n;
	cout<<"Enter the numbers: \n";
	vector<int> vect; int temp;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"The vector you entered: \n";
	for(int i=0; i<vect.size(); i++)
	{
		cout<<vect[i]<<" ";
	}
	cout<<"\n";
	int result=findMissing(vect);
	cout<<"Reuslt: \n";
	cout<<result;
	return 0;
}
