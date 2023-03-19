#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
//    binarySearch(Array array, int toSearch) : retourne l’index de la valeur toSearch ou −1 si la valeur n’est pas dans le tableau
//    t ⇐ tableau de n nombre aléatoire triés
//    toSearch ⇐ nombre à chercher
//    start ⇐ 0
//    end ⇐ n
//    Tant que start < end faire
//    mid ⇐ start+end
//    2
//    Si toSearch > t[mid] Alors
//    start ⇐ mid + 1
//    Sinon Si toSearch < t[mid] Alors
//    end ⇐ mid
//    Sinon
//    foundIndex ⇐ mid
//    Arrêt
//    fin Si
//    fin Tant que
    int start = 0;
    int end = array.size();
    int mid;
    while(start<end){
        mid = (start+end)/2;
        if(toSearch > array[mid]){
            start = mid+1;
        }else
            if(toSearch < array[mid]){
                end = mid;
            }else{
                return mid;
            }
    }
	return -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
