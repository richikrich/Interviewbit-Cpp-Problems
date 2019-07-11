#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool isPower(int n)
{
	bool ret=false;
	double val;
	for(int i=2; i<n; i++)
	{
		//cout<<i<<endl;
		val=log(n)/log(i);
		//cout<<val<<endl;
		if(val<2) break;
		double dec=val-((int)val);
		//cout<<dec<<endl;
		if(dec<=0.00001)
		{
			ret=true;
			break;
		}
	}
	return ret;
}

int main()
{
	int n;
	cout<<"Enter your number: ";
	cin>>n;
	if(isPower(n)) cout<<"True";
	else cout<<"False";
	cout<<endl;
	return 0;
}
