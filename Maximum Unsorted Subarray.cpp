#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

vector<int> maxUnsortedArray(vector<int> &A)
{
	int j=-1; vector<int> ret;
	//check if the vector is already sorted
	for(int i=0; i<A.size()-1; i++)
	{
		if(A[i]>A[i+1])
		{
			j=i;
			break;
		} 
	}
	if(j==-1) 
	{
		ret.push_back(-1);
		return ret;
	}
	//If it's not sorted the index returned by 'j' is the first erratic element from start and hence will definitely belong to theunsorted sub-array 
	int k; //Find the first erratic element from end. This too will definitely belong to the unsorted array
	for(int i=A.size()-1; i>0; i--)
	{
		if(A[i]<A[i-1])
		{
			k=i;
			break;
		}
	}
	//to find the actual unsorted subarray: if there is some an input to the left of the above defined range, greater than the minimum of this sub-array, it will also be in the unbsorted subarray
	//										similarly, any element to the right, but smaller than the maximum will belong to this subarray
	int maxi=*max_element(A.begin()+j, A.begin()+k+1); int mini=*min_element(A.begin()+j, A.begin()+k+1); //maximum abd minimum in the given range
	int j2=-1, k2=-1;
	for(int i=0; i<j; i++)
	{
		if(A[i]>mini)
		{
			j2=i;
			break;
		}
	}
	if(j2!=-1) j=j2;
	ret.push_back(j);
	for(int i=A.size()-1; i>k; i--)
	{
		if(A[i]<maxi)
		{
			k2=i;
			break;
		}
	}
	if(k2!=-1) k=k2;
	ret.push_back(k);
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
	vector<int> result=maxUnsortedArray(vect);
	cout<<"Result: \n";
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
