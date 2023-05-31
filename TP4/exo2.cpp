#include <time.h>
#include <stdio.h>

#include <QApplication>
#include <QDebug>

#include "tp3.h"
#include "tp4.h"
#include "tp4_exo2.h"
#include "HuffmanNode.h"

    _TestMainWindow* w1 = nullptr;
using std::size_t;
using std::string;

void processCharFrequences(string data, Array& frequences);
void buildHuffmanHeap(const Array& frequences, HuffmanHeap& priorityMinHeap, int& heapSize);
HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode);
HuffmanNode* buildHuffmanTree(HuffmanHeap& priorityMinHeap, int heapSize);

string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree);
string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTreeRoot);


void main_function(HuffmanNode*& huffmanTree)
{
    string data = "Ouesh, bien ou bien ? Ceci est une chaine de caracteres sans grand interet";

    // this array store each caracter frequences indexed by their ascii code
    Array characterFrequences(256);
    characterFrequences.fill(0);
    // this array store each caracter code indexed by their ascii code
    string characterCodes[256];
    HuffmanHeap priorityMinHeap;
    int heapSize = 0;

    processCharFrequences(data, characterFrequences);
    displayCharacterFrequences(characterFrequences);
    buildHuffmanHeap(characterFrequences, priorityMinHeap, heapSize);
    qDebug() << priorityMinHeap.toString().toStdString().c_str();

    huffmanTree = buildHuffmanTree(priorityMinHeap, heapSize);
    huffmanTree->processCodes("");
    string encoded = huffmanEncode(data, huffmanTree);
    string decoded = huffmanDecode(encoded, *huffmanTree);

    qDebug("Encoded: %s\n", encoded.c_str());
    qDebug("Decoded: %s\n", decoded.c_str());
}


void processCharFrequences(string data, Array& frequences)
{
    /**
      * Fill `frequences` array with each caracter frequence.
      * frequences is an array of 256 int. frequences[i]
      * is the frequence of the caracter with ASCII code i
     **/

    // Your code
    frequences.fill(0);
    // On parcours le tableau de fréquences
    for(uint i = 0; i < data.size(); i++){
        frequences[data[i]]++;
    }
}

void HuffmanHeap::insertHeapNode(int heapSize, HuffmanNode* newNode)
{
    /**
      * Insert a HuffmanNode into the lower heap. A min-heap put the lowest value
      * as the first cell, so check the parent should be lower than children.
      * Instead of storing int, the cells of HuffmanHeap store HuffmanNode*.
      * To compare these nodes use their frequences.
      * this->get(i): HuffmanNode*  <-> this->get(i)->frequences
      * you can use `this->swap(firstIndex, secondIndex)`
     **/

    // Your code
    int i = heapSize;
    // On crée un nouveau noeud
    this->set(i, newNode);
    // On insère ce noeud à l'endroit voulu
    while(i>0 &&  this->get(i)->frequences < this->get((i-1)/2)->frequences){
        this->swap( (i),  (i-1)/2);
        i = (i-1)/2;
    }
}

void buildHuffmanHeap(const Array& frequences, HuffmanHeap& priorityMinHeap, int& heapSize)
{
    /**
      * Do like Heap::buildHeap. Use only non-null frequences
      * Define heapSize as numbers of inserted nodes
      * allocate a HuffmanNode with `new`
     **/

    // Your code
    heapSize = 0;
    for(uint i=0; i<frequences.size(); i++){
        if(frequences[i] != 0){
            HuffmanNode *huffmanNode = new HuffmanNode(i, frequences[i]);
            priorityMinHeap.insertHeapNode(heapSize, huffmanNode);
            heapSize++;
        }
    }

}

void HuffmanHeap::heapify(int heapSize, int nodeIndex)
{
    /**
      * Repair the heap starting from nodeIndex. this is a min-heap,
      * so check the parent should be lower than children.
      * this->get(i): HuffmanNode*  <-> this->get(i)->frequences
      * you can use `this->swap(firstIndex, secondIndex)`
     **/
    // Your code
    int i_min = nodeIndex;
    int largest = heapSize;

    if( (nodeIndex*2+1) < heapSize
        &&
        this->get((nodeIndex*2+1))->frequences < this->get(i_min)->frequences)
    {
        i_min = nodeIndex*2+1;
    }

    if( (nodeIndex*2+2) < heapSize
        &&
        this->get(nodeIndex*2+2)->frequences < this->get(i_min)->frequences)
    {
        i_min = nodeIndex*2+2;
    }

    if(nodeIndex != i_min){
        this->swap((i_min), (nodeIndex));
        this->heapify(largest, i_min);
    }
}


HuffmanNode* HuffmanHeap::extractMinNode(int heapSize)
{
    /**
      * Extract the first cell, replace the first cell with the last one and
      * heapify the heap to get a new well-formed heap without the returned cell
      * you can use `this->swap`
     **/

    // Your code
    if(heapSize != 0){
        // on échange les cellules
        this->swap(0, heapSize-1);
        // On reforme le tas
        this->heapify(heapSize-1, 0);
    }
    return(this->get(heapSize-1));
}

HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode)
{
    /**
     * Make a subtree (parent + 2 children) with the given 2 nodes.
     * These 2 characters will be the children of a new parent node which character is '\0'
     * and frequence is the sum of the 2 children frequences
     * Return the new HuffmanNode* parent
     **/
    // Your code
    // On crée le parent
    HuffmanNode *parentNode = new HuffmanNode('\0');
    // On ajoute les enfants
    if(rightNode != nullptr){
        parentNode->right = rightNode;
    }
    if(leftNode != nullptr){
        parentNode->left = leftNode;
    }
    // On calcule les fréquences
    parentNode->frequences = parentNode->right->frequences + parentNode->left->frequences;
    return parentNode;
}

HuffmanNode* buildHuffmanTree(HuffmanHeap& priorityMinHeap, int heapSize)
{
    /**
      * Build Huffman Tree from the priorityMinHeap, pick nodes from the heap until having
      * one node in the heap. For every 2 min nodes, create a subtree and put the new parent
      * into the heap. The last node of the heap is the HuffmanTree;
      * use extractMinNode()
     **/

    // Your code
    // Tant qu'on n'a pas qu'un seul noeud
    while (heapSize > 1) {
        // On récupère les deux enfants
        HuffmanNode* leftNode = priorityMinHeap.extractMinNode(heapSize);
        heapSize--;
        HuffmanNode* rightNode = priorityMinHeap.extractMinNode(heapSize);
        heapSize--;

        // On crée le parent avec la fonction précédente
        HuffmanNode* parentNode = makeHuffmanSubTree(rightNode, leftNode);
        priorityMinHeap.insertHeapNode(heapSize, parentNode);
        heapSize++;
    }

    return priorityMinHeap.get(0);
}

void HuffmanNode::processCodes(const std::string& baseCode)
{
    /**
      * Travel whole tree of HuffmanNode to determine the code of each
      * leaf/character.
      * Each time you call the left child, add '0' to the baseCode
      * and each time call the right child, add '1'.
      * If the node is a leaf, it takes the baseCode.
     **/

    // Your code
    // Si c'est une feuille on donne le code
    if(!this->left && !this->right){
        this->code = baseCode;
    }else{ // Sinon on ajoute à baseCode
        if(this->left){
            this->left->processCodes(baseCode + "0");
        }
        if(this->right){
            this->right->processCodes(baseCode + "1");
        }
    }

}

void HuffmanNode::fillCharactersArray(std::string charactersCodes[])
{
    /**
      * Fill the string array with all nodes codes of the tree
      * It store a node into the cell corresponding to its ascii code
      * For example: the node describing 'O' should be at index 79
     **/
    if (!this->left && !this->right)
        charactersCodes[this->character] = this->code;
    else {
        if (this->left)
            this->left->fillCharactersArray(charactersCodes);
        if (this->right)
            this->right->fillCharactersArray(charactersCodes);
    }
}

string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree)
{
    /**
      * Encode a string by using the huffman compression.
      * With the huffmanTree, determine the code for each character
     **/

    // Your code
    std::string charactersCodes[256]; // array of 256 huffman codes for each character
    huffmanTree->fillCharactersArray(charactersCodes);
    string encoded = "";
    // On parcours la chaine de caractères à encoder
    for(uint i = 0; i<toEncode.size(); i++){
        // On encode chaque élément
        encoded = encoded + charactersCodes[toEncode[i]];
    }

    return encoded;
}


string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTreeRoot)
{
    /**
      * Use each caracters of toDecode, which is '0' either '1',
      * to travel the Huffman tree. Each time you get a leaf, get
      * the decoded character of this node.
     **/
    // Your code
    string decoded = "";

    const HuffmanNode* monNode = &huffmanTreeRoot;

    for (char c : toDecode) {
        // Si on a un 0 alors on doit aller à gauche, sinon on va à droite
        if (c == '0') {
            monNode = monNode->left;
        } else if (c == '1') {
            monNode = monNode->right;
        }

        if (monNode->isLeaf()) {
            // On ajoute le caractère décodé à la chaine de caractères
            decoded += monNode->character;
            // On remet monNode à sa position d'origine
            monNode = &huffmanTreeRoot;
        }
    }

    return decoded;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Array::wait_for_operations = false;
    w1 = new HuffmanMainWindow(main_function);
    w1->show();
    return a.exec();
}
