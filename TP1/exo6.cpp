#include <iostream>

using namespace std;

// -----------------------------------------------------------
// Création des structures
// -----------------------------------------------------------

struct Noeud{
    int donnee;
    Noeud* suivant;
    Noeud* precedent;
};

struct DynaTableau{
    int* donnees;
    // your code
    int capacite; // capacité max du tableau
    int size; // taille du tableau
};

struct Liste{
    Noeud* premier;
    // your code
};

// -----------------------------------------------------------
// LISTES
// -----------------------------------------------------------

void initialise(Liste* liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier != nullptr){
        return false;
    }
    return true;
}

void ajoute(Liste* liste, int valeur)
{
    if(liste->premier == nullptr){
        liste->premier = new Noeud {valeur, nullptr};
        return;
    }
    Noeud* liste_a_modif = liste->premier;
    while(liste_a_modif->suivant != nullptr){
        liste_a_modif = liste_a_modif->suivant;
    }
    liste_a_modif->suivant = new Noeud {valeur, nullptr};
    return;
}

void affiche(const Liste* liste)
{
    cout << endl << endl << "Affichage liste : " << endl;
    Noeud* liste_a_modif = liste->premier;
    while(liste_a_modif != nullptr){
        cout << liste_a_modif->donnee << endl;
        liste_a_modif = liste_a_modif->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud* liste_a_modif = liste->premier;
    int value = 0;
    while(value < n){
        liste_a_modif = liste_a_modif->suivant;
        value++;
    }
    return liste_a_modif->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* liste_a_modif = liste->premier;
    int compt = 0;
    while(liste_a_modif != nullptr){
        compt++;
        if(liste_a_modif->donnee == valeur){
            return compt;
        }
        liste_a_modif = liste_a_modif->suivant;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* liste_a_modif = liste->premier;
    for(int i=0; i<n; i++){
        liste_a_modif = liste_a_modif->suivant;
    }
    liste_a_modif->donnee = valeur;
}

// -----------------------------------------------------------
// TABLEAUX
// -----------------------------------------------------------

void ajoute(DynaTableau* tableau, int valeur)
{
    // réallocation de tableaux
    if(tableau->size == tableau->capacite) {
        tableau->capacite = tableau->capacite*2;
        int* temp = new int[tableau->capacite];
        for(int i = 0; i < tableau->size; i++) {
            temp[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees; // libérer mémoire du tableau
        tableau->donnees = temp;
    }
    tableau->donnees[tableau->size] = valeur;
    tableau->size = tableau->size + 1;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int[capacite];
    tableau->capacite = capacite;
    tableau->size=0;
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->donnees != nullptr){
        return false;
    }
    return true;
}

void affiche(const DynaTableau* tableau)
{
    cout << endl << "Affichage tableau : " << endl;
    for(int i=0; i<tableau->size; i++){
        cout << tableau->donnees[i] << endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    int value = 0;
    for(int i=0; i<tableau->size; i++){
        if(value == n){
            return tableau->donnees[i];
        }
        value++;
    }
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->size; i++){
        if(tableau->donnees[i] == valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    int i;
    for(i=0; i<n; i++){
    }
    tableau->donnees[i] = valeur;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    if(liste->premier == nullptr) {
        liste->premier = new Noeud {valeur, nullptr};
        return;
    }

    Noeud* liste_a_modif = liste->premier;
    while(liste_a_modif->suivant != nullptr){
        liste_a_modif = liste_a_modif->suivant;
    }
    // liste_a_modif->donnee = valeur;
    liste_a_modif->suivant = new Noeud {valeur, nullptr};
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int val_ret = 0;
    if (liste != nullptr)
    {
        /* Pointeur vers le deuxième élément de la file. */
        Noeud* liste_a_modif = liste->premier->suivant;
        /* Valeur qu'on a enlevé de la file */
        val_ret = liste->premier->donnee;
        /* On efface le premier élément puis on le met à null. */
        free(liste), liste->premier = nullptr;
        /* On fait pointer la file vers le deuxième élément. */
        liste->premier = liste_a_modif;
    }
    return val_ret;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(DynaTableau* tableau, int valeur)
{
    if(tableau->size == tableau->capacite) {
        tableau->capacite = tableau->capacite*2;
        int* temp = new int[tableau->capacite];
        for(int i = 0; i < tableau->size; i++) {
            temp[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees; // libérer mémoire du tableau
        tableau->donnees = temp;
    }
    tableau->donnees[tableau->size] = valeur;
    tableau->size = tableau->size + 1;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(DynaTableau* tableau)
{
    int val_ret = 0;
    if (tableau->size != 0)
    {
        int taille = tableau->size;
        delete[] &tableau->donnees[taille];
        tableau->size = tableau->size-1;
        return tableau->donnees[taille];
    }
    // On prend la dernière valeur du tableau et on la retourne
    // On prend l'avant dernière valeur du tableau et on met la size à size-1
    return val_ret;
    return 0;
}

// -----------------------------------------------------------
// MAIN
// -----------------------------------------------------------

int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    // if (!est_vide(&liste))
    // {
    //     std::cout << "Oups y a une anguille dans ma liste 01" << std::endl;
    // }

    // if (!est_vide(&tableau))
    // {
    //     std::cout << "Oups y a une anguille dans mon tableau 01" << std::endl;
    // }

    // for (int i=1; i<=7; i++) {
    //     ajoute(&liste, i*7);
    //     ajoute(&tableau, i*5);
    // }


    // if (est_vide(&liste))
    // {
    //     std::cout << "Oups y a une anguille dans ma liste 02" << std::endl;
    // }

    // if (est_vide(&tableau))
    // {
    //     std::cout << "Oups y a une anguille dans mon tableau 02" << std::endl;
    // }

    // std::cout << "Elements initiaux:" << std::endl;
    // affiche(&liste);
    // affiche(&tableau);
    // std::cout << std::endl;

    // std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    // std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    // std::cout << "21 se trouve dans la liste a " << cherche(&liste, 21) << std::endl;
    // std::cout << "15 se trouve dans le tableau a " << cherche(&tableau, 15) << std::endl;

    // stocke(&liste, 4, 7);
    // stocke(&tableau, 4, 7);

    // std::cout << "Elements apres stockage de 7:" << std::endl;
    // affiche(&liste);
    // affiche(&tableau);
    // std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    DynaTableau pileTab; // DynaTableau pile;
    DynaTableau fileTab; // DynaTableau file;

    initialise(&pile);
    initialise(&file);
    initialise(&pileTab, 6);
    initialise(&fileTab, 6);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pileTab, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        retire_file(&file);
        // std::cout << retire_file(&file) << std::endl;
        affiche(&file);
        compteur--;
    }
    cout << endl;

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 7;
    while(!est_vide(&pileTab) && compteur > 0)
    {
        // std::cout << retire_pile(&pileTab) << std::endl;
        retire_pile(&pileTab);
        affiche(&pileTab);
        // cout << endl;
        compteur--;
    }
    cout << endl;

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
