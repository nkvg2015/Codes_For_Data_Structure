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

int min(struct node* root)
{
	if(root==NULL)
		return -1;
	while(root->left!=NULL)
		root=root->left;
	return root->data;
}
int max(struct node* root)
{
	if(root==NULL)
		return -1;
	else if(root->right==NULL)
		return root->data;
	max(root->right);
}

int main()
{
	struct node* root=NULL;
	root=Insert(root,60);
	root=Insert(root,20); 
	root=Insert(root,70);
	root=Insert(root,40);
	root=Insert(root,90);	
	root=Insert(root,190);
	root=Insert(root,85);
		
	cout<<"Minimum: "<<min(root)<<"\n";
	cout<<"Maximum: "<<max(root)<<"\n";
	
}
