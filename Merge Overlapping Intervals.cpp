#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

struct intervals
{
	int start;
	int end;
};

bool compIntervals(intervals i1, intervals i2)
{
	return i1.start<i2.start;
}

vector<intervals> mergeOverlaps(vector<intervals> &A)
{
	vector<intervals> ret;
	sort(A.begin(), A.end(), compIntervals);
	ret.push_back(A[0]);
	//cout<<"["<<ret[0].start<<","<<ret[0].end<<"]"<<" ";
	for(int i=1; i<A.size(); i++)
	{
		if(A[i].start<=ret[ret.size()-1].end)
		{
			if(A[i].end>ret[ret.size()-1].end) ret[ret.size()-1].end=A[i].end;
		}
		else
		{
			ret.push_back(A[i]);
		}
		//for(int j=0; j<ret.size(); j++) {cout<<"["<<ret[j].start<<","<<ret[j].end<<"]"<<" ";}
	}
	return ret;
}

int main()
{
	cout<<"Enter the number of intervals: \n";
	int n; cin>>n; intervals tempInter;
	vector<intervals> vect;
	cout<<"Enter start and end of each interval: \n";
	for(int i=0; i<n; i++)
	{
		cin>>tempInter.start;
		cin>>tempInter.end;
		vect.push_back(tempInter);
	}
	cout<<"The intervals you entered are: \n";
	for(int i=0; i<vect.size(); i++)
	{
		cout<<vect[i].start<<" "<<vect[i].end<<endl;
	}
	cout<<"Result: \n";
	vector<intervals> result=mergeOverlaps(vect);
	for(int i=0;i<result.size(); i++)
	{
		cout<<result[i].start<<" "<<result[i].end<<endl;
	}
	return 0;
}
