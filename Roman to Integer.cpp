#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int romanInt(string A)
{
    int ret=0, i=A.size()-1;
    while(i>=0)
    {
        if(A[i]=='I')
        {
            ret+=1;
            i--;
        }
        if(A[i]=='V')
        {
            ret+=5;
            i--;
            if(A[i]=='I')
            {
                ret-=1; i--;
            }
        }
        if(A[i]=='X')
        {
            ret+=10;
            i--;
            if(A[i]=='I')
            {
                ret-=1; i--;
            }
        }
        if(A[i]=='L')
        {
            ret+=50;
            i--;
            if(A[i]=='X')
            {
                ret-=10; i--;
            }
        }
        if(A[i]=='C')
        {
            ret+=100;
            i--;
            if(A[i]=='X')
            {
                ret-=10; i--;
            }
        }
        if(A[i]=='D')
        {
            ret+=500;
            i--;
            if(A[i]=='C')
            {
                ret-=100; i--;
            }
        }
        if(A[i]=='M')
        {
            ret+=1000;
            i--;
            if(A[i]=='C')
            {
                ret-=100; i--;
            }
        }
    }
    return ret;
}

int main()
{
    cout<<"Enter your string: "; string str; cin>>str;
    cout<<"The string you entered is: "<<str<<endl;
    int result=romanInt(str);
    cout<<"Result: "<<result;
    return 0;
}
