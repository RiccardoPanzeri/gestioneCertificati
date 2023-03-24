#include <stdio.h>
#include "prototipi.h"
int contaSingoloAnno(Data data1, Data data2){
	bool febbraio = false;//variabile booleana che mi serve per controllare se febbraio viene preso in considerazione;
	int totale = 0;
	int mesi[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (data1.anno != data2.anno || data1.mese > data2.mese) {
		return -1;//se gli anni non coincidono o i mesi sono in un'ordine impossibile, la funzione restituisce -1;
	}
	if (data1.mese == data2.mese) {
		return data2.giorno - data1.giorno;//se le due date hanno lo stesso mese, mi basta una semplice sottrazione tra i giorni;
	}
	totale = (mesi[data1.mese - 1] - data1.giorno) + data2.giorno;
	printf("%d\n", totale);
	for (int i = data1.mese; i < (data2.mese - 1); i++) {//l'indice parte dal mese e non da mese -1, perchè cosi facendo, non aggiungo di nuovo anche il mese di partenza;
		printf("%d + ", totale);
		totale += mesi[i];//aggiungo i giorni di ogni mese che sta tra le due date;
		printf("%d = %d\n", mesi[i], totale);
		if (i == 2) { //Siccome non conto il mese iniziale nel ciclo for, ora l'indice i e il mese della struct sono in pari: se i == 2, allora corrisponde a febbraio.
			febbraio = true;//se viene utilizzato il mese di febbraio nell'array, il booleano cambia valore, e so chè il controllo sul bisestile va effettuato.
		}
		
	}
	if (febbraio == true) {//se il booleano febbraio è vero, sono sicuro che Febbraio è compreso nel calcolo;
		if ((data1.mese != 2 && data2.mese != 2) || (data1.mese == 2 && data1.giorno < 29) || (data1.mese == 2 && data2.mese > 2 && data1.giorno < 29) || (data2.mese == 2 && data2.giorno > 28)) {//ho provato a prendere in considerazione anche l'opzione in cui la datache tocca febbraio si fermi prima del 29, o cominci il 29 stesso;
			if ((data1.anno % 4 == 0  && data1.anno % 100 != 0) || (data1.anno % 4 == 0 && (data1.anno % 100 == 0 && data1.anno % 400 == 0))){//siccome questa funzione prende in esame solo due date con anno uguale, posso verificare che solo l'anno della prima rispetti le condizioni della formula per il bisestile; 
				totale += 1;
				printf("%s\n", "l'anno è bisestile");
			}
		}
	}
	return totale;

}