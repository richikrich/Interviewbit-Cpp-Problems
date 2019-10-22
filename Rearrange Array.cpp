#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

void arrange(vector<int> &A) {
    /*The basic idea here is:
                            int(a+(b*n))/n=(0+b)=(b); since, a,b<n
    **For values that have been incremented already, doing a modulus by n will give:
                            (a+(b*n))%n=(a%n)+((b*n)%n)=(a+0)=a;
    */
    int n=A.size();
    for(int i=0; i<n; i++)
    {
        //A[i]+=A[A[i]]*n;  //This will not work since for previously increased values just
                            //by n will not yield the desired output
        A[i]+=(A[A[i]]%n)*n;//The mod by n will ensure we get a value that has been multiplied
                            //by n only once
    }
    for(int i=0; i<n; i++)
    {
        A[i]/=n;
    }
}

int main()
{
    vector<int> vect; int n, temp;
    cout<<"Enter the size of your matrix: "; cin>>n;
    cout<<"Enter n values in the range of 0 to n-1: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    arrange(vect);
    cout<<"Result: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
    return 0;
}

