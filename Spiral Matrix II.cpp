#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

vector<vector<int>> spiralMatrix(int n)
{
	vector<vector<int>> ret(n,vector<int>(n, 0));
	int x=1;
	int a=0, p=0; //starting row and starting column index
	int b=n-1, q=n-1;//ending row and ending column index;
	while(a<=b && p<=q)
	{
		for(int j=p; j<=q; j++)
		{
			ret[a][j]=x;
			x++;
		}
		a++;
		for(int i=a; i<=b; i++)
		{
			ret[i][q]=x;
			x++;
		}
		q--;
		for(int j=q; j>=p;j--)
		{
			ret[b][j]=x;
			x++;
		}
		b--;
		for(int i=b; i>=a; i--)
		{
			ret[i][p]=x;
			x++;
		}
		p++;
	}
	return ret; 
}

int main()
{
	cout<<"Enter your matrix size: \n";
	int n; cin>>n;
	vector<vector<int>> vect;
	/*vector<int> tempv;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter row: \n";
		for(int j=0; j<n; j++)
		{
			cin>>temp;
			tempv.push_back(temp);
		}
		vect.push_back(tempv);
		tempv.clear();
	}*/
	//cout<<"The matrix you entered is: \n";
	vect=spiralMatrix(n);
	cout<<"Your spiral matrix is: \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<vect[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	/*for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<" ";
	}*/
	cout<<"\n";
	return 0;
}
