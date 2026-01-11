#include "menu.h"

int menu_widok(){
    int wybor;
    while(1){
        printf("Centralny Rejestr Cybernetycznych Modyfikacji\n");
        printf("1. Zarejestruj nowy implant\n");
        printf("2. Wyswietl Rejestr\n");
        printf("3. Modyfikuj implant\n");
        printf("4. Znajdz implanty\n");
        printf("5. Sortuj implanty\n");
        printf("6. Usun implant\n");
        printf("7. Zapisz dane do pliku\n");
        printf("0. Zakoncz program\n");
        if(scanf("%d",&wybor)!=1){
            while(getchar()!='\n');
            system("cls");
            printf("Bledny wybor\n");
            continue;
        }
        if(wybor >= 0 && wybor <=7){
            break;
        }
        system("cls");
        printf("Bledny wybor\n");
    }
    while(getchar()!='\n');
    return wybor;
} 