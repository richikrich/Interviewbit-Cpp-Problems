#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int solve(int A, int B)
{
    if(B==0 || B>9*A) return 0;
    long long dp[A][B];
    int i=0;
    while(i<B)
    {
        if(i<9) dp[0][i]=1;
        else dp[0][i]=0;
        i++;
    }
    for(int i=0; i<A; i++) dp[i][0]=1;
    for(int i=1; i<A; i++)
    {
        for(int j=1; j<B; j++)
        {
            dp[i][j]=0;
            int k=j;
            while(j-k<=9 && k>=0)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                k--;
            }
        }
    }
    return dp[A-1][B-1];
}

int main()
{
    int n,s;
    cout<<"Enter the number of digits: ";
    cin>>n;
    cout<<"Enter the desired sum: ";
    cin>>s;
    int result=solve(n,s);
    cout<<"Result: "<<result<<endl;
    return 0;
}
