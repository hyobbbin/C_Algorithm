#define MAX_QUEUE_SIZE 100

typedef int element;

element queue[MAX_QUEUE_SIZE];
int front, rear;
front = rear = 0;

int is_empty(){
  return (front == rear);
}

int is_full(){
  return (front == (rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(element item){
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = item;
}

element dequeue(){
  front = (front + 1) % MAX_QUEUE_SIZE;
  return queue[front];
}
