#include "serie.h"

Serie::Serie() : Video(0, "", 0, "", 0.0) {}

Serie::Serie(int ID, string nombre, int duracion, string genero, double calificacion) 
    : Video(ID, nombre, duracion, genero, calificacion) {}

void Serie::mostrar() const {
    int IDs[] {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    string nombres[] {"Breaking Bad", "Game of Thrones", "Stranger Things", "The Office", 
        "Friends", "The Crown", "Narcos", "Money Heist", "The Witcher", "Ozark",
        "House of Cards", "Black Mirror", "Sherlock", "The Mandalorian", "Better Call Saul",
        "Succession", "The Boys", "Euphoria", "Wednesday", "The Last of Us"
    };
    int duraciones[] {47, 57, 51, 22, 22, 58, 49, 67, 60, 60, 51, 61, 88, 40, 46, 60, 60, 50, 51, 81};
    string generos[] {"Drama", "Fantasía", "Ciencia ficción", "Comedia", "Comedia", 
        "Drama histórico", "Crimen", "Thriller", "Fantasía", "Thriller",
        "Drama político", "Ciencia ficción", "Misterio", "Space opera", "Drama",
        "Drama", "Superhéroes", "Drama", "Comedia", "Post-apocalíptico"
    };
    
    Serie *series = new Serie[20];
    
    for (int i = 0; i < 20; i++) {
        double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
        series[i] = Serie(IDs[i], nombres[i], duraciones[i], generos[i], calificacionPromedio);
        cout << (i + 1) << " - " << series[i] << endl;
    }
    
    delete[] series;
}