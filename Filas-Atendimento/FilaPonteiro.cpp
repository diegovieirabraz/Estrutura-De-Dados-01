#include <iostream>
using namespace std;

struct No
{
    int senha;
    No *prox;
};

struct Fila 
{
    No *ini;
    No *fim;
};

Fila *init()
{
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmpty(Fila *f)
{
    return (f->ini == NULL);
}

int count(Fila *f)
{
    int qtde = 0;
    No *no = f->ini;
    while (no != NULL)
    {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void enqueue(Fila *f, int senha)
{
    No *no = new No;
    no->senha = senha;
    no->prox = NULL;
    
    if (isEmpty(f))
    {
        f->ini = no;
    }
    else
    {
        f->fim->prox = no;		
    }
    f->fim = no;
}

int dequeue(Fila *f)
{
    int ret;
    if (isEmpty(f))
    {
        ret = -1;
    }
    else
    {
        No *no = f->ini;
        ret = no->senha;
        f->ini = no->prox;
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        delete no;
    }
    return ret;
}

void freeFila(Fila *f)
{
    No *no = f->ini;
    while (no != NULL)
    {
        No *aux = no->prox;
        delete no;
        no = aux;
    }
    delete f;
}

int main()
{
    Fila *senhasGeradas = init();
    Fila *senhasAtendidas = init();
    
    int opcao;
    int proximaSenha = 1;
    
    do {
        cout << "\n===============================\n";
        cout << "SISTEMA DE ATENDIMENTO\n";
        cout << "===============================\n";
        cout << "Senhas aguardando atendimento: " << count(senhasGeradas) << "\n";
        cout << "===============================\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Realizar atendimento\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        switch(opcao)
        {
            case 0:
                if (!isEmpty(senhasGeradas))
                {
                    cout << "\nAinda existem senhas aguardando atendimento!\n";
                    cout << "Nao e possivel sair agora.\n";
                    opcao = -1;
                }
                break;
                
            case 1:
                enqueue(senhasGeradas, proximaSenha);
                cout << "\nSenha gerada: " << proximaSenha << "\n";
                proximaSenha++;
                break;
                
            case 2:
                if (isEmpty(senhasGeradas))
                {
                    cout << "\nNenhuma senha aguardando atendimento!\n";
                }
                else
                {
                    int senhaAtendida = dequeue(senhasGeradas);
                    enqueue(senhasAtendidas, senhaAtendida);
                    cout << "\nAtendendo senha: " << senhaAtendida << "\n";
                }
                break;
                
            default:
                cout << "\nOpcao invalida!\n";
                break;
        }
        
    } while (opcao != 0);
    
    cout << "\n===============================\n";
    cout << "SISTEMA ENCERRADO\n";
    cout << "===============================\n";
    cout << "Total de senhas atendidas: " << count(senhasAtendidas) << "\n";
    cout << "===============================\n";
    
    
    freeFila(senhasGeradas);
    freeFila(senhasAtendidas);
    
    return 0;
}