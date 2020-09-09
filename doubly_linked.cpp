#include<iostream>
using namespace std;
class Node
{
public:
	int data;
    Node *next;	
    Node *prev;
	void Push(Node **head_ref,int data){
		Node *new_node = new Node();
		new_node->data=data;
		new_node->next=*head_ref;
		new_node->prev=NULL;
		
		if((*head_ref)!=NULL){
			(*head_ref)->prev=new_node;
			
		}
		(*head_ref)=new_node;
	}
	void Printall(Node *node){
		Node *last;
		cout<<"Forward Traversal"<<endl;
		while(node!=NULL){
			cout<<node->data<<endl;
			last=node;
			node=node->next;
		}
		cout<<"Backward traversal"<<endl;
		while(last!=NULL){
			cout<<last->data<<endl;
			last=last->prev;
		}
	}
	void deletN(Node **head_ref,Node *del){
		if(*head_ref==NULL || del ==NULL){
			return;
		}
		if((*head_ref)==del){
			(*head_ref)=del->next;
		}
		if(del->next!=NULL){
			del->next->prev=del->prev;
		}
		if(del->prev){
			del->prev->next=del->next;
		}
		delete(del);
		
	}
};

int main()
{
	Node *head=NULL;
	Node obj;
	obj.Push(&head,1);
	obj.Push(&head,2);
	obj.Push(&head,3);
	obj.Push(&head,4);
	obj.Push(&head,5);
	obj.Push(&head,6);
	 
	cout<<"Before Deletion"<<endl;
    obj.Printall(head);
    
    
    obj.deletN(&head,head->next);
    
    cout<<"After Deletion"<<endl;
    obj.Printall(head);
	
	
	
}

