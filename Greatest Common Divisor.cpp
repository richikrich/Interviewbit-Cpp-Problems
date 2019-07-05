#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 
#include<string>

using namespace std;

int greatestCommonDivisor(int a, int b)
{
	int mini=min(a,b);
	int maxi=max(a,b);
	while(true)
	{
		int rem=b%a;
		if(rem==0) break;
		else
		{
			b=a;
			a=rem;
		}
	}
	return a;
}

int main()
{
	int a,b;
	cout<<"Enter the numbers whose GCD you want to find: "; cin>>a>>b; 
	cout<<greatestCommonDivisor(a,b)<<endl;
	return 0;
}
