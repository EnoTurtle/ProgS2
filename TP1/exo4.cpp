#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

void allEvens(Array& evens, Array& array, int evenSize, int arraySize)
{
    Context _("allEvens", evenSize, arraySize); // do not care about this, it allow the display of call stack

    // rempli evens avec tous les nombres paires de array.
    // evenSize représente le nombre de valeur dans evens
    // (est donc égal à 0 au début) et arraySize est le nombre de valeur dans array.
    int compteur_evens = 0;
    int compteur_array = 0;

    for(int i=0; i<arraySize; i++){
        if(array[compteur_array]%2 == 0){
            evens[compteur_evens]=array[compteur_array];
            compteur_evens++;
        }
        compteur_array++;
    }
//    return_and_display(evens);
     return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new AllEvensWindow(allEvens); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}




