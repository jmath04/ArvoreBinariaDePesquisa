#include <iostream>
#include "arvore.h"

using namespace std;



int main(){
    int numero;
    Arvore<int> par;
    Arvore<int> impar;
    criaArvore(par);
    criaArvore(impar);
    char resp;
    do{
        cout << "Digite um numero de 10 a 80" << endl;
        cin >> numero;
        if(numero >= 10 and numero <= 80){
            if(numero % 2 == 0){
                addElem(par,numero);
            }else{
                addElem(impar,numero);
            }
        }
        cin.ignore();
        cout << "mais um numero?(S/N): " << endl;
        resp = toupper(cin.get());
    }while(resp != 'N');
    cout << " par: " << endl;
    mostrarArvore(par);
    cout << endl << "impar: " << endl;
    mostrarArvore(impar);
    deletaArvore(par);
    deletaArvore(impar); 
}
