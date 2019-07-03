#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

int maxsProd(vector<int> &A)
{
	int ret=INT_MIN;
	for(int i=0; i<A.size(); i++)
	{
		int a=0,b=0;
		for(int j=i-1;j>-1;j--)
		{
			if(A[i]<A[j])
			{
				a=j;
				break;
			}
		}
		for(int j=i+1; j<A.size(); j++)
		{
			if(A[j]>A[i])
			{
				b=j;
				break;
			}
		}
		if((a*b)>ret) ret=a*b;
	}
	return ret;
}


int main()
{
	cout<<"Enter the number of inputs in your vector: \n";
	int n; cin>>n; int temp;
	vector<int> vect;
	cout<<"\nEnter: ";
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"The vector you entered is: \n";
	for(int i=0; i<n; i++)
	{
		cout<<vect[i]<<" ";
	}
	cout<<endl;
	int result=maxsProd(vect);
	cout<<"Result: "<<result<<endl;
	return 0;
}
