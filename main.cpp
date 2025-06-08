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
    public:
        Video(int, string, int, string, double);
        virtual int mostrar() const;
        static string convertirTiempoEnHorasYMinutos(int);
        friend ostream& operator<<(ostream& salida, const Video& video);
};

Video::Video(int ID, string nombre, int duracion, string genero, double calificacion) : 
ID(ID), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion) {};

int Video::mostrar() const {
    cout << "¨Qu‚ quieres ver hoy?\n1. Pel¡culas\n2. Series\n3. Salir" << endl;
    int opcion;
    cin >> opcion;
    return opcion;
}

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

class Pelicula : public Video {
    public:
        Pelicula();
        Pelicula(int, string, int, string, double);
        int mostrar() const override;
};

Pelicula::Pelicula() : Video(0, "", 0, "", 0.0) {};

Pelicula::Pelicula(int ID, string nombre, int duracion, string genero, double calificacion) : Video(ID, nombre, duracion, genero, calificacion) {};

int Pelicula::mostrar() const {
    int IDs[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    string nombres[] {"Avatar", "Avengers: Endgame", "Avatar: The Way of Water", "Titanic", 
        "Ne Zha 2", "Star Wars: Episodio VII - El despertar de la Fuerza", "Avengers: Infinity War", "Spider-Man: No Way Home",
        "Inside Out 2", "Jurassic World", "El rey le¢n", "The Avengers",
        "Furious 7", "Top Gun: Maverick", "Frozen II", "Barbie",
        "Avengers: Age of Ultron", "Super Mario Bros.: la pel¡cula", "Black Panther", "Harry Potter y las reliquias de la Muerte: parte 2"
    };
    int duraciones[] {183, 181, 192, 195, 144, 136, 149, 148, 96, 124, 118, 143, 140, 131, 103, 114, 141, 92, 134, 130};
    string generos[] = {"Ciencia ficci¢n", "Superh‚roes", "Ciencia ficci¢n", "Romance", 
        "Animaci¢n", "Space opera", "Superh‚roes", "Superh‚roes", 
        "Animaci¢n", "Ciencia ficci¢n", "Animaci¢n", "Superh‚roes",
        "Acci¢n", "Acci¢n", "Animaci¢n", "Comedia", 
        "Superh‚roes","Animaci¢n", "Superh‚roes", "Fantas¡a"};
    double calificaciones[20] {0.0};
    Pelicula *peliculas = new Pelicula[20];
    
    for (int i = 0; i < 20; i++) {
        peliculas[i] = Pelicula(IDs[i], nombres[i], duraciones[i], generos[i], calificaciones[i]);
        cout << (i + 1) << " - " << peliculas[i] << endl;
    } 

    delete[] peliculas;
    return 0;
}

int main() {
    Pelicula peliculas;
    peliculas.mostrar();
    return 0;
}