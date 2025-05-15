//iter
treeNode* insert_BST_i(treeNode *root, int key){
  treeNode *pPre, *pLoc, *pNew;
  pNew = (treeNode *)malloc(sizeof(treeNode));
  pNew -> key = key;
  pNew -> leftChild = pNew -> rightChild = NULL;
  pPRE = NULL;
  pLoc = root;
  while(pLoc){
    if(key == pLoc -> key){
      pNew -> rightChild = pLoc -> rightChild;
      pLoc -> rightChild = pNew;
      return root;
    }
    pPre = pLoc;
    pLoc = (key < pLoc -> key) ? pLoc -> leftChild : pLoc -> rightChild;
  }
  if(pPre){
    if(key < pPre -> key) pPre -> leftChild = pNew;
    else pPre -> rightChild = pNew;
  }
  else return pNew;
  return root;
}
