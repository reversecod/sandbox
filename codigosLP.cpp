#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double ler_coeficiente(string nome) {
    double coef;
    cout << "Digite o coeficiente " << nome << ": ";
    cin >> coef;
    return coef;
}

double calculo_delta(double a, double b, double c) {
    return (b * b) - (4 * a * c);
}

void calcular_raizes(double a, double b, double delta, double &x1, double &x2) {
    if (delta < 0) {
    cout << "Não é possível calcular raíz negativa.\n";

} else {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
}

}
void exibir(double delta, double x1, double x2) {
    cout << "\nDelta: " << delta << endl;
    cout << "Raiz 1: " << x1 << endl;
    cout << "Raiz 2: " << x2 << endl;

}

int main() {
double a, b, c, delta, x1, x2;

    a = ler_coeficiente("a");
    b = ler_coeficiente("b");
    c = ler_coeficiente("c");
    delta = calculo_delta(a, b, c);
    calcular_raizes(a, b, delta, x1, x2);

    exibir(delta, x1, x2);

return 0;

} 