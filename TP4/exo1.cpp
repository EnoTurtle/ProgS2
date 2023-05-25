#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChildIndex(int nodeIndex)
{
//    return this->leftChildIndex(nodeIndex);
    return (nodeIndex * 2) + 1;
//    return 0;
}

int Heap::rightChildIndex(int nodeIndex)
{
//    return this->rightChildIndex(nodeIndex);
    return (nodeIndex * 2) + 2;
//    return 0;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
    int i = heapSize;

//    int heap[i];
    this->get(i) = value;
    while(i>0 &&  this->get(i) >  this->get((i-1)/2)){
        swap( (i),  (i-1)/2);
        i = (i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i

	int i_max = nodeIndex;
    int largest = heapSize;

    if(leftChildIndex(nodeIndex) < largest && this->get(leftChildIndex(nodeIndex)) > this->get(i_max)){
        i_max = leftChildIndex(nodeIndex);
    }

    if(rightChildIndex(nodeIndex) < largest && this->get(rightChildIndex(nodeIndex)) > this->get(nodeIndex)){
        i_max = rightChildIndex(nodeIndex);
    }

    if(largest != i_max){
        swap((i_max), (nodeIndex));
        heapify(largest, i_max);
    }
}

void Heap::buildHeap(Array& numbers)
{
    int heapSize = numbers.size();
    for(int i=0; i<heapSize-1; i++){
        insertHeapNode(heapSize, numbers[i]);
    }
}

void Heap::heapSort()
{
    int heapSize = size();

    for (int i = heapSize - 1; i > 0; i--) {
        swap(0, i);
        heapSize--;
        heapify(heapSize, 0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
