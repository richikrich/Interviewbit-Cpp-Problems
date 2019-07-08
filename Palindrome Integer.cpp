#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 
#include<string>

using namespace std;

bool checkLoop(int A, int d)
{
	if(A==0) return true;
	else if(((int) A/d)==(A%10))
	{
		A=(int) ((A%d)/10);
		d/=100;
		return checkLoop(A,d);
	}
	else return false;
}

/*int divisorFirstDigit(int A)
{
	int d=1;
	while(A/d>=10)
	{
		d*=10;
	}
	return d;
}*/

bool isPalindrome(int A)
{
	if(A<0) return false;
	int d=1;
	while(A/d>=10)
	{
		d*=10;
	}
	if(checkLoop(A,d)) return true;
	else return false;
}

int main()
{
	int a;
	cout<<"Enter the number you want to check: "; cin>>a; 
	if(isPalindrome(a)) cout<<"It is a palindrome \n";
	else cout<<"Not a palindrome \n";
	return 0;
}
