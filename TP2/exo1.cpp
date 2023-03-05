#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
//    t ⇐ tableau de nombre aléatoire
//    Pour chaque indice i de t faire
//    chercher le minimum à partir de i
//    inverser le minimum et la case courante
//    fin Pour
    // On parcours le tableau i fois au total, en avançant d'une case à chaque fois
    for(uint i=0; i<toSort.size(); i++){
        // On utilise un compteur pour se souvenir de l'indice du tableau le plus petit
        int comp = i;

        // On parcours le tableau pour trouver la valeur la plus petite
        for(uint j=i+1; j<toSort.size(); j++){
            // Si on trouve une valeur plus petite
            if(toSort[j] < toSort[comp]){
                // Notre compteur retient son emplacement dans le tableau
                comp = j;
            }
        }

        // On inverse les valeurs (celle de l'indice auquel on est avec la plus petite) à l'aide d'une variable temporaire
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
