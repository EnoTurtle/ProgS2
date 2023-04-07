#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child

        // Création d'un nouveau noeud avec notre valeur dedans
        SearchTreeNode* newNode  = new SearchTreeNode(value);

        // Si il y a une valeur à gauche plus grande que notre valeur on va à droite
        if(this->value > value && this->left != nullptr){
            this->left->insertNumber(value);
        }else // Sinon si il y a une valeur à droite plus petite que notre valeur on va à droite
        if(this->value < value && this->right != nullptr){
            this->right->insertNumber(value);
        }

        // Si il n'y a pas de valeur à gauche et que notre valeur est plus petite alors on met notre nouveau noeud à gauche
        if(this->value > value && this->left == nullptr){
            this->left = newNode;
        }else // Sinon si il n'y a pas de valeur à droite et que notre valeur est plus grande alors on met notre nouveau noeud à droite
        if(this->value < value && this->right == nullptr){
            this->right = newNode;
        }
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        if(isLeaf() == true){
            return 1;
        }
        int left = 0;
        int right = 0;

        if(this->left != nullptr){
            left = this->left->height();
        }
        if(this->right != nullptr){
            right = this->right->height();
        }

        if(left > right){
            return (left+1);
        }
        if(left <= right){
            return (right+1);
        }

//        return ((left > right ? left : right) + 1);
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if(isLeaf()){
            return 1;
        }

        int left = 0;
        int right = 0;

        if(this->left != nullptr){
            left = this->left->nodesCount();
        }
        if(this->right != nullptr){
            right = this->right->nodesCount();
        }
        return (1+right+left);

    }

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->right == nullptr && this->left == nullptr){
            return true;
        }
        return false;
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        int left = 0;
        int right = 0;

        // Si c'est une feuille
        if(isLeaf()){
            // On remplit le tableau a la position leavesCount avec la valeur de la feuille
            leaves[leavesCount] = this;
            // On incrémente LeavesCount de 1
            leavesCount += 1;
        }else
        // Si il reste des éléments à gauche
        if(this->left != nullptr){
            // On rappelle la fonction pour les branches de gauche
            this->left->allLeaves(leaves, leavesCount);
        }
        // Si il reste des éléments à droite
        if(this->right != nullptr){
            // On rappelle la fonction pour les branches de droite
            this->right->allLeaves(leaves, leavesCount);
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        //  rempli le tableau nodes en parcourant l’arbre dans l’ordre infixe (fils gauche, parent, fils droit)

        // Si il reste des éléments à droite
        if(this->left != nullptr){
            this->left->inorderTravel(nodes, nodesCount);
        }
        nodes[nodesCount] = this;
        nodesCount += 1;

        // Si il reste des éléments à droite
        if(this->right != nullptr){
            this->right->inorderTravel(nodes, nodesCount);
        }

	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount] = this;
        nodesCount += 1;

        if(this->left != nullptr){
            this->left->preorderTravel(nodes, nodesCount);
        }


        // Si il reste des éléments à droite
        if(this->right != nullptr){
            this->right->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel

        if(this->left != nullptr){
            this->left->postorderTravel(nodes, nodesCount);
        }

        // Si il reste des éléments à droite
        if(this->right != nullptr){
            this->right->postorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount += 1;
	}

    Node* find(int value) {
            // find the node containing value
            // Si c'est la valeur qu'on cherche
            if(this->value == value){
                return this;
            }

            // Sinon, si la valeur est inférieure à celle de gauche : on va à gauche
            else if(value < this->value && this->left != nullptr){
                this->left->find(value);
            }

            // Sinon, si la valeur est suppérieure à celle de droite : on va à droite
            else if(value > this->value && this->right != nullptr){
                this->right->find(value);
            }
        }

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
