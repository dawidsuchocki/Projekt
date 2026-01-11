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

#endif