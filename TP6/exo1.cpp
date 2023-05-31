#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */

    for(int i=0; i<nodeCount; i++){
        this->appendNewNode(new GraphNode(i));
    }

    // On a besoin de deux boucles for car on travaille avec une matrice qui est donc en deux dimensions
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            if (adjacencies[i][j] != 0) {
                this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
            }
        }
    }
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	  */

    // Application de l'algorithme du parcours en profondeur
    visited[first->value] = true;
    for (Edge *e = first->edges; e != nullptr; e = e->next) {
        if (!visited[e->destination->value]) {
            // On ré-appelle la fonction
            deepTravel(e->destination, nodes, nodesSize, visited);
        }
    }
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);

    // Application de l'algorithme du parcours en largeur
    while (!nodeQueue.empty()) {
        GraphNode* current = nodeQueue.front();
        nodeQueue.pop();

        nodes[nodesSize++] = current;
        visited[current->value] = true;

        for (Edge *e = current->edges; e != nullptr; e = e->next) {
             if (!visited[e->destination->value]) {
                nodeQueue.push(e->destination);
            }
        }
    }
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
    **/
    // On commence par mettre le noeud actuel comme déjà visité
    visited[first->value] = true;

    for (Edge *e = first->edges; e != nullptr; e = e->next) {
        // Cas où le noeud à côté n'est pas visité, sinon le noeud a déjà été visité
        if (!visited[e->destination->value]) {
            if (detectCycle(e->destination, visited)) {
                return true;
            }
        } else {
            return true;
        }
    }

    visited[first->value] = false;
    return false;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
