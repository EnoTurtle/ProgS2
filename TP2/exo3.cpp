#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort

    // On parcours le tableau un nombre maximum de fois pour permettre tous les changements nécessaires
    for(uint i = 0; i<toSort.size()-1; i++){
        // On parcours le tableau une deuxième fois
        for(uint j=0; j<toSort.size()-1; j++){
            // Si la valeur la plus petite est après la plus grande
            if(toSort[j] > toSort[j+1]){
                // On intervertit les valeurs à l'aide d'une variable temporaire pour ne pas perdre la première valeur
                int temp = toSort[j];
                toSort[j] = toSort[j+1];
                toSort[j+1] = temp;
            }
        }
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
