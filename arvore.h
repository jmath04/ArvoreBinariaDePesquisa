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
void addElem(Arvore<T> &arvore, T elemento){
    Nodo<T>* aux = new Nodo<T>;
    aux->elem = elemento;
    aux->direita = NULL;
    aux->esquerda = NULL;
    if(arvore.raiz == NULL){
        arvore.raiz = aux;
    }else{
        addElemSub(arvore.raiz,aux);
    }
    arvore.cardinalidade++;
}
template<typename T>
void addElemSub(Nodo<T>* raiz, Nodo<T>* aux){
    if(aux->elem < raiz->elem){
        if(raiz->esquerda == NULL){
            raiz->esquerda = aux;
        }else{
            addElemSub(raiz->esquerda,aux);
        }
    }else if (raiz->direita == NULL){
        raiz->direita = aux;
        }else{
            addElemSub(raiz->direita,aux);
        }
}

template<typename T> 
void mostraNodo(Nodo<T>* nodo){
    cout << nodo->elem << " ";
    if(nodo->esquerda != NULL){
        mostraNodo(nodo->esquerda);
    }
    if(nodo->direita != NULL){
        mostraNodo(nodo->direita);
    }
}

template<typename T> 
void mostrarArvore(Arvore<T> arvore){ 
    mostraNodo(arvore.raiz);
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

template<typename T>
void deletaArvore(Arvore<T> &arvore){
    if(arvore.raiz != NULL){    
        deletaNodo(arvore.raiz);
        arvore.cardinalidade = 0;
        arvore.raiz = NULL;
    }
}

template<typename T>
bool existeElemNodo(Nodo<T>* raiz, T elem){
    if(elem == raiz->elem){
        return true;
    }
    if(raiz->direita == NULL and raiz->esquerda == NULL){
        return false;
    }
    if(elem > raiz->elem and raiz->direita != NULL){
        return existeElemNodo(raiz->direita, elem);
    }else{
        if(raiz->esquerda != NULL){
            return existeElemNodo(raiz->esquerda, elem);
        }else{
            return false;
        }
        
    }
}

template<typename T>
bool existeElem(Arvore<T> arvore, T elem){
    return existeElemNodo(arvore.raiz, elem) ? true : false;
}

template<typename T>
void retiraNdoDesempate(Nodo<T>** nodo, Nodo<T>** aux){
    if((*nodo)->direita != NULL){
        retiraNdoDesempate(&(*nodo)->direita,&(*aux));
    }else{
        (*aux)->elem = (*nodo)->elem;
        (*aux) = (*nodo);
        (*nodo) = (*nodo)->esquerda;
    }
}

template<typename T>
void retiraElemNdo(Nodo<T>** nodo, T elem){
    Nodo<T>* aux;
    if((*nodo)->elem == elem){
        aux = (*nodo);
        if((*nodo)->direita == NULL){
            (*nodo) = (*nodo)->esquerda;
        }else if((*nodo)->esquerda == NULL){
                (*nodo) = (*nodo)->direita;
        }else{
            retiraNdoDesempate(&aux->esquerda,&aux);
        }
        delete aux;
        return;
    }
    if((*nodo)->elem > elem){
        retiraElemNdo(&(*nodo)->esquerda, elem);
    }else{
        retiraElemNdo(&(*nodo)->direita, elem);
    }
}

template<typename T>
void retiraElemArvore(Arvore<T>& arvore, T elem){
    if(!existeElem(arvore,elem)){
        throw("o elemento não existe na arvore");
    }
    retiraElemNdo(&arvore.raiz,elem);
    arvore.cardinalidade--;
}



