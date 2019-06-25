#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;

//While traversing the positive elements, mark the element by using the present (element-1) as index as negative, if the element is less than maximum possible index. If all the positive integers are present to (A.size()), all the 
//elements will be negative. If a positive number is missing, the elements at A[element-1] will be positive, thus returning us the number. 
//Please note that the first positive number to be missing can only be a number in 1..A.size(). 

void findMissing(vector<int> &A)
{
	vector<int> positive, nonPositive;
	for(int i=0; i<A.size(); i++)
	{
		if(A[i]>0) positive.push_back(A[i]);
		else nonPositive.push_back(A[i]);
	}
	
	for(int i=0; i<positive.size(); i++)
	{
		if((abs(positive[i])-1)<positive.size()) 
		{
			if(positive[abs(positive[i])-1]>0) positive[abs(positive[i])-1]*=(-1);
		}
	}
	int i=0;
	while (i<positive.size())
	{
		if(positive[i]>0) break;
		else i++;
	}
	cout<<"The missing number is: \n";
	cout<<(i+1);
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
	findMissing(vect);
	return 0;
}
