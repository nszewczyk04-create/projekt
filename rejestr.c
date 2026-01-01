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




int main(){


}