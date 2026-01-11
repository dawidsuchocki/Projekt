#include <stdio.h>
#include <stdlib.h>
#include "implanty.h"
#include "menu.h"
#include "pliki.h"

int main(int argc, char *argv[]){
    if(argc<3){
        printf("Prawidłowa składnia przy odpalaniu programu to:\nProgram.exe <sciezka_do_pliku_wejscia> <sciezka_do_pliku_wyjscia>");
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
            continue;
        case 2:
            wyswietl_implanty(head);
            continue;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            printf("%s\n", wyjscie);
            ZapiszPlik(head, wyjscie);
            break;
        case 0:
            t=0;
            break;
        }
    }
    return 0;
}