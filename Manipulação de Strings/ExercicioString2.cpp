#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
    string msg, formatada = "";
    cout << "Digite uma palavra ou frase para verificar se � um pal�ndromo:" << endl;
    getline(cin, msg);

    for (int i = 0; i < msg.size(); i++)
    {
        if (msg[i] != ' ')
        {
            formatada += toupper(msg[i]);
        }
    }

    bool ehPalindromo = true;
    int n = formatada.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (formatada[i] != formatada[n - 1 - i])
        {
            ehPalindromo = false;
            break;
        }
    }

    if (ehPalindromo)
    {
        cout << "� um pal�ndromo!" << endl;
    }
    else
    {
        cout << "N�o � um pal�ndromo." << endl;
    }

    return 0;
}
