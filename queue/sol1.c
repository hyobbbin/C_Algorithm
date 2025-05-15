//음수가 입력될 때까지 정수들을 입력받는다. 첫번째 줄에는 입력받은 정수들을 역순으로 출력하고, 두번째 줄에는 입력 순서대로 출력하여라. 입력되는 정수의 개수는 100 이하이다.
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef int element;

element stack[MAX_STACK_SIZE];
element queue[MAX_QUEUE_SIZE];
int top = -1;
int front, rear;
front = rear = 0;

int is_empty_stack(){
  return top == -1;
}
int is_full_stack(){
  return top == MAX_STACK_SIZE - 1;
}
void push(element item){
  stack[++top] = item;
}
element pop(){
  return stack[top--];
}

int is_empty(){
  return front == rear;
}
int is_full(){
  return front == (rear + 1) % MAX_QUEUE_SIZE;
}
void enqueue(element item){
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = item;
}
element dequeue(){
  front = (front + 1) % MAX_QUEUE_SIZE;
  return queue[front];
}


int main(){
  int num;

  while(1){
    scanf("%d", &num);
    if(num < 0) break;
    push(num);
    enqueue(num);  
  }

  while(!is_empty_stack()){
    printf("%d ", pop());
  }
  printf("\n");

  while(!is_empty()){
    printf("%d ", dequeue());
  }

  return 0;  
}
