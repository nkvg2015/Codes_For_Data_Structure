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

struct node* minValueNode(struct node* node) 
{ 
    struct node* current=node; 
    while(current&&current->left!=NULL) 
        current=current->left; 
    return current; 
}

struct node* DeleteNode(struct node* root,int item)
{
	if(root==NULL)
		return root;
	else if(root->data>item)
		root->left=DeleteNode(root->left,item);
	else if(root->data<item)
		root->right=DeleteNode(root->right,item);
	else
	{
		if(root->left==NULL){              // node with only right child
			struct node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)        // node with only left child
		{
			struct node* temp=root->left;
			delete root;
			return temp;
		}
		struct node* temp=minValueNode(root->right); // inoreder successor-smallest in right tree
		root->data=temp->data;                            
		root->right=DeleteNode(root->right,temp->data);   // deleting placed node
	}
	return root;
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
	
	root=Insert(root,50);
	root=Insert(root,30); 
	root=Insert(root,20);
	root=Insert(root,40);
	root=Insert(root,70);	
	root=Insert(root,60);
	root=Insert(root,80);
		
	Inorder(root);
	root=DeleteNode(root,0);
	cout<<"\nAfter Deletion:\n";
	Inorder(root);
}
