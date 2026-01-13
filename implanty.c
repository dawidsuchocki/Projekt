#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implanty.h"

void nowy_implant(implanty **head){
    implanty *n = calloc(1,sizeof(implanty));
    int nazwaistnieje = 0;
    if(n==NULL){
        printf("Blad alokacji pamieci\n");
        return;
    }
    int temp=-1;
    printf("Podaj nazwe implantu(nie uzywaj znaku ;):\n");
    while(1){
        fgets(n->nazwa,101,stdin);
        n->nazwa[strcspn(n->nazwa, "\n")] = '\0';
        if(strchr(n->nazwa,';')!=NULL){
            printf("Nazwa nie moze zawierac znaku ;\n");
            continue;
        }else break;
    }
    for(implanty* p=*head; p != NULL; p = p->next){
        if(strcmp(n->nazwa,p->nazwa)==0){
            nazwaistnieje = 1;
            break;
        }
    } 
    printf("Podaj producenta implantu(nie uzywaj znaku ;):\n");
    while(1){
        fgets(n->producent,101,stdin);
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
    int blad = 0;
    while(1){
        blad=0;
        printf("Wprowadz ID wlasciciela implantu:\n");
        if(scanf("%d",&temp)!=1){
            while(getchar()!='\n');
            printf("Bledne dane\n");
            continue;
        }
        for(implanty* p=*head; p != NULL; p = p->next){
            if((p->id_wlasciciela==temp)&&nazwaistnieje==1){
                temp = -1;
                printf("Ta osoba ma juz ten implant\n");
                blad = 1;
                break;
            }
        }
        if(blad) continue;    
        if(temp>0){
            n->id_wlasciciela = temp;
            break;
        }
    }
    n->next = *head;
    *head = n;
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

void edytuj_implant(implanty *head){
    int id;
    while(1){
        printf("Wprowadz id wlasciciela implantu\n");
        if(scanf("%d",&id)!=1){
            while(getchar()!='\n');
            continue;
        }
        if(id>0){
            break;
        }
    }
    while(getchar()!='\n');
    char nazwa[101];
    while(1){
        printf("Wprowadz nazwe implantu\n");
        fgets(nazwa,101,stdin);
        nazwa[strcspn(nazwa, "\n")] = '\0';
        if(strchr(nazwa,';')!=NULL){
            printf("Nazwa nie moze zawierac znaku ;\n");
            continue;
        }else break;
    }
    implanty* n=NULL;
    for(implanty* p=head;p!=NULL;p = p->next){
        if(p->id_wlasciciela==id&&strcmp(nazwa,p->nazwa)==0){
            n=p;
            break;
        }
    }
    if(n==NULL){
        printf("Nie znaleziono implantu o podanej nazwie i id wlasciciela\n");
        return;
    }
    int wybor,temp;
    while(1)
    {
        printf("Wybierz ktore pole chcesz edytowac\n");
        printf("1. Nazwe producenta\n");
        printf("2. Poziom ryzyka\n");
        printf("3. Zapotrzebowanie energetyczne\n");
        if(scanf("%d",&wybor)!=1){
            while(getchar()!='\n');
            continue;
        }
        if(wybor>=1&&wybor<=3){
            break;
        }
    }
    while(getchar()!='\n');
    switch (wybor)
    {
    case 1:
        printf("Podaj producenta implantu(nie uzywaj znaku ;):\n");
        while(1){
            fgets(n->producent,101,stdin);
            if(strchr(n->producent,';')!=NULL){
                printf("Nazwa producenta nie moze zawierac znaku ;\n");
                continue;
            }else break;
        }
        n->producent[strcspn(n->producent, "\n")] = '\0';
        break;
    case 2:
        while(1){
            printf("Podaj poziom ryzyka implantu (0-10):\n");
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
        break;
    case 3:
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
        break;
    }
}

void znajdz_implant(implanty* head){
    int id;
    while(1){
        printf("Wprowadz id wlasciciela implantu\n");
        if(scanf("%d",&id)!=1){
            while(getchar()!='\n');
            continue;
        }
        if(id>0){
            break;
        }
    }
    while(getchar()!='\n');
    char nazwa[101];
    while(1){
        printf("Wprowadz nazwe implantu\n");
        fgets(nazwa,101,stdin);
        nazwa[strcspn(nazwa, "\n")] = '\0';
        if(strchr(nazwa,';')!=NULL){
            printf("Nazwa nie moze zawierac znaku ;\n");
            continue;
        }else break;
    }
    implanty* n=NULL;
    for(implanty* p=head;p!=NULL;p = p->next){
        if((p->id_wlasciciela==id)&&(strcmp(nazwa,p->nazwa)==0)){
            n=p;
            break;
        }
    }
    if(n==NULL){
        printf("Nie znaleziono implantu o podanej nazwie i id wlasciciela\n");
        return;
    }
    printf("%40s","Nazwa");
    printf("%40s","Producent");
    printf("%10s","Ryzyko");
    printf("%25s","Zapotrzebowanie(kWh)");
    printf("%15s","Legalnosc");
    printf("%20s","ID wlasciciela\n");
    printf("%40s",n->nazwa);
    printf("%40s",n->producent);
    printf("%10d",n->poziom_ryzyka);
    printf("%25.2f",n->zapotrzebowanie_energetyczne);
    printf("%15s",n->legalnosc ? (n->legalnosc == 1 ? "Szara strefa" : "Nielegalny") : "Legalny");
    printf("%20d\n",n->id_wlasciciela);
}

void znajdz_implanty(implanty *head){
    int wybor=0,ilosc=0,ryzyko=-1;
    char nazwa[101];
    while(!(wybor>=1&&wybor<=2)){
        printf("Po jakiej wartosci chcesz szukac implantow:\n");
        printf("1. Nazwa\n");
        printf("2. Poziom ryzyka\n");
        if(scanf("%d",&wybor)!=1){
            while(getchar()!='\n');
            printf("Bledny wybor\n");
            continue;
        }
    }
    switch(wybor){
        case 1:
            wybor=0;
            while(!(wybor>=1&&wybor<=2)){
                printf("Wybierz opcje:\n");
                printf("1. Dokladnie taka sama nazwa\n");
                printf("2. Prefix\n");
                if(scanf("%d",&wybor)!=1){
                    while(getchar()!='\n');
                    printf("Bledny wybor\n");
                    continue;
                }
            }
            while(getchar()!='\n');
            if(wybor==1){
                while(1){
                    printf("Wprowadz nazwe implantu\n");
                    fgets(nazwa,101,stdin);
                    nazwa[strcspn(nazwa, "\n")] = '\0';
                    if(strchr(nazwa,';')!=NULL){
                        printf("Nazwa nie moze zawierac znaku ;\n");
                        continue;
                    }else break;
                }
                for(implanty* p=head;p!=NULL;p = p->next){
                    if(strcmp(nazwa,p->nazwa)==0){
                        ilosc++;
                    }
                }
                if(ilosc){
                    printf("%40s","Nazwa");
                    printf("%40s","Producent");
                    printf("%10s","Ryzyko");
                    printf("%25s","Zapotrzebowanie(kWh)");
                    printf("%15s","Legalnosc");
                    printf("%20s","ID wlasciciela\n");
                    for(implanty* p=head;p!=NULL;p = p->next){
                        if(strcmp(nazwa,p->nazwa)==0){
                            printf("%40s",p->nazwa);
                            printf("%40s",p->producent);
                            printf("%10d",p->poziom_ryzyka);
                            printf("%25.2f",p->zapotrzebowanie_energetyczne);
                            printf("%15s",p->legalnosc ? (p->legalnosc == 1 ? "Szara strefa" : "Nielegalny") : "Legalny");
                            printf("%20d\n",p->id_wlasciciela);
                        }
                    }
                }else printf("Nie znaleziono zadnego implantu\n");
            }else{
                while(1){
                    printf("Wprowadz prefix\n");
                    fgets(nazwa,101,stdin);
                    nazwa[strcspn(nazwa, "\n")] = '\0';
                    if(strchr(nazwa,';')!=NULL){
                        printf("Prefix nie moze zawierac znaku ;\n");
                        continue;
                    }else break;
                }
                for(implanty* p=head;p!=NULL;p = p->next){
                    if(strncmp(p->nazwa,nazwa,strlen(nazwa))==0){
                        ilosc++;
                    }
                }
                if(ilosc){
                    printf("%40s","Nazwa");
                    printf("%40s","Producent");
                    printf("%10s","Ryzyko");
                    printf("%25s","Zapotrzebowanie(kWh)");
                    printf("%15s","Legalnosc");
                    printf("%20s","ID wlasciciela\n");
                    for(implanty* p=head;p!=NULL;p = p->next){
                        if(strncmp(p->nazwa,nazwa,strlen(nazwa))==0){
                            printf("%40s",p->nazwa);
                            printf("%40s",p->producent);
                            printf("%10d",p->poziom_ryzyka);
                            printf("%25.2f",p->zapotrzebowanie_energetyczne);
                            printf("%15s",p->legalnosc ? (p->legalnosc == 1 ? "Szara strefa" : "Nielegalny") : "Legalny");
                            printf("%20d\n",p->id_wlasciciela);
                        }
                    }
                }else printf("Nie znaleziono zadnego implantu\n");
            }
            break;
        case 2:
            while(getchar()!='\n');
            while(!(ryzyko>=0 && ryzyko<=10)){
                printf("Podaj poziom ryzyka implantu (0-10):\n");
                if(scanf("%d",&ryzyko)!=1){
                    while(getchar()!='\n');
                    printf("Bledne dane\n");
                    continue;
                }
            }
            for(implanty* p=head;p!=NULL;p = p->next){
                if(p->poziom_ryzyka==ryzyko){
                    ilosc++;
                }
            }
            if(ilosc){
                printf("%40s","Nazwa");
                printf("%40s","Producent");
                printf("%10s","Ryzyko");
                printf("%25s","Zapotrzebowanie(kWh)");
                printf("%15s","Legalnosc");
                printf("%20s","ID wlasciciela\n");
                for(implanty* p=head;p!=NULL;p = p->next){
                    if(p->poziom_ryzyka==ryzyko){
                        printf("%40s",p->nazwa);
                        printf("%40s",p->producent);
                        printf("%10d",p->poziom_ryzyka);
                        printf("%25.2f",p->zapotrzebowanie_energetyczne);
                        printf("%15s",p->legalnosc ? (p->legalnosc == 1 ? "Szara strefa" : "Nielegalny") : "Legalny");
                        printf("%20d\n",p->id_wlasciciela);
                    }
                }
            }else printf("Nie znaleziono zadnego implantu\n");
    }
}