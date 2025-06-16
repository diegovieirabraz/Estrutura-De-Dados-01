#include <iostream>
using namespace std;

#define MAX 100  

struct Fila
{
    int senhas[MAX];
    int ini;
    int fim;
};

Fila* init()
{
    Fila *f = new Fila;
    f->ini = 0;
    f->fim = 0;
    return f;
}

int isEmpty(Fila *f)
{
    return (f->ini == f->fim);
}

int incrementa(int i)
{
    return (i == MAX-1 ? 0 : i+1);
}

int isFull(Fila *f)
{
    return (incrementa(f->fim) == f->ini);
}

int count(Fila *f)
{
    int qtde = 0;
    int i = f->ini;
    while (i != f->fim)
    {
        qtde++;
        i = incrementa(i);
    }
    return qtde;
}

int enqueue(Fila *f, int senha)
{
    if (isFull(f))
    {
        return 0; 
    }
    
    f->senhas[f->fim] = senha;
    f->fim = incrementa(f->fim);
    return 1; 
}

int dequeue(Fila *f)
{
    if (isEmpty(f))
    {
        return -1; 
    }
    
    int ret = f->senhas[f->ini];
    f->ini = incrementa(f->ini);
    return ret;
}

void freeFila(Fila *f)
{
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
                if (isFull(senhasGeradas))
                {
                    cout << "\nFila de senhas esta cheia!\n";
                }
                else
                {
                    enqueue(senhasGeradas, proximaSenha);
                    cout << "\nSenha gerada: " << proximaSenha << "\n";
                    proximaSenha++;
                }
                break;
                
            case 2:
                if (isEmpty(senhasGeradas))
                {
                    cout << "\nNenhuma senha aguardando atendimento!\n";
                }
                else
                {
                    int senhaAtendida = dequeue(senhasGeradas);
                    if (isFull(senhasAtendidas))
                    {
                        cout << "\nErro: Fila de senhas atendidas esta cheia!\n";

                        enqueue(senhasGeradas, senhaAtendida);
                    }
                    else
                    {
                        enqueue(senhasAtendidas, senhaAtendida);
                        cout << "\nAtendendo senha: " << senhaAtendida << "\n";
                    }
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