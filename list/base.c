//자기 참조 구조체(self-referential structure)
typedef struct NODE{
  int data;
  struct NODE *link;
}NODE;
-------------------------------------------------------------------------------------------------

NODE* p1;
p1 = (NODE *)malloc(sizeof(NODE));

p1 -> data = 10;
p1 -> link = NULL;

NODE *p2;
p2 = (NODE *)malloc(sizeof(NODE));

p2 -> data = 20;
p2 -> link = NULL;
p1 -> link = p2;

free(p1);
free(p2);

-------------------------------------------------------------------------------------------------
//연결 리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
  int data;
  struct listNode *next;
}listNode;

int main(){
  listNode *first = NULL;
  listNode *second;

  first = (listNode *)malloc(sizeof(listNode));
  first -> data = 10;
  first -> next = NULL;

  second = (listNode *)malloc(sizeof(listNode));
  second -> data = 20;
  second -> next = NULL;
  first -> next = second;

  printf("%d %d", first->data, first->next->data);
  return 0;
}

-------------------------------------------------------------------------------------------------
//이중 연결 리스트

