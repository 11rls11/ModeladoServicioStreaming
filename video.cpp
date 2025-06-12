#include "video.h"

Video::Video() : ID(0), nombre(""), duracion(0), genero(""), calificacion(0.0) {}

Video::Video(int ID, string nombre, int duracion, string genero, double calificacion) : 
ID(ID), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion) {};

string Video::getNombre() const {
    return nombre;
}
int Video::getDuracion() const {
    return duracion;
}

string Video::getGenero() const {
    return genero;
}

double Video::getCalificacion() const {
    return calificacion;
}

string Video::convertirTiempoEnHorasYMinutos(int duracion) {
    int horas = duracion / 60;
    duracion %= 60;
    int minutos = duracion;
    string tiempo = to_string(horas) + "h " + to_string(minutos) + "m";
    return tiempo;
}

void Video::imprimir(ostream& salida, const Video &video) const {
    if (video.calificacion == 0.0) {
        salida << video.nombre << " | " << Video::convertirTiempoEnHorasYMinutos(video.duracion)
        << " | " << video.genero;
    } else {
        salida << video.nombre << " | " << Video::convertirTiempoEnHorasYMinutos(video.duracion)
        << " | " << video.genero << " | " << "Calificación: " << video.calificacion;
    }
}

ostream& operator<<(ostream& salida, const Video& video) {
    video.imprimir(salida, video);
    return salida;
}

double Video::calcularPromedioCalificacion(const int &ID) {
    ifstream calificaciones("calificaciones.txt");

    if (!calificaciones.is_open()) {
        return 0.0;
    }

    double suma = 0.0;
    int contador = 0;
    int IDArchivo;
    double calificacionArchivo;

    while (calificaciones >> IDArchivo >> calificacionArchivo) {
        if (IDArchivo == ID) {
            suma += calificacionArchivo;
            contador++;
        }
    }
    calificaciones.close();

    return (contador > 0) ? (suma / contador) : 0.0;
}

void Video::guardarCalificacion(const int &ID, const double &calificacion) {
    ofstream calificaciones("calificaciones.txt", ios::app);
    if (calificaciones.is_open()) {
        calificaciones << ID << " " << calificacion << endl;
        calificaciones.close();
        cout << "Calificación guardada exitosamente" << endl;
    } else {
        cout << "Error al abrir el archivo para guardar tu calificación" << endl;
    }
}