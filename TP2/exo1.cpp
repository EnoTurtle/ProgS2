#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
	// selectionSort
//    t ⇐ tableau de nombre aléatoire
//    Pour chaque indice i de t faire
//    chercher le minimum à partir de i
//    inverser le minimum et la case courante
//    fin Pour
    for(uint i=0; i<toSort.size(); i++){
        int comp = i;
        for(uint j=i+1; j<toSort.size(); j++){
            if(toSort[j] < toSort[comp]){
                comp = j;
            }
        }
        int tmp = toSort[i];
        toSort[i] = toSort[comp];
        toSort[comp] = tmp;
        }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
