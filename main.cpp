#include <iostream>
#include "arvore.h"

using namespace std;

int main(){
    Arvore<int> arvore;
    criaArvore(arvore);
    addElem(arvore,5);
    addElem(arvore,6);
    addElem(arvore,4);
    addElem(arvore,2);
    addElem(arvore,7);
    mostrarArvore(arvore); 
    existeElem(arvore, 5) ? cout << " sim " << endl : cout << " nao " << endl;
    deletaArvore(arvore);
}