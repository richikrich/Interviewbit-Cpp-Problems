#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool areAnagram(string A, string B)
{

    if(A.size()!=B.size()) return false;
    int n=A.size();
    vector<int> countChars(26,0);
    int x,y;
    for(int i=0; i<n; i++)
    {
        x=(int) (A[i]-'a');
        y=(int) (B[i]-'a');
        //x-=97; y-=97;
        countChars[x]+=1;
        countChars[y]-=1;
    }
    for(int i=0; i<26; i++) if(countChars[i]!=0) return false;
    return true;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> ret; 
    vector<int> temp;
    int n=A.size();
    vector<bool> checked(n,false);
    for(int i=0; i<n; i++)
    {
        if(checked[i]==false)
        {
            temp.push_back(i+1);
            for(int j=i+1; j<n; j++)
            {
                if(areAnagram(A[i],A[j]))
                {
                    temp.push_back(j+1);
                    checked[j]=true;
                }
            }
            checked[i]=true;
            ret.push_back(temp);
            temp.clear();
        }
    }
     
    return ret;
    
}
