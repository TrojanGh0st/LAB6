#include <iostream>

using namespace std;

class Estudiante {
public:
    // Constructor de la clase Estudiante
    Estudiante(const string& nombre, float nota1, float nota2, float nota3) 
        : nombre_(nombre) {
        notas_[0] = nota1;
        notas_[1] = nota2;
        notas_[2] = nota3;
    }

    // Método para calcular el promedio de notas del estudiante
    float calcularPromedio() const {
        return (notas_[0] + notas_[1] + notas_[2]) / 3.0;
    }

    // Método para obtener el nombre del estudiante
    const string& getNombre() const {
        return nombre_;
    }

private:
    string nombre_; // Nombre del estudiante
    float notas_[3]; // Notas del estudiante
};

// Función de ordenación personalizada utilizando el método de la burbuja
void ordenarEstudiantes(Estudiante estudiantes[], int numEstudiantes) {
    // Recorremos el array de estudiantes
    for (int i = 0; i < numEstudiantes; ++i) {
        // Recorremos nuevamente el array para comparar los promedios de cada estudiante con los siguientes
        for (int j = 0; j < numEstudiantes - 1; ++j) {
            // Si el promedio del estudiante actual es mayor que el siguiente, intercambiamos los estudiantes
            if (estudiantes[j].calcularPromedio() > estudiantes[j + 1].calcularPromedio()) {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
}

int main() {
    // Crear un array de Estudiantes
    Estudiante estudiantes[3] = {
        Estudiante("Miguelito FF", 80, 75, 90),
        Estudiante("Nylder", 95, 85, 92),
        Estudiante("Abby", 60, 65, 70)
    };

    // Ordenar el array por promedio de nota usando la función personalizada
    ordenarEstudiantes(estudiantes, 3);

    // Imprimir estudiantes con promedio mayor a 80
    cout << "\tEstudiantes con promedio mayor a 80:\n";
    // Iterar a través del array de estudiantes
    for (const auto& estudiante : estudiantes) {
        // Verificar si el promedio del estudiante actual es mayor a 80
        if (estudiante.calcularPromedio() > 80) {
            // Imprimir el nombre del estudiante y su promedio
            cout << estudiante.getNombre() << " - Promedio: " << estudiante.calcularPromedio() << "\n";
        }
    }

    return 0;
}
