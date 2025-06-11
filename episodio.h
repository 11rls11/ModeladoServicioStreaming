#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
#include "video.h"

using namespace std;

class Episodio : public Video {
    private:
        int numeroTemporada;
        int numeroEpisodio;
        int IDSerie;
    public:
        Episodio();
        Episodio(int ID, string nombre, int duracion, 
            string genero, double calificacion, 
            int numeroTemporada, int numeroEpisodio, int IDSerie);
        void mostrar() const override;
};

#endif