#include <stdio.h>
#include <stdlib.h>
#include "implanty.h"
#include "menu.h"
#include "pliki.h"

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Prawidlowa skladnia przy odpalaniu programu to:\n./Program.exe <sciezka_do_pliku_wejscia> <sciezka_do_pliku_wyjscia>");
        return 0;
    }
    char *wejscie = argv[1];
    char *wyjscie = argv[2];
    implanty* head = NULL;
    int t=1;
    if(WczytajPlik(&head, wejscie)==0) return 0;
    while(t){
        switch (menu_widok())
        {
        case 1:
            nowy_implant(&head);
            break;
        case 2:
            wyswietl_implanty(head);
            break;
        case 3:
            edytuj_implant(head);
            break;
        case 4:
            znajdz_implant(head);
            break;
        case 5:
            znajdz_implanty(head);
            break;
        case 6:
            sortuj_implanty(head);
            break;
        case 7:
            usun_implant(&head);
            break;
        case 8:
            usuwanie_implantow(&head);
            break;
        case 9:
            printf("%s\n", wyjscie);
            ZapiszPlik(head, wyjscie);
            break;
        case 0:
            t=0;
            break;
        }
    }
    koniec(head);
    return 0;
}