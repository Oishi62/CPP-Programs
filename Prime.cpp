#include<iostream>
using namespace std;
int isprime(int);
int main()
{
	int n,d,flag=0;
	cout<<"Enter the number";
	cin>>n;
	for(int i=2;i<=n/2;i++)
	{
		d=n-i;
		
		if(isprime(i) && isprime(d))
		{
			cout<<n<<" ="<<i<<"+"<<d<<"\n";
			flag=1;
		}
	}
	if(flag==1)
	cout<<"The number can be expressed as the sum of two prime numbers";
	else
	cout<<"The number cannot be expressed as the sum of two prime numbers"; 
	return 0;
}
int isprime(int a)
{
	int c=0;
	for(int i=2;i<=a/2;i++)
	{
		if(a%i==0)
		{
			c=1;
			break;
		}
	}
	if(c==0)
	return 1;
	else
	return 0;
}
