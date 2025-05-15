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

//전위순회 1.루트 노드 방문 2. 왼쪽 서브트리 방문 3. 오른쪽 서브트리 방문
void preorder(treeNode *root){
  if(root){
    printf("%d ", root -> key);
    preorder(root -> leftChild);
    preorder(root -> rightChild);
  }
}
//중위순회 1. 왼쪽 서브트리 방문 2. 루트 노드 방문 3. 오른쪽 서브트리 방문
void inorder(treeNode *root){
  if(root){
    inorder(root -> leftChild);
    printf("%d ", root -> key);
    inorder(root -> rightChild);
  }
}
//후위순회 1. 왼쪽 서브트리 방문 2. 오른쪽 서브트리 방문 3. 루트 노드 방문
void postorder(treeNode *root){
  if(root){
    postorder(root -> leftChild);
    postorder(root -> rightChild);
    printf("%d ", root -> key);
  }
}
//레벨순회
void level_order(treeNode *root){
  int queue;
  if(root == NULL) break;
  enqueue(root);
  while(!is_empty()){
    printf("%d ", dequeue());
    if((root -> leftChild) != '\n') enqueue(root -> leftChild);
    if((root -> rightChild) != '\n') enqueue(root -> rightChild);
  }
}
