#ifndef UI_UX_H
#define UI_UX_H

#include <iostream>
#include "video.h"
#include "pelicula.h"

using namespace std;

class UI_UX {
    private:
        void mostrarMenuSeleccion(int);
        void mostrarMenuAccion(int, int);
        void realizarReseña(int);
    public:
        UI_UX();
        void mostrarMenuPrincipal();
};

#endif
