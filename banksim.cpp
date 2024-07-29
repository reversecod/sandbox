#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#ifdef _WIN32
#include <windows.h>
void clear_screen() {
    system("cls");
}
#else
void clear_screen() {
}
#endif

class ContaBancaria {
private:
    float saldo;
    float limite_credito;
    float fatura;
    float caixinha;

public:
    ContaBancaria(float saldo, float limite_credito)
        : saldo(saldo), limite_credito(limite_credito), fatura(0), caixinha(0) {}

    void depositar(float valor) {
        saldo += valor;
        cout << "Deposito de R$" << valor << " realizado." << endl;
    }

    void sacar(float valor, bool debito = true) {
        if (debito) {
            if (saldo >= valor) {
                saldo -= valor;
                cout << "Saque de R$" << valor << " realizado no debito." << endl;
            } else {
                cout << "Saldo insuficiente." << endl;
            }
        } else {
            if (valor > limite_credito) {
                cout << "Valor de saque excede o limite do credito." << endl;
            } else if (limite_credito >= valor) {
                limite_credito -= valor;
                fatura += valor;
                cout << "Gasto de R$" << valor << " realizado no credito." << endl;
            } else {
                cout << "Limite de credito ultrapassado." << endl;
            }
        }
    }

    void pagar_fatura(char answer) {
        if (answer == 'Y' && saldo >= fatura) {
            saldo -= fatura;
            float valorpago = fatura;
            limite_credito += fatura;
            fatura -= fatura;
            cout << "Pagamento total da fatura de R$" << valorpago << " realizado. Saldo e credito atualizados." << endl;
        } else if (answer == 'Y' && saldo < fatura) {
            cout << "Voce nao possui saldo o suficiente para pagar toda a fatura!";
        } else if (answer == 'N') {
            float valor;
            cout << "Digite o valor a pagar da fatura: R$";
            cin >> valor;
                if (fatura >= valor) {
                    saldo -= valor;
                    limite_credito += valor;
                    fatura -= valor;
                    cout << "Pagamento de fatura de R$" << valor << " realizado. Saldo e credito atualizados." << endl;
                } else {
                    cout << "Valor da fatura excede o valor a pagar." << endl;
                }
        }else
            cout << "Alternativa inválida!";   
}

    void status_conta() {
        cout << "Saldo: R$" << saldo << endl;
        cout << "Fatura: R$" << fatura << endl;
        cout << "Limite de credito: R$" << limite_credito << endl;
    }

    pair<int, int> passar_dia(int dia_atual, int mes_atual) {
        map<int, int> dias_por_mes = {
            {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
            {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
        };

        int proximo_dia = dia_atual + 1;
        int proximo_mes = mes_atual;

        if (proximo_dia > dias_por_mes[mes_atual]) {
            proximo_dia = 1;
            proximo_mes += 1;
            if (proximo_mes > 12) {
                proximo_mes = 1;
            }
        }

        return {proximo_dia, proximo_mes};
    }

    void adicionar_caixinha(float valor) {
        if (valor <= saldo) {
            saldo -= valor;
            caixinha += valor;
            cout << "Adicionado R$" << valor << " a caixinha." << endl;
        } else {
            cout << "Valor excede o saldo disponível para adicionar a caixinha." << endl;
        }
    }

    void verificar_caixinha() {
        cout << "Valor na caixinha: R$" << caixinha << endl;
    }

    void retornar_caixinha(float valor) {
        if (valor <= caixinha) {
            saldo += valor;
            caixinha -= valor;
            cout << "Valor de R$" << valor << " retornado ao saldo." << endl;
        } else {
            cout << "Valor excede o montante na caixinha." << endl;
        }
    }
};

int main() {
    int dia, mes;
    float saldo_inicial, limite_inicial;

    cout << "Digite o dia inicial: ";
    cin >> dia;
    cout << "Digite o mes inicial: ";
    cin >> mes;
    cout << "Informe o saldo inicial: R$";
    cin >> saldo_inicial;
    cout << "Informe o limite de credito inicial: R$";
    cin >> limite_inicial;

    ContaBancaria minha_conta(saldo_inicial, limite_inicial);

    while (true) {
        // Menu
        cout << "\n------- MENU -------\n";
        cout << "Dia: " << dia << "/" << mes << endl;
        cout << "1 - Consultar saldo e status da conta" << endl;
        cout << "2 - Depositar" << endl;
        cout << "3 - Sacar (Debito)" << endl;
        cout << "4 - Sacar (Credito)" << endl;
        cout << "5 - Pagar fatura" << endl;
        cout << "6 - Adicionar a caixinha" << endl;
        cout << "7 - Verificar caixinha" << endl;
        cout << "8 - Retirar da caixinha" << endl;
        cout << "9 - Avancar o dia" << endl;
        cout << "0 - Sair" << endl;

        int opcao;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        clear_screen();

        switch (opcao) {
            case 1:
                minha_conta.status_conta();
                break;
            case 2:
                float valor_deposito;
                cout << "Digite o valor a depositar: R$";
                cin >> valor_deposito;
                minha_conta.depositar(valor_deposito);
                break;
            case 3:
                float valor_saque_debito;
                cout << "Digite o valor a sacar no debito: R$";
                cin >> valor_saque_debito;
                minha_conta.sacar(valor_saque_debito, true);
                break;
            case 4:
                float valor_saque_credito;
                cout << "Digite o valor a sacar no credito: R$";
                cin >> valor_saque_credito;
                minha_conta.sacar(valor_saque_credito, false);
                break;
            case 5:
                char yn;
                cout << "Deseja pagar toda a fatura ? (Y/N): ";
                cin >> yn;
                yn = toupper(yn);
                minha_conta.pagar_fatura(yn);
                break;
            case 6:
                float valor_caixinha;
                cout << "Digite o valor a adicionar na caixinha: R$";
                cin >> valor_caixinha;
                minha_conta.adicionar_caixinha(valor_caixinha);
                break;
            case 7:
                minha_conta.verificar_caixinha();
                break;
            case 8:
                float valor_retirar_caixinha;
                cout << "Digite o valor a retornar da caixinha ao saldo: R$";
                cin >> valor_retirar_caixinha;
                minha_conta.retornar_caixinha(valor_retirar_caixinha);
                break;
            case 9:
                tie(dia, mes) = minha_conta.passar_dia(dia, mes);
                cout << "Dia: " << dia << ", Mes: " << mes << endl;
                break;
            case 0:
                cout << "Encerrando o aplicativo." << endl;
                return 0;
            default:
                cout << "Opcao inválida. Tente novamente." << endl;
        }
    }

    return 0;
}