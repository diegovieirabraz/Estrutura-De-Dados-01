#include <iostream>
using namespace std;

void swap(int *primeiroElemento, int *segundoElemento) {
    int aux = *primeiroElemento;
    *primeiroElemento = *segundoElemento;
    *segundoElemento = aux;
}

void sort(int arr[], int n) {
    int elemento, i, j;
    for (i = 0; i < n-1; i++) {

        elemento = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[elemento]) {
                elemento = j;
            }
        }
        swap(&arr[elemento], &arr[i]);
    }
}

int main(int argc, char** argv) {
    int v[5] = {7, 4, 19, 0, 21};
    int qtd = sizeof(v)/sizeof(v[0]);

    cout << "Desordenado: ";
    for (int i = 0; i < qtd; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    sort(v, qtd);

    cout << "Ordenado: ";
    for (int i = 0; i < qtd; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}