#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int sameLine(vector<int> &A, vector<int> &B)
{
    int n=A.size(), x_slope=0, y_slope=0, curr_max, global_max=INT_MIN,gcd, overlapping_points;
    if(n<=2) return n;
    map<pair<int,int>, int> slopes;
    //slopes[{x_slope,y_slope}];
    for(int i=0; i<n-1; i++)
    {
        overlapping_points=1;
        curr_max=0;
        for(int j=i+1; j<n; j++)
        {
            x_slope=A[j]-A[i];
            y_slope=B[j]-B[i];
            if(x_slope==0 && y_slope!=0)
            {
                slopes[{0,-1}]+=1;
                curr_max=max(curr_max,slopes[{0,-1}]);
            }
            else if(y_slope==0 && x_slope!=0)
            {
                slopes[{-1,0}]+=1;
                curr_max=max(curr_max,slopes[{-1,0}]);
            }
            else if(x_slope==0 && y_slope==0)
            {
                overlapping_points++;
            }
            else
            {
                gcd=__gcd(x_slope,y_slope);
                if(gcd!=0)
                {
                    x_slope/=gcd;
                    y_slope/=gcd;
                }
                slopes[{x_slope,y_slope}]++;
                curr_max=max(curr_max,slopes[{x_slope,y_slope}]);
            }
        }
        //curr_max=(*max_element(slopes.begin(),slopes.end()));
        curr_max+=overlapping_points;
        global_max=max(global_max,curr_max);
        slopes.clear();
    }
    return global_max;
}

int main()
{
    int n;
    cout<<"Size of your array: "; cin>>n;
    vector<int> X,Y;
    int temp;
    cout<<"Inputs: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        X.push_back(temp);
        cin>>temp;
        Y.push_back(temp);
    }
    cout<<"The vector you entered is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"("<<X[i]<<","<<Y[i]<<")"<<endl;
    }
    int result=sameLine(X,Y);
    cout<<"Result: "<<result<<endl;
    return 0;
}

