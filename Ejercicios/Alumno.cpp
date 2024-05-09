#include <iostream>
#include <string>

using namespace std;

class Alumno {
public:
    string nombre;
    int edad;
    float promedio;
};

class Grupo {
public:
    Alumno alumnos[5]; // Vector de objetos Alumno
    int cantidad = 5; // Miembro estático que define la cantidad de alumnos en el grupo

    // Función para calcular el promedio del grupo
    float promedio_grupo() {
        float suma_promedios = 0.0;
        int cantidad_alumnos_validos = 0;
        // Iterar sobre los alumnos y sumar sus promedios
        for (int i = 0; i < cantidad; ++i) {
            suma_promedios += alumnos[i].promedio;
            cantidad_alumnos_validos++;
        }
        // Calcular y devolver el promedio
        if (cantidad_alumnos_validos == 0) {
            return 0;
        }
        return suma_promedios / cantidad_alumnos_validos;
    }

    // Función para encontrar al alumno con el mejor promedio
    Alumno* mejor_promedio() {
        Alumno* mejor_promedio_alumno = &alumnos[0];
        // Iterar sobre los alumnos para encontrar el mejor promedio
        for (int i = 1; i < cantidad; ++i) {
            if (alumnos[i].promedio > mejor_promedio_alumno->promedio) {
                mejor_promedio_alumno = &alumnos[i];
            }
        }
        return mejor_promedio_alumno;
    }

    // Función para ordenar los alumnos por promedio usando el algoritmo de burbuja
    void ordenar_por_promedio() {
        for (int i = 0; i < cantidad - 1; ++i) {
            for (int j = 0; j < cantidad - i - 1; ++j) {
                // Intercambiar los alumnos si el promedio actual es mayor que el siguiente
                if (alumnos[j].promedio > alumnos[j + 1].promedio) {
                    Alumno temp = alumnos[j];
                    alumnos[j] = alumnos[j + 1];
                    alumnos[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Grupo grupo;

    // Agregar 5 objetos Alumno al objeto Grupo con los nombres y edades especificados
    grupo.alumnos[0].nombre = "Nylder";
    grupo.alumnos[0].edad = 17;
    grupo.alumnos[0].promedio = 8.5;

    grupo.alumnos[1].nombre = "Diego";
    grupo.alumnos[1].edad = 19;
    grupo.alumnos[1].promedio = 9.0;

    grupo.alumnos[2].nombre = "Kevin";
    grupo.alumnos[2].edad = 19;
    grupo.alumnos[2].promedio = 8.0;

    grupo.alumnos[3].nombre = "Sebastian";
    grupo.alumnos[3].edad = 22;
    grupo.alumnos[3].promedio = 7.5;

    grupo.alumnos[4].nombre = "Miguel";
    grupo.alumnos[4].edad = 20;
    grupo.alumnos[4].promedio = 9.5;

    // Ordenar los alumnos por promedio
    grupo.ordenar_por_promedio();

    // Mostrar en pantalla el objeto Grupo
    cout << "Grupo de Alumnos:" << endl;
    for (int i = 0; i < grupo.cantidad; ++i) {
        cout << "Nombre: " << grupo.alumnos[i].nombre << ", Edad: " << grupo.alumnos[i].edad << ", Promedio: " << grupo.alumnos[i].promedio << endl;
    }

    // Mostrar en pantalla el promedio de los promedios de los objetos Alumno del objeto Grupo
    cout << "Promedio de los promedios del grupo: " << grupo.promedio_grupo() << endl;

    // Mostrar en pantalla el objeto Alumno con el mejor promedio del objeto Grupo
    Alumno* mejor_promedio = grupo.mejor_promedio();
    cout << "Alumno con el mejor promedio del grupo: Nombre: " << mejor_promedio->nombre << ", Edad: " << mejor_promedio->edad << ", Promedio: " << mejor_promedio->promedio << endl;

    return 0;
}
