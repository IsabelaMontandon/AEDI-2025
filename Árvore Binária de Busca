#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no *e,*d;
}no;

no* ins(no *r,int v){
    if(!r){
        r=(no*)malloc(sizeof(no));
        r->v=v;
        r->e=r->d=NULL;
    }else if(v<r->v) r->e=ins(r->e,v);
    else r->d=ins(r->d,v);
    return r;
}

void pre(no *r){
    if(!r) return;
    printf("%d",r->v);
    if(r->e||r->d) printf(" ");
    pre(r->e);
    if(r->e&&r->d) printf(" ");
    pre(r->d);
}

void in(no *r){
    if(!r) return;
    in(r->e);
    printf("%d",r->v);
    if(r->d) printf(" ");
    in(r->d);
}

void post(no *r){
    if(!r) return;
    post(r->e);
    if(r->e) printf(" ");
    post(r->d);
    if(r->d) printf(" ");
    printf("%d",r->v);
}

void pre2(no *r){
    if(!r) return;
    printf("%d",r->v);
    if(r->e||r->d) printf(" ");
    pre2(r->e);
    pre2(r->d);
}

void in2(no *r){
    if(!r) return;
    in2(r->e);
    printf("%d",r->v);
    if(r->d) printf(" ");
    in2(r->d);
}

void post2(no *r){
    if(!r) return;
    post2(r->e);
    post2(r->d);
    printf("%d",r->v);
    if(r->v!=0) printf(" ");
}

void pre3(no *r){
    if(!r) return;
    printf("%d",r->v);
    if(r->e) printf(" ");
    pre3(r->e);
    if(r->d) printf(" ");
    pre3(r->d);
}

int f1=1;
void preo(no *r){
    if(!r) return;
    if(!f1) printf(" ");
    printf("%d",r->v);
    f1=0;
    preo(r->e);
    preo(r->d);
}
int f2=1;
void ino(no *r){
    if(!r) return;
    ino(r->e);
    if(!f2) printf(" ");
    printf("%d",r->v);
    f2=0;
    ino(r->d);
}
int f3=1;
void posto(no *r){
    if(!r) return;
    posto(r->e);
    posto(r->d);
    if(!f3) printf(" ");
    printf("%d",r->v);
    f3=0;
}

int main(){
    int c,n,v;
    scanf("%d",&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&n);
        no *r=NULL;
        for(int j=0;j<n;j++){
            scanf("%d",&v);
            r=ins(r,v);
        }
        printf("Case %d:\n",i);
        printf("Pre.: ");
        f1=1;
        preo(r);
        printf("\nIn..: ");
        f2=1;
        ino(r);
        printf("\nPost: ");
        f3=1;
        posto(r);
        printf("\n\n");
    }
    return 0;
}
