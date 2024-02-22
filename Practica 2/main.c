#include <stdio.h>
#define MAX 30

void leer(int v[], int *m){
    *m=0;
    do{
        printf("Dame un numero ");
        scanf("%d", &v[*m]);
        *m=*m+1;
    }while(v[*m-1]>0);
    *m=*m-1;
}
int cuenta(int v[], int m){
    int k, cta;
    cta = 0;
    for(k=0; k<m; k=k+1)
        if((v[k]%2)==0)
            cta = cta+1;
    return cta;
}
void resultado(int p, int v[], int m){
    printf("Hay %d pares:\n", p);
    for(m=m-1; m>=0; m=m-1)
        if((v[m]%2)==0)
            printf("%d\t", v[m]);
}
int main(){
    int num[MAX], n, pares;
    leer(num, &n);
    pares = cuenta(num, n);
    resultado(pares, num, n);
    return 0;
}