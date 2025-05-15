 //음수가 입력될 때까지 정수들을 입력받고, 입력받은 정수들을 역순으로 출력하여라. 입력되는 정수(음수 제외)의 개수는 100 이하이다.
#include <stido.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
  return (top == -1);
}

int is_full(){
  return (top == (MAX_STACK_SIZE - 1));
}

void push(element item){
  stack[++top] = item;
}

element pop(){
  return stack[top--];
}

int main(void){
  int num;
  
  while(1){
    scanf("%d", &num);
    if(num < 0) break;
    push(num);
  }

  while(!is_empty()){
    printf("%d", pop());  
  }

  return 0;  
}
