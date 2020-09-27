#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void Solution::connect(TreeLinkNode* A) {
    map<int, vector<TreeLinkNode* >> myMap;
    int level=0;
    vector<TreeLinkNode* > temp;
    temp.push_back(A);
    temp.push_back(nullptr);
    myMap[level]=temp;
    temp.clear();
    level++;
    while(true)
    {
        for(int i=0; i<myMap[level-1].size()-1; i++)
        {
            if(myMap[level-1][i]->left) temp.push_back(myMap[level-1][i]->left);
            if(myMap[level-1][i]->right) temp.push_back(myMap[level-1][i]->right);
            myMap[level-1][i]->next=myMap[level-1][i+1];
        }
        if(temp.size()==0) break;
        else
        {
            temp.push_back(nullptr);
            myMap[level]=temp;
            level++;
            temp.clear();
        }
    }
}
