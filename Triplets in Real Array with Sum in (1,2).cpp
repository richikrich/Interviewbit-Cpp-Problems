#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

void tripletInRange(vector<string> &A)
{
	int countX=0, countY=0, countZ=0;
	float max1X=-FLT_MAX, max2X=-FLT_MAX, max3X=-FLT_MAX, max1Y=-FLT_MAX, max2Y=-FLT_MAX, max3Y=-FLT_MAX, max1Z=-FLT_MAX, max2Z=-FLT_MAX, max3Z=-FLT_MAX;
	float min1X=FLT_MAX, min2X=FLT_MAX, min3X=FLT_MAX, min1Y=FLT_MAX, min2Y=FLT_MAX, min3Y=FLT_MAX, min1Z=FLT_MAX, min2Z=FLT_MAX, min3Z=FLT_MAX;
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<A.size(); i++)
		{
			if(stof(A[i])>0 && stof(A[i])<(float) 2.0/3.0)
			{
				if(stof(A[i])>max1X) max1X=stof(A[i]);
				if(stof(A[i])<min1X) min1X=stof(A[i]);
				if(stof(A[i])<max1X && stof(A[i])>max2X) max2X=stof(A[i]);
				if(stof(A[i])>min1X && stof(A[i])<min2X) min2X=stof(A[i]);
				if(stof(A[i])<max2X && stof(A[i])>max3X) max3X=stof(A[i]);
				if(stof(A[i])>min2X && stof(A[i])<min3X) min3X=stof(A[i]);
				countX++;
			}
			if(stof(A[i])>=(float) 2.0/3.0 && stof(A[i])<=1)
			{
				if(stof(A[i])>max1Y) max1Y=stof(A[i]);
				if(stof(A[i])<min1Y) min1Y=stof(A[i]);
				if(stof(A[i])<max1Y && stof(A[i])>max2Y) max2Y=stof(A[i]);
				if(stof(A[i])>min1Y && stof(A[i])<min2Y) min2Y=stof(A[i]);
				if(stof(A[i])<max2Y && stof(A[i])>max3Y) max3Y=stof(A[i]);
				if(stof(A[i])>min2Y && stof(A[i])<min3Y) min3Y=stof(A[i]);
				countY++;
			}
			if(stof(A[i])>1 && stof(A[i])<2.0)
			{
				if(stof(A[i])>max1Z) max1Z=stof(A[i]);
				if(stof(A[i])<min1Z) min1Z=stof(A[i]);
				if(stof(A[i])<max1Z && stof(A[i])>max2Z) max2Z=stof(A[i]);
				if(stof(A[i])>min1Z && stof(A[i])<min2Z) min2Z=stof(A[i]);
				if(stof(A[i])<max2Z && stof(A[i])>max3Z) max3Z=stof(A[i]);
				if(stof(A[i])>min2Z && stof(A[i])<min3Z) min3Z=stof(A[i]);
				countZ++;
			}
		}
	}
	countX/=3; countY/=3;countZ/=3;
	if(countX>=3 && max1X+max2X+max3X>(float) 1) cout<<1<<endl;
    else if(countX>=2 && countY>=1 && max1X+max2X+max1Y<(float) 2 && min1X+min2X+min1Y>(float) 1) cout<<1<<endl;
    else if(countX>=1 && countY>=2 && min1X+min1Y+min2Y<(float) 2) cout<<1<<endl;
    else if(countX>=2 && countZ>=1 && min1X+min2X+min1Z<(float) 2) cout<<1<<endl;
    else if(countX>=1 && countY>=1 && countZ>=1 && min1X+min1Y+min1Z<(float) 2) cout<<1<<endl;
    else cout<<0<<endl;
	cout<<"=======================================STATS===============================\n";
	cout<<"In range (0,2/3): "<<"Max: "<<max1X<<" "<<max2X<<" "<<max3X<<" "<<"Min: "<<min1X<<" "<<min2X<<" "<<min3X<<" "<<"Count: "<<countX<<endl;
	cout<<"In range [2/3,1]: "<<"Max: "<<max1Y<<" "<<max2Y<<" "<<max3Y<<" "<<"Min: "<<min1Y<<" "<<min2Y<<" "<<min3Y<<" "<<"Count: "<<countY<<endl;
	cout<<"In range (1,2): "<<"Max: "<<max1Z<<" "<<max2Z<<" "<<max3Z<<" "<<"Min: "<<min1Z<<" "<<min2Z<<" "<<min3Z<<" "<<"Count: "<<countZ<<endl;
}

int main()
{
	cout<<"Enter the size of your vector: \n";
	int n; cin>>n;
	vector<string> vect; string temp;
	cout<<"Inputs: ";
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"The vector you entered is: \n";
	for(int i=0; i<vect.size(); i++)
	{
		cout<<vect[i]<<" ";
	}
	cout<<"\n";
	//cout<<"Result: ";
	/*int result=*/tripletInRange(vect);
	//cout<<result<<endl;
	return 0;
}

