#include <iostream>
#include <cstddef> 

using namespace std;

const int MAX = 100;
struct FilaVetor {
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
};

FilaVetor* initFilaVetor() {
    FilaVetor* f = new FilaVetor();
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
    return f;
}

bool isFullVetor(FilaVetor* f) { return f->qtd == MAX; }
bool isEmptyVetor(FilaVetor* f) { return f->qtd == 0; }

bool enfileirarVetor(FilaVetor* f, int valor) {
    if (isFullVetor(f)) return false;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
    return true;
}

int desenfileirarVetor(FilaVetor* f) {
    if (isEmptyVetor(f)) return -1;
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return valor;
}

int tamanhoVetor(FilaVetor* f) { return f->qtd; }

struct Node {
    int valor;
    Node* prox;
};

struct FilaPtr {
    Node* inicio;
    Node* fim;
    int qtd;
};

FilaPtr* initFilaPtr() {
    FilaPtr* f = new FilaPtr();
    f->inicio = f->fim = NULL; 
    f->qtd = 0;
    return f;
}

bool isEmptyPtr(FilaPtr* f) { return f->inicio == NULL; } 

bool enfileirarPtr(FilaPtr* f, int valor) {
    Node* novo = new Node();
    novo->valor = valor;
    novo->prox = NULL; 
    if (isEmptyPtr(f)) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtd++;
    return true;
}

int desenfileirarPtr(FilaPtr* f) {
    if (isEmptyPtr(f)) return -1;
    Node* temp = f->inicio;
    int valor = temp->valor;
    f->inicio = temp->prox;
    if (f->inicio == NULL) f->fim = NULL; 
    delete temp;
    f->qtd--;
    return valor;
}

int tamanhoPtr(FilaPtr* f) { return f->qtd; }

struct Guiche {
    int id;
    FilaPtr* senhasAtendidas;
    Guiche* prox;
};

struct ListaGuiches {
    Guiche* inicio;
    int qtd;
};

ListaGuiches* initListaGuiches() {
    ListaGuiches* l = new ListaGuiches();
    l->inicio = NULL; 
    l->qtd = 0;
    return l;
}

void adicionarGuiche(ListaGuiches* l, Guiche* novoGuiche) {
    if (l->inicio == NULL) { 
        l->inicio = novoGuiche;
    } else {
        Guiche* atual = l->inicio;
        while (atual->prox != NULL) { 
            atual = atual->prox;
        }
        atual->prox = novoGuiche;
    }
    l->qtd++;
}

Guiche* buscarGuiche(ListaGuiches* l, int id) {
    Guiche* atual = l->inicio;
    while (atual != NULL) { 
        if (atual->id == id) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; 
}

int tamanhoListaGuiches(ListaGuiches* l) { return l->qtd; }

int main() {
    FilaVetor* senhasGeradas = initFilaVetor();
    ListaGuiches* guichesAbertos = initListaGuiches();

    int proximaSenha = 1;
    int proximoGuicheId = 1;
    int opcao;

    do {
        cout << "\n======================================\n";
        cout << "Senhas aguardando atendimento: " << tamanhoVetor(senhasGeradas) << "\n";
        cout << "Guiches abertos para atendimento: " << tamanhoListaGuiches(guichesAbertos) << "\n";
        cout << "--------------------------------------\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Abrir guiche\n";
        cout << "3. Realizar atendimento\n";
        cout << "4. Listar senhas atendidas por guiche\n";
        cout << "Escolha: ";
        cin >> opcao;
        cout << "======================================\n";

        switch (opcao) {
            case 1: {
                if (enfileirarVetor(senhasGeradas, proximaSenha)) {
                    cout << ">>> Senha gerada: " << proximaSenha << "\n";
                    proximaSenha++;
                } else {
                    cout << ">>> Fila cheia! Nao foi possivel gerar nova senha.\n";
                }
                break;
            }
            case 2: {
                Guiche* novoGuiche = new Guiche();
                novoGuiche->id = proximoGuicheId;
                novoGuiche->senhasAtendidas = initFilaPtr();
                novoGuiche->prox = NULL; 

                adicionarGuiche(guichesAbertos, novoGuiche);
                cout << ">>> Guiche " << proximoGuicheId << " aberto para atendimento.\n";
                proximoGuicheId++;
                break;
            }
            case 3: {
                if (isEmptyVetor(senhasGeradas)) {
                    cout << ">>> Nenhuma senha aguardando atendimento.\n";
                    break;
                }
                if (tamanhoListaGuiches(guichesAbertos) == 0) {
                    cout << ">>> Nenhum guiche aberto. Abra um guiche primeiro.\n";
                    break;
                }

                int idGuiche;
                cout << "Digite o ID do guiche que vai atender: ";
                cin >> idGuiche;

                Guiche* guiche = buscarGuiche(guichesAbertos, idGuiche);
                if (guiche != NULL) { 
                    int senha = desenfileirarVetor(senhasGeradas);
                    enfileirarPtr(guiche->senhasAtendidas, senha);
                    cout << ">>> Guiche " << idGuiche << " atendendo a senha: " << senha << "\n";
                } else {
                    cout << ">>> Guiche com ID " << idGuiche << " nao encontrado.\n";
                }
                break;
            }
            case 4: {
                 if (tamanhoListaGuiches(guichesAbertos) == 0) {
                    cout << ">>> Nenhum guiche aberto.\n";
                    break;
                }
                int idGuiche;
                cout << "Digite o ID do guiche para listar as senhas: ";
                cin >> idGuiche;

                Guiche* guiche = buscarGuiche(guichesAbertos, idGuiche);
                if (guiche != NULL) { 
                    cout << "--- Senhas atendidas pelo Guiche " << idGuiche << " ---\n";
                    if (isEmptyPtr(guiche->senhasAtendidas)) {
                        cout << "Nenhuma senha atendida por este guiche ainda.\n";
                    } else {
                        Node* atual = guiche->senhasAtendidas->inicio;
                        while (atual != NULL) { 
                            cout << "Senha: " << atual->valor << "\n";
                            atual = atual->prox;
                        }
                    }
                    cout << "--------------------------------------\n";
                } else {
                    cout << ">>> Guiche com ID " << idGuiche << " nao encontrado.\n";
                }
                break;
            }
            case 0: {
                if (!isEmptyVetor(senhasGeradas)) {
                    cout << ">>> Ainda restam " << tamanhoVetor(senhasGeradas) << " senha(s) a atender.\n";
                    cout << ">>> Finalize o atendimento antes de sair.\n";
                    opcao = -1;
                } else {
                    int totalAtendido = 0;
                    Guiche* atual = guichesAbertos->inicio;
                    while (atual != NULL) { 
                        totalAtendido += tamanhoPtr(atual->senhasAtendidas);
                        atual = atual->prox;
                    }
                    cout << ">>> Encerrando sistema. Total de senhas atendidas: " << totalAtendido << "\n";
                }
                break;
            }
            default:
                cout << ">>> Opcao invalida!\n";
        }
    } while (opcao != 0);
    
    delete senhasGeradas;
    Guiche* atual = guichesAbertos->inicio;
    while(atual != NULL) { 
        Guiche* proximo = atual->prox;
        
        while(!isEmptyPtr(atual->senhasAtendidas)){
            desenfileirarPtr(atual->senhasAtendidas);
        }
        delete atual->senhasAtendidas;
        delete atual;
        atual = proximo;
    }
    delete guichesAbertos;

    return 0;
}
