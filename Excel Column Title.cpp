#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 
#include<string>

using namespace std;

string excelColumn(int A)
{
	string ret;
	int rem; string a;
	while(A>=1)
	{
		rem=(A%26)-1;
		A=(int) A/26;
		if(rem<0) 
		{
			rem=25;
			A-=1;
		}
		a=(char) ('A'+rem);
		ret.insert(0,a);
		cout<<a<<endl;
		//A=(int) A/26;
	}
	return ret;
}

int main()
{
	int x;
	cout<<"Enter the numbr of your choice: "; cin>>x;
	string result=excelColumn(x);
	cout<<"Result: "<<result<<endl;
	return 0;
}
