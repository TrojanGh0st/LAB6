#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double _x, double _y) : x(_x), y(_y) {}  
    // Sobrecarga del operador de suma (+)
    Vector2D operator+(const Vector2D& other) const { //Other se utilzia para referirnos al otro vector
        return Vector2D(x + other.x, y + other.y);
    }

    // Sobrecarga del operador de resta (-)
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Función para imprimir el vector
    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Crear instancias de la clase Vector2D
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    // Sumar dos vectores utilizando el operador sobrecargado '+'
    Vector2D sum = v1 + v2;
    cout << "La suma de los vectores es: ";
    sum.print();

    // Restar dos vectores utilizando el operador sobrecargado '-'
    Vector2D difference = v1 - v2;
    cout << "La diferencia de los vectores es: ";
    difference.print();

    return 0;
}
