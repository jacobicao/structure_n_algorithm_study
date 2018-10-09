#include<stdio.h>
#include<stdlib.h>

/**
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第 n 个结点
 * 5) 求链表的中间结点
 *
 */

typedef struct Node
{
  int data;
  struct Node *next;
}node;

node* reverse(node **H)
{
  if (!*H) return NULL;
  node *cur=*H, *pre=NULL, *tmp=NULL;
  while(cur)
  {
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}

int hasCircle(node *H)
{
  if (!H) return 0;
  node *fast=H, *slow=H;
  while(fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast==slow)
      return 1;
  }
  return 0;
}

node* mergeList(node *a, node *b)
{
  if (!a) return b;
  if (!b) return a;
  node *H = NULL;
  if (a->data<b->data)
  {
    H = a;
    H->next = mergeList(a->next,b);
  } 
  else
  {
    H = b;
    H->next = mergeList(a,b->next);
  }
  return H;
}

node* deleteLastKth(node **H, int k);

node* midNode(node *H);

/** 工具方法 **/
void insertNode(node **H, int elem)
{
  node *n = malloc(sizeof(node));
  n->data = elem;
  n->next = *H;
  *H = n;
}

void dump(node *H)
{
  if (!H) return;
  printf("--- start ---\n");
  while(H)
  {
    printf("%d\n", H->data);
    H = H->next;
  }
  printf("--- end ---\n");
}

/** 测试方法 **/
int test_reverse()
{
  printf("==== test_reverse ===\n");
  node *H = NULL;
  insertNode(&H,1);
  insertNode(&H,2);
  insertNode(&H,3);
  dump(H);
  H = reverse(&H);
  dump(H);
  return 0;
}

int test_hasCircle()
{
  node *H = NULL;
  insertNode(&H,1);
  insertNode(&H,2);
  insertNode(&H,3);
  printf("Has circle: %d\n", hasCircle(H));
  node *l = malloc(sizeof(node));
  l->data = 0;
  l->next = H;
  H->next->next->next = l;
  printf("Has circle: %d\n", hasCircle(H));
  return 0;
}

int test_mergeList()
{
  node *H = NULL;
  insertNode(&H,9);
  insertNode(&H,5);
  insertNode(&H,3);
  node *K = NULL;
  insertNode(&K,8);
  insertNode(&K,4);
  dump(mergeList(H,K));
  return 0;
}

int test_deleteLastKth()
{

  return 0;
}

int test_midNode()
{

  return 0;
}

int main()
{
  test_reverse();
  test_hasCircle();
  test_mergeList();
  test_deleteLastKth();
  test_midNode();
  return 0;
}
