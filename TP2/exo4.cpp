#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
//    t ⇐ tableau de nombre aléatoire
//    pivot ⇐ un nombre quelconque de t
//    lowers ⇐ [n ∈ t tel que n < pivot]
//    greaters ⇐ [n ∈ t tel que n > pivot]
//    trier lowers et greaters
//    fusionner lowers, pivot et greaters

	// stop statement = condition + return (return stop the function even if it does not return anything)
	
    // Création du pivot (qui vaut la moitié de la taille du tableau)
    int pivot = size/2;

    // Création des deux tableaux qui contiendrons les "moitié" de tableau
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

    // split : On va séparer le tableau en deux
    // On parcours la première moitié du tableau
    for(int i=0; i<= pivot-1; i++){
        // On remplit un des tableaux crées avec le grand tableau
        lowerArray[i] = toSort[i];
    }
    int compteur = 0;
    // On parcours la seconde moitié du tableau
    for(int i=pivot; i<= size-1; i++){
        // On remplit l'autre tableau crée avec le grand tableau
        greaterArray[compteur] = toSort[i];
        compteur++;
    }
	
    // recursiv sort of lowerArray and greaterArray : On rappelle la fonction tant que la taille des tableaux est plus grande que 1
    if(size>1){
        return(recursivQuickSort(lowerArray, pivot));
        return(recursivQuickSort(greaterArray, pivot));
    }

    // merge : on va fusionner les tableaux dans le bon ordre
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
