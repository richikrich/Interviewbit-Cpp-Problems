#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

bool isValid(vector<string> board, int row, int col)
{
    int n=board[0].size();
    //check the row to it's left
    for(int i=0; i<col; i++)
    {
        if(board[row][i]=='Q') return false;
    }
    //top left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j]=='Q') return false;
    }
    //bottom left diagonal
    for(int i=row, j=col; i<n && j>=0; i++, j--)
    {
        if(board[i][j]=='Q') return false;
    }
    return true;
}

bool backtracking(vector<vector<string>> &ret, vector<string> &board, int col, int n)
{
    if(col>=n)
    {
        ret.push_back(board);
        return true;
    }
    for(int i=0; i<n; i++)
    {
        if(isValid(board,i,col))
        {
            board[i][col]='Q';
            backtracking(ret,board,col+1,n);
            board[i][col]='.';
        }
    }
    return false;
}

vector<vector<string>> solveNQueens(int A)
{
    vector<vector<string>> ret;
    vector<string> board;
    string row(A,'.');
    for(int i=0; i<A; i++)
    {
        board.push_back(row);
    }
    backtracking(ret,board,0,A);
    return ret;
}


int main()
{
    int n;
    cout<<"Enter the size of your board: "; cin>>n;
    cout<<"The number you entered is: "<<n<<endl;
    vector<vector<string>> result=solveNQueens(n);
    cout<<"Results: ";
    for(int i=0; i<result.size(); i++)
    {
        cout<<i<<"."<<endl;
        for(int j=0; j<result[i].size(); j++)
        {
            cout<<result[i][j]<<endl;
        }
    }
}
