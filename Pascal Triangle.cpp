#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

vector<vector<int>> pascalTriangle(int n)
{
	vector<vector<int>> ret;
	vector<int> temp;
	temp.push_back(1);
	ret.push_back(temp);
	for(int i=1; i<n; i++)
	{
			temp.clear();
			temp.push_back(1);
			int j=0;
			while(j<ret[i-1].size()-1)
			{
				temp.push_back(ret[i-1][j]+ret[i-1][j+1]);
				j++;
			}
			temp.push_back(1);
			ret.push_back(temp);
	}
	return ret; 
}

int main()
{
	cout<<"Enter the value of n: \n";
	int n; cin>>n;
	cout<<"\n";
	vector<vector<int>> result=pascalTriangle(n);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
