#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
}node;

/**
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第 n 个结点
 * 5) 求链表的中间结点
 *
 */

node* reverse(node **H)
{
    return NULL;
}
int hasCircle(node *H)
{
    return NULL;
}
node* mergeList(node *a, node *b)
{
    return NULL;
}
node* deleteLastKth(node **H, int k)
{
    return NULL;
}
node* midNode(node *H)
{
    return NULL;
}

/** 
 * 工具方法
 *
 */

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

/**
 * 测试方法
 *
 */

int test_reverse()
{
  printf("==== test_reverse ===\n");
  node *H = NULL;
  insertNode(&H,1);
  insertNode(&H,2);
  insertNode(&H,3);
  insertNode(&H,4);
  dump(H);
  H = reverse(&H);
  dump(H);
  return 0;
}

int test_hasCircle()
{
  printf("==== test_hasCircle ===\n");
  node *H = NULL;
  insertNode(&H,1);
  insertNode(&H,2);
  insertNode(&H,3);
  printf("Has circle: %d\n", hasCircle(H));
  node *l = malloc(sizeof(node));
  l->next = H;
  H->next->next->next = l;
  printf("Has circle: %d\n", hasCircle(H));
  return 0;
}

int test_mergeList()
{
  printf("==== test_mergeList ===\n");
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
  printf("==== test_deleteLastKth ===\n");
  node *H = NULL;
  insertNode(&H,9);
  insertNode(&H,5);
  insertNode(&H,3);
  insertNode(&H,8);
  insertNode(&H,4);
  dump(deleteLastKth(&H,2));
  return 0;
}

int test_midNode()
{
  printf("==== test_midNode ===\n");
  node *H = NULL;
  insertNode(&H,9);
  insertNode(&H,5);
  insertNode(&H,3);
  insertNode(&H,8);
  insertNode(&H,4);
  dump(midNode(&H));
  return 0;
}

/* 
 * 主函数 
 */

int main()
{
  test_reverse();
  test_hasCircle();
  test_mergeList();
  test_deleteLastKth();
  test_midNode();
  return 0;
}
