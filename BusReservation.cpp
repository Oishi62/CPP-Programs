#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
using namespace std;
static int p=0;

class BusReservation
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}

bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i++)
	cout<<ch;
}
void BusReservation::install()
{
	cout<<"Enter bus number: ";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\nArrival Time: ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture: ";
	cin>>bus[p].depart;
	cout<<"\nFrom: \t\t";
	cin>>bus[p].from;
	cout<<"\nTo: \t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void BusReservation::allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"Bus number: ";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nSeat Number ";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in this bus. ";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
				{
					cout<<"Enter passange's name ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
				else
				cout<<"The seat number is already booked, \n";
			}
		}
		if(n>p)
		{
			cout<<"Enter correct bus number. \n";
			goto top;
		}
}
void BusReservation::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}    
void BusReservation::show()
{
	int n;
	char number[5];
	cout<<"Enter bus number.\n";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"Bus number:\t"<<bus[n].busn
		<<"\nDriver:\t"<<bus[n].driver<<"\tArrival time:\t"
		<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
		<<"\nFrom:\t"<<bus[n].from<<"\tto:\t"<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
		    {
		    	a++;
		    	if(strcmp(bus[n].seat[i][j],"Empty")!=0)
		    	cout<<"\nThe seat number "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>=p)
	cout<<"Enter correct bus number: ";
}
void BusReservation::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				
				
				cout<<s<<".";
				
				cout<<bus[l].seat[i][j];
				p++;
			}
			else
			{
			    
				cout<<s<<".";
				
				cout<<bus[l].seat[i][j];
	
			}
		}
	}
	cout<<"\n There are "<<p<<" seats empty in Bus number "<<bus[l].busn;
}
void BusReservation::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus number:\t"<<bus[n].busn
		<<"\nDriver:\t"<<bus[n].driver<<"\tArrival time:\t"
		<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
		<<"\nFrom:\t"<<bus[n].from<<"\tto:\t"<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<"\n\n\n";
		cout<<"\t\t1.Install\n\t\t"
		<<"2.Reservation\n\t\t"
		<<"3.Show\n\t\t"
		<<"4.Buses available.\n\t\t"
		<<"5.Exit";
		cout<<"\n\t\tEnter your choice\n";
		cin>>w;
		switch(w)
		{
			case 1:
				bus[p].install();
				break;
			case 2:
			    bus[p].allotment();
				break;
			case 3:
			    bus[0].show();
				break;
			case 4:
			    bus[0].avail();
				break;
			case 5:
				exit(0);
						
		}
	}
	return 0;
}
