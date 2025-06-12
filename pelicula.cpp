#include "pelicula.h"

Pelicula::Pelicula() : Video(0, "", 0, "", 0.0) {};

Pelicula::Pelicula(int ID, string nombre, int duracion, string genero, double calificacion) : Video(ID, nombre, duracion, genero, calificacion) {};

Video* Pelicula::getPeliculas() {
    int IDs[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    string nombres[] {"Avatar", "Avengers: Endgame", "Avatar: The Way of Water", "Titanic", 
        "Ne Zha 2", "Star Wars: Episodio VII - El despertar de la Fuerza", "Avengers: Infinity War", "Spider-Man: No Way Home",
        "Inside Out 2", "Jurassic World", "El rey león", "The Avengers",
        "Furious 7", "Top Gun: Maverick", "Frozen II", "Barbie",
        "Avengers: Age of Ultron", "Super Mario Bros.: la película", "Black Panther", "Harry Potter y las reliquias de la Muerte: parte 2"
    };
    int duraciones[] {183, 181, 192, 195, 144, 136, 149, 148, 96, 124, 118, 143, 140, 131, 103, 114, 141, 92, 134, 130};
    string generos[] = {"Ciencia ficción", "Superhéroes", "Ciencia ficción", "Romance", 
        "Animación", "Space opera", "Superhéroes", "Superhéroes", 
        "Animación", "Ciencia ficción", "Animación", "Superhéroes",
        "Acción", "Acción", "Animación", "Comedia", 
        "Superhéroes","Animación", "Superhéroes", "Fantasía"};
    Video *peliculas = new Pelicula[20];
    
    for (int i = 0; i < 20; i++) {
        double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
        peliculas[i] = Pelicula(IDs[i], nombres[i], duraciones[i], generos[i], calificacionPromedio);
    } 

    return peliculas;
}

void Pelicula::mostrar() const {
    switch (ID) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10: {
            cout << "\nReproduciendo película:" << endl;
            Video *peliculas = getPeliculas();
            cout << peliculas[ID] << endl;
            delete[] peliculas;
            break;
        }
        default:
            cout << "La película no está disponible por el momento." << endl;
            break;
    }
}