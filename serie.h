#ifndef SERIE_H
#define SERIE_H

#include "video.h"

class Serie : public Video {
    public:
        Serie();
        Serie(int ID, string nombre, 
            int duracion, string genero, 
            double calificacion);
        static Video* getSeries();
        void mostrar() const override;
};

#endif