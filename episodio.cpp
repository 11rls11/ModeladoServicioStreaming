#include "episodio.h"

Episodio::Episodio() : Video(0, "", 0, "", 0.0), numeroTemporada(0), numeroEpisodio(0) {}

Episodio::Episodio(int ID, string nombre, int duracion, string genero, double calificacion,
                   int numeroTemporada, int numeroEpisodio) 
    : Video(ID, nombre, duracion, genero, calificacion), 
      numeroTemporada(numeroTemporada), numeroEpisodio(numeroEpisodio) {}

void Episodio::mostrar() const {
    if (ID == 21) {
        int IDs[] = {2101, 2102, 2103};
        string nombres[] = {"Pilot", "Cat's in the Bag...", "...And the Bag's in the River"};
        int duraciones[] = {58, 48, 48};
        int temporadas[] = {1, 1, 1};
        int episodios[] = {1, 2, 3};

        cout << "\nEpisodios de Breaking Bad (3 primeros):" << endl;
        for (int i = 0; i < 3; i++) {
            double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
            cout << "T" << temporadas[i] << "E" << episodios[i] << ": " << nombres[i] 
                 << " | Duración: " << duraciones[i] << " min | Calificación: " << calificacionPromedio << endl;
        }
    } else if (ID == 22) {
        int IDs[] = {2201, 2202, 2203};
        string nombres[] = {"Winter Is Coming", "The Kingsroad", "Lord Snow"};
        int duraciones[] = {62, 56, 58};
        int temporadas[] = {1, 1, 1};
        int episodios[] = {1, 2, 3};

        cout << "\nEpisodios de Game of Thrones (3 primeros):" << endl;
        for (int i = 0; i < 3; i++) {
            double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
            cout << "T" << temporadas[i] << "E" << episodios[i] << ": " << nombres[i] 
                 << " | Duración: " << duraciones[i] << " min | Calificación: " << calificacionPromedio << endl;
        }
    } else {
        cout << "No hay episodios disponibles para esta serie." << endl;
    }
}

bool Episodio::hayEpisodios(const int &ID) {
    switch (ID) {
        case 21:
        case 22:
            return true;
        default:
            return false;
    }
}