#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

//////Fixing each consecutive character of the string, we check the number of strings possible with a better rank. That is the number of characters to it's right and the number of permutations each can form.///////
using namespace std;

int factorial(int n)
{
	if(n<=1) return 1;
	else return (n*factorial(n-1))%1000003;
}

int rightLesser(int index, string &s)
{
	int count=0;
	for(int i=index+1; i<s.size(); i++)
	{
		if(s[i]<s[index]) count+=1;
	}
	//cout<<count<<endl;
	return count;
}

int findRank(string &s)
{
	long long int rank=1;
	for(int i=0; i<s.size(); i++)
	{
		rank+=((rightLesser(i,s)*factorial(s.size()-1-i))%1000003);
	}
	return (rank%1000003);
}

int main()
{
	string s;
	cout<<"Enter the string: \n";
	cin>>s;
	cout<<"The string you entered is: "<<s<<endl;
	cout<<"Result:\n";
	cout<<findRank(s)<<endl;
	return 0;
}
