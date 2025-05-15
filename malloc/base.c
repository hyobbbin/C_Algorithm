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
