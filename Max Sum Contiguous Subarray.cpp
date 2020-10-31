//This solution follows Kadane's algorithm to find the maximum contiguous subarray

#include<iostream>
#include<vector>


using namespace std;

int maxSubArraySum(vector<int> &A)
{
	int maxSoFar=A[0];
    int currMax=A[0];
    
    for(int i=1; i<A.size(); i++)
    {
        currMax=max(A[i],currMax+A[i]);
        maxSoFar=max(maxSoFar, currMax); //stores and checks maximum values found before this
    }
    
    return maxSoFar;
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
