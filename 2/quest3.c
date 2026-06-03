#include <stdio.h>

int fibonacci(int limit, int index, int prevprev, int prev){
    int curr = prev + prevprev;
    // printf("%d)%d\n",index, curr);
    if (index == limit){
        return curr;
    }
    else{
        return fibonacci(limit, index + 1, prev, curr);
    }
}

int main(){
    int limit = 21;
    int ans = fibonacci(limit, 3, 0, 1);
    printf("%d\n", ans);
}
