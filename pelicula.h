#ifndef PELICULA_H
#define PELICULA_H

#include "video.h"

class Pelicula : public Video {
    public:
        Pelicula();
        Pelicula(int, string, int, string, double);
        void mostrar() const override;
};

#endif