#include "video.h"

Video::Video(int ID, string nombre, int duracion, string genero, double calificacion) : 
ID(ID), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion) {};

string Video::convertirTiempoEnHorasYMinutos(int duracion) {
    int horas = duracion / 60;
    duracion %= 60;
    int minutos = duracion;
    string tiempo = to_string(horas) + "h " + to_string(minutos) + "m";
    return tiempo;
}

ostream& operator<<(ostream& salida, const Video& video) {
    if (video.calificacion == 0.0) {
    salida << video.nombre << " | " << Video::convertirTiempoEnHorasYMinutos(video.duracion)
        << " | " << video.genero;
    } else {
    salida << video.nombre << " | " << Video::convertirTiempoEnHorasYMinutos(video.duracion)
        << " | " << video.genero << video.calificacion;
    }
    return salida;
}
