#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int Solution::minDistance(string A, string B) {
    vector<vector<int>> minD;
    vector<int> temp(B.size()+1,0);
    for(int i=0; i<=A.size(); i++) minD.push_back(temp);
    for(int i=0; i<=A.size(); i++)
    {
        for(int j=0; j<=B.size(); j++)
        {
            if(i==0) minD[i][j]=j; //first string is empty so inserting 'j' elements
            else if(j==0) minD[i][j]=i; //second string is empty, so deleting 'i' elements
            else
            {
                if(A[i-1]==B[j-1]) minD[i][j]=minD[i-1][j-1]; //no new operation required
                else minD[i][j]=1+min(min(minD[i][j-1], minD[i-1][j]),minD[i-1][j-1]);
                //1 is added to count a move and then minimum number of further required moves
                //is calculated. The three moves are respectively inserting, removal and changing
            }
        }
    }
    return minD[A.size()][B.size()];
}
