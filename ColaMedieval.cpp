#include <iostream>
#include "ColaMedieval.hpp"

//**********************************************
ColaMedieval::ColaMedieval() : tam(0), tamNoble(0), tamPlebeyo(0), fondo(nullptr), fondoNoble(nullptr)
{
}
//**********************************************

ColaMedieval::~ColaMedieval()
{
    Vaciar();
}
//***********************************************

ColaMedieval::ColaMedieval(const ColaMedieval &c) : tam(0), tamNoble(0), tamPlebeyo(0), fondo(nullptr), fondoNoble(nullptr)
{
    *this = c;
}
//*********************************************

ColaMedieval& ColaMedieval::operator=(const ColaMedieval& c) {
    if (this == &c) return *this;
    Vaciar();
    Individuo* actual = c.fondo->siguiente;
    while (actual != fondo) {
        Agregar(actual->nombre, actual->claseSocial);
        actual = actual->siguiente;
    }
    return *this;
}

//*********************************************************************************************************
void ColaMedieval::Agregar(std::string nombre, std::string claseSocial) {
    Individuo* nuevo = new Individuo(nombre, claseSocial, nullptr);
    if (EstaVacia()) {
        fondo = nuevo;
        fondo->siguiente = fondo;
        if (claseSocial == "Noble") {
            fondoNoble = fondo;
            tamNoble++;
        } else {
            tamPlebeyo++;
        }
    } else {
        if (claseSocial == "Noble") {
            if (fondoNoble == nullptr) {
                nuevo->siguiente = fondo->siguiente;
                fondo->siguiente = nuevo;
                fondoNoble = nuevo;
            } else {
                nuevo->siguiente = fondoNoble->siguiente;
                fondoNoble->siguiente = nuevo;
                fondoNoble = nuevo;
            }
            tamNoble++;
        } else {
            nuevo->siguiente = fondo->siguiente;
            fondo->siguiente = nuevo;
            fondo = nuevo;
            tamPlebeyo++;
        }
    }
    tam++;
}
//****************************************************************************************

void ColaMedieval::Eliminar() {
    if (EstaVacia()) throw ColaVacia();

    Individuo* temp = fondo->siguiente;
    fondo->siguiente = temp->siguiente;

    if (temp == fondoNoble) {
        fondoNoble = nullptr;
    }
    if (temp == fondo) {
        fondo = nullptr;
    }
    if (temp->claseSocial == "Noble") {
        tamNoble--;
    } else {
        tamPlebeyo--;
    }
    delete temp;
    tam--;
}


//**********************************************

int ColaMedieval::ObtenerTam() const
{
    return tam;
}
//**********************************************

int ColaMedieval::ObtenerTamPlebeyo() const
{
    return tamPlebeyo;
}
//**********************************************

int ColaMedieval::ObtenerTamNoble() const
{
    return tamNoble;
}
//**********************************************

std::string ColaMedieval::ObtenerFondo() const
{
    if (EstaVacia()) throw ColaVacia();
    return fondo->nombre;
}
//**********************************************

std::string ColaMedieval::ObtenerFrente() const
{
    if (EstaVacia()) throw ColaVacia();
    return fondo->siguiente->nombre;
}
//**********************************************

std::string ColaMedieval::ObtenerClaseSocialFrente() const
{
    if (EstaVacia()) throw ColaVacia();
    return fondo->siguiente->claseSocial;
}

//*********************************************
bool ColaMedieval::EstaVacia() const
{
    return tam == 0;
}
//********************************************

void ColaMedieval::Vaciar()
{
    while (!EstaVacia())
        Eliminar();
}
//*******************************************
void ColaMedieval::Imprimir() const
{
    if (EstaVacia()) return;
    Individuo *actual = fondo->siguiente;
    std::cout << actual->claseSocial << " : " << actual->nombre << std::endl;
    while(actual!=fondo){

        actual = actual->siguiente;
        std::cout << actual->claseSocial << " : " << actual->nombre << std::endl;
    }
}
//*******************************************
void ColaMedieval::ImprimirSinFrente() const
{
    if (EstaVacia()) return;
    Individuo *actual = fondo->siguiente;
    bool omitirPrimerElemento = true;

    while(actual!=fondo){
        if (omitirPrimerElemento) omitirPrimerElemento = false;
            else std::cout << actual->claseSocial << " : " << actual->nombre << std::endl;
        actual = actual->siguiente;
    }
}
//*******************************************
const char* ColaVacia::what() const throw() {
    return "Cola vacia";
}
