//구조체 배열을 동적 메모리를 이용하여 생성하고 여기에 영화 정보를 저장했다가 다시 화면에 예쁘게 출력하는 프로그램을 작성하여 보자.
//영화 정보를 사용자로부터 받는다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie{
  char title[100];
  double rating;
}MOVIE;

int main(void){
  MOVIE* movies;
  int size;

  scanf("%d", &size);
  printf("영화의 개수: %d", size);

  movies = (MOVIE*)malloc(size*sizeof(MOVIE));
  if(movies == NULL) break;
  
  for(int i=0; i<size; i++){
    printf("영화 제목: ");
    gets_s(movies[i].title, 100);

    printf("영화 평점: ");
    scanf("%lf", &movies[i].rating);
    getchar();
  }
  free(movies);
  return 0;
}
