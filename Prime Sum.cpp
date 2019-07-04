#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

vector<int> primeSum(int n)
{
	vector<bool> isPrime(n+1,true);
	isPrime[0]=false; isPrime[1]=false;
	for(int i=2; i<=n; i++)
	{
		if(isPrime[i])  //basically finds the prime numbers and marks their multiples as non-prime.
		{
			int j=i+i;
			while(j<=n)
			{
				isPrime[j]=false;
				j+=i;
			}
		}
	}
	vector<int> ret;
	int a=2;
	while(a<n)
	{
		if(isPrime[n-a]) 
		{
			ret.push_back(a);
			ret.push_back(n-a);
			break;
		}
		else a++;
	}
	return ret;
}

int main()
{
	cout<<"Enter the even number you want: ";
	int n; cin>>n;
	cout<<"The number you entered is: "<<n<<endl;
	vector<int> result=primeSum(n);
	cout<<"Result: \n";
	for(int i=0;i<2;i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
