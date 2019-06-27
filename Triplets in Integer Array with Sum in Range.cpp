#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;

int tripletsLessThan(vector<int> &A, int a)
{
	sort(A.begin(), A.end());
	int counter=0; int j, k;
	for(int i=0; i<A.size()-2; i++)
	{
		j=i+1; k=A.size()-1;
		while(j!=k)
		{
			if(A[i]+A[j]+A[k]>a)
			{
				k--;
			}
			else
			{
				counter+=k-j;
				j++;
			}
		}
	}
	return counter;
}

void tripletsInRange(vector<int> &A, int a, int b)
{
	int ret=tripletsLessThan(A,b)-tripletsLessThan(A,a-1);
	cout<<"The required number is: \n"<<ret;
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
	cout<<"Enter the lower limit: \n";
	int a; cin>>a;
	cout<<"Enter the upper limit: \n";
	int b; cin>>b;
	//cout<<tripletsLessThan(vect,b)<<"\n";
	//cout<<tripletsLessThan(vect,a-1)<<"\n";
	tripletsInRange(vect, a, b);
	return 0;
}
