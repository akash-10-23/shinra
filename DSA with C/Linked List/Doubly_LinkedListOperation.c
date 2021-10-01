/*Question done in Lab*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node *next;
 struct Node *prev;
};
struct Node *head=NULL;
void create()//function for creating a node
{
struct Node *ptr,*current;
char ch;
current=NULL;
ptr->next=NULL;
ptr->prev=NULL;
do
{
 ptr=(struct Node*)malloc(sizeof(struct Node));
 printf("Enter the data for the node\n");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr->prev=NULL;
  if(head==NULL)
  {
   head=ptr;
   current=ptr;
  }
  else
  {
   current->next=ptr;
   ptr->prev=current;
   current=ptr;
  }
  printf("Want to create more node Y or N\n");
  fflush(stdin);
  scanf("%c",&ch);
 }
 while(ch=='Y'||ch=='y');
 printf("The Linked List is created!!\n");
}
//........................................
void count()
{
  struct Node *temp,*first;
  first=head;
  temp=head;
  int ctr=0;
  while(temp!=NULL)
    {
        if(first->data==temp->data)
        { ctr++;}
        temp=temp->next;
      if(temp==NULL)
      {
     printf("No of %d in node = %d\n",first->data,ctr);
          temp=head;
        first=first->next;
        ctr=0;}
        if(first==NULL)
        {break;}
    }
}
//.......................................................................
void deleteAtIndex()
{
    int n;
    printf("Enter which node is to be deleted\n");
    scanf("%d",&n);
 struct Node *temp,*k,*l;
 temp=head;
 int ctr=1;
 while(ctr<=n)
 {
    if(ctr==n)
    {
         k=temp->prev;
         l=temp->next;
       k->next=l;
       l->prev=k;
        free(temp);
           }
    temp=temp->next;
    ctr++;
    }
 }
//.....................................................................
void display()
{
 struct Node *temp;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d ",temp->data);
  temp=temp->next;
 }
 printf("\n");
}
//...........................................
int menu()
{
int choice;
printf("1.counting each element\n");
printf("2.Deleting the particular element other than head or tail of the node\n");
printf("3.Displaying the linked list\n");
printf("4.Exit!!\n");
printf("Enter the choice\n");
scanf("%d",&choice);
return(choice);
}
//***********************************************************************************
void main()
    {
        printf("Create the linked list\n");
        create();
         printf("\n*****************************************************\n");
        while(1)
     {
        switch(menu())
        {
           case 1:count();
                  printf("\n*****************************************************\n");
                   break;
           case 2:deleteAtIndex();
                  printf("\n*****************************************************\n");
                  break;
           case 3:display();
                  printf("\n*****************************************************\n");
                  break;
           case 4: printf("\n.........................EXIT...................................\n");
                   exit(0);
          default:printf("\nPlease enter the correct choice\n");
                  printf("\n*****************************************************\n");
            }
         }
       }



