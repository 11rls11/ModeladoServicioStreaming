#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>

using namespace std;

class Video {
    private:
        int ID;
        string nombre;
        int duracion;
        string genero;
        double calificacion;
    public:
        Video(int, string, int, string, double);
        virtual void mostrar() const = 0;
        static string convertirTiempoEnHorasYMinutos(int);
        friend ostream& operator<<(ostream& salida, const Video& video);
};

#endif