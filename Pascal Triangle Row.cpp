#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

vector<int> pascalTriangleRow(int n)
{
	vector<int> ret;
	ret.push_back(1);
	if(n==0) return ret;
	for(int i=1; i<n; i++)
	{
			ret.push_back(ret[i-1]*(n-i+1)/i);
	}
	ret.push_back(1);
	return ret; 
}

int main()
{
	cout<<"Enter the value of k, where k is zero based: \n";
	int k; cin>>k;
	cout<<"============================================\n";
	vector<int> result=pascalTriangleRow(k);
	cout<<"The k-th row is: \n";
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
