#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
    LEGALNY,
    NIELEGALNY,
    SZARA_STREFA
} StatusLegalnosci;

typedef struct implant
{
    char nazwa[100];
    char producent[100];
    int poziom_ryzyka;
    int zapotrzebowanie_energetyczne;
    StatusLegalnosci status;
    int id_wlasciciela;
    struct implant *nastepny;
} implant;

bool czy_zawiera_liczby(char *tekst)
{
    int dl = strlen(tekst);
    for (int i = 0; i < dl; i++)
    {
        if (isdigit(tekst[i]))
        {
            return true;
        }
    }
    return false;
}

implant* stworz_implant(implant *pierwszy)
{
    implant *nowy_implant;
    implant *koniec = pierwszy;
    nowy_implant = malloc(sizeof(implant));
    char tekst[100];
    do
    {
        printf("Podaj nazwe implantu:\n");
        scanf(" %99[^\n]", tekst);
        if (czy_zawiera_liczby(tekst))
        {
            printf("Wprowadzono bledne dane\n");
        }
        else
        {
            strcpy(nowy_implant->nazwa, tekst);
        }
    }
    while (czy_zawiera_liczby(tekst));

    do
    {
        printf("Podaj producenta implantu:\n");
        scanf("%s", tekst);
        if (czy_zawiera_liczby(tekst))
        {
            printf("Wyprowadzono bledne dane\n");
        }
        else
        {
            strcpy(nowy_implant->producent, tekst);
        }
    }
    while (czy_zawiera_liczby(tekst));

    do
    {
        printf("Podaj poziom ryzyka (1-10): \n");
        scanf("%d", &nowy_implant->poziom_ryzyka);
    }
    while (nowy_implant->poziom_ryzyka < 1 || nowy_implant->poziom_ryzyka > 10);

    do
    {
        printf("Podaj zapotrzebowanie energetyczne (dodatnie):\n");
        scanf("%d", &nowy_implant->zapotrzebowanie_energetyczne);
    }
    while (nowy_implant->zapotrzebowanie_energetyczne < 0);

    int legalnosc = 0;
    do
    {
        printf("Podaj status legalnosci\n1.Legalny\n2.Nielegalny\n3.Szara strefa\nWybor:\n");
        scanf("%d", &legalnosc);

        switch (legalnosc)
        {
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
    }
    while (legalnosc < 1 || legalnosc > 3);

    do
    {
        printf("Podaj id wlasciciela:\n");
        scanf("%d", &nowy_implant->id_wlasciciela);
    }
    while (nowy_implant->id_wlasciciela < 0);

    nowy_implant->nastepny = NULL;
    if (pierwszy == NULL)
    {
        pierwszy = nowy_implant;
    }
    else
    {
        while (koniec->nastepny != NULL)
        {
            koniec = koniec->nastepny;
        }
        koniec->nastepny = nowy_implant;
    }
    return pierwszy;
}
void wypiszliste(implant *pierwszy)
{
    implant *nowy_implant = pierwszy;
    while (nowy_implant != NULL)
    {
        printf("Nazwa:%s\nProducent:%s\nPoziom ryzyka:%d\nZapotrzebowanie energetyczne:%d\nStatus:",nowy_implant->nazwa, nowy_implant->producent, nowy_implant->poziom_ryzyka, nowy_implant->zapotrzebowanie_energetyczne);
        switch (nowy_implant->status)
        {
            case LEGALNY:
                printf("Legalny\n");
                break;
            case NIELEGALNY:
                printf("Nielegalny\n");
                break;
            case SZARA_STREFA:
                printf("Szara strefa\n");
                break;
            default:
                printf("Nieznany\n");
                break;
        }
        printf("Id wlascicela:%d\n\n", nowy_implant->id_wlasciciela);
        nowy_implant = nowy_implant->nastepny;
    }
}

void wypisz_implant(implant *implant_do_wypisania)
{
    printf("Nazwa: %s\n", implant_do_wypisania->nazwa);
    printf("Producent: %s\n", implant_do_wypisania->producent);
    printf("Poziom ryzyka: %d\n",implant_do_wypisania->poziom_ryzyka);
    printf("Zapotrzebowanie energetyczne: %d\n",implant_do_wypisania->zapotrzebowanie_energetyczne);
    printf("Status: ");
    switch (implant_do_wypisania->status)
    {
    case LEGALNY:
        printf("Legalny\n");
        break;
    case NIELEGALNY:
        printf("Nielegalny\n");
        break;
    case SZARA_STREFA:
        printf("Szara strefa\n");
        break;
    default:
        printf("Nieznany\n");
        break;
    }

    printf("Id wlasciciela: %d\n",implant_do_wypisania->id_wlasciciela);

}

void wyszukaj_implant(implant *pierwszy)
{
    implant *nowy_implant = pierwszy;
    char nazwa_znaleziona[100];
    printf("Podaj nazwe implantu do znalezienia:\n");
    scanf("%s", nazwa_znaleziona);
    while (nowy_implant != NULL)
    {
        if (strcmp(nowy_implant->nazwa, nazwa_znaleziona) == 0)
        {
            printf("---ZNALEZIONO IMPLANT---\n");
            printf("Nazwa: %s\nProducent: %s\nPoziom ryzyka: %d\nZapotrzebowanie energetyczne: %d\nStatus: ",nowy_implant->nazwa, nowy_implant->producent, nowy_implant->poziom_ryzyka, nowy_implant->zapotrzebowanie_energetyczne);
            switch (nowy_implant->status)
            {
            case LEGALNY:
                printf("Legalny\n");
                break;
            case NIELEGALNY:
                printf("Nielegalny\n");
                break;
            case SZARA_STREFA:
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
    if (nowy_implant == NULL)
    {
        printf("Nieznaleziono implantu o podanej nazwie");
    }
}

void zmodyfikuj_implant(implant *pierwszy)
{
    if (pierwszy == NULL)
    {
        printf("Lista jest pusta\n");
        return;
    }
    char implant_do_modyfikacji[100];
    printf("Podaj nazwe implantu do modyfikacji:\n");
    scanf("%s", implant_do_modyfikacji);

    implant *temp = pierwszy;
    while (temp != NULL)
    {
        if (strcmp(temp->nazwa, implant_do_modyfikacji) == 0)
        {
            int opcja;
            printf("Wybierz parametr do modyfikacji:\n1.Producent\n2.Poziom ryzyka\n3.Zapotrzebowanie energetyzne\n4.Status legalnosci\n");
            scanf("%d", &opcja);
            switch (opcja)
            {
            case 1:
                printf("Producent:\n");
                scanf("%s", temp->producent);
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
            {
                int nowy_status;
                do
                {
                    printf("Status legalnosci (1.Legalny 2.Nielegalny 3.Szara strefa):\n");
                    scanf("%d", &nowy_status);
                }
                while (nowy_status < 1 || nowy_status > 3);

                if (nowy_status == 1)
                {
                    temp->status = LEGALNY;
                }
                else if (nowy_status == 2)
                {
                    temp->status = NIELEGALNY;
                }
                else
                    temp->status = SZARA_STREFA;

                break;
            }
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
implant* sortowanie(implant *pierwszy)
{
    if (pierwszy == NULL || pierwszy->nastepny == NULL)
    {
        printf("Lista jest pusta lub za krotka aby ja posortowac\n");
        return pierwszy;
    }
    int opcja;
    printf("Podaj opcje sortowania:\n");
    printf("1 - Alfabetycznie po nazwie implantu\n");
    printf("2 - Rosnaco po poziomie ryzyka\n");
    printf("Opcja:\n");
    if (scanf("%d", &opcja)!=1)
        return pierwszy;

    int zamiana;
    implant *wsk1;
    implant *wsk2 = NULL;

    do
    {
        zamiana = 0;
        wsk1 = pierwszy;
        while (wsk1->nastepny != wsk2)
        {
            int warunek=0;

            if (opcja == 1)
            {
                if (strcmp(wsk1->nazwa, wsk1->nastepny->nazwa) > 0)
                    warunek = 1;
            }
            else if (opcja == 2)
            {
                if (wsk1->poziom_ryzyka > wsk1->nastepny->poziom_ryzyka)
                    warunek = 1;
            }

            if (warunek)
            {
                char temp_nazwa[50];
                strcpy(temp_nazwa, wsk1->nazwa);
                strcpy(wsk1->nazwa, wsk1->nastepny->nazwa);
                strcpy(wsk1->nastepny->nazwa, temp_nazwa);

                char temp_prod[50];
                strcpy(temp_prod, wsk1->producent);
                strcpy(wsk1->producent, wsk1->nastepny->producent);
                strcpy(wsk1->nastepny->producent, temp_prod);

                int temp_ryzyko = wsk1->poziom_ryzyka;
                wsk1->poziom_ryzyka = wsk1->nastepny->poziom_ryzyka;
                wsk1->nastepny->poziom_ryzyka = temp_ryzyko;

                int temp_energia = wsk1->zapotrzebowanie_energetyczne;
                wsk1->zapotrzebowanie_energetyczne = wsk1->nastepny->zapotrzebowanie_energetyczne;
                wsk1->nastepny->zapotrzebowanie_energetyczne = temp_energia;

                StatusLegalnosci temp_status = wsk1->status;
                wsk1->status = wsk1->nastepny->status;
                wsk1->nastepny->status = temp_status;

                int temp_id = wsk1->id_wlasciciela;
                wsk1->id_wlasciciela = wsk1->nastepny->id_wlasciciela;
                wsk1->nastepny->id_wlasciciela = temp_id;

                zamiana = 1;
            }
            wsk1=wsk1->nastepny;
        }
        wsk2 = wsk1;
    }
    while (zamiana);

    printf("Lista posortowana\n");
    return pierwszy;
}

implant* usun_implant(implant *pierwszy)
{
    if (pierwszy == NULL)
    {
        printf("Lista jest pusta\n");
        return NULL;
    }
    char implant_do_usuniecia[100];
    printf("Podaj nazwe implantu do usuniecia:\n");
    scanf("%s", implant_do_usuniecia);

    implant *temp = pierwszy;
    implant *poprzedni = NULL;
    while (temp != NULL && strcmp(temp->nazwa, implant_do_usuniecia) != 0)
    {
        poprzedni = temp;
        temp = temp->nastepny;
    }
    if (temp == NULL)
    {
        printf("Nie znaleziono implantu o podanej nazwie\n");
        return pierwszy;
    }
    if (temp->status == NIELEGALNY)
    {
        printf("Nie mozna usunac implantu z statusem NIELEGALNY!\n");
        return pierwszy;
    }
    if (poprzedni == NULL)
    {
        pierwszy = temp->nastepny;
    }
    else
    {
        poprzedni->nastepny = temp->nastepny;
    }
    free(temp);
    printf("Implant usuniety \n");
    return pierwszy;
}

implant* odczyt_z_pliku(implant *pierwszy)
{
    char nazwa_pliku[100];
    printf("Podaj nazwe pliku z ktorego chcesz odczytac dane o implantach (z rozszerzeniem):\n");
    scanf("%s", nazwa_pliku);
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL)
    {
        printf("Nie udalo sie otworzyc pliku o nazwie %s!\n", nazwa_pliku);
        return pierwszy;
    }
    implant *temp = NULL;
    implant *koniec = pierwszy;
    if (koniec != NULL)
    {
        while (koniec->nastepny != NULL)
        {
            koniec = koniec->nastepny;
        }
    }
    char nazwa[100];
    char prod[100];
    char status[100];
    int poziom_ryzyka, zapotrzebowanie, id_wlasciciela;
    while (fscanf(plik, "%s %s %d %d %s %d", nazwa, prod, &poziom_ryzyka, &zapotrzebowanie, status, &id_wlasciciela) != EOF)
    {
        temp = malloc(sizeof(implant));
        if (temp == NULL)
        {
            printf("Blad pamieci\n");
            break;
        }
        strcpy(temp->nazwa, nazwa);
        strcpy(temp->producent, prod);
        temp->poziom_ryzyka = poziom_ryzyka;
        temp->zapotrzebowanie_energetyczne = zapotrzebowanie;
        temp->id_wlasciciela = id_wlasciciela;
        temp->nastepny = NULL;
        for (int i=0; status[i]; i++)
        {
            status[i] = tolower(status[i]);
        }
        if (strcmp(status, "legalny") == 0)
        {
            temp->status = LEGALNY;
        }
        else if (strcmp(status, "szara_strefa") == 0)
        {
            temp->status = SZARA_STREFA;
        }
        else if (strcmp(status, "nielegalny") == 0)
        {
            temp->status = NIELEGALNY;
        }
        if (pierwszy == NULL)
        {
            pierwszy = temp;
            koniec = pierwszy;
        }
        else
        {
            koniec->nastepny = temp;
            koniec = temp;
        }
    }
    printf("Poprawnie dodano dane!\n");
    fclose(plik);
    return pierwszy;
}
void zapis_do_pliku(implant* pierwszy)
{
    if (pierwszy == NULL)
    {
        printf("Lista jest pusta");
        return;
    }
    char nazwa_pliku[100];
    printf("Podaj nazwe pliku do zapisu (z roszerzeniem):");
    scanf("%s", nazwa_pliku);
    FILE *plik = fopen(nazwa_pliku, "w");
    if (plik == NULL)
    {
        printf("Blad otwarcia pliku wynikowego\n");
        return;
    }
    implant *temp = pierwszy;
    while (temp != NULL)
    {
        char status_tekst[20];
        if (temp->status == LEGALNY)
        {
            strcpy(status_tekst, "legalny");
        }
        else if (temp->status == NIELEGALNY)
        {
            strcpy(status_tekst, "nielegalny");
        }
        else
        {
            strcpy(status_tekst, "szara_strefa");
        }
        fprintf(plik, "%s\n%s\n%d\n%d\n%d\n%d\n", temp->nazwa, temp->producent, temp->poziom_ryzyka, temp->zapotrzebowanie_energetyczne, (int)temp->status, temp->id_wlasciciela);
        temp = temp->nastepny;
    }
    fclose(plik);
    printf("Zapisano do pliku\n");
}
void zwalnianie_pamieci(implant *pierwszy)
{
    implant *aktualny = pierwszy;
    implant *nastepny;
    while (aktualny != NULL)
    {
        nastepny = aktualny->nastepny;
        free(aktualny);
        aktualny = nastepny;
    }
    printf("Pamiec zostala zwolniona\n");
}
int main()
{
    implant *pierwszy = NULL;
    int opcja;
    do
    {
        printf("--- MENU ---\n");
        printf("1 - Rejestracja implantu\n");
        printf("2 - Wyszukaj implant\n");
        printf("3 - Modyfikacja implantu\n");
        printf("4 - Sortowanie implantow\n");
        printf("5 - Usuwanie implantu\n");
        printf("6 - Odczyt z pliku\n");
        printf("7 - Zapis do pliku\n");
        printf("8 - Zakonczenie programu\n");
        printf("Wybierz opcje\n");
        scanf("%d", &opcja);
        switch (opcja)
        {
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
            pierwszy = sortowanie(pierwszy);
            wypiszliste(pierwszy);
            break;
        case 5:
            pierwszy = usun_implant(pierwszy);
            break;
        case 6:
            pierwszy = odczyt_z_pliku(pierwszy);
            wypiszliste(pierwszy);
            break;
        case 7:
            zapis_do_pliku(pierwszy);
            break;
        case 8:
            zwalnianie_pamieci(pierwszy);
            printf("Zakonczono program\n");
            break;
        default:
            printf("Nie rozpoznany znak!\n");
            break;
        }
    }
    while (opcja !=8);
}
