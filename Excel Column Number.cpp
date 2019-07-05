#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

long long int columnNumber(string s)
{
	long long int ret=0;
	for(int i=0; i<s.size(); i++)
	{
		int x=(int) s[i];
		long long int power=pow(26,s.size()-1-i);
		ret+=power*(x-64);
		//cout<<(x-64)<<" "<<power<<" "<<ret<<endl;
	}
	//cout<<x; 
	return ret;
}

int main()
{
	string s;
	cout<<"Enter column title: "; cin>>s;
	cout<<"The column you entered is: "<<s<<endl;
	//cout<<(((int)s[0])-64)<<" "<<pow(26,s.size()-0-1)<<endl;
	cout<<"Result: ";
	long long int y=columnNumber(s);
	cout<<y<<endl;
	return 0;
}
