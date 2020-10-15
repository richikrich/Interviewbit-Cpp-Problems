#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int uniquePaths(vector<vector<int> > &A, vector<vector<int> > &paths, int  row, int column)
{
    if(paths[row][column]!=-1) return paths[row][column];
    int ans=0;
    if(row>0 && column>0) ans+=(uniquePaths(A,paths,row-1,column)+uniquePaths(A,paths,row,column-1));
    else if(row==0) ans+=uniquePaths(A,paths,row,column-1);
    else if(column==0) ans+=uniquePaths(A,paths,row-1,column);

    paths[row][column]=ans;
    return paths[row][column];
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int rows=A.size(), columns=A[0].size(); bool flag=true;
    if(rows==0 || columns==0) return 0;
    vector<vector<int> > paths; vector<int > temp(columns,-1);
    for(int i=0; i<rows; i++) paths.push_back(temp);
    //fill first row
    for(int i=0; i<columns; i++)
    {
        if(A[0][i]==0 && flag) paths[0][i]=1;
        else
        {
            paths[0][i]=0;
            flag=false;
        }
    }
    //fill first column
    flag=true;
    for(int i=0; i<rows; i++)
    {
        if(A[i][0]==0 && flag) paths[i][0]=1;
        else
        {
            paths[i][0]=0;
            flag=false;
        }
    }
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(A[i][j]==1) paths[i][j]=0;
        }
    }

    int ret=uniquePaths(A,paths,rows-1, columns-1);
    return ret;
}
