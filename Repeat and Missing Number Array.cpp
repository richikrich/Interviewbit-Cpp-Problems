#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> repeatedNumber(vector<int> &A)   
{
	long long int n=A.size();
	//long long int sum=0, sumsq=0;
	long long int sum=n*(n+1)/2, sumsq=n*(n+1)*(2*n+1)/6;
	for(int i=0;i<n;i++)
	{
		sum-=A[i]; sumsq-=A[i]*A[i]; //give (y-x) and (y^2-x^2) respectively
	}
	long long int a=(sum+(sumsq/sum))/2; //missing number
	long long int b=(-sum+(sumsq/sum))/2; //repeating number
	vector<int> ret; ret.push_back(b); ret.push_back(a);
	return ret;
}



int main()
{
	cout<<"Enter the length of the array: \n";
	int n,temp; cin>>n;
	vector<int> vect;
	cout<<"Input: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"vectors: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<"\n";}
	vector<int>::iterator it;
	/*for(it=vect.begin();it!=vect.end();it++)
	{
		if(*it==2) break;
	}*/
	vector<int> A=repeatedNumber(vect);
	for(int i=0; i<2; i++)
	{
		cout<<A[i]<<" ";
	} 
	return 0; 
}
