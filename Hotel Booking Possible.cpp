#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std;

bool hotelBookingsPossible(vector<int> &arrival, vector<int> &departure, int k)
{
	int i=0, j=0, guestCount=0; bool ret=true;
	sort(arrival.begin(), arrival.end());
	sort(departure.begin(), departure.end());
	while(i<arrival.size() && j<departure.size())
	{
		if(arrival[i]<departure[j])
		{
			guestCount+=1;
			//cout<<guestCount<<endl;
			i++;
			if (guestCount>k)
			{
				ret=false;
				break;
			}
		}
		else
		{
			guestCount-=1; //Not adding the (if guestCount>k) condition here, as it will occur during increment itself and thus break loop there.
			//cout<<guestCount<<endl;
			j++;	
		}
	}
	/*while(i<arrival.size()) //No point in doing this because "i" is bound to reach limit before "j"
	{
		total.clear();
		guestCount++;
		i++;
	}*/
	/*while(j<departure.size()) //No point in doing this either as "guestCount" is only going to decrease now and hence if it were to cross the no. of rooms, it'd have done so already
	{
		guestCount-=1;
		cout<<guestCount<<endl;
		j++;	
	}*/
	return ret;
}

int main()
{
	cout<<"Enter the number of arrivals and departures: \n";
	int n; cin>>n;
	vector<int> arrival, departure; int temp1, temp2;
	for(int i=0; i<n; i++)
	{
		cout<<(i+1)<<". Enter arrival and departure time respectively: ";
		cin>>temp1; arrival.push_back(temp1);
		cin>>temp2; departure.push_back(temp2);
	}
	cout<<"\nArrival: ";
	for(int i=0; i<n; i++) {cout<<arrival[i]<<" ";}
	cout<<"\nDeparture: ";
	for(int i=0; i<n; i++) {cout<<departure[i]<<" ";}
	cout<<endl;
	cout<<"Enter no. of rooms: \n";
	int k; cin>>k;
	cout<<"Are guest bookings possible? \n";
	if(hotelBookingsPossible(arrival, departure, k)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 1;
}
