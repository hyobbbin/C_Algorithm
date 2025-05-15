//사용자로부터 문자열을 입력하여 저장해야 한다고 하자. 사용자가 몇 개의 문자를 입력할지, 미리 알 수는 없다. 이런 경우에는 일단 최대 10개의 문자를 저장할 수 있는 동적 메모리를 할당한 후에, 10개가 넘어가면 realloc()을 이용하여 동적 메모리의 크기를 조정해보자.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char *p;
  int size = 10, index = 0;
  char c;
  
  p = (char *)malloc(size * sizeof(char));
  while(c != '\n'){
    c = getchar();
    if(index >= size - 1){
      size *= 2;
      p = (char *)realloc(p, size * sizeof(char));
    }
    p[index++] = c;
  }

  p[index] = NULL;
  printf("%s\n", p);
  return 0;
}
