#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *left,*right;
	
	Node(int data){
		this->left=this->right= NULL;
	}
};
int max(int a,int b){
	return (a>b)?a:b;
}
int height(Node *node){
	if(node==NULL)
		return 0;
		
	return 1+max(height(node->left),height(node->right));
	
}
int diameter(Node *tree){
	if(tree==NULL)
		return 0;
		
	int lheight=height(tree->left);
	int rheight=height(tree->right);
	
	int ldiameter=diameter(tree->left);
	int rdiameter=diameter(tree->right);
	
	return max(lheight+rheight+1,max(ldiameter, rdiameter));
}

int main()
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	
	cout<<"Diameter of root is: "<<diameter(root)<<endl;
	cout<<"Height of root is: "<<height(root)<<endl;
	
	return 0;
}

