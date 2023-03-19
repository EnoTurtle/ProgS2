#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
//    t ⇐ tableau de nombre aléatoire
//    t1 ⇐ première moitié du t
//    t2 ⇐ deuxième moitié t
//    diviser et trier t1 et t2
//    Pour chaque indice i de t faire
//    t[i] ⇐ min(t1, t2)
//    fin Pour


//    int pivot = origin[(origin.size())/2];

    // stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
    int firtSize = 0, secondSize = 0;

    int size = origin.size();
	
    // split : On va séparer le tableau en deux
    // On parcours la première moitié du tableau
    for(int i=0; i< (size/2); i++){
        // On remplit un des tableaux crées avec le grand tableau
        first[firtSize] = origin[i];
        firtSize++;

    }
    // Cas nombre d'éléments positifs
    if(size%2 == 0){
        // On parcours la première moitié du tableau
        for(int i=0; i< (size/2); i++){
            second[secondSize] = origin[i+(size/2)];
            secondSize++;
        }
    }else
    // Cas nombre d'éléments positifs
    {
        // On parcours la première moitié du tableau
        for(int i=0; i<= (size/2); i++){
            second[secondSize] = origin[i+(size/2)];
            secondSize++;
        }
    }


// recursiv splitAndMerge of lowerArray and greaterArray
    if(first.size() != 1 && second.size() != 1){
        merge(first, second, origin);
        splitAndMerge(first);
        splitAndMerge(second);
    }

	// merge
}

void merge(Array& first, Array& second, Array& result)
{
uint firstCompt = 0;
uint secondCompt = 0;
    for(uint i=0; i<= first.size()-1; i++){
        for(uint j=0; j<=second.size()-1; j++){
            if(second[secondCompt]<first[firstCompt]){
                result[i] = second[secondCompt];
                secondCompt++;
                break;
            }
            if(first[firstCompt]<second[secondCompt]){
                result[i] = first[firstCompt];
                firstCompt++;
                break;
            }
            if(secondCompt == second.size()-1){
                for(int k=firstCompt; k<second.size()-1; k++){
                    result[k] = first[firstCompt];
                    firstCompt++;
                }
                break;
            }
            if(firstCompt == first.size()-1){
                for(int k=secondCompt; k<first.size()-1; k++){
                    result[k] = second[secondCompt];
                    secondCompt++;
                }
                break;
            }
        }
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
