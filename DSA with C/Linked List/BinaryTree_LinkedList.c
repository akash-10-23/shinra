#include<stdio.h>
#include<stdlib.h>
struct Queue
{
     int data;
    struct Queue *next;
};
struct Queue *head;
struct Queue *tail;
//***********************************************
struct BinaryTreeNode
{
int data;
struct BinaryTreeNode *left,*right;
};
struct BinaryTreeNode *root;
//***************************************************

//***************************************************************
void Enqueue(struct BinaryTreeNode *x)//Enqueue
{
struct Queue *new;
new=(struct Queue*)malloc(sizeof(struct Queue));
new->data=(int)x;
new->next=NULL;
if(head==NULL)
{
head=new;
tail=new;
}
else
{
tail->next=new;
tail=new;
}
}
//****
int Dequeue()//Dequeue
{
struct Queue *k;
if(head==NULL)
printf("Queue underflow!!\n");
else
{
 k=head;
head=head->next;
printf("%d is dequeued!\n",k->data);
return(k->data);
}
}
//**********************************************************88
void LevelOrderTraversal(struct BinaryTreeNode *root)
{
struct BinaryTreeNode *temp;
if(root==NULL)
{
printf("Tree is Empty!!\n");
  return;
}
Enqueue(root);
temp=(struct BinaryTreeNode*)Dequeue();
while(temp!=NULL)
{
printf("%d",temp->data);
if(temp->left!=NULL)
Enqueue(temp->left);
if(temp->right!=NULL)
Enqueue(temp->right);
temp=(struct BinaryTreeNode*)Dequeue();
}
}
//**********************************************************
void insert()
{
struct BinaryTreeNode *new;
new=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
printf("Enter the value to be inserted\n");
scanf("%d",&new->data);
new->right=NULL;
new->left=NULL;
if(root==NULL)
root=new;
else
{
 LevelOrderTraversal(new);
}



}
//******************************************************************
int main()
{
    struct BinaryTreeNode *root;
    insert();
    LevelOrderTraversal(root);
     return 0;
}
//******************************************************************



