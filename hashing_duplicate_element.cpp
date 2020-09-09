#include<iostream>
using namespace std;
int main()
{
	int i,j,size,count;
	cout<<"Enter size: ";
	cin>>size;
	int arr[size];
	
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	for(i=1;i<size;i++)
	{
		if(arr[0]<arr[i]){
			arr[0]=arr[i];
		}
	}
	cout<<arr[0];
	
}
