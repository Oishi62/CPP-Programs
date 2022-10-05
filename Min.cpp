#include<iostream>
using namespace std;
class Min
{
    public:
	void input(int h,int m,int s);	
};

void Min::input(int h,int m,int s)
{
	cout<<"\nTime in total seconds: "<<(h*60*60 + m*60 +s);
}
int main()
{
	Min ob;
	int h,m,s;
	cout<<"Enter time:\nHours? ";
	cin>>h;
	cout<<"Minutes? \n";
	cin>>m;
	cout<<"Seconds? \n";
	cin>>s;
	cout<<"The time is= ";
	if(h<=9)
	   cout<<"0"<<h<<":";
	else   
	   cout<<h<<":";
	if(m<=9)
	   cout<<"0"<<m<<":";
	else
	   cout<<m<<":";
	if(s<=9)
	   cout<<"0"<<s;
	else
	   cout<<s;
	   ob.input(h,m,s);   
	return 0;    
}
