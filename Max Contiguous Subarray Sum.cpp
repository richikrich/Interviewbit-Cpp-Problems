//This solution follows Kadane's algorithm to find the maximum contiguous subarray

#include<iostream>
#include<vector>


using namespace std;

int maxSubArraySum(vector<int> &A)
{
	int global_max=0; int local_max=0; //global_max=max_so_far and local_max=max_ending_here
	for(int i=0; i<A.size(); i++)
	{
		if(local_max<0) {local_max=0;}
		local_max+=A[i];
		if(local_max>global_max) {global_max=local_max;}
	}
	return global_max;
}


int main()
{
	cout<<"Enter the number of elements: \n";
	int n,temp; cin>>n;
	vector<int> vect;
	cout<<"Inputs: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"vector: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<" ";}
	cout<<"\nThe sum of maximum contiguous subarray is: "<<maxSubArraySum(vect);
	return 0;
}
