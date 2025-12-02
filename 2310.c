#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Jgdr {
    int s, b, a;
    int ps, pb, pa;
};

int main()
{
    short nj;
    char njg[100];
    long ts = 0, tb = 0, ta = 0;
    long tps = 0, tpb = 0, tpa = 0;
    struct Jgdr jgdr;
    
    scanf("%hd", &nj);
    
    while(nj--)
    {
        scanf("%s %d %d %d", njg, &jgdr.s, &jgdr.b, &jgdr.a);
        scanf("%d %d %d", &jgdr.ps, &jgdr.pb, &jgdr.pa);
        
        ts += jgdr.s;
        tb += jgdr.b;
        ta += jgdr.a;

        tps += jgdr.ps;
        tpb += jgdr.pb;
        tpa += jgdr.pa;
    }

    printf("Pontos de Saque: %.2lf %%.\n", (tps * 100.0) / ts);
    printf("Pontos de Bloqueio: %.2lf %%.\n", (tpb * 100.0) / tb);
    printf("Pontos de Ataque: %.2lf %%.\n", (tpa * 100.0) / ta);
    
    return 0;
}
