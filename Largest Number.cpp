#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;

bool customCompare(string X, string Y) //custom function for comparing the strings so that they can be sorted to get the highest possible number on arranging 
{
	string A=X.append(Y);
	string B=Y.append(X);
	if(A>B) return 1;
	else return 0;
}

string largestNumber(vector<int> &A)
{
	vector<string> B;
	for(int i=0; i<A.size(); i++)
	{
		B.push_back(to_string(A[i]));
	}
	sort(B.begin(), B.end(), customCompare);
	string ret;
	for(int i=0; i<B.size(); i++)
	{
		ret.append(B[i]);
	}
	int j=0;
	while(ret[j]=='0') j++; //we want to remove the initial zeroes.
	if(j==ret.size()) ret='0'; //the only way a zero can come in front is if all the inputs were zeros. So, we don't need to worry about non-negative entry after negative one
	return ret;
	
}

int main()
{
	cout<<"Enter the number of inputs: \n"; 
	int n; cin>>n;
	cout<<"Enter the numbers: \n";
	vector<int> Str; int temp;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		Str.push_back(temp);
	}
	string result=largestNumber(Str);
	cout<<result;
	return 0;
}
