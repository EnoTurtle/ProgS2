#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;
#define return_and_display(result) return _.store(result);

void insertionSort(Array& toSort){
    Array& sorted=w->newArray(toSort.size());
    // On met la première valeur du tableau toSort dans la première case du tableau sorted
    sorted[0] = toSort[0];
    // On parcours le tablau toSort de l'indice 1 jusqu'à sa taille
    for(uint i=1; i<toSort.size(); i++){
        // On parcours le tableau toSort de l'indice 0 jusqu'à sa taille (permet de comparer toSort à sorted)
        for(uint j=0; j<=i; j++){
            if(j==i){
                sorted[j] = toSort[i];
            }
            // Si la valeur toSort est entre deux valeurs de sorted
            if(toSort[i]<sorted[j]){
                // décaler les cases de la fin jusqu'à l'emplacement de l'index j (emplacement où il faut mettre toSort
                for(uint k=(sorted.size()-1); k>j; k--){
                    sorted[k]=sorted[k-1];
                }
                // mettre toSort[i] à la place de sorted[j] dans le cas où c'est la plus grande valeur du tableau sorted
                sorted[j] = toSort[i];
                break;
            }
        }

    }
    toSort=sorted; // update the original array
}


	


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
