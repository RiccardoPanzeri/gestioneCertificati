#include <stdio.h>
#include "prototipi.h"


int main()
{
    
    Data dataInizio;
    Data dataFine;
    
    
    dataInizio.giorno = 1;
    dataInizio.mese = 1;
    dataInizio.anno = 2024;
    dataFine.giorno = 31;
    dataFine.mese = 12;
    dataFine.anno = 2024;

    int risultato = contaSingoloAnno(dataInizio, dataFine);
    if (risultato != -1) {//controllo che le date abbiano anno uguale e mesi in ordine crescente; se non li hanno, la funzione restituisce -1 e visualizzerò il messaggio di errore;
        printf("%d\n", risultato);
    }
    else {
        printf("Attenzione: gli anni delle due date non corrispondono, oppure i mesi sono invertiti.\n");
    }

    
}


