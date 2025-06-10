#ifndef PELICULA_H
#define PELICULA_H

#include "video.h"

class Pelicula : public Video {
    public:
        Pelicula();
        Pelicula(int ID, string nombre, int duracion, string genero, double calificacion);
        void mostrar() const override;
};

#endif