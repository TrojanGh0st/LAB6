#include <iostream>
using namespace std;

class Circulo; // Declaración adelantada de la clase Circulo

// Función para calcular el área de un círculo
float calcular_area(const Circulo& c);

class Circulo {
private:
    float radio;

public:
    // Constructor
    Circulo(float r) : radio(r) {}

    // Función amiga para permitir que la función calcular_area acceda al radio
    friend float calcular_area(const Circulo& c);
};

// Definición de la función amiga para calcular el área del círculo
float calcular_area(const Circulo& c) {
    return 3.14159 * c.radio * c.radio;
}

int main() {
    // Crear instancias de la clase Circulo
    Circulo circulo1(5.0);
    Circulo circulo2(7.5);

    // Calcular y mostrar áreas de los círculos
    cout << "El area del circulo 1 es: " << calcular_area(circulo1) << endl;
    cout << "El area del circulo 2 es: " << calcular_area(circulo2) << endl;

    return 0;
}
