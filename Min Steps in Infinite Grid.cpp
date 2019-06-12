//This solution follows Kadane's algorithm to find the maximum contiguous subarray

#include<iostream>
#include<vector>



using namespace std;

int coverPoints(vector<int> &A, vector<int> &B)
{
	int dist=0;
	for(int i=0;i<A.size()-1;i++)
	{
		dist+=max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
	}
	return dist;
}


int main()
{
	cout<<"Enter the number of points: \n";
	int n,temp; cin>>n;
	vector<int> vect;
	cout<<"Input x: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	vector<int> vect2;
	cout<<"Input y: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect2.push_back(temp);
	}
	cout<<"vectors: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<" "<<vect2[i]<<" "<<"\n";}
	cout<<"\nThe result is: "<<coverPoints(vect,vect2);
	return 0;
}
