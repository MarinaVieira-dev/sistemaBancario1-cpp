#include <iostream>
#include <string>
using namespace std;
#include <iomanip> // Necessário para setprecision
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    //Declaração de Variáveis 
    int numeroConta, tipoConta, opcao;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva = false, contaCadastrada = false;

    do{
       cout<<"*****************************" <<endl;
       cout<<"**    BANCO INF101         **" <<endl;
       cout<<"*****************************" <<endl;
    
       cout<<"Digite a opcão desejada conforme o menu:" << endl;
       cout << "\n1 - Cadastrar conta" << endl;
       cout << "2 - Consultar conta" << endl;
       cout << "3 - Verificar saldo" << endl;
       cout << "4 - Alterar tipo da conta" << endl;
       cout << "5 - Ativar/Desativar conta" << endl;
       cout << "6 - Sair" << endl;
    
      cin>>opcao;

       switch (opcao){
            case 1: 
                //Leitura e Validação de Variáveis 
                //leitura de nome completo
                cout << "\n===== CADASTRO DE CONTA =====" << endl;
                cout << "Digite seu nome completo: \n";
                cin.ignore();
                getline(cin, nomeCliente); 

                //leitura de CPF
                cout<<"Digite o seu CPF no formato 000.000.000-00: \n";
                getline(cin, cpf);

                do{
                //Validação de número da conta
                    cout<<"Digite o número da conta" <<endl;
                    cin>>numeroConta;
                    if(numeroConta <= 0){
                        cout<<"Número da conta é inválido\n";
                    }
               } while(numeroConta <= 0);

                //Validação do tipo da conta
                do{
                    cout<<"Digite o tipo da conta que você deseja: 1:CONTA CORRENTE 2:CONTA POUPANÇA\n";
                    cin>>tipoConta;
                    if(tipoConta !=1 && tipoConta != 2){
                        cout<<"O tipo informado não é válido\n";
                    }
                    
                } while (tipoConta != 1 && tipoConta != 2);

                //saldo incial
                do {
                    cout<<"Digite o saldo inicial: R$ ";
                    cin>>saldo;
                    if(saldo < 0) {
                        cout << "O saldo inicial nao pode ser negativo!" << endl;
                    }
                } while (saldo < 0);

                //ativar conta e concluir cadastro
                 contaCadastrada = true;
                 contaAtiva=true;
                 cout << "Conta cadastrada com sucesso!" << endl;

                break;

            case 2:
                //Consultar  conta
                if (contaCadastrada == true && contaAtiva == true) {
                    cout << "Nome: " << nomeCliente << endl;
                    cout << "CPF: " << cpf << endl;
                    cout << "Numero da conta: " << numeroConta << endl;
                     if (tipoConta == 1) {
                        cout<<"Tipo: Conta Corrente" << endl;
                    } else {
                        cout<<"Tipo: Conta Poupanca" << endl;
                    }

                 } else if(contaCadastrada == true && contaAtiva == false) {
                    cout<<"A conta esta inativa!" << endl;
                }else{
                    cout<< "Nenhuma conta cadastrada!" << endl;
                }

                 break;

            case 3: 
                 //consultar saldo
                if (contaCadastrada == true && contaAtiva == true) {
                    cout << "Saldo: R$" << fixed << setprecision(2) << saldo << endl;
                }else if(contaCadastrada == true && contaAtiva == false) {
                    cout << "A conta esta inativa!" << endl;
                }else{
                    cout << "Nenhuma conta cadastrada!" << endl;
                }

                 break;

            case 4:
                 //alterar o tipo de conta
                if (contaCadastrada == true && contaAtiva == true) {
                    if(tipoConta == 1){
                        tipoConta = 2;
                        cout<<"Conta alterada para Conta POUPANÇA" << endl ;
                    } else {
                        tipoConta = 1;
                        cout<<"Conta alterada para Conta CORRENTE" << endl ;
                    }
                } else if(contaCadastrada == true && contaAtiva == false) {
                    cout<<"A conta esta inativa!" << endl;
                }else{
                    cout<<"Nenhuma conta cadastrada!" << endl;
                }

                 break;

            case 5:
                 //desativar ou ativar conta
                 if (contaCadastrada == true && contaAtiva == true) {
                    contaAtiva = false;
                    cout<<"Conta desativada com sucesso!" << endl;
                 } else if (contaCadastrada == true && contaAtiva==false){
                    contaAtiva = true;
                    cout<<"Sua conta foi ativada" << endl;
                 } else {
                    cout << "Nenhuma conta cadastrada!" << endl;
                 }
                 break; 

            case 6:
                cout << "Saindo do sistema." << endl;
                break;
        
        }
    } while(opcao != 6);
        
    return 0;
    
}