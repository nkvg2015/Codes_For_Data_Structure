#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
	int data,height;
	Node* left;
	Node* right;
	Node* Insert(Node,int);	
	Node* deleteNode(Node,int);
};

int height(Node* root){
	if(root==NULL)
		return 0;
	return root->height;
}

int getBalance(Node* root){
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}

Node* rotateRight(Node* root){
	Node* newRoot=root->left;
	root->left=newRoot->right;
	newRoot->right=root;
	root->height=max(height(root->left),height(root->right))+1;
	newRoot->height=max(height(newRoot->left),height(newRoot->right))+1;
	
	return newRoot;
}

Node* rotateLeft(Node *root){
    Node *y =root->right;  
    Node *T2 = y->left;  
  
    y->left =root;  
    root->right = T2;  
  
    root->height = max(height(root->left),     
                    height(root->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}

class Node::Node* AVLInsert(Node* root,int data){
	if(root==NULL)
    	return new Node(data);
	else if(root->data > data)
		root->left=AVLInsert(root->left,data);
	else if(root->data <= data)
		root->right=AVLInsert(root->right,data);		
	else 
		return root;
	
	root->height=1+max(height(root->left),height(root->right));
	
	int balance=getBalance(root);
	
	if(balance>1){
		if(height(root->left->left) >= height(root->left->right))
			return rotateRight(root);
		else{
			root->left=rotateLeft(root->left);
			return rotateRight(root);
		}
	}
	
	if(balance<-1){
		if(height(root->right->right) >= height(root->right->left))
			return rotateLeft(root);
		else{
			root->right=rotateRight(root->right);
			return rotateLeft(root);
		}
	}
	
	root->height=1+max(height(root->left),height(root->right));
	
	return root;
}

Node* getSmallestElement(Node* root){
	while(root&&root->left!=NULL)
		root=root->left;
	return root;
}

class Node::Node* deleteNode(Node* root,int data){
	if(root==NULL)
		return NULL;
	else if(root->data > data)
		root->left=deleteNode(root,data);
	else if(root->data < data)
		root->right=deleteNode(root,data);
	else
	{
		if(root->right==NULL){
			Node* temp=root->left;
			delete root;
			return temp;	
		}
		else if(root->left==NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		Node* temp=getSmallestElement(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
	return root;
} 


void preOrder(Node *root)  {  
    if(root != NULL)  
    {  
        cout<<root->data<<" "<<root->height<<"\n";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

int main(){
	Node* root=NULL;
	root=AVLInsert(root,10);
	root=AVLInsert(root,20);
	root=AVLInsert(root,30);
	root=AVLInsert(root,40);
	root=AVLInsert(root,50);
	root=AVLInsert(root,25);	
	
//	deleteNode(root,30);
	preOrder(root);
		
}
