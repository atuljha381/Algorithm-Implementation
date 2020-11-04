#include<bits/stdc++.h>
using namespace std;
struct Item
{
	int value,weight;
	
	Item(int value,int weight): value(value), weight(weight)
	{}
};
bool comp(struct Item a,struct Item b)
{
	double self = (double)a.value/a.weight;
	double other = (double)b.value/b.weight;
	return self>other;
}

double fractional(int Capacity,struct Item arr[],int n)
{
	sort(arr,arr+n,comp);
	int currWeight = 0;
	double finalValue=0.0;
	
	for(int i=0;i<n;i++)
	{
		if(currWeight+arr[i].weight<=Capacity){
			currWeight+=arr[i].weight;
			finalValue+=arr[i].value;
		}
		else{
			int remain = Capacity-currWeight;
			finalValue+=arr[i].value*((double)remain/arr[i].weight);
			break;
		}
	}
	return finalValue;
}
int main()
{
	int Capacity=20;
	//Item arr[]={{70,20},{80,30},{90,40},{200,70}};
	Item arr[]={{3,10,15,5},{5,13,12,8}};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum value for knapsack"<<fractional(Capacity,arr,n)<<endl;
	return 0;
}
