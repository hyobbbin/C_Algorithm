//순환적인 탐색 함수
treeNode *search_BST(treeNode *root, int targetKey){
  if(!root) return NULL;
  if(targetKey == root -> key) return root;
  if(targetKey < root -> key) return search_BST(root -> leftChild, targetKey);
  return searh_BST(root -> rightChild, taretKey);
}

//반복적인 탐색 함수
treeNode *search_BST(treeNode *root, int targetKey){
  while(root != NULL){
    if(targetKey == root -> key) return root;
    else if(targetKey < root -> key) root = root -> leftChild;
    else root = root -> rightChild;
  }
  return NULL;
}
