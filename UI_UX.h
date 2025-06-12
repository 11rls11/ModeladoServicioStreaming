#ifndef UI_UX_H
#define UI_UX_H

#include <iostream>
#include "video.h"
#include "pelicula.h"
#include "serie.h"
#include "episodio.h"

using namespace std;

class UI_UX {
    private:
        void mostrarMenuSeleccion(const int &opcion);
        void mostrarMenuSubseleccion(const int &opcion, Video* &videos);
        void mostrarGenerosDisponibles(const int &opcion);
        void mostrarMenuAccion(const int &opcion, int &numero);
        void realizarReseña(int &ID);
    public:
        UI_UX();
        void mostrarMenuPrincipal();
};

#endif