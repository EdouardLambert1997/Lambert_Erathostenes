/*
 ============================================================================
 Name        : Lambert_Erathostenes.c
 Author      : Lambert Edouard
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "inout.h"

/* typedef short int bool; */
typedef unsigned char bool;
#define false 0
#define true 1

typedef unsigned int uint32;
#define setbitarray(pba, i) (pba[i >> 5] |= (0x00000001 << (i & 0x0000001F)))
#define unsetbitarray(pba, i) (pba[i >> 5] &= ~(0x00000001 << (i & 0x0000001F)))
#define issetbitarray(pba, i) (pba[i >> 5] & (0x00000001 << (i & 0x0000001F)))


#define MAX 2147483647       /* (2^31-1) */

struct TListPrimes {
    int maximum; /*valeur max donnée au début du prog (objectif)*/
    int* pPrimes; /*résultat(tous nmbre premier en int)*/
    int cPrimes; /*nbre entier stocker*/
};

void InitializeTListPrimes(struct TListPrimes* listPrim);
void Erathostenes(struct TListPrimes* listPrim);
void ShowPrimes2(struct TListPrimes* listPrim);
void DestroyTListPrimes(struct TListPrimes* listPrim);

int main(int argc, char* argv[]) {
    clock_t ct1, ct2;
    struct TListPrimes listPrimes;
    do {
        InitializeTListPrimes(&listPrimes);
        listPrimes.maximum = ReadIntLimited("\nVotre naturel maximum ? ", 0, MAX);
        ct1 = clock();
        Erathostenes(&listPrimes);
        ct2 = clock();
        printf("Duree calculs : %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
        ShowPrimes2(&listPrimes);
        /*ShowPrimes(&listPrimes);*/
        DestroyTListPrimes(&listPrimes);
    } while(!Stop());
    return EXIT_SUCCESS;
}

void InitializeTListPrimes(struct TListPrimes* listPrim){
    (*listPrim).cPrimes = 0;
    (*listPrim).maximum = 0;
    (*listPrim).pPrimes = NULL; 
}
void Erathostenes(struct TListPrimes* listPrim){
        uint32* tab;
        int n;
        uint32 i;
        uint32 j;
        int indice = 0;
        int racine;
        
        n = (*listPrim).maximum;
        tab = calloc((n/32), sizeof(uint32));
        racine = (int)sqrt(n);
        
for (i=2; i <= n && i>0; ++i){
    setbitarray(tab, i);
}

for (i=2; i <= racine && i>0; ++i){
                
    if(issetbitarray(tab, i)){
                        
        for (j=i; i*j <= n && i*j>0; ++j){
            unsetbitarray(tab, i*j);
        }
   }
}

for(i=2; i <= n && i>0; ++i){
     if(issetbitarray(tab, i)){
        (*listPrim).cPrimes++;
     }
}
(*listPrim).pPrimes = calloc(listPrim ->cPrimes, sizeof(uint32));

for(i=2; i <= n; ++i){
    if(issetbitarray (tab, i)){
    (*listPrim).pPrimes[indice] = i;
    indice++;
    }  
}

free(tab); 
        
}
    
}
void ShowPrimes2(struct TListPrimes* listPrim){
    
}
void DestroyTListPrimes(struct TListPrimes* listPrim){
    
}