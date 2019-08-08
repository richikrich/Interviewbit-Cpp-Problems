#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

string zigzagString(string A, int k)
{
    string ret; int i=0;
    if(k==1) return A;
    //first row
    int odd=(2*k)-2, even=0;
    while(i<A.size()) {ret.push_back(A[i]);i+=((2*k)-2);}
    int j=1;
    //rest rows
    while(j<k-1)
    {
        odd-=2; even+=2;
        //cout<<j<<": "<<odd<<" "<<even<<endl;
        int a=j;
        while(a<A.size())
        {
            //cout<<a<<" ";
            ret.push_back(A[a]);
            if((a-j)%((2*k)-2)==0) a+=odd;
            else a+=even;
        }
        j++;
        //cout<<endl;
    }
    //other rows
    for(int j=k-1; j<A.size(); j+=((2*k)-2)) ret.push_back(A[j]);
    return ret;
}

int main()
{
    cout<<"Enter your string: "; string str; cin>>str;
    cout<<"The string you entered is: "<<str<<endl;
    cout<<"Enter no. of rows you want: "; int k; cin>>k;
    string result=zigzagString(str,k);
    cout<<"Result: "<<result;
    return 0;
}
