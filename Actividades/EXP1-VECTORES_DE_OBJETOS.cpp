#include <iostream>
#include <vector>

using namespace std;

class Estudiante {
public:
    // Constructor de la clase Estudiante
    Estudiante(const string& nombre, float nota1, float nota2, float nota3) 
        : nombre_(nombre), notas_{nota1, nota2, nota3} {}

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
void ordenarEstudiantes(vector<Estudiante>& estudiantes) {
    // Recorremos el vector de estudiantes
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        // Recorremos nuevamente el vector para comparar los promedios de cada estudiante con los siguientes
        for (size_t j = 0; j < estudiantes.size() - 1; ++j) {
            // Si el promedio del estudiante actual es mayor que el siguiente, intercambiamos los estudiantes
            if (estudiantes[j].calcularPromedio() > estudiantes[j + 1].calcularPromedio()) {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
}

int main() {
    // Crear un vector de Estudiantes
    vector<Estudiante> estudiantes;

    // Llenar el vector con información de estudiantes
    estudiantes.push_back(Estudiante("Miguelito FF", 80, 75, 90));
    estudiantes.push_back(Estudiante("Nylder", 95, 85, 92));
    estudiantes.push_back(Estudiante("Abby", 60, 65, 70));

    // Ordenar el vector por promedio de nota usando la función personalizada
    ordenarEstudiantes(estudiantes);

    // Imprimir estudiantes con promedio mayor a 80
    cout << "\tEstudiantes con promedio mayor a 80:\n";
    // Iterar a través del vector de estudiantes
    for (const auto& estudiante : estudiantes) {
        // Verificar si el promedio del estudiante actual es mayor a 80
        if (estudiante.calcularPromedio() > 80) {
            // Imprimir el nombre del estudiante y su promedio
            cout << estudiante.getNombre() << " - Promedio: " << estudiante.calcularPromedio() << "\n";
        }
    }

    return 0;
}
