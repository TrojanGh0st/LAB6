#include <iostream>
using namespace std;
// Clase que representa un banco y su tasa de interés
class Banco {
public:
    // Método estático para obtener la tasa de interés
    static double obtenerTasaInteres() {
        return tasaInteres_;
    }

    // Método estático para establecer la tasa de interés
    static void establecerTasaInteres(double tasa) {
        tasaInteres_ = tasa;
    }

private:
    // Atributo estático que almacena la tasa de interés
    static double tasaInteres_;
};

// Inicialización del atributo estático de la clase Banco
double Banco::tasaInteres_ = 0.05; // Tasa de interés predeterminada

// Clase que representa una cuenta bancaria con su saldo y realiza operaciones de depósito y retiro
class CuentaBancaria {
public:
    // Constructor que inicializa el saldo
    CuentaBancaria(double saldo) : saldo_(saldo) {}

    // Método para depositar dinero en la cuenta
    void depositar(double monto) {
        this->saldo_ += monto;
    }

    // Método para retirar dinero de la cuenta
    bool retirar(double monto) {
        if (this->saldo_ >= monto) {
            this->saldo_ -= monto;
            return true;
        }
        return false;
    }

    // Método para calcular el interés ganado por la cuenta utilizando la tasa de interés estática del banco
    double calcularInteres() const {
        return this->saldo_ * Banco::obtenerTasaInteres();
    }

private:
    // Saldo de la cuenta bancaria
    double saldo_;
};

int main() {
    // Establecer la tasa de interés en 0.07
    Banco::establecerTasaInteres(0.07);

    // Crear una cuenta bancaria con un saldo de $1000
    CuentaBancaria cuenta(1000);

    // Depositar $500
    cuenta.depositar(500);

    // Retirar $200
    cuenta.retirar(200);

    // Calcular el interés ganado
    double interes = cuenta.calcularInteres();

    // Imprimir el interés ganado
    cout << "Interes ganado: $" << interes << endl;

    return 0;
}
