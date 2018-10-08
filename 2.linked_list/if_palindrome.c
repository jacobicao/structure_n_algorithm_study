#include<stdio.h>
#include<stdlib.h>
#include<sys/malloc.h>
typedef struct Node
{
  char data;
  struct Node *next;
}node;

node* creat()
{
  node *head,*p,*q;
  head=(node*)malloc(sizeof(node));
  q=head;
  puts("Insert the word:");
  while(1)
  {
      char a; 
      scanf("%c",&a);
      if (a=='\n') 
        break;
      p=(node*)malloc(sizeof(node));
      p->data=a;
      q->next=p;
      q=p;
   }
   q->next=NULL;
   q=head->next;
   free(head);
   return(q);
}

void print(node *a)
{
  puts("print:");
  while(a!=NULL)
  {
    printf("%c ",a->data);
    a=a->next;
  }
  printf("\n");
}

node* reverseList(node *H)
{
  if (H==NULL || H->next==NULL) 
      return H;
  node *newHead=reverseList(H->next); 
  H->next->next=H;
  H->next=NULL;
  return newHead;
}

node* reverseList2(node* H)
{
  if (H==NULL || H->next==NULL) 
    return H;
  node* p=H, *newH=NULL;
  while (p!=NULL)
  {
    node *tmp=p->next;
    p->next=newH;
    newH=p;
    p=tmp;
  }
  return newH;
}

int if_palindrome(node *a)
{
  node *fast,*slow;
  fast=a;
  slow=a;
  while(fast!=NULL)
  {
    fast=fast->next;
    if(fast==NULL) 
      break;
    fast=fast->next;
    slow=slow->next;
  }
  fast=reverseList2(slow);
  while(a!=slow)
  {
    if (fast->data!=a->data)
      return 0;
    fast=fast->next;
    a=a->next;
  }
  
  return 1; 
}

int main(){
  node *a=NULL;
  a=creat();
  if (if_palindrome(a))
    printf("It is a palindrome.\n");
  else
    printf("It is not a palindrome.\n");
}
