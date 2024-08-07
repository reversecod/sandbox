#include <iostream>
#include <cstdlib>
#include <cmath>
#define TAM 10

using namespace std;

void imprimir_vetor(int vetor [TAM]){
    for (int i = 0; i < TAM; i++){
        cout << "|" << vetor[i] << "|";
    }
}

void bubblesort(int vetor[TAM]){
    int aux;
    for (int i = 0; i < TAM; i++){
        for (int j = i+1; j < TAM; j++){
            if (vetor[i]>vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    int vetor[TAM];

    for (int i = 0; i < TAM; i++){
        cout << "Digite o " << i + 1 << "° numero aleatorio: ";
        cin >> vetor[i];
    }

    cout << "\nVetor original: ";
    imprimir_vetor(vetor);

    bubblesort(vetor);

    cout << "\n\nVetor ordenado: ";
    imprimir_vetor(vetor);

    return 0;
}