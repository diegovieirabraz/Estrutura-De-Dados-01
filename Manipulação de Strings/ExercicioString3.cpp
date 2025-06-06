#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream arquivo("nomes.txt");
    string linha;

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while (getline(arquivo, linha))
    {
        string nome[10];
        int pos = 0;
        string palavra = "";

        for (int i = 0; i <= linha.size(); i++)
        {
            if (linha[i] == ' ' || i == linha.size())
            {
                nome[pos] = palavra;
                pos++;
                palavra = "";
            }
            else
            {
                palavra += linha[i];
            }
        }

        cout << nome[pos - 1] << ", ";
        for (int i = 0; i < pos - 1; i++)
        {
            cout << nome[i];
            if (i < pos - 2)
                cout << " ";
        }
        cout << endl;
    }

    arquivo.close();
    return 0;
}
