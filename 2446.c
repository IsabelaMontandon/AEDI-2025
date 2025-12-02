#include <stdio.h>
#include <stdbool.h>
#define MAXM 1001

int v, m;
int c[MAXM];

int troco(int val, int mds);

int main(){
    int v, m, i;
    while(scanf("%d %d", &v, &m) != EOF){
        for(i = 1; i <= m; i++){
            scanf("%d", &c[i]);
        }
        printf("%c\n", troco(v, m) ? 'S' : 'N');
    }
    return 0;
}

int troco(int val, int mds){
    if(val < 0) return false;
    if(val == 0) return true;
    if(mds == 0) return false;
    return troco(val - c[mds], mds - 1) || troco(val, mds - 1);
}
