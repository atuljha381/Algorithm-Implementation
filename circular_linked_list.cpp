#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};
void printall(Node *head)
{
	Node *temp=head;
	if(head!=NULL){
		do{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		while(temp!=head);
	}
}
void Insert(Node **head_ref,int data)
{
	Node *ptr=new Node();
	Node *temp= *head_ref;
	ptr->data=data;
	ptr->next=*head_ref;
	
	if(*head_ref!=NULL){
		while(temp->next != *head_ref){
			temp=temp->next;	
		}	
		temp->next=ptr;
	}
	else{
		ptr->next=ptr;
	}
	*head_ref=ptr;
}



int main()
{
	Node *head=NULL;
	
	Insert(&head,7);
	Insert(&head,1);
	Insert(&head,2);
	Insert(&head,5);
	
	
	cout<<"Contents of circular linked list"<<endl;
	printall(head);
}
