#include <stdio.h>
void impresionCoincidente(int va[], int vb[], int MaxA, int MaxB, int inicioCoincidencia){
    int k, m;
    m=0;
    printf("|-va-|-vb-|\n");
    for(k=0; k<MaxA; k=k+1){
        if(va[k]!=0){
            printf("|[%d]|", va[k]);
            if(k==inicioCoincidencia){
                printf("[%d]", vb[m]);
                m=m+1;
                if(m<MaxB)
                    inicioCoincidencia++;
            }
            printf("\n");
        }
    }
}
void buscarSecuenciaVBenVA(int va[], int vb[], int iMaxA, int iMaxB){
    int coincidencias, k, m, inicioCoincidencia;
    coincidencias=0; m=0; k=0;
    while(k<iMaxA && coincidencias!=iMaxB){
            inicioCoincidencia=k;
            coincidencias=0;
            while(m<iMaxB && coincidencias!=-1){
                if(va[k+m]!=vb[m])
                    coincidencias=-1;
                else
                    coincidencias++;
                m=m+1;
            }
            k=k+1;
            m=0;
        }
        if(coincidencias == iMaxB){
            printf("\n==> La secuencia del arreglo vb esta dentro de va a partir del indice [%d], (Elemento %d)\n", inicioCoincidencia, inicioCoincidencia+1);
            impresionCoincidente(va, vb, iMaxA, iMaxB, inicioCoincidencia);
        }
        else 
            printf("La secuencia del arreglo vb no esta en el arreglo va\n"); // --TODO: imprime ambos arreglos de manera estetica
}