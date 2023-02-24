#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);


int search(int value, Array& toSort, int size)
{
    Context _("search", value, size); // do not care about this, it allow the display of call stack

    //  retourne l’index de value dans array
    // (pour ce faire, il faudra parcourir le tableau dans le sens inverse en accédant à chaque appel à la dernière case)
    if (size == 0){
        return 0;
    }
    // check the last cell and if it does not correspond
    if(toSort[value] == value){
        return_and_display(size);
    }else{
        // then consider a smaller array when recalling search
        return_and_display(search(value, toSort, size-1));
    }
//    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new SearchWindow(search); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}




