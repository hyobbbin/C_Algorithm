//성적처리 프로그램을 작성한다고 하자. 사용자한테 학생이 몇 명인지를 물어보고 적절한 동적메모리를 할당한다. 사용자로부터 성적을 받아서 저장하였다가 다시 출력한다.
#include <stdio.h>
#include <stdlib.h>

int main(void){

	int people;
	int *score;
	int avg = 0;

	scanf("%d", &people);
	score = (int *)malloc(people*sizeof(int));
	
	if(score == NULL){
		printf("동적 메모리 할당 오류");
		exit(1);
	}

	for(int i=0; i<people; i++){
		scanf("%d", &score[i]);
		avg += score[i];
	}
	
	avg = avg / people;
	printf("%.2f\n", (double)avg/people);
	free(score);

	return 0;
}
