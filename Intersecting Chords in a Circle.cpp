/**
Intersecting Chords in a Circle:

Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.
Return the answer modulo 10^9 + 7.
**/



#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

/**#define div 1000000007;**/

using namespace std;

vector<long long int> Dp(1000,0);

int chordCnt(int A)
{
    Dp[0]=1; Dp[1]=1; Dp[2]=2; ///base cases
    if(Dp[A]!=0) return (Dp[A]%1000000007);
    else
    {
        for(int i=3; i<=A; i++)
        {
            Dp[i]=0;
            for(int j=0; j<i; j++)
            {
                /**Every chord we make can divide the circle into two regions. If we join two points across these regions, that chord is sure to intersect our previous chord
                 **So, we are basically diving the region into two parts of (i) and (A-i) chords each, which must be non-intersecting for success of our problem.
                 **Thus we have divided the problem into two sub-problems.**/
                Dp[i] = ((Dp[i]+(Dp[j]*Dp[i-j-1]))%1000000007);
            }
        }
        return (Dp[A]%1000000007);
    }

}

int main()
{
    int n;
    cout<<"Enter the number of chords you want: "; cin>>n;
    cout<<"The number you entered is: "<<n<<endl;
    cout<<"Result: "<<chordCnt(n);
}
