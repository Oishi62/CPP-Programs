#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
  int *a,n;
	cout<<"Enter the size of the array";
	cin>>n;
	a=(int*) malloc(n*sizeof(int));
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
	cin>>*(a+i);
	cout<<"You entered:";
	for(int j=0;j<n;j++)
	cout<<*(a+j)<<"\n";
  return 0;
}
