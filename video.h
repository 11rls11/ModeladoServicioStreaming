#ifndef VIDEO_H
#define VIDEO_H

#include <fstream>
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
        static string convertirTiempoEnHorasYMinutos(int);
    public:
        Video(int, string, int, string, double);
        virtual ~Video() {};
        virtual void mostrar() const = 0;
        friend ostream& operator<<(ostream& salida, const Video& video);
        static double calcularPromedioCalificacion(int);
        static void guardarCalificacion(int, double);
};

#endif