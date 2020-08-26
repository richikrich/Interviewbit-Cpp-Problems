int Solution::solve(int A) {
    vector<int> counts(A+1,0);
    int A_power, j, k, next, ret;
    A_power=(int) (log(A)/log(2));
    counts[1]=1; counts[2]=1; counts[3]=2;
    for(int i=2; i<=A_power; i++)
    {
        j=(int) pow(2,i);
        counts[j]=1;
        next=(int) pow(2,i+1);
        k=1;
        while(j+k<next && j+k<=A)
        {
            counts[j+k]=counts[j]+counts[k];
            k++;
        }
    }
    ret=0;
    for(int i=0; i<counts.size(); i++) ret+=counts[i];
    //cout<<endl;
    return ret;
}
