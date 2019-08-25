#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct TrieNode //defining a trie node
{
  TrieNode* character[26];
  bool isEndofWord;
};

TrieNode* getNode()
{
    TrieNode* newNode=new TrieNode();
    newNode->isEndofWord=false;
    for(int i=0; i<26; i++) newNode->character[i]=nullptr;
    return newNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* pCrawl=root;
    int index;
    for(int i=0; i<key.size(); i++)
    {
        index=key[i]-'a';
        if(!pCrawl->character[index])
            pCrawl->character[index]=getNode();
        pCrawl=pCrawl->character[index];
    }
    pCrawl->isEndofWord=true;
}

bool search(TrieNode* root, string key)
{
    TrieNode* pCrawl=root;
    int index;
    for(int i=0; i<key.size(); i++)
    {
        index=key[i]-'a';
        if(!pCrawl->character[index]) return false;
        else pCrawl=pCrawl->character[index];
    }
    if(!pCrawl) return false;
    else
    {
        if(pCrawl->isEndofWord) return true;
    }
}

void converToSpaces(string& A)
{
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]=='_') A[i]=' ';
    }
    //stringstream ss;
    //ss.clear();
    //ss<<B;
}

bool customCompare(const vector<int> &A, const vector<int> &B) //for such custom comparison functions, always use const vector;
{
    if(A[1]==B[1]) return A[0]<B[0];
    else return A[1]>B[1];
}

vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode* root=getNode();
    vector<vector<int>> vect;
    vector<int> ret;
    converToSpaces(A);
    string word;
    stringstream ss;
    ss<<A;
    while(ss>>word) insert(root, word);
    int count;
    for(int i=0; i<B.size(); i++)
    {
        count=0;
        ss.clear();
        converToSpaces(B[i]);
        ss<<B[i];
        while(ss>>word)
        {
            if(search(root,word)) count+=1;
        }
        ret.push_back(i); ret.push_back(count);
        vect.push_back(ret); ret.clear();
    }
    sort(vect.begin(),vect.end(),customCompare);
    for(int i=0;i<vect.size();i++) ret.push_back(vect[i][0]);
    return ret;
}
