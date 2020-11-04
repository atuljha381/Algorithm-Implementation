#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *left,*right,*parent;
		Node(int data){
			this->left=this->right= NULL;
		}
};
Node *minValue(Node *node){
	Node *current= node;
	
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}
Node *inOrder(Node *root,Node *node){
	if(node->right!=NULL){
		return minValue(node->right);
	}
	Node *imp= node->parent;
	
	while(imp!=NULL && node==imp->right){
		node=imp;
		imp=imp->parent;
	}
	return imp;
}

Node *insert(Node *root,int data){
	if(!root)
		return new Node(data);
	
	if(data>root->data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
		
	return root;
}
int main()
{
	Node *root=NULL,*temp,*min,*successor;
	root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
    temp=root->left->right->right;
    
    if(successor!=NULL){
    	cout<<"Inorder successor of "<<temp->data<<" is "<<successor->data<<endl;
	}
	else{
		cout<<"Successor doesn't exist"<<endl;
	}
    
    
	
}
