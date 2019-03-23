#include<iostream>
using namespace std;

struct node
{
int data;
struct node *left=NULL,*right=NULL;
};
struct node *root=NULL,*ptr=NULL;

void push(int num)
{
ptr=root;
struct node *par=NULL;
struct node *temp=new node;
temp->data=num;

if(ptr==NULL)
 root=temp;
else
{
 par=NULL;
 while(1)
 {
  par=ptr;
   if(num<par->data)
    {
     ptr=ptr->left;
      if(ptr==NULL)
       { par->left=temp; break; }
    }
   else
    {
     ptr=ptr->right;
      if(ptr==NULL)
       { par->right=temp; break; }
    }
 }
}  // else
}

int preorder(struct node *ptr)
{
 if(ptr==NULL)
  return 0;
 cout<<ptr->data<<" ";
 preorder(ptr->left);
 preorder(ptr->right);
}
int postorder(struct node *ptr)
{
 if(ptr==NULL)
  return 0;
 postorder(ptr->left);
 postorder(ptr->right);
 cout<<ptr->data<<" ";
}
int inorder(struct node *ptr)
{
 if(ptr==NULL)
  return 0;
 inorder(ptr->left);
 cout<<ptr->data<<" ";
 inorder(ptr->right);
}


int main()
{
int ch,num;
push(50);
push(40);
push(60);
push(10);
push(20);

do
{
 cout<<"\n\n";
 cout<<"1. Push"<<endl;
 cout<<"2. POP"<<endl;
 cout<<"3. Preorder"<<endl;
 cout<<"4. Postrder"<<endl;
 cout<<"5. Inoder"<<endl;
 cout<<"6. EXIT"<<endl;
 cout<<"Enter your choice: "<<endl;
  cin>>ch;
switch(ch)
{
 case 1:cout<<"Enter number to be pushed:"<<endl;
        cin>>num;
        push(num);
        break;
 case 2:break;
 case 3:preorder(root);
        break;
 case 4:postorder(root);
	break;
 case 5:inorder(root);
	break;
}
}while(ch!=6);

return 0;
}
