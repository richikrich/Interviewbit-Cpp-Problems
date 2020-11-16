vector<int> Solution::lszero(vector<int> &A) {
    int n=A.size(), a, b, maxDist=INT_MIN, dist;
    vector<long long > cumSum(n+1, 0);
    for(int i=1; i<n+1; i++) cumSum[i]=cumSum[i-1]+A[i-1];
    map<long long, int> myMp;
    //two values of the cumSum array will be same if the elements between in A sum upto 0
    //the first zero takes care if sum of all elements from beginning is 0
    for(int i=0; i<n+1; i++)
    {
        if(myMp[cumSum[i]]>0)
        {
            dist=i-(myMp[cumSum[i]]-1);
            if(dist>maxDist)
            {
                maxDist=dist; b=i-1; a=myMp[cumSum[i]]-1;
            }
        }
        else myMp[cumSum[i]]=i+1;
    }
    
    vector<int> ret;
    if(maxDist<0) return ret;
    for(int i=a; i<=b; i++) ret.push_back(A[i]);
    return ret;
}
