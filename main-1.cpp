#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Requisito 1: struct Producto con campos nombre (string) y precio (float)
struct Producto {
    string nombre;
    float precio;
};

int main() {
    // Requisito 2: vector<Producto> inicializado con al menos 4 objetos usando push_back()
    vector<Producto> inventario;

    Producto p1;
    p1.nombre = "Cuaderno";
    p1.precio = 45.50;
    inventario.push_back(p1);

    Producto p2;
    p2.nombre = "Lapicero";
    p2.precio = 12.75;
    inventario.push_back(p2);

    Producto p3;
    p3.nombre = "Mochila";
    p3.precio = 250.00;
    inventario.push_back(p3);

    Producto p4;
    p4.nombre = "Calculadora";
    p4.precio = 89.99;
    inventario.push_back(p4);

    // Requisito 3: recorrer con for (Producto p : inventario) e imprimir nombre y precio
    cout << "=== Inventario original ===" << endl;
    for (Producto p : inventario) {
        cout << "Producto: " << p.nombre << " | Precio: $" << p.precio << endl;
    }

    // Requisito 4: modificar el precio de un producto accediendo por índice
    inventario[0].precio = 50.00;

    cout << "\n=== Inventario despues de modificar el precio del producto 0 ===" << endl;
    for (Producto p : inventario) {
        cout << "Producto: " << p.nombre << " | Precio: $" << p.precio << endl;
    }

    // Requisito 5: calcular el precio promedio del inventario recorriendo los objetos
    float suma = 0;
    for (Producto p : inventario) {
        suma += p.precio;
    }
    float promedio = suma / inventario.size();
    cout << "\nPrecio promedio del inventario: $" << promedio << endl;

    // Requisito 6: usar at() para acceder de forma segura a un producto por posicion
    int posicion = 2;
    cout << "\nProducto en la posicion " << posicion << " (usando at()): "
         << inventario.at(posicion).nombre << " | Precio: $"
         << inventario.at(posicion).precio << endl;

    return 0;
}
