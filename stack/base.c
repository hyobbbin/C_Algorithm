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

-------------------------------------------------------------------------------------------
//2개 이상의 스택이 필요한 경우
typedef struct Stack{
	element stack[MAX_STACK_SIZE];
	int top;
} Stack;

Stack s1, s2;

push(&s1, val);
// Stack s1에 push
// 구조체의 내용이 변경되므로, call-by-reference로 호출하여야 함.

val = pop(&s2);
// Stack s2에서 pop
