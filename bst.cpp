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

bool Search(struct node* root,int data)
{
	if(root==NULL)
		return 0;
	else if(root->data==data)
		return 1;
	else if(root->data>data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}

int main()
{
	struct node* root=NULL;
	root=Insert(root,10);
	root=Insert(root,20); 
	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,30);	
		
	int n;
	cout<<"Enter any number to search for: ";
	cin>>n;
	if(Search(root,n))
		cout<<"YES";
	else
		cout<<"NO";
	
}
