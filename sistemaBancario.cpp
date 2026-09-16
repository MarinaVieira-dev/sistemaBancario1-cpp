#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    
     SetConsoleOutputCP(CP_UTF8);
     SetConsoleCP(CP_UTF8);
    //opcao escolhida no menu
    int opcao;

    // Vetores para armazenar os dados das 5 contas
    int numeroConta[5];
    string nomeCliente[5];
    string cpf[5];
    int tipoConta[5];
    double saldo[5];
    bool contaAtiva[5];

    // Para verificar se as 5 contas foram cadastradas
    bool contasCadastradas = false;

    do {
        cout<<"*****************************"<<endl;
        cout<<"**    BANCO INF101         **"<<endl;
        cout<<"*****************************"<<endl;

        cout<<"Digite a opcão desejada conforme o menu:"<< endl;

        cout << "1 - Cadastrar conta"<< endl;
        cout << "2 - Consultar conta"<< endl;
        cout << "3 - Verificar saldo"<< endl;
        cout << "4 - Alterar tipo da conta"<< endl;
        cout << "5 - Ativar/Desativar conta"<< endl;
        cout << "6 - Sair" << endl;
        
        cin>>opcao;

        switch (opcao) {
            case 1:
                cout << " CADASTRO DE 5 CONTAS"<< endl;

                for(int i = 0; i < 5; i++){ //percorre as posições de 0 a 4 
                    //Leitura e Validação de Variáveis 
                    //leitura de nome completo
                    cout<<"Digite o nome completo: ";
                    cin.ignore();
                    getline(cin, nomeCliente[i]);

                    //leitura de CPF
                    cout<<"Digite o CPF: ";
                    getline(cin, cpf[i]);

                    do {
                        //Validação de número da conta
                        cout<<"Digite o numero da conta: ";
                        cin>>numeroConta[i];

                        if(numeroConta[i] <= 0) {
                            cout<< "Numero da conta invalido!"<< endl;
                        }

                    }while(numeroConta[i] <= 0);

                   
                    do {
                        //validação do tipo da conta
                        cout<<"Digite o tipo da conta que você deseja: 1:CONTA CORRENTE 2:CONTA POUPANÇA\n";
                        cin>>tipoConta[i];
                        
                        //verifica se é diferente de 1 ou 2
                        if(tipoConta[i] != 1 && tipoConta[i] != 2){
                            cout<<"Tipo de conta invalido!" << endl;
                        }

                    }while(tipoConta[i] != 1 && tipoConta[i] != 2);

                    
                    do{
                        //validação de saldo
                        cout<<"Digite o saldo inicial: R$ ";
                        cin>>saldo[i];

                        if(saldo[i] < 0){
                            cout<<"O saldo nao pode ser negativo!"<< endl;
                        }

                    }while (saldo[i] < 0);

                    //quando a conta é criada a conta já fica ativa automaticamente
                    contaAtiva[i] = true;

                    cout<<"Conta cadastrada com sucesso!"<< endl;
                }

                contasCadastradas = true; //todas as 5 contas foram cadastradas

                break;


           
            case 2:
            //consultar conta
                if (contasCadastradas == false){
                    cout<<"Nenhuma conta cadastrada!"<< endl;

                }else{
                    for(int i = 0; i < 5; i++){
                        cout<< "Nome: "<< nomeCliente[i] << endl;

                        cout << "CPF: "<< cpf[i] << endl;

                        cout << "Numero da conta: " << numeroConta[i] << endl;

                        if(tipoConta[i] == 1){
                            cout<< "Tipo: Conta Corrente"<< endl;
                        }else{
                            cout<< "Tipo: Conta Poupanca"<< endl;
                        }

                        if(contaAtiva[i] == true) {
                            cout<< "Situacao: Ativa"<< endl;
                        }else{
                            cout<< "Situacao: Inativa"<< endl;
                        }
                    }
                }
                break;

            case 3:
                //consultar saldo
                if(contasCadastradas == false){

                    cout<< "Nenhuma conta cadastrada!"<< endl;

                }else{
                    for(int i = 0; i < 5; i++) {
                        cout<< "\nConta: "<< numeroConta[i]<< endl;
                        if(contaAtiva[i] == true){
                            cout << "Saldo: R$ "<< fixed << setprecision(2) << saldo[i]<< endl;
                        }else{
                            cout<< "A conta esta inativa!"<< endl;
                        }
                    }
                }
                break;

            case 4:
                //alterar o tipo de conta
                if(contasCadastradas == false){
                    cout<< "Nenhuma conta cadastrada!"<< endl;

                }else{
                    int contaEscolhida; //pega uma das contas para fazer a mudança
                    bool encontrada = false; //comeca com a conta não encontrada

                    cout<< "Digite o numero da conta: ";
                    cin>> contaEscolhida;

                    for(int i = 0; i < 5; i++){

                        if(numeroConta[i] == contaEscolhida){
                            encontrada = true;

                            if(contaAtiva[i] == true){ //se a conta estiver ativa 
                                if(tipoConta[i] == 1){
                                    tipoConta[i] = 2;
                                    cout << "Conta alterada para Poupanca!"<< endl;

                                }else{
                                    tipoConta[i] = 1;
                                    cout << "Conta alterada para Corrente!" << endl;
                                }
                            }else{ //se não, é porque a conta está inativa
                                cout<< "A conta esta inativa!" << endl;
                            }
                        }
                    }
                    if(encontrada == false) {
                        cout << "Conta não encontrada!" << endl;
                    }
                }

                break;

            case 5:
                //desativar ou ativar conta
                if(contasCadastradas == false){
                    cout<< "Nenhuma conta cadastrada!"<< endl;

                }else{
                    int contaEscolhida;
                    bool encontrada = false;

                    cout<<"Digite o numero da conta: ";
                    cin>>contaEscolhida;

                    for(int i = 0; i < 5; i++){
                        if(numeroConta[i] == contaEscolhida){
                            encontrada = true;

                            if(contaAtiva[i] == true){
                                contaAtiva[i] = false;
                                cout<<"Conta desativada com sucesso!"<< endl;

                            }else{
                                contaAtiva[i] = true;
                                cout<<"Conta ativada com sucesso!"<< endl;
                            }
                        }
                    }

                    if(encontrada == false){
                        cout<< "Conta nao encontrada!"<< endl;
                    }
                }
                break;
            
            case 6:
            //sair do sistema e exibir as 5 contas 
                if(contasCadastradas == true){
                    for(int i = 0; i < 5; i++){
                        cout<<" Conta " << i + 1<< endl;

                        cout<<"Nome: "<< nomeCliente[i]<< endl;
                        cout << "CPF: " << cpf[i] << endl;
                        cout << "Numero da conta: " << numeroConta[i]<< endl;

                        if(tipoConta[i] == 1){
                            cout<< "Tipo: Conta Corrente"<< endl;

                        }else{
                            cout<< "Tipo: Conta Poupanca"<< endl;
                        }
                        cout<< "Saldo: R$ "<< fixed << setprecision(2) << saldo[i] << endl;

                        if(contaAtiva[i] == true){
                            cout<< "Situacao: Ativa"<< endl;

                        }else{
                            cout<< "Situacao: Inativa"<< endl;
                        }
                    }

                }else{
                    cout<<"Nenhuma conta foi cadastrada!"<< endl;
                }
                cout << "Saindo do BANCO..."<< endl;
                break;

            default:

                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}