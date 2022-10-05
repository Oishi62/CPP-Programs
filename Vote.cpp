#include <iostream>
using namespace std;

int main()
{
  int a;
	cout<<"Enter your age";
	cin>>a;
	if(a>=18)
	cout<<"You are eligible to vote";
	else
	cout<<"Sorry, you are not eligible to vote you will be able to after "<<(18-a)<<" years";
  return 0;
}
