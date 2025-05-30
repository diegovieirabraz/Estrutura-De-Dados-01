#include <iostream>
#include <stdlib.h>

using namespace std;

struct No {
    int dado;
    No* prox;
};

struct Pilha {
    No* topo;
};

Pilha* init() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, int v) {
    No* no = (No*) malloc(sizeof(No));
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

int pop(Pilha* p) {
    if (!isEmpty(p)) {
        No* no = p->topo;
        int v = no->dado;
        p->topo = no->prox;
        free(no);
        return v;
    } else {
        return -1;
    }
}

void freePilha(Pilha* p) {
    while (!isEmpty(p)) {
        pop(p);
    }
    free(p);
}

int main() {
    Pilha* pilhaPar = init();
    Pilha* pilhaImpar = init();

    int valor, anterior = -999999;

    for (int i = 0; i < 30; ) {
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
        int topoPar = isEmpty(pilhaPar) ? -999999 : pilhaPar->topo->dado;
        int topoImpar = isEmpty(pilhaImpar) ? -999999 : pilhaImpar->topo->dado;

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
