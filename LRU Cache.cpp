#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

map<int, int> myMap;
vector<int> keys; //stores the keys in order of their usage
int B;

LRUCache::LRUCache(int capacity) {
    myMap.clear();
    keys.clear();
    B=capacity;
}

int LRUCache::get(int key) {
    map<int, int>::iterator itr;
    vector<int>::iterator itr2;
    itr=myMap.find(key);
    if(itr==myMap.end()) return -1;
    else
    {
        itr2=find(keys.begin(), keys.end(), key);
        keys.erase(itr2);
        keys.push_back(key);
        //for(int i=0; i<keys.size(); i++) cout<<keys[i]<<" ";
        //cout<<endl;
        return itr->second;
    }
}

void LRUCache::set(int key, int value) {
    map<int, int>::iterator itr;
    vector<int>::iterator itr2;
    itr=myMap.find(key);
    if(itr==myMap.end())
    {
        myMap.insert({key,value});
        keys.push_back(key);
        B--;
        if(B<0)
        {
            myMap.erase(keys[0]);
            keys.erase(keys.begin());
            B++;
        }
        //for(int i=0; i<keys.size(); i++) cout<<keys[i]<<" ";
        //cout<<endl;
    }
    else
    {
        myMap[key]=value;
        itr2=find(keys.begin(), keys.end(), key);
        keys.erase(itr2);
        keys.push_back(key);
        //for(int i=0; i<keys.size(); i++) cout<<keys[i]<<" ";
        //cout<<endl;
    }
}
