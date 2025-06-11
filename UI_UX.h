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
        void mostrarMenuAccion(const int &opcion, const int &numero);
        void mostrarMenuEpisodios(const int &IDSerie);
        void realizarReseña(const int &ID);
    public:
        UI_UX();
        void mostrarMenuPrincipal();
};

#endif