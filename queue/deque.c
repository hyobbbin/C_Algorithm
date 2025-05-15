#define MAX_QUEUE_SIZE 100
typedef int element;

element queue[MAX_QUEUE_SIZE];
int front, rear;
front = rear = 0;

int is_empty(){
  return front == rear;
}

int is_full(){
  return front == (rear + 1) % MAX_QUEUE_SIZE;
}

void add_rear(element item){
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = item;
}

element delete_front(){
  front = (front + 1) % MAX_QUEUE_SIZE;
  return queue[front];
}

void add_front(element item){
  queue[front] = item;
  front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(){
  element item = queue[rear];
  rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
  return item;
}
