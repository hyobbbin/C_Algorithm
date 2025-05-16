//if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
//    1
//if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
//    w(20, 20, 20)
//if a < b and b < c, then w(a, b, c) returns:
//    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
//otherwise it returns:
//    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
//위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)
//a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.


//dp memoization

#include <stdio.h>

int num[21][21][21];

int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return w(20, 20, 20);
    if(num[a][b][c] != 0) return num[a][b][c];
    if(a<b && b<c) return num[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return num[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(void){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==-1 && b==-1 && c==-1) break;
        else{
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
        }
    }
    return 0;
}
