#include "menu.h"

int menu_widok(){
    int wybor;
    while(1){
        printf("Centralny Rejestr Cybernetycznych Modyfikacji\n");
        printf("1. Zarejestruj nowy implant\n");
        printf("2. Wyswietl Rejestr\n");
        printf("3. Edytuj implant\n");
        printf("4. Znajdz implant\n");
        printf("5. Znajdz kilka implantow\n");
        printf("6. Sortuj implanty\n");
        printf("7. Usun implant\n");
        printf("8. Usun implanty danego wlasciciela\n");
        printf("9. Zapisz dane do pliku\n");
        printf("0. Zakoncz program\n");
        if(scanf("%d",&wybor)!=1){
            while(getchar()!='\n');
            printf("Bledny wybor\n");
            continue;
        }
        if(wybor >= 0 && wybor <=9){
            break;
        }
        printf("Bledny wybor\n");
    }
    while(getchar()!='\n');
    return wybor;
}