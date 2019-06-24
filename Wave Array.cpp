#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;

vector<int> wave(vector<int> &A)
{
	sort(A.begin(), A.end());
	int i=0; int temp;
	//vector<int> ret;
	while(i<A.size()-1)
	{
		temp=A[i];
		A[i]=A[i+1];
		A[i+1]=temp;
		i+=2;	
	}
	return A;
	
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
	vector<int> result=wave(vect);
	cout<<"Result: \n";
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<" ";
	}
	return 0;
}
