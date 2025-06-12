#ifndef VIDEO_H
#define VIDEO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Video {
    protected:
        int ID;
    private:
        string nombre;
        int duracion;
        string genero;
        double calificacion;
        static string convertirTiempoEnHorasYMinutos(int duracion);
    public:
        Video();
        Video(int, string, int, string, double);
        virtual ~Video() {};
        string getGenero();
        virtual void mostrar() const = 0;
        friend ostream& operator<<(ostream& salida, const Video& video);
        static double calcularPromedioCalificacion(const int &ID);
        static void guardarCalificacion(const int &ID, const double &calificacion);
};

#endif