#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implanty.h"

void nowy_implant(implanty **head){
    implanty *n = calloc(1,sizeof(implanty));
    if(n==NULL){
        printf("Blad alokacji pamieci\n");
        return;
    }
    n->next = *head;
    *head = n;
    int temp=-1;
    printf("Podaj nazwe implantu(nie uzywaj znaku ;):\n");
    while(1){
        fgets(n->nazwa,100,stdin);
        if(strchr(n->nazwa,';')!=NULL){
            printf("Nazwa nie moze zawierac znaku ;\n");
            continue;
        }else break;
    }
    
    n->nazwa[strcspn(n->nazwa, "\n")] = '\0';
    printf("Podaj producenta implantu(nie uzywaj znaku ;):\n");
    while(1){
        fgets(n->producent,100,stdin);
        if(strchr(n->producent,';')!=NULL){
            printf("Nazwa producenta nie moze zawierac znaku ;\n");
            continue;
        }else break;
    }
    n->producent[strcspn(n->producent, "\n")] = '\0';
    printf("Podaj poziom ryzyka implantu (0-10):\n");
    while(1){
    if(scanf("%d",&temp)!=1){
        while(getchar()!='\n');
        printf("Bledne dane\n");
        continue;
        }
        if(temp>=0 && temp<=10){
            n->poziom_ryzyka = temp;
            break;
        }else printf("Bledne dane\n");
    }
    while(getchar()!='\n');
    temp = -1;
    printf("Podaj zapotrzebowanie energetyczne implantu(kWh):\n");
    while(1){
    if(scanf("%d",&temp)!=1){
        while(getchar()!='\n');
        printf("Bledne dane\n");
        continue;
        }
        if(temp>=0){
            n->zapotrzebowanie_energetyczne = temp;
            break;
        }else printf("Bledne dane\n");
    }
    temp = -1;
    printf("Wybierz legalnosc implantu:\n");
    printf("1.Legalny\n2.Szara strefa\n3.Nielegalny\n");
    while(1){
    if(scanf("%d",&temp)!=1){
        while(getchar()!='\n');
        printf("Bledne dane\n");
        continue;
        }
        if(temp>=1 && temp<=3){
            n->legalnosc = temp - 1;
            break;
        }else printf("Bledne dane\n");
    }
    temp = -1;
    printf("Wprowadz ID wlasciciela implantu:\n");
    while(1){
        if(scanf("%d",&temp)!=1){
            while(getchar()!='\n');
            printf("Bledne dane\n");
            continue;
        }
        if(temp>0){
            n->id_wlasciciela = temp;
            break;
        }
    }
    printf("Pomyslnie dodano implant\n");
}

void wyswietl_implanty(implanty *head){
    implanty *p = head;
    printf("%40s","Nazwa");
    printf("%40s","Producent");
    printf("%10s","Ryzyko");
    printf("%25s","Zapotrzebowanie(kWh)");
    printf("%15s","Legalnosc");
    printf("%20s","ID wlasciciela\n");
    while(p!=NULL){
        printf("%40s",p->nazwa);
        printf("%40s",p->producent);
        printf("%10d",p->poziom_ryzyka);
        printf("%25.2f",p->zapotrzebowanie_energetyczne);
        printf("%15s",p->legalnosc ? (p->legalnosc == 1 ? "Szara strefa" : "Nielegalny") : "Legalny");
        printf("%20d\n",p->id_wlasciciela);
        p = p->next;
    }
}