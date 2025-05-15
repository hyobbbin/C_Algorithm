element *stack, *queue;

int capacity = (원하는 크기);
stack = (element *)malloc(capacity * sizeof(element));
queue = (element *)malloc(capacity * sizeof(element));

//동적할당 stack 구현
void push(element item){
  if(is_full()){
    capacity *= 2;
    stack = (element *)realloc(stack, capacity *sizeof(element));
  }
  stack[++top] = item;
}

//동적할당 queue 구현
void enqueue(element item){
  if(is_full()) queueFull();
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = item;
}

void queueFull(){
  int start;//start는 첫번째 원소의 위치

  start = (front + 1) % MAX_QUEUE_SIZE;
  if(start < 2){
    capacity *= 2;
    queue = (element *)realloc(queue, capacity * sizeof(element));
  }
  else{
    element *newQueue = (element *)malloc(2 * capacity *sizeof(element));

    memcpy(newQueue, queue + start, (capacity - start) * sizeof(element));
    memcpy(newQueue + capacity - start, queue, (rear + 1) * sizeof(element));

    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;
  }
}
