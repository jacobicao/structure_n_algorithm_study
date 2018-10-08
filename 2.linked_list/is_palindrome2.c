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

int is_palindrome(node *H)
{
  if (H==NULL || H->next==NULL)
    return 1;
  node *pre=NULL,*fast=H,*slow=H;
  // find the middle node and reverse the left linked list
  while(fast!=NULL && fast->next!=NULL)
  {
    fast=fast->next->next;
    node *tmp=slow->next;
    slow->next=pre;
    pre=slow;
    slow=tmp;
  }
  // the case of odd number
  if (fast!=NULL)
    slow=slow->next;
  // diff two list
  while(slow!=NULL)
  {
    if(slow->data!=pre->data)
      return 0;
    slow=slow->next;
    pre=pre->next;
  }
  return 1;
}

int main()
{
  node *a=NULL;
  a=creat();
  if (is_palindrome(a))
    printf("It is a palindrome.\n");
  else
    printf("It is not a palindrome.\n");
}
