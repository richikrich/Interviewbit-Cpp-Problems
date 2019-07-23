#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int squareRoot(int A)
{
    if(A==0 || A==1) return A;
    int start=1, last=A, ret;
    while(start<=last)
    {
        long long int mid=(start+last)/2;
        if((mid*mid)==A) return mid;
        else if ((mid*mid)>A) last=mid-1;
        else
        {
            start=mid+1;
            ret=mid;
        }
    }
    return ret;
}

int main()
{
    int n;
    cout<<"Enter your number: "; cin>>n;
    int result=squareRoot(n);
    cout<<"Result: "<<result<<endl;
}
