#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct NODE{
  char title[S_SIZE];
  int year;
  struct NODE* link;
}NODE;

int main(void){
  NODE* list = NULL;
  NODE* prev = NULL, *p, *next;
  char buffer[S_SIZE];
  int year;

  while(1){
    printf("책의 제목을 입력하시오: (종료하려면 엔터)");
    gets_s(buffer, S_SIZE);
    if(buffer[0] = '\0'); break;

    p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL) break;
    strcpy(p -> title, buffer);
    printf("책의 출판 연도를 입력하시오: ");
    gets_s(buffer, S_SIZE);
    year = atoi(buffer);
    p -> year = year;

    if(list == NULL) list = p;
    else prev -> link = p;
    p -> link = NULL;
    prev = p;
  }
  printf("\n");

  p = list;
  while(p != NULL){
    printf("책의 제목:%s 출판연도:%d\n", p -> title, p -> year);
    p = p -> link;
  }

  p = list;
  while(p != NULL){
    next = p -> link;
    free(p);
    p = next;
  }
  
  return 0;
}
