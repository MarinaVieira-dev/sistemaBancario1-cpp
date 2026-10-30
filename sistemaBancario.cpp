
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcao;

    //maximo de contas que podem ser cadastradas
    const int MAX_CONTAS = 100;

    //vetores pedidos
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    //variavel para contar as contas cadastradas 
    int quantidadeContas = 0;
    //maximo de movimentacoes
    const int MAX_MOVIMENTACOES = 500;
    //conta que realizou a movimentacao
    int contaMovimentacao[MAX_MOVIMENTACOES];
    //tipo de movimentacao (s ou d)
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    //valor de cada movimentacao
    double valorMovimentacao[MAX_MOVIMENTACOES];

    //quant de movimentacoes foram realizadas
    int quantidadeMovimentacoes = 0;

    do {

        cout << "\n********************************" << endl;
        cout << "**  Sistema Bancário - parte 2  **" << endl;
        cout << "**********************************" << endl;
        cout << "\nDigite a opcao desejada:" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar contas cadastradas" << endl;
        cout << "3 - Consultar conta pelo número" << endl;
        cout << "4 - Realizar depósitos" << endl;
        cout << "5 - Realizar saques" << endl;
        cout << "6 - Realizar transferência" << endl;
        cout << "7 - Exibir o extrato de uma conta" << endl;
        cout << "8 - Sair" << endl;

        cin >> opcao;

        switch (opcao) {
            //cadastro da conta 
            case 1: {
                //ver se tem limite para cadastrar
                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite de contas atingido!" << endl;
                    break; //se não tiver limite, não cadastra mais 
                }
                //o i recebe 0 pois esse foi o valor atribuído a variavel quantdadadeContas
                int i = quantidadeContas;

                cin.ignore();

                cout << "Digite o nome completo: ";
                getline(cin, nomeCliente[i]);

                cout << "Digite o CPF: ";
                getline(cin, cpf[i]);

                do {
                    cout << "Digite o numero da conta: ";
                    cin >> numeroConta[i];

                    //numero da conta precisa ser maior que zero
                    if (numeroConta[i] <= 0) {
                        cout << "Numero da conta invalido!" << endl;
                    }

                // Repete enquanto o numero for invalido ou repetido
                } while (numeroConta[i] <= 0);
                
                do {
                    //validacao do tipo da conta 
                    cout << "Digite o tipo da conta:";
                    cout << " 1 - Corrente  2 - Poupanca: ";
                    cin >> tipoConta[i];

                    //verifica se é diferente de 1 ou 2
                    if (tipoConta[i] != 1 && tipoConta[i] != 2) {
                        cout << "Tipo de conta invalido!" << endl;
                    }

                } while (tipoConta[i] != 1 && tipoConta[i] != 2);

                do {
                    //validaçao de saldo
                    cout << "Digite o saldo inicial: R$ ";
                    cin >> saldo[i];

                    if (saldo[i] < 0) {
                        cout << "O saldo nao pode ser negativo!" << endl;
                    }

                } while (saldo[i] < 0);


                //quando a conta é criada a conta já fica ativa automaticamente
                contaAtiva[i] = true;

                //aumenta +1 na quantidade de contas cadastradas
                quantidadeContas++;

                cout << "Conta cadastrada com sucesso!" << endl;

                break;
            }
            case 2:{
                //consultar contas cadastradas 
                //verifica se existe alguma conta cadastrada
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    //aqui o i corresponde a uma conta ja cadastrada
                    for (int i = 0; i < quantidadeContas; i++) {
                        cout << "Nome: " << nomeCliente[i] << endl;
                        cout << "CPF: " << cpf[i] << endl;
                        cout << "Numero da conta: " << numeroConta[i] << endl;

                        //verifica o tipo da conta
                        if (tipoConta[i] == 1) {
                            cout << "Tipo: Conta Corrente" << endl;
                        } else {
                            cout << "Tipo: Conta Poupanca" << endl;
                        }
                        //saldo 
                        cout << "Saldo: R$ " << fixed << setprecision(2)
                             << saldo[i] << endl;

                        //verifica se a conta esta ativa ou inativa
                        if (contaAtiva[i] == true) {
                            cout << "Situacao: Ativa" << endl;
                        } else {
                            cout << "Situacao: Inativa" << endl;
                        }
                        
                        cout << "****************************" << endl;
                    }
                }

                break;
            }
            case 3: {
                //consultar conta pelo numero
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    //conta que o usuário quer consultar 
                    int contaEscolhida;
                    bool encontrada = false;

                    cout << "Digite o numero da conta: ";
                    cin >> contaEscolhida;

                    //percorre os vetores procurando o numero informado, entre as contas já cadastradas 
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == contaEscolhida) {
                            encontrada = true;

                            cout << "Nome: " << nomeCliente[i] << endl;
                            cout << "CPF: " << cpf[i] << endl;
                            if (contaAtiva[i] == true) {
                                cout << "Saldo: R$ " << fixed
                                    << setprecision(2) << saldo[i] << endl;
                            } else {
                                cout << "A conta esta inativa!" << endl;
                            }
                        }
                    }
                    //caso nao encontre a conta
                    if (encontrada == false) {
                        cout << "Conta nao encontrada!" << endl;
                    }
                }
                break;
            }
             case 4: {
                //realizar deposito
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int contaEscolhida;
                    double valor; //valor a ser depositado
                    bool encontrada = false;

                    cout << "Digite o numero da conta: ";
                    cin >> contaEscolhida;

                    //variavel que representa a posicao da conta no vetor
                    int i;

                    //procura a conta pelo numero informado
                    for (i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == contaEscolhida) {
                            encontrada = true;
                            break;
                        }
                    }
                    //verifica se encontrou a conta
                    if (encontrada == false) {
                        cout << "Conta nao encontrada!" << endl;

                    //verifica se a conta esta ativa
                    } else if (contaAtiva[i] == false) {
                        cout << "A conta esta inativa!" << endl;

                    //verifica se ainda existe espaço disponvel no vetor de movimentacoes 
                    } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                        cout << "Limite de movimentacoes atingido!" << endl;

                    } else {
                        do {
                            cout << "Digite o valor do deposito: R$ ";
                            cin >> valor;

                            if (valor <= 0) {
                                cout << "O valor deve ser positivo!" << endl;
                            }

                        } while (valor <= 0);

                        //acrescenta o valor ao saldo da conta
                        saldo[i] = saldo[i] + valor;

                        //registrar a movimentacao
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Deposito realizado com sucesso!" << endl;
                        cout << "Novo saldo: R$ " << fixed << setprecision(2)
                            << saldo[i] << endl;
                    }
                }
                break;
             }
             case 5: {
                //saques, verificando saldo suficiente 
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int contaEscolhida;
                    double valor;
                    bool encontrada = false;

                    cout << "Digite o numero da conta: ";
                    cin >> contaEscolhida;

                    int i;
                    //procura a conta no vetor
                    for (i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == contaEscolhida) {
                            encontrada = true;
                            break;
                        }
                    }

                    if (encontrada == false) {
                        cout << "Conta nao encontrada!" << endl;
        
                    } else if (contaAtiva[i] == false) {
                        cout << "A conta esta inativa!" << endl;

                    } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                        cout << "Limite de movimentacoes atingido!" << endl;

                    } else {
                        do {
                            cout << "Digite o valor do saque: R$ ";
                            cin >> valor;

                            if (valor <= 0) {
                                cout << "O valor deve ser positivo!" << endl;

                            } else if (valor > saldo[i]) {
                                cout << "Saldo insuficiente!" << endl;
                            }

                        } while (valor <= 0 || valor > saldo[i]);

                        saldo[i] = saldo[i] - valor;


                        //registrar a movimentacao
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;
                        cout << "Saque realizado com sucesso!" << endl;
                        cout << "Novo saldo: R$ " << fixed << setprecision(2)
                            << saldo[i] << endl;
                    }
                }
            break;
            }
           case 6: {
                //para transferir precisa de pelo menos 2 contas 
                if (quantidadeContas < 2) {
                    cout << "Cadastre pelo menos duas contas!" << endl;
                } else {
                    int contaOrigem; //dinheiro sai
                    int contaDestino; //dinheiro entra

                    //guarda a posicao das duas contas nos vetores
                    int indiceOrigem = -1;
                    int indiceDestino = -1;
                    double valor;

                    cout << "Digite o numero da conta de origem: ";
                    cin >> contaOrigem;
                    cout << "Digite o numero da conta de destino: ";
                    cin >> contaDestino;

                    //procura as duas contas nos vetores
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == contaOrigem) {
                            indiceOrigem = i; //recebe o numero da conta 
                        }
                        if (numeroConta[i] == contaDestino) {
                            indiceDestino = i; //recebe o numero da conta 
                        }
                    }

                    //verifica se as duas contas foram encontradas
                    if (indiceOrigem == -1 || indiceDestino == -1) {
                        cout << "Uma das contas nao foi encontrada!" << endl;

                    //verifica se as duas contas estao ativas
                    } else if (contaAtiva[indiceOrigem] == false || contaAtiva[indiceDestino] == false) {
                        cout << "As duas contas devem estar ativas!" << endl;

                    //transferencia precisa de dois espacos no historico
                    } else if (quantidadeMovimentacoes > MAX_MOVIMENTACOES - 2) {
                        cout << "Nao ha espaco para a transferencia!" << endl;

                    } else {
                        do {
                            cout << "Digite o valor da transferencia: R$ ";
                            cin >> valor;

                            if (valor <= 0) {
                                cout << "O valor deve ser positivo!" << endl;

                            } else if (valor > saldo[indiceOrigem]) {
                                cout << "Saldo insuficiente!" << endl;
                            }
                        } while (valor <= 0 || valor > saldo[indiceOrigem]);

                        //retira saldo da conta origem 
                        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;

                        //acrescenta saldo na conta destino 
                        saldo[indiceDestino] = saldo[indiceDestino] + valor;

                    //registra movimentacao das 2 contas
                    //conta origem  
                        contaMovimentacao[quantidadeMovimentacoes] = contaOrigem;
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        //conta 1 movimentacao, do saque, no caso da conta origem 
                        quantidadeMovimentacoes++;

                        //conta destino 
                        contaMovimentacao[quantidadeMovimentacoes] = contaDestino;
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        //conta 1 movimentacao, do saque, no caso da conta destino 
                        quantidadeMovimentacoes++;

                        cout << "Transferencia realizada com sucesso!" << endl;
                        cout << "Saldo da conta de origem: R$ "<< fixed << setprecision(2) << saldo[indiceOrigem] << endl;
                        cout << "Saldo da conta de destino: R$ "<< fixed << setprecision(2) << saldo[indiceDestino] << endl;
                    }
                }
                break;
            }

            case 7: {
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {

                    int contaEscolhida;
                    bool encontrada = false;

                    cout << "Digite o numero da conta: ";
                    cin >> contaEscolhida;

                    //verificar se existe a conta 
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == contaEscolhida) {
                            encontrada = true;
                        }
                    }
                    if (encontrada == false) {
                        cout << "Conta nao encontrada!" << endl;

                    } else {
                        cout << "\nEXTRATO DA CONTA " << contaEscolhida << endl;
                        cout << "****************************" << endl;

                        bool temMovimentacao = false;

                        //percorrer vetor de movimentacoes 
                        for (int i = 0; i < quantidadeMovimentacoes; i++) {
                            // Verifica se a movimentacao pertence a conta escolhida
                            if (contaMovimentacao[i] == contaEscolhida) {
                                temMovimentacao = true;

                                //verificar o tipo de movimetacao
                                if (tipoMovimentacao[i] == 'D') {
                                cout << "Deposito: R$ " << fixed << setprecision(2) << valorMovimentacao[i] << endl;

                                } else if (tipoMovimentacao[i] == 'S') {
                                    cout << "Saque: R$ " << fixed << setprecision(2) << valorMovimentacao[i] << endl;
                                }
                            }
                        }
                
                        if (temMovimentacao == false) {
                            cout << "Nenhuma movimentacao registrada!" << endl;
                        }
                    }
                }
                break;
            }
            case 8: { 
                cout << "Saindo do banco ..." << endl;
                break;
            }

            default:
                cout << "Opcao invalida! " << endl;
        }

    } while (opcao != 8);


    return 0;
}
