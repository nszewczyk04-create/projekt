#include <stdlib.h>
#include <stdio.h>

typedef enum{
    LEGALNY,
    NIELEGALNY,
    SZARA_STREFA
}StatusLegalnosci;

typedef struct rejestr
{
    char nazwa[100];
    char producent[100];
    int poziom_ryzyka;
    int zapotrzebowanie_energetyczne;
    StatusLegalnosci status;
    int id_wlasciciela;
}implant;

const char* status(StatusLegalnosci s){
    switch (s)
    {
    case LEGALNY:
        return "LEGALNY";
        break;
    case NIELEGALNY:
        return "NIELEGALNY";
        break;
    case SZARA_STREFA:
        return "SZARA_STREFA";
        break;
    default:
        return "NIEZNANY"
        break;
    }
}

int unikalny(implant* baza, int rozmiar, const char* nazwa, int id_wlasciciela){
    for (int i = 0; i < rozmiar; i++){
        if (strcmp(baza[i].nazwa,nazwa) == 0 && baza[i].id_wlasciciela == id_wlasciciela){
            return 0;
        }
    }
    return 1;
}




int main(){


}