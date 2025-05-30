#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 30

struct Pilha {
    int qtde;
    int elementos[MAX];
};

Pilha* init() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->qtde = 0;
    return p;
}

int isEmpty(Pilha* p) {
    return p->qtde == 0;
}

void push(Pilha* p, int v) {
    if (p->qtde < MAX) {
        p->elementos[p->qtde++] = v;
    }
}

int pop(Pilha* p) {
    if (!isEmpty(p)) {
        return p->elementos[--p->qtde];
    } else {
        return -1;
    }
}

void freePilha(Pilha* p) {
    free(p);
}

int main() {
    Pilha* pilhaPar = init();
    Pilha* pilhaImpar = init();
    
    int valor, anterior = -999999;

    for (int i = 0; i < MAX; ) {
        cout << "Digite o " << (i + 1) << "o numero: ";
        cin >> valor;
        
        if (valor > anterior) {
            anterior = valor;
            if (valor % 2 == 0) {
                push(pilhaPar, valor);
            } else {
                push(pilhaImpar, valor);
            }
            i++;
        } else {
            cout << "Erro! O numero deve ser maior que o anterior." << endl;
        }
    }

    cout << "\nDesempilhando em ordem decrescente:\n";

    while (!isEmpty(pilhaPar) || !isEmpty(pilhaImpar)) {
        int topoPar = isEmpty(pilhaPar) ? -999999 : pilhaPar->elementos[pilhaPar->qtde - 1];
        int topoImpar = isEmpty(pilhaImpar) ? -999999 : pilhaImpar->elementos[pilhaImpar->qtde - 1];

        if (topoPar > topoImpar) {
            cout << "Par: " << pop(pilhaPar) << endl;
        } else {
            cout << "Impar: " << pop(pilhaImpar) << endl;
        }
    }

    freePilha(pilhaPar);
    freePilha(pilhaImpar);

    return 0;
}
