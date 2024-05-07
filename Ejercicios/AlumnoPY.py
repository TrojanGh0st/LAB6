class Alumno:
    def __init__(self, nombre, edad, promedio):
        self.nombre = nombre
        self.edad = edad
        self.promedio = promedio

    def __str__(self):
        return f"Nombre: {self.nombre}, Edad: {self.edad}, Promedio: {self.promedio}"

    def __lt__(self, otro):
        return self.promedio < otro.promedio

class Grupo:
    def __init__(self, cantidad):
        self.alumnos = [None] * cantidad
        self.cantidad = cantidad

    def __str__(self):
        result = "Grupo:\n"
        for alumno in self.alumnos:
            if alumno is not None:
                result += str(alumno) + "\n"
        return result

    def agregar_alumno(self, nombre, edad, promedio):
        for i in range(self.cantidad):
            if self.alumnos[i] is None:
                self.alumnos[i] = Alumno(nombre, edad, promedio)
                return
        print("El grupo está lleno, no se puede agregar más alumnos.")

    def promedio_grupo(self):
        suma_promedios = sum(alumno.promedio for alumno in self.alumnos if alumno is not None)
        cantidad_alumnos_validos = sum(1 for alumno in self.alumnos if alumno is not None)
        if cantidad_alumnos_validos == 0:
            return 0
        return suma_promedios / cantidad_alumnos_validos

    def mejor_promedio(self):
        mejor_promedio_alumno = None
        for alumno in self.alumnos:
            if alumno is not None:
                if mejor_promedio_alumno is None or alumno.promedio > mejor_promedio_alumno.promedio:
                    mejor_promedio_alumno = alumno
        return mejor_promedio_alumno

    def ordenar_por_promedio(self):
        self.alumnos.sort()


def main():
    # objeto Grupo con capacidad para 5 objetos Alumno
    grupo = Grupo(5)

    # 5 objetos Alumno al objeto Grupo
    grupo.agregar_alumno("Nylder", 17, 8.5)
    grupo.agregar_alumno("Diego", 19, 9.0)
    grupo.agregar_alumno("Kevin", 19, 8.0)
    grupo.agregar_alumno("Sebastian", 22, 7.5)
    grupo.agregar_alumno("Miguel", 20, 9.5)

    # Ordenar los alumnos por promedio
    grupo.ordenar_por_promedio()

    # Objeto Grupo
    print("Grupo de Alumnos:")
    print(grupo)

    # Promedio de los promedios de los objetos Alumno del objeto Grupo
    print("Promedio de los promedios del grupo:", grupo.promedio_grupo())

    # Objeto Alumno con el mejor promedio del objeto Grupo
    print("Alumno con el mejor promedio del grupo:", grupo.mejor_promedio())

# Función principal
main()
