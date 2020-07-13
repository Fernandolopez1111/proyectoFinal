#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int cantidadArticulos;

const int longCad = 20;
string cad;

float total;

struct costoPorArticulo{
  char nombreArticulo[longCad+1];
  int cantidad;
  float precio;
  float costoPorArticulo;
};

struct costoPorArticulo art[0];/*se incializa el arreglo en cero*/

void leerDatos(int);
void calcularCosto(int);
void desplegarDatos(int);
float mostrarTotal(int);


int main()
{
  std::cout << "============================================" << '\n';
  std::cout << "             Bienvenido" << '\n';
  std::cout << "============================================" << '\n';
  std::cout << "Introduzca el número de elementos a comprar (Solo incluir 1 por producto)" << '\n';
  std::cin >> cantidadArticulos;

  struct costoPorArticulo art[cantidadArticulos];


  leerDatos(cantidadArticulos);
  calcularCosto(cantidadArticulos);
  desplegarDatos(cantidadArticulos);
  mostrarTotal(cantidadArticulos);


  std::cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////" << '\n';
  std::cout <<"                                    Total a pagar: $"<<total<< '\n';
  std::cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////" << '\n';

  return 0;
}

void leerDatos(int cantidadArticulos){
  for (int i = 0; i<cantidadArticulos; i++) {
    std::cout << "Articulo "<<i+1<<":"<< '\n';
    std::cout << "  Ingrese el nombre del Articulo ---> ";
    cin.ignore(100, '\n');/* borrar de la memoria los datos de otro cin*/
    getline(cin, cad);
    strncpy(art[i].nombreArticulo, cad.c_str(), longCad);
    art[i].nombreArticulo[longCad]='\0';
    std::cout << '\n';
    std::cout << "  Ingrese la cantidad de unidades que se compraran de "<<art[i].nombreArticulo<<" ---> ";
    std::cin >> art[i].cantidad;
    std::cout << '\n';
    std::cout << "  Ingrese el precio unitario del articulo "<<art[i].nombreArticulo<<"---> ";
    std::cin >> art[i].precio;
    std::cout << '\n';
  }
}

void calcularCosto(int cantidadArticulos) {
  for (int i = 0; i<cantidadArticulos; i++) {
    art[i].costoPorArticulo = art[i].precio*art[i].cantidad;
  }
}

void desplegarDatos(int cantidadArticulos) {
std::cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////" << '\n';
std::cout << "                                           FACTURA" << '\n';
std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << '\n';
std::cout << "Producto "<<"     Cantidad "<<"     Precio unitario "<<"          SubTotal "<< '\n'<<'\n';
  for (int i = 0; i<cantidadArticulos; i++) {
    std::cout <<art[i].nombreArticulo<<"        "<<art[i].cantidad<<"                   "<<art[i].precio<<"                   "<<art[i].costoPorArticulo<<'\n';
  }
}

float mostrarTotal(int cantidadArticulos){
  for (int i = 0; i<cantidadArticulos; i++) {
    total = total + art[i].costoPorArticulo;
  }
  return total;
}
