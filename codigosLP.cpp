#include <iostream>
#include <string>

struct PESSOA {
    std::string nome;
    int idade;
    char sexo;
    double salario;
    double salarioNovo;
};

void NovaLinhaStruct(PESSOA *p);
void listarLinhasStruct(PESSOA *pessoas, int count);
void ler_idade(PESSOA *p);
void ler_sexo(PESSOA *p);
void ler_nome(PESSOA *p);
void ler_salario(PESSOA *p);
double getAumento(double salario);

int main() {
    PESSOA pessoas[2];
    PESSOA *pPessoa = pessoas;

    int opcao;
    do {
        std::cout << "Menu:\n1 - Ler linha\n2 - Mostrar\n3 - Sair\nEscolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                for (int i = 0; i < 2; ++i) {
                    NovaLinhaStruct(&pPessoa[i]);
                }
                break;
            case 2:
                listarLinhasStruct(pPessoa, 2);
                break;
            case 3:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (opcao != 3);

    return 0;
}

void NovaLinhaStruct(PESSOA *p) {
    ler_nome(p);
    ler_idade(p);
    ler_sexo(p);
    ler_salario(p);
    p->salarioNovo = getAumento(p->salario);
}

void listarLinhasStruct(PESSOA *pessoas, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Nome: " << pessoas[i].nome 
                  << ", Idade: " << pessoas[i].idade 
                  << ", Sexo: " << pessoas[i].sexo 
                  << ", Salário: " << pessoas[i].salario 
                  << ", Novo Salário: " << pessoas[i].salarioNovo << std::endl;
    }
}

void ler_idade(PESSOA *p) {
    std::cout << "Digite a idade: ";
    std::cin >> p->idade;
}

void ler_sexo(PESSOA *p) {
    std::cout << "Digite o sexo (M/F): ";
    std::cin >> p->sexo;
}

void ler_nome(PESSOA *p) {
    std::cout << "Digite o nome: ";
    std::cin.ignore();
    std::getline(std::cin, p->nome);
}

void ler_salario(PESSOA *p) {
    std::cout << "Digite o salário: ";
    std::cin >> p->salario;
}

double getAumento(double salario) {
    return salario * 1.1;
}