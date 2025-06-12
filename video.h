#ifndef VIDEO_H
#define VIDEO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Video {
    protected:
        int ID;
        static string convertirTiempoEnHorasYMinutos(int duracion);
    private:
        string nombre;
        int duracion;
        string genero;
        double calificacion;
    public:
        Video();
        Video(int, string, int, string, double);
        virtual ~Video() {};
        string getNombre() const;
        int getDuracion() const;
        string getGenero() const;
        double getCalificacion() const;
        virtual void imprimir(ostream& salida, const Video &video) const;
        virtual void mostrar() const = 0;
        friend ostream& operator<<(ostream& salida, const Video& video);
        static double calcularPromedioCalificacion(const int &ID);
        static void guardarCalificacion(const int &ID, const double &calificacion);
};

#endif