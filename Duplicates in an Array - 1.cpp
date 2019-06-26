#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;
 
 //The array is supposed to contain only integers from 0..A.size()-1. Therefore traverse through the elements of the array and do (A[element%A.size()]+A.size()) (Since (A[i]+A.size())%A.size()=A[i]). 
 //Traverse through the array again and do A[i]=/A.size(), only idices which are repeated elements will be >1
 //Unfortunately the interviewbit problem has declared A as 'const',i.e., we cannot change in it. Hence we must go with a different solution. ;_;
void findLargest(vector<int> &A)
{
	vector<int> ret;
	/*for(int i=0; i<A.size(); i++)
	{
		A[i]+=1;
	}*/
	for(int i=0; i<A.size(); i++)
	{
		A[A[i]%(A.size())]+=A.size();
	}
	cout<<"The duplicate elements are: \n";
	for(int i=0; i<A.size();i++)
	{
		if(A[i]/A.size()>1)
		{
			cout<<i<<" ";
		}
	}
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
	findLargest(vect);
	return 0;
}
