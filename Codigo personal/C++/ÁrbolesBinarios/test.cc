#include <iostream>

#include "ArbolB.h"
#include "NodoB.h"

int main() {
    // ArbolB<int>* arbol;
    // arbol = new ArbolBE<int> ();
    // if (arbol->Insertar(80)) std::cout << "si\n";
    // if (arbol->Insertar(74)) std::cout << "si\n";
    // if (arbol->Insertar(4)) std::cout << "si\n";
    // if (arbol->Insertar(7)) std::cout << "si\n";
    // if (arbol->Insertar(14)) std::cout << "si\n";
    // if (arbol->Insertar(24)) std::cout << "si\n";

    // std::cout << arbol->GetRaiz()->GetDato() << std::endl;
    // std::cout << arbol->GetRaiz()->GetIzquierda()->GetDato() << std::endl;
    // std::cout << arbol->GetRaiz()->GetDerecha()->GetDato() << std::endl;
    // std::cout << arbol->GetRaiz()->GetIzquierda()->GetIzquierda()->GetDato() << std::endl;

    // if (arbol->Buscar
    // (24)) std::cout << "si\n";

    ArbolB<int>* arbol;
    arbol = new ArbolBB<int> ();
    if (arbol->Insertar(80)) std::cout << "80\n";
    if (arbol->Insertar(8)) std::cout << "80\n";
    if (arbol->Insertar(70)) std::cout << "70\n";
if (arbol->Insertar(100)) std::cout << "80\n";
    if (arbol->Insertar(90)) std::cout << "90\n";
    if (arbol->Insertar(80)) std::cout << "90\n";
    if (arbol->Insertar(7)) std::cout << "90\n";
    if (arbol->Insertar(190)) std::cout << "90\n";


std::cout << "/////////////////////////" << std::endl;

if (arbol->Buscar(80)) std::cout << "80\n";
if (arbol->Buscar(70)) std::cout << "70\n";
if (arbol->Buscar(90)) std::cout << "90\n";
std::cout << "/////////////////////////" << std::endl;
arbol->Inorden(arbol->GetRaiz());
std::cout << "/////////////////////////" << std::endl;
std::cout << *arbol;
}