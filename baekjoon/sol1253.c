//N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
//N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.
//수의 위치가 다르면 값이 같아도 다른 수이다.

// 투포인터

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000

long long num[MAX_N];
int N;

int cmp(const void *a, const void *b){
    long long n1 = *(long long *)a;
    long long n2 = *(long long *)b;
    if(n1 < n2) return -1;
    if(n1 > n2) return 1;
    return 0; 
}

int main(void){
    int cnt = 0;
    int left, right;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%lld", &num[i]);
    }
    
    qsort(num, N, sizeof(long long), cmp);
    
    for(int i=0; i<N; i++){
        left = 0; right = N - 1;
        while(left < right){
            if(left == i){left++; continue;}
            if(right == i){right--; continue;}
            long long sum = num[left] + num[right];
            if(sum == num[i]){
                cnt++;
                break;
            }
            else if(sum < num[i]) left++;
            else if(sum > num[i]) right--;
        }
    }
    printf("%d", cnt);
    return 0;
}
