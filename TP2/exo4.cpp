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
	
    int pivot = size/2;

	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    for(int i=0; i<= pivot-1; i++){
        lowerArray[i] = toSort[i];
    }
    int compteur = 0;
    for(int i=pivot; i<= size-1; i++){
        greaterArray[compteur] = toSort[i];
        compteur++;
    }
	
	// recursiv sort of lowerArray and greaterArray
    if(size>1){
        return(recursivQuickSort(lowerArray, pivot));
        return(recursivQuickSort(greaterArray, pivot));
    }
	// merge
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
