#include<iostream>
using namespace std;
int Power(int a,int b)
{
	int Res=1;
	while(b>0)
	{
		if(b%2!=0){
			Res=Res * a;
			b-=1;
		}
		else{
			b=b/2;
			a*=a;
		}	
	}
	return Res;
}
main()
{
	int x=2,y=8;
	cout<<Power(x,y);
}
