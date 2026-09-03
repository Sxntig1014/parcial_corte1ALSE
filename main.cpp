#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    if (n <= 0) return -1;
    double menorDistancia = sqrt(pow(puntos[0].x - pUsuario.x, 2) + pow(puntos[0].y - pUsuario.y, 2));
    indiceMasCercano = 0;

    for (int i = 1; i < n; i++) {
        double distancia = sqrt(pow(puntos[i].x - pUsuario.x, 2) + pow(puntos[i].y - pUsuario.y, 2));
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceMasCercano = i;
        }
    }
    return menorDistancia;
}

int main() {
    int n;
    cout << "Ingrese el numero de puntos: ";
    cin >> n;

    if (n <= 0) {
        cout << "Numero de puntos invalido." << endl;
        return 0;
    }

    Point puntos[100];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese las coordenadas x e y para el punto " << i << ": ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    Point pUsuario;
    cout << "Ingrese las coordenadas x e y del punto de referencia del usuario: ";
    cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano = 0;
    double distanciaMinima = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    cout << "El punto mas cercano es el indice " << indiceMasCercano 
         << " con coordenadas (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y 
         << ") a una distancia de " << distanciaMinima << endl;

    return 0;
}