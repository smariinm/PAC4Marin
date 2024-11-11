// PAC4Marin.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>

using namespace std;

const int META = 50;

void animalRace(const string& nombre, int velocidad_base) {
    int posicion = 0;

    while (posicion < META) {
        int avance = rand() % velocidad_base + 1;
        posicion += avance;

        cout << nombre << ": " << string(posicion, '.') << "🏁\n";

        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << nombre << " ha llegado a la meta!\n";
}

int main() {
    srand(time(0));

    thread liebre(animalRace, "Liebre", 5);
    thread tortuga(animalRace, "Tortuga", 2);
    thread perro(animalRace, "Perro", 4);

    liebre.join();
    tortuga.join();
    perro.join();

    cout << "La carrera ha terminado!\n";

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
