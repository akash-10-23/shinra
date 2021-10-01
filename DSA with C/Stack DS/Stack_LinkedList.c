#include<stdio.h>
#include<stdlib.h>
struct Node//creating the configuration of  a node
{
    int data;
    struct Node *next;
};
struct Node *head;
//****************************************************************************
void insertNode()//inserting node
{
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value for the element to be pushed\n");
scanf("%d",&new->data);
new->next=NULL;
if(head==NULL)
head=new;
else
{
 new->next=head;
  head=new;
}
}
//*******************************************************************************
void deleteNode()//deleting top of stack
{
struct Node *k;
if(head==NULL)
printf("Stack underflow!!\n");
else
{
 k=head;
head=head->next;
printf("%d is popped out!\n",k->data);
free(k);
}
}
//*********************************************************************************
void display()
{
 struct Node *temp;
 temp=head;
 if(head==NULL)
    printf("Stack is empty!!");
 else
 {
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->next;
 }
  }
}
//...........................................
int menu()
{
int choice;
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Peek\n");
printf("4.Delete stack\n");
printf("5.Displaying the stack\n");
printf("6.Exit!!\n");
printf("Enter the choice\n");
scanf("%d",&choice);
return(choice);
}
//***********************************************************************************
void main()
    {
         printf("\n*****************************************************\n");
        while(1)
     {
        switch(menu())
        {
           case 1:insertNode();
                  printf("\n*****************************************************\n");
                   break;
           case 2:deleteNode();
                  printf("\n*****************************************************\n");
                  break;
           case 3:printf("%d is at the top of the stack!!",head->data);
                  printf("\n*****************************************************\n");
                  break;
           case 4:printf("The stack is deleted!!");
                  head=NULL;
                  printf("\n*****************************************************\n");
                  break;
           case 5:display();
                  printf("\n*****************************************************\n");
                  break;
           case 6: printf("\n.........................EXIT...................................\n");
                   exit(0);
          default:printf("\nPlease enter the correct choice\n");
                  printf("\n*****************************************************\n");
            }
         }
       }
