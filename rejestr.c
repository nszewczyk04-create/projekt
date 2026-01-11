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
    struct implant *nastepny;
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

implant* stworz_implant(implant *pierwszy) {
    implant *nowy_implant;
    implant *koniec = pierwszy;
    nowy_implant = malloc(sizeof(nowy_implant));
    char tekst[100];
    do {
        printf("Podaj nazwe implantu:\n");
        scanf("%s", tekst);
        if (czy_zawiera_liczby(tekst)) {
            printf("Wprowadzono bledne dane\n");
        } else {
            strcpy(nowy_implant->nazwa, tekst);
        }
    } while (czy_zawiera_liczby(tekst));


    do {
        printf("Podaj producenta implantu:\n");
        scanf("%s", tekst);
        if (czy_zawiera_liczby(tekst)) {
            printf("Wyprowadzono bledne dane\n");
        }else {
            strcpy(nowy_implant->producent, tekst);
        }
    } while (czy_zawiera_liczby(tekst));

    do {
        printf("Podaj poziom ryzyka (1-10): \n");
        scanf("%d", &nowy_implant->poziom_ryzyka);
    } while (nowy_implant->poziom_ryzyka < 1 || nowy_implant->poziom_ryzyka > 10);

    do {
        printf("Podaj zapotrzebowanie energetyczne (dodatnie):\n");
        scanf("%d", &nowy_implant->zapotrzebowanie_energetyczne);
    } while (nowy_implant->zapotrzebowanie_energetyczne < 0);

    int legalnosc = 0;
    do {
        printf("Podaj status legalnosci\n1.Legalny\n2.Nielegalny\n3.Szara strefa\nWybor:\n");
        scanf("%d", &legalnosc);

        switch (legalnosc) {
            case 1:
                nowy_implant->status = LEGALNY;
                break;
            case 2:
                nowy_implant->status = NIELEGALNY;
                break;
            case 3:
                nowy_implant->status = SZARA_STREFA;
                break;
            default:
                printf("Niepoprawny wybor! Sprobuj ponownie.\n");
                legalnosc = 0;
                break;
        }
    } while (legalnosc < 1 || legalnosc > 3);

    do {
        printf("Podaj id wlasciciela:\n");
        scanf("%d", &nowy_implant->id_wlasciciela);
    } while (nowy_implant->id_wlasciciela < 0);

    nowy_implant->nastepny = NULL;
    if (pierwszy == NULL) {
        pierwszy = nowy_implant;
    }else {
        while (koniec->nastepny != NULL) {
            koniec = koniec->nastepny;
        }
        koniec->nastepny = nowy_implant;
    }
    return pierwszy;
}
void wypiszliste(implant *pierwszy) {
    implant *nowy_implant = pierwszy;
    while (nowy_implant != NULL) {
        printf("Nazwa:%s\nProducent:%s\nPoziom ryzyka:%d\nZapotrzebowanie energetyczne:%d\nStatus:%d\nId wlasciciela:%d\n",nowy_implant->nazwa, nowy_implant->producent, nowy_implant->poziom_ryzyka, nowy_implant->zapotrzebowanie_energetyczne, nowy_implant->status, nowy_implant->id_wlasciciela);
        nowy_implant = nowy_implant->nastepny;
    }
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

void wyszukaj_implant(implant *pierwszy) {
    implant *nowy_implant = pierwszy;
    char nazwa_znaleziona[100];
    printf("Podaj nazwe implantu do znalezienia:\n");
    scanf("%s", nazwa_znaleziona);
    while (nowy_implant != NULL) {
        if (strcmp(nowy_implant->nazwa, &nazwa_znaleziona) == 0) {
            printf("---ZNALEZIONO IMPLANT---");
            printf("Nazwa: %s\nProducent: %s\nPoziom ryzyka: %d\nZapotrzebowanie energetyczne: %d\nStatus: ",nowy_implant->nazwa, nowy_implant->producent, nowy_implant->poziom_ryzyka, nowy_implant->zapotrzebowanie_energetyczne);
            switch (nowy_implant->status) {
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
            printf("Id wlasciciela: %d\n",nowy_implant->id_wlasciciela);
            break;
        }
        nowy_implant = nowy_implant->nastepny;
    }
    if (nowy_implant == NULL) {
        printf("Nieznaleziono implantu o podanej nazwie");
    }
}

void zmodyfikuj_implant(implant *pierwszy) {
    if (pierwszy == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    char implant_do_modyfikacji[100];
    printf("Podaj nazwe implantu do modyfikacji:\n");
    scanf("%s", implant_do_modyfikacji);

    implant *temp = pierwszy;
    while (temp != NULL) {
        if (strcmp(temp->nazwa, implant_do_modyfikacji) == 0) {
            int opcja;
            printf("Wybierz parametr do modyfikacji:\n1.Producent\n2.Poziom ryzyka\n3.Zapotrzebowanie energetyzne\n4.Status legalnosci\n");
            scanf("%d", &opcja);
            switch (opcja) {
                case 1:
                    printf("Producent:\n");
                    scanf("%d", &temp->producent);
                    break;
                case 2:
                    printf("Poziom ryzyka:\n");
                    scanf("%d", &temp->poziom_ryzyka);
                    break;
                case 3:
                    printf("Zapotrzebowanie energetyzne:\n");
                    scanf("%d", &temp->zapotrzebowanie_energetyczne);
                    break;
                case 4:
                    printf("Status legalnosci:\n");
                    scanf("%d", &temp->status);
                    break;
                default:
                    printf("Nieznaleziono opcji\n");
            }
            printf("Zmodyfikowano pomyslnie\n");
            wypisz_implant(temp);
            return;
        }
        temp = temp->nastepny;
    }
    printf("Nie znaleziono implantu o podanej nazwie\n");
}

implant* usun_implant(implant *pierwszy) {
    if (pierwszy == NULL) {
        printf("Lista jest pusta\n");
        return NULL;
    }
    char implant_do_usuniecia[100];
    printf("Podaj nazwe implantu do usuniecia:\n");
    scanf("%s", implant_do_usuniecia);

    implant *temp = pierwszy;
    implant *poprzedni = NULL;
    while (temp != NULL && strcmp(temp->nazwa, implant_do_usuniecia) != 0) {
        poprzedni = temp;
        temp = temp->nastepny;
    }
    if (temp == NULL) {
        printf("Nie znaleziono implantu o podanej nazwie\n");
        return pierwszy;
    }
    if (temp->status == NIELEGALNY) {
        printf("Nie mozna usunac implantu z statusem NIELEGALNY!\n");
        return pierwszy;
    }
    if (poprzedni == NULL) {
        pierwszy = temp->nastepny;
    }else {
        poprzedni->nastepny = temp->nastepny;
    }
    free(temp);
    printf("Implant usuniety \n");
    return pierwszy;
}

implant* odczyt_z_pliku(implant *pierwszy) {
    char nazwa_pliku[100];
    printf("Podaj nazwe pliku z ktorego chcesz odczytac dane o implantach (z rozszerzeniem):\n");
    scanf("%s", nazwa_pliku);
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku o nazwie %s!\n", nazwa_pliku);
        return pierwszy;
    }
        implant *temp = NULL;
        implant *koniec = pierwszy;
        if (koniec != NULL) {
            while (koniec->nastepny != NULL) {
                koniec = koniec->nastepny;
            }
        }
        char nazwa[100];
        char prod[100];
        char status[100];
        int poziom_ryzyka, zapotrzebowanie, id_wlasciciela;
        while (fscanf(plik, "%s %s %d %d %s %d", nazwa, prod, &poziom_ryzyka, &zapotrzebowanie, status, &id_wlasciciela) != EOF) {
            temp = malloc(sizeof(implant));
            if (temp == NULL) {
                printf("Blad pamieci\n");
                break;
            }
            strcpy(temp->nazwa, nazwa);
            strcpy(temp->producent, prod);
            temp->poziom_ryzyka = poziom_ryzyka;
            temp->zapotrzebowanie_energetyczne = zapotrzebowanie;
            temp->id_wlasciciela = id_wlasciciela;
            temp->nastepny = NULL;
            for (int i=0; status[i]; i++) {
                status[i] = tolower(status[i]);
            }
            if (strcmp(status, "legalny") == 0) {
                temp->status = LEGALNY;
            }else if (strcmp(status, "szara_strefa") == 0) {
                temp->status = SZARA_STREFA;
            }else if (strcmp(status, "nielegalny") == 0) {
                temp->status = NIELEGALNY;
            }
            if (pierwszy == NULL) {
                pierwszy = temp;
                koniec = pierwszy;
            }else {
                koniec->nastepny = temp;
                koniec = temp;
            }
        }
    printf("Poprawnie dodano dane!\n");
    fclose(plik);
    return pierwszy;
}
int main() {
    implant *pierwszy = NULL;
    int opcja;
    do {
        printf("--- MENU ---\n");
        printf("1 - Rejestracja implantu\n");
        printf("2 - Wyszukaj implant\n");
        printf("3 - Modyfikacja implantu\n");
        printf("4 - Sortowanie implantow\n");
        printf("5 - Usuwanie implantu\n");
        printf("6 - Zapis/odczyt z pliku\n");
        printf("7 - Zakonczenie programu\n");
        printf("Wybierz opcje\n");
        scanf("%d", &opcja);
        switch (opcja) {
            case 1:
                pierwszy = stworz_implant(pierwszy);
                break;
            case 2:
                wyszukaj_implant(pierwszy);
                break;
            case 3:
                zmodyfikuj_implant(pierwszy);
                break;
            case 4:

                break;
            case 5:
                usun_implant(pierwszy);
                break;
            case 6:
                pierwszy = odczyt_z_pliku(pierwszy);
                wypiszliste(pierwszy);
                break;
            case 7:
                printf("Zakonczono program\n");
                break;

        }
    }while (opcja !=7);
}
