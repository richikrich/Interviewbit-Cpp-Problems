#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string A)
{
    vector<bool> counter(75,false); int ret=0, n=A.size(), index, max_ret=INT_MIN;
    for(int i=0; i<n; i++)
    {
        index=(int) A[i]-48;
        counter[index]=true;
        ret=1;
        for(int j=i+1; j<n; j++)
        {
            index=(int) A[j]-48;
            if(counter[index]) break;
            else
            {
                ret+=1;
                counter[index]=true;
            }
        }
        max_ret=max(ret,max_ret);
        fill(counter.begin(),counter.end(),false);
    }
    return max_ret;
}

int main()
{
    string str;
    cout<<"Enter your string: "; cin>>str;
    int result=lengthOfLongestSubstring(str);
    cout<<"Result: "<<result;
    return 0;
    //cout<<(int) '9';
}

