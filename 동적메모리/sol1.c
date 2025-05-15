//정수1개, 실수1개, 문자1개를 저장할 수 있는 공간을 할당받아서 사용한 후에 반납하는 코드를 작성해보자.
#include <stdio.h>
#incldue <stdlib.h>

int main(void){
	int *pi;
	double *pf;
	char *pc;

	pi = (int *)malloc(sizeof(int));
	pf = (double *)malloc(sizeof(double));
	pc = (char *)malloc(sizeof(char));

	if(pi == NULL || pf == NULL || pc == NULL){
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	
	*pi = 100; // pi[0] = 100;
	*pf = 3.14; // pf[0] = 3.14;
 	*pc = 'a'; // pc[0] = 'a’;

	free(pi);
	free(pf);
	free(pc);

	return 0;
}
