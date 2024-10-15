#include <iostream>
#include "arvore.h"

using namespace std;

int main(){
    Arvore<int> arvore;
    criaArvore(arvore);
    addElem(arvore,10);
    addElem(arvore,20);
    addElem(arvore,8);
    addElem(arvore,9);
    addElem(arvore,5);
    addElem(arvore,3);
    addElem(arvore,6);
    addElem(arvore,7);
    addElem(arvore,15);
    addElem(arvore,25);
    addElem(arvore,14);
    addElem(arvore,16);
    mostrarArvore(arvore); 
    existeElem(arvore, 5) ? cout << " sim " << endl : cout << " nao " << endl;
    retiraElemArvore(arvore,8);
    mostrarArvore(arvore);
    deletaArvore(arvore);
}