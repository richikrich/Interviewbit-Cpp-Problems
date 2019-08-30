#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
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

string smallPref(TrieNode* root, string key)
{
    string ret;
    TrieNode* pCrawl=root;
    int index, count, j;
    stack<TrieNode* > nodes;

    for(int i=0; i<key.size(); i++)
    {
        index=key[i]-'a';
        nodes.push(pCrawl);
        pCrawl=pCrawl->character[index];
    }

    TrieNode* curr;
    while(!nodes.empty())
    {
        curr=nodes.top();
        //nodes.pop();
        count=0;
        j=0;
        while(j<26 && count<=1)
        {
            if(curr->character[j]) count++;
            j++;
        }
        if(count<=1)
        {
            nodes.pop();
            //prev=curr;
        }
        else break;
    }

    j=0;
    while(!nodes.empty() && j<key.size())
    {
        ret.push_back(key[j]);
        nodes.pop();
        j++;
    }
    return ret;
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode* root=getNode();
    string temp;
    vector<string> ret;
    for(int i=0; i<A.size(); i++)
    {
        insert(root,A[i]);
    }
    for(int i=0; i<A.size(); i++)
    {
        temp=smallPref(root,A[i]);
        ret.push_back(temp);
    }
    return ret;
}
