#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool areAnagram(string &A, string &B)
{
    //int n;
    if(A.size()!=B.size()) return false;
    int n=A.size();
    //int x=0;
    vector<int> countChars(26,0);
    int x,y;
    //cout<<(int) A[0];
    for(int i=0; i<n; i++)
    {
        x=(int) A[i];
        y=(int) B[i];
        x-=97; y-=97;
        //cout<<x<<" "<<y<<endl;
        countChars[x]+=1;
        countChars[y]-=1;
    }
    for(int i=0; i<26; i++) if(countChars[i]!=0) return false;
    return true;
}

vector<vector<int>> anagrams(vector<string> &A)
{
    vector<vector<int>> ret; vector<int> temp;
    int n=A.size();

    vector<bool> done(n,false);
    for(int i=0; i<n; i++)
    {
        if(done[i]==false)
        {
            temp.push_back(i+1);
            for(int j=i+1; j<n; j++)
            {
                if(areAnagram(A[i],A[j]))
                {
                    temp.push_back(j+1);
                    done[j]=true;
                }
            }
            done[i]=true;
            ret.push_back(temp);
            temp.clear();
        }
        else continue;
    }
    //cout<<"fffff"<<endl;
    return ret;
}

int main()
{
   vector<string> vect; string temp; int n;
   cout<<"Enter your vector size: "; cin>>n;
   cout<<"Enter the strings: ";
   for(int i=0; i<n; i++)
   {
       cin>>temp; vect.push_back(temp);
   }
   cout<<"The strings you entered are: ";
   for(int i=0; i<n; i++) cout<<vect[i]<<" ";
   vector<vector<int>> result;
   result=anagrams(vect);
   cout<<"Result: "<<endl;
   for(int i=0; i<result.size(); i++)
   {
       for(int j=0; j<result[i].size(); j++)
       {
           cout<<result[i][j]<<" ";
       }
       cout<<endl;
   }
   //cout<<endl<<"Result: "<<areAnagram(vect[0],vect[1]);
   return 0;
}

