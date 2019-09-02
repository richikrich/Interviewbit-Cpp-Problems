#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int climbStairs(int A) {
    if(A<=1) return 1;
    else return climbStairs(A-1)+climbStairs(A-2);
}

int main()
{
    cout<<"Enter the number of stairs: ";
    int n; cin>>n;
    int result=climbStairs(n);
    cout<<endl<<"Result: "<<result;
    return 0;
}
