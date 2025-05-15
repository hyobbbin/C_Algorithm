//링크 표현법
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int key;
  struct node *leftChild, *rightChild;
}treeNode;

treeNode *makeBTreeNode(int key){
  treeNode *ptr = (treeNode *)malloc(sizeof(treeNode));
  ptr -> key = key;
  ptr -> leftChild = ptr -> rightChild = NULL;
  return ptr;
}

int main(void){
  treeNode *bt1 = makeBTreeNode(1);
  treeNode *bt2 = makeBTreeNode(2);
  treeNode *bt3 = makeBTreeNode(3);
  treeNode *bt4 = makeBTreeNode(4);

  bt1 -> leftChild = bt2;
  bt1 -> rightChild = bt3;
  bt2 -> leftChild = bt4;

  printf("%d", bt1->leftChild->leftChild->key);

  return 0; 
}
