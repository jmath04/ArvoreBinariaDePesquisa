#include <iostream> 

using namespace std;

template<typename T>
struct Nodo{
    T elem;
    Nodo<T>* direita;
    Nodo<T>* esquerda;
};

template<typename T>
struct Arvore{
    int cardinalidade;
    Nodo<T>* raiz;
};


template<typename T>
void criaArvore(Arvore<T> &arvore){
    arvore.cardinalidade = 0;
    arvore.raiz = NULL;
}

template<typename T>
int retornaCard(Arvore<T> arvore){
    return arvore.cardinalidade;
}

template<typename T>
bool ehVazia(Arvore<T> arvore){
    return arvore.cardinalidade == 0 ? true : false;
}

template<typename T>
void addElem(Arvore<T> &arvore){
    if(arvore.raiz == NULL){

    }
}

template<typename T>
void deletaArvore(Arvore<T> &arvore){
    deletaNodo(arvore.raiz);
    arvore.raiz = NULL;
    arvore.cardinalidade = 0;
}

template<typename T>
void deletaNodo(Nodo<T>* subArvore){
    if(subArvore->esquerda != NULL){
        deletaNodo(subArvore->esquerda);
    }
    if(subArvore->direita != NULL){
        deletaNodo(subArvore->direita);
    }
    delete subArvore;
}