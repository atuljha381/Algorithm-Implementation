#include<iostream>
using namespace std;
int main()
{
	int i,j,count,size;
	cout<<"Enter size of array";
	cin>>size;
	int arr[size];
	int dup_arr[size];
	
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
		dup_arr[i]=-1;
	}
	
	for(i=0;i<size;i++)
	{
		count=1;
		for(j=i+1;j<size;j++)
		{
			if(arr[i]==arr[j]){
				count++;
				dup_arr[j]=0;
			}
		}

		if(dup_arr[i]!=0){
			dup_arr[i]=count;
		}
   } 
	
	for(i=0;i<size;i++)
	{
		if(dup_arr[i]!=0){
		cout<<arr[i]<<" Occurs "<<dup_arr[i]<<" times"<<endl;
	    }
	}

}
