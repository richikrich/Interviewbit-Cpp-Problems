#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int isInList(string A, vector<string> &B, int index, int word_length)
{
    int j;
    if(A.size()-index<word_length) return -1;
    for(int i=0; i<B.size(); i++)
    {
        if(A[index]==B[i][0])
        {
            if(word_length<=1) return i;
            else{
            j=1;
            while(j<word_length && A[index+j]==B[i][j])
            {
                j++;
            }
            if(j==word_length) return i;}
        }
    }
    return -1;
}

vector<int> findSubstring(string A, vector<string> &B) {
    vector<int> ret;
    map<string,int> counted, counted_cpy;
    for(int i=0; i<B.size(); i++) counted[B[i]]++;
    counted_cpy=counted;

    int i=0, count=0, index=-1, word_length=B[0].size(), x;
    while(i<A.size())
    {
        x=isInList(A,B,i,word_length);
        //cout<<counted_cpy[B[x]]<<endl;
        if(x!=-1)
        {
            if(counted_cpy[B[x]]!=0)
            {
                count++;
                if(index==-1) index=i;
                counted_cpy[B[x]]--;
                i+=word_length;
            }
            else
            {
                if(count==B.size()) ret.push_back(index);
                counted_cpy=counted;
                i=index+1;
                count=0; index=-1;
            }
        }
        else
        {
            if(count==B.size()) ret.push_back(index);
            counted_cpy=counted;
            if(index!=-1) i=index+1;
            else i+=1;
            count=0; index=-1;
        }
    }
    if(count==B.size())
    {
        if(ret.size()==0 || ret[-1]!=index) ret.push_back(index);
    }
    //cout<<ret.size()<<endl;
    return ret;
}


int main()
{
    string S, temp;
    vector<string> L;
    int n;
    cout<<"Enter the main string in which to search: "; cin>>S;
    cout<<"Enter the size of your list of words: "; cin>>n;
    cout<<"Enter the list: \n";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        L.push_back(temp);
    }
    cout<<"Your string is:\n"<<S<<endl;
    cout<<"Your list of words are: \n";
    for(int i=0; i<n; i++) cout<<L[i]<<" ";
    cout<<endl;
    /**/
    vector<int> results;
    results=findSubstring(S,L);
    cout<<"Result: ";
    for(int i=0; i<results.size();i++) cout<<results[i]<<" ";
    cout<<endl;
    /**/
    return 0;
}
