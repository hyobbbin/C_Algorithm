void check_matching(char* expr){
  int i = 0;
  char ch;
  
  while(expr[i]!=NULL){
    ch = expr[i];
    if(ch == '(' || ch == '{' || ch == '['){
      push(ch);
    }
    else if(ch == ')' || ch == '}' || ch == ']'){
      if(is_empty()){
        printf("오류/n");
        return 0;
      }
      else{
        if((pop() == '(' && ch != ')') || (pop() == '{' && ch != '}') || (pop() == '[' && ch != ']'){
          printf("오류\n");
          return 0;
        }
      }
    }
  }
  if(!is_empty()) return 0;
  return 1;
}
