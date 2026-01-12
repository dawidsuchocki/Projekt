#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pliki.h"

int WczytajPlik(implanty **head,char *sciezka){
    FILE *plikwejscia = fopen(sciezka,"r");
    if(plikwejscia == NULL){
        printf("Blad przy otwieraniu pliku\n");
        return 0;
    }
    implanty *n;
    while(1){
        n = calloc(1,sizeof(implanty));
        if(n==NULL){
            printf("Blad alokacji pamieci\n");
            return 0;
        }
        int wynik = fscanf(plikwejscia,"%100[^;];%100[^;];%d;%lf;%d;%d;",n->nazwa,n->producent,&(n->poziom_ryzyka),&(n->zapotrzebowanie_energetyczne),&(n->legalnosc),&(n->id_wlasciciela));
        if(wynik==EOF){
            free(n);
            break;
        }
        for(implanty* p=*head; p != NULL; p = p->next){
        if((strcmp(n->nazwa,p->nazwa)==0)&&n->id_wlasciciela==p->id_wlasciciela){
            printf("Blad w wczytywaniu danych z pliku wejsciowego\n");
            return 0;
        }
    } 
        if(wynik!=6){
            printf("Blad w wczytywaniu danych z pliku wejsciowego\n");
            fclose(plikwejscia);
            free(n);
            return 0;
        }
        if(n->poziom_ryzyka<0 || n->poziom_ryzyka>10 || n->zapotrzebowanie_energetyczne<0 || n->legalnosc<0 || n->legalnosc>2 || n->id_wlasciciela<1){
            printf("Nieprawidlowe dane w pliku wejsciowym\n");
            fclose(plikwejscia);
            free(n);
            return 0;
        }
        n->next = *head;
        *head = n;
    }
    printf("Pomyslnie wczytano dane z pliku\n");
    fclose(plikwejscia);
    return 1;
}

void ZapiszPlik(implanty* head,char *sciezka){
    implanty* p = head;
    FILE *plikwyjscia = fopen(sciezka,"w");
    if(plikwyjscia == NULL){
        printf("Blad przy otwieraniu pliku\n");
        return;
    }
    while(p!=NULL){
        fprintf(plikwyjscia,"%s;%s;%d;%lf;%d;%d;",p->nazwa,p->producent,p->poziom_ryzyka,p->zapotrzebowanie_energetyczne,p->legalnosc,p->id_wlasciciela);
    p = p->next;
    }
    fclose(plikwyjscia);
}