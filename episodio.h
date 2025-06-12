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
    public:
        Episodio();
        Episodio(int ID, string nombre, int duracion, 
            string genero, double calificacion, 
            int numeroTemporada, int numeroEpisodio);
        static int getNumeroDeEpisodios(const int &ID);
        void imprimir(ostream& salida, const Video &video) const override;
        void mostrar() const override;
        static bool hayEpisodios(const int &ID);
};

#endif