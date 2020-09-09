#include<iostream>
using namespace std;
int Power(int a,int b)
{
	int result=1;
	if(b==0){
		return 1;
	}
	result = Power(a,b/2);
	if(b%2==0){
		return (result*result);
	}
	else{
		return (a*result*result);
	}

}
main()
{
	int a=2,b=8;
	cout<<Power(a,b);
}
