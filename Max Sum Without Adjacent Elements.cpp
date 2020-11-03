int Solution::adjacent(vector<vector<int> > &A) {
    vector<vector<int> > DP; vector<int> temp(A[0].size()+1,0);
    for(int i=0; i<2; i++) DP.push_back(temp);
    DP[0][1]=A[0][0]; DP[1][1]=max(A[0][0],A[1][0]);
    for(int i=2; i<=A[0].size(); i++)
    {
        DP[0][i]=max(A[0][i-1]+DP[1][i-2], DP[1][i-1]); //bottom-up knapsack approach, taking 
        DP[1][i]=max(A[1][i-1]+DP[1][i-2], DP[0][i]); //maximum of the cases where we include and exclude the elements
    }
    /*for(int i=0; i<DP.size(); i++)
    {
        for(int j=0; j<DP[i].size(); j++) cout<<DP[i][j]<<" ";
        cout<<endl;
    }*/
    return DP[1][A[0].size()];
}
