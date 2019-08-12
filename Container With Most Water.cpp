#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int maxCap(vector<int> &A)
{
    if(A.size()==1) return 0;
    int j, max_cap=INT_MIN, cap, last_index=0;
    for(int i=0; i<A.size()-1;i++)
    {
        if(A[i]>last_index)
        {
            last_index=A[i];
            j=A.size()-1;
            if(A[j]>=A[i]) cap=A[i]*(j-i);
            else
            {
                cap=A[j]*(j-i);
                while(j>i)
                {
                    if(A[j]>=A[i])
                    {
                        cap=max(cap,A[i]*(j-i));
                        break;
                    }
                    else
                    {
                        cap=max(cap,A[j]*(j-i));
                        j--;
                    }
                }
            }
        }
        else continue;
        max_cap=max(max_cap,cap);
    }
    return max_cap;
}

int main()
{
    int n, temp;
    vector<int> vect;
    cout<<"Length of vector: "; cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>> temp;
        vect.push_back(temp);
    }
    cout<<"Vector you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" "; cout<<endl;
    //cout<<"Required difference: "; cin>>k;
    int result=maxCap(vect);
    cout<<"Result: "<<result<<endl;
    return 0;
}
