#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    if (n <= 0) return -1;
    double menorDistancia = std::sqrt(std::pow(puntos[0].x - pUsuario.x, 2) + std::pow(puntos[0].y - pUsuario.y, 2));
    indiceMasCercano = 0;

    for (int i = 1; i < n; i++) {
        double distancia = std::sqrt(std::pow(puntos[i].x - pUsuario.x, 2) + std::pow(puntos[i].y - pUsuario.y, 2));
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceMasCercano = i;
        }
    }
    return menorDistancia;
}

int main() {
    int n;
    std::cout << "Ingrese el numero de puntos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Numero de puntos invalido." << std::endl;
        return 0;
    }

    Point puntos[100];
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese las coordenadas x e y para el punto " << i << ": ";
        std::cin >> puntos[i].x >> puntos[i].y;
    }

    Point pUsuario;
    std::cout << "Ingrese las coordenadas x e y del punto de referencia del usuario: ";
    std::cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano = 0;
    double distanciaMinima = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    std::cout << "El punto mas cercano es el indice " << indiceMasCercano 
              << " con coordenadas (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y 
              << ") a una distancia de " << distanciaMinima << std::endl;

    return 0;
}
