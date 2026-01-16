#ifndef IMPLANTY_H
#define IMPLANTY_H

enum Legalnosc{
    LEGALNY,        
    SZARASTREFA,
    NIELEGALNY,
};

typedef struct implanty{
    char nazwa[101];
    char producent[101];
    int poziom_ryzyka;
    double zapotrzebowanie_energetyczne;
    enum Legalnosc legalnosc;
    int id_wlasciciela;
    struct implanty* next;
    }implanty;

void nowy_implant(implanty **head);
void wyswietl_implanty(implanty *head);
void edytuj_implant(implanty *head);
void znajdz_implant(implanty *head);
void znajdz_implanty(implanty *head);
void sortuj_implanty(implanty *head);
void zamiana(implanty *a, implanty* b);
void usun_implant(implanty **head);
void usuwanie_implantow(implanty** head);
void koniec(implanty *head);

#endif