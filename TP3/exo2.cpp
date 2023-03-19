#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
//    binarySearchAll(Array array, int toSearch, int indexMin, int indexMax) : rempli l’index minzimum et maximum de la valeur toSearch. Si la valeur n’est pas dans le tableau rempli les deux index par −1
	// do not use increments, use two different binary search loop
    int start = 0;
    int end = array.size();
    int mid;
    while(start<end){
        mid = (start+end)/2;
        if(toSearch > array[mid]){
            start = mid+1;
        }else
            if(toSearch < array[mid])
            {
                end = mid;
            }else
                indexMin = mid;
                indexMax = mid;
//                while(toSearch == array[mid]){
                for(int i=0; i <50; i++){
                    if(array[indexMax+i] = toSearch)
                    {
                        indexMax = mid+i;
//                        mid = mid-1;
                    }
                    if(array[indexMin-i] = toSearch)
                    {
                        indexMin = mid-i;
//                        mid2 = mid2-1;
                    }

//                }
                start = mid+1;
            }
    }

//    return -1;
//    indexMin = indexMax = -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
