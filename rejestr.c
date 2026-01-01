#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    LEGALNY,
    NIELEGALNY,
    SZARA_STREFA
} StatusLegalnosci;

typedef struct {
    char nazwa[100];
    char producent[100];
    int poziom_ryzyka;
    int zapotrzebowanie_energetyczne;
    StatusLegalnosci status;
    int id_wlasciciela;
} implant;

bool czy_zawiera_liczby(char *tekst) {
    int dl = strlen(tekst);
    for (int i = 0; i < dl; i++) {
        if (isdigit(tekst[i])) {
            return true;
        }
    }
    return false;
}

implant stworz_implant() {
    implant nowy_implant;
    char tekst[100];
    do {
        printf("Podaj nazwe implantu:\n");
        scanf("%s", tekst);
        if (czy_zawiera_liczby(tekst)) {
            printf("Wprowadzono bledne dane\n");
        } else {
            strcpy(nowy_implant.nazwa, tekst);
        }
    } while (czy_zawiera_liczby(tekst));


    do {
        printf("Podaj producenta implantu:\n");
        scanf("%s", tekst);
        if (czy_zawiera_liczby(tekst)) {
            printf("Wyprowadzono bledne dane\n");
        }else {
            strcpy(nowy_implant.producent, tekst);
        }
    } while (czy_zawiera_liczby(tekst));

    do {
        printf("Podaj poziom ryzyka (1-10): \n");
        scanf("%d", &nowy_implant.poziom_ryzyka);
    } while (nowy_implant.poziom_ryzyka < 1 || nowy_implant.poziom_ryzyka > 10);

    do {
        printf("Podaj zapotrzebowanie energetyczne (dodatnie):\n");
        scanf("%d", &nowy_implant.zapotrzebowanie_energetyczne);
    } while (nowy_implant.zapotrzebowanie_energetyczne < 0);

    int legalnosc = 0;
    do {
        printf("Podaj status legalnosci\n1.Legalny\n2.Nielegalny\n3.Szara strefa\nWybor:\n");
        scanf("%d", &legalnosc);

        switch (legalnosc) {
            case 1:
                nowy_implant.status = LEGALNY;
                break;
            case 2:
                nowy_implant.status = NIELEGALNY;
                break;
            case 3:
                nowy_implant.status = SZARA_STREFA;
                break;
            default:
                printf("Niepoprawny wybor! Sprobuj ponownie.\n");
                legalnosc = 0;
                break;
        }
    } while (legalnosc < 1 || legalnosc > 3);

    do {
        printf("Podaj id wlasciciela:\n");
        scanf("%d", &nowy_implant.id_wlasciciela);
    } while (nowy_implant.id_wlasciciela < 0);

    return nowy_implant;
}

void wypisz_implant(implant *implant_do_wypisania) {
    printf("Nazwa: %s\n", implant_do_wypisania->nazwa);
    printf("Producent: %s\n", implant_do_wypisania->producent);
    printf("Poziom ryzyka: %d\n",implant_do_wypisania->poziom_ryzyka);
    printf("Zapotrzebowanie energetyczne: %d\n",implant_do_wypisania->zapotrzebowanie_energetyczne);
    printf("Status: ");
    switch (implant_do_wypisania->status) {
        case 0:
            printf("Legalny\n");
            break;
        case 1:
            printf("Nielegalny\n");
            break;
        case 2:
            printf("Szara strefa\n");
            break;
        default:
            printf("Nieznany\n");
            break;
    }

    printf("Id wlasciciela: %d\n",implant_do_wypisania->id_wlasciciela);

}

int main() {
    implant pierwszy = stworz_implant();
    printf("%s\n", pierwszy.nazwa);
    wypisz_implant(&pierwszy);
}
