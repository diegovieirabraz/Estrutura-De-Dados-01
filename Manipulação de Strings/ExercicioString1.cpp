#include <iostream>
#include <windows.h>
#include <locale.h>
#include <string>

using namespace std;

void gotoxy(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition(
	GetStdHandle (STD_OUTPUT_HANDLE), coord
							);
}
int centralizar(const string& msg)
{	
	int tamanho = msg.length();
	return (80-tamanho)/2;	
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string msg;
	cout << "Digite a mensagem"<< endl;
	getline(cin, msg);
	
	int xInicial = centralizar(msg);
	gotoxy(xInicial , 5);
	
	cout << msg << endl;
	
	for (size_t i = 0; i < msg.length(); i++)
	 {
        char letra = msg[i];
        int x = xInicial + i;

        
        for (int y = 6; y <= 20; y++) {
            gotoxy(x, y - 1); 
			cout << " ";
            gotoxy(x, y);
  	 	 	cout << letra;
            Sleep(40); 
        }
    }
	return 0;
}
