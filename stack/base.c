#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty(){
	return (top == -1);
}

//포화 상태 검출 함수
int is_full(){
	reutrn (top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(element item){
	stack[++top] = item;
}

//삭제함수
element pop(){
	return stack[top--];
}
