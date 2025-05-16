//현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다. 현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고, 돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 현우는 통장에서 K원을 인출하며, 통장에서 뺀 돈으로 하루를 보낼 수 있으면 그대로 사용하고, 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 다만 현우는 M이라는 숫자를 좋아하기 때문에, 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. 현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.

//이진 탐색

#include <stdio.h>

#define MAX_N 100000

int money[MAX_N];
int N;
int M;

int can_withdraw(int key){
    int cnt = 1;
    int balance = key;
    for(int i=0; i<N; i++){
        if(money[i] > key) return 0;
        if(balance < money[i]){
            cnt ++;
            balance = key;
        }
        balance -= money[i];
    }
    
    return cnt <= M;
}

int main(void){
    int left, right, K, mid;
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%d", &money[i]);
    }
    
    left = 1;    right = 0;
    for(int i=0; i<N; i++){
        if(money[i] < left) left = money[i];
        right += money[i];
    }
    
    K = right;
    while(left <= right){
        mid = (left + right) / 2;
        if(can_withdraw(mid)){
            K = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    
    printf("%d", K);
    return 0;
}
