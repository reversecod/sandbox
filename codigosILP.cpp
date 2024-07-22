#include <iostream>
#include <vector>

using namespace std;

void average()
{
    vector<int> numbers; // Declaração do vetor
    int qntd;
    double sum = 0;

    // Pergunta ao usuário quantos numeros ele quer inserir
    cout << "Quantos numeros voce deseja inserir? ";
    cin >> qntd;

    // Le os numeros e armazena-os no vetor
    for (int i = 0; i < qntd; ++i)
    {
        int number;
        cout << "Digite o numero " << (i + 1) << ": ";
        cin >> number;
        numbers.push_back(number);
        sum += number; // Adiciona o numero ao vetor
    }

    if (numbers.size() > 0)
    {
        cout << "A media desses numeros e: " << sum / numbers.size() << endl;
    }
    else
    {
        cout << "Nenhum numero foi inserido." << endl;
    }

    cout << endl;
}

int main()
{
    average();
    return 0;
    
}