#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
    // stop statement = condition + return (return stop the function even if it does not return anything)

    // Création du pivot (qui vaut la moitié de la taille du tableau)
    int pivot = toSort[size-1];

    // Création des deux tableaux qui contiendrons les "moitié" de tableau
    Array& lowerArray = w->newArray(size);
    Array& greaterArray= w->newArray(size);
    int lowerSize = 0, greaterSize = 0; // effectives sizes

    // split : On va séparer le tableau en deux
    // On parcours la première moitié du tableau
    for(int i=0; i< size-1; i++){
        // On remplit un des tableaux crées avec le grand tableau
        if(toSort[i]<pivot){
            lowerArray[lowerSize] = toSort[i];
            lowerSize++;
        }else
            if(toSort[i]>pivot){
                greaterArray[greaterSize] = toSort[i];
                greaterSize++;
            }
    }



    // recursiv sort of lowerArray and greaterArray : On rappelle la fonction tant que la taille des tableaux est plus grande que 1
    if(lowerSize>1 && greaterSize>1){
        (recursivQuickSort(lowerArray, lowerSize));
        (recursivQuickSort(greaterArray, greaterSize));
    }
    if(lowerSize>1){
        (recursivQuickSort(lowerArray, lowerSize));
    }
    if(greaterSize>1){
        (recursivQuickSort(greaterArray, greaterSize));
    }

    // merge : on va fusionner les tableaux dans le bon ordre
    // lower array avec pivot à la fin
    for(int i=0; i < lowerSize; i++){
        toSort[i] = lowerArray[i];
    }
    toSort[lowerSize] = pivot;

    // for greater array en déplaçant pour laisser la place pour le lower
    for(int i=0; i < greaterSize; i++){
        toSort[i+lowerSize+1] = greaterArray[i];
    }
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
