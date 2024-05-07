#include <iostream>
#include <vector>

using namespace std;

class Estudiante {
public:
    Estudiante(const string& nombre, float nota1, float nota2, float nota3) 
        : nombre_(nombre), notas_{nota1, nota2, nota3} {}

    float calcularPromedio() const {
        return (notas_[0] + notas_[1] + notas_[2]) / 3.0;
    }

    const string& getNombre() const {
        return nombre_;
    }

private:
    string nombre_;
    float notas_[3];
};

// Función de ordenación personalizada
void ordenarEstudiantes(vector<Estudiante>& estudiantes) {
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        for (size_t j = 0; j < estudiantes.size() - 1; ++j) {
            if (estudiantes[j].calcularPromedio() > estudiantes[j + 1].calcularPromedio()) {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
}

int main() {
    // Crear un vector de Estudiantes
    vector<Estudiante> estudiantes;

    // Llenarlo con información
    estudiantes.push_back(Estudiante("Miguelito FF", 80, 75, 90));
    estudiantes.push_back(Estudiante("Nylder", 95, 85, 92));
    estudiantes.push_back(Estudiante("Abby", 60, 65, 70));

    // Ordenar el vector por promedio de nota usando la función personalizada
    ordenarEstudiantes(estudiantes);

    // Imprimir estudiantes con promedio mayor a 80
    cout << "\tEstudiantes con promedio mayor a 80:\n";
    for (const auto& estudiante : estudiantes) {
        if (estudiante.calcularPromedio() > 80) {
            cout << estudiante.getNombre() << " - Promedio: " << estudiante.calcularPromedio() << "\n";
        }
    }

    return 0;
}
