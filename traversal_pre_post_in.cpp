#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node* getNewNode(int item){
	struct node* temp=new node();
	temp->data=item;
	temp->left=temp->right=NULL;
	
	return temp;
}

struct node* Insert(struct node* root,int item){
	if(root==NULL)
		root=getNewNode(item);
	else if(item<root->data)
		root->left=Insert(root->left,item);
	else
		root->right=Insert(root->right,item);
	return root;
}

int Preorder(struct node* root)
{
	if(root==NULL)
		return 0;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

int Postorder(struct node* root)
{
	if(root==NULL)
		return 0;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}

int Inorder(struct node* root)
{
	if(root==NULL)
		return 0;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main()
{
	struct node* root=NULL;
	root=Insert(root,60);
	root=Insert(root,20); 
	root=Insert(root,70);
	root=Insert(root,40);
	root=Insert(root,90);	
		
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\nPostorder: ";
	Postorder(root);
	cout<<"\nInoredr: ";
	Inorder(root);
	
}
