#include <iostream>
using namespace std;

    const int FILEIRAS = 15;
    const int POLTRONAS = 40;
    const float preco_fileiras[FILEIRAS] = {
        50.0, 50.0, 50.0, 50.0, 50.0,
        30.0, 30.0, 30.0, 30.0, 30.0,  
        15.0, 15.0, 15.0, 15.0, 15.0
    };
    
    int teatro [FILEIRAS] [POLTRONAS] = {0};
    
    void reservarPoltrona()
    {
        int fileira, poltrona;
        
        cout << "Digite o número da fileira (1 a 15): ";
        cin >> fileira;
        cout << "Digite o numero da poltrona (1 a 40): ";
        cin >> poltrona;
         
        if(fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40) {
            cout << "Valores invalidos. Tente novamente!";
            return;
        }
    
        fileira--;
        poltrona--;
    
        if (teatro [fileira][poltrona] == 1) {
            cout << "Esse lugar já esta ocupado." << endl;
        }
        else{
            teatro [fileira][poltrona] = 1;
            cout << "Poltrona reservada com sucesso" << endl;
        }
    }
    
    void mapaDeOcupacao() 
    {
        cout << "Mapa de Ocupação" << endl;
        
        for(int i = 0; i < FILEIRAS; i++) 
        {
            for(int j = 0; j < POLTRONAS; j++) 
            {
                if (teatro [i][j] == 1)
                {
                    cout << " # ";
                }else 
                {
                    cout << " . ";
                }
            }
            cout << endl;
        }
    }
    
    void faturamento()
    {
        int lugaresOcupados = 0;
        float totalFaturamento = 0.0;
        
        for(int i = 0; i <= FILEIRAS; i++)
        {
            for(int j = 0; j <= POLTRONAS; j++)
            {
                if (teatro [i][j] == 1)
                {
                    lugaresOcupados++;
                    totalFaturamento += preco_fileiras[i];
                }
            }
        }
        cout << "Quantidade de lugares ocupado: "<< lugaresOcupados << endl;
        cout << "Valor da bilheteria é R$" << totalFaturamento << endl;
    }   
    
    int main(){
        
        int opcao;
        
        do {
        
            cout << "\nMenu:"<< endl;
            cout << "1 - Reserva poltrona" << endl;
            cout << "2 - Mapa ocupação" << endl;
            cout << "3 - Faturamento" << endl;
            cout << "0 - Finalizar" << endl;
            cin >> opcao;
            
            switch (opcao) 
            {
                case 1:
                    reservarPoltrona();
                    break;
            
                case 2:
                    mapaDeOcupacao();
                    break;
            
                case 3:
                    faturamento();
                    break;
                
                case 0:
                    cout << "Finalizando..." << endl; 
                    
                default:
                cout << "Opção invalida" << endl;
            }
        }while (opcao != 0);

    return 0;
    }