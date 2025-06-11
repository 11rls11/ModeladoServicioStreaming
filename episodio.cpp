#include "episodio.h"

Episodio::Episodio() : Video(0, "", 0, "", 0.0), numeroTemporada(0), numeroEpisodio(0), IDSerie(0) {}

Episodio::Episodio(int ID, string nombre, int duracion, string genero, double calificacion,
                   int numeroTemporada, int numeroEpisodio, int IDSerie) 
    : Video(ID, nombre, duracion, genero, calificacion), 
      numeroTemporada(numeroTemporada), numeroEpisodio(numeroEpisodio), IDSerie(IDSerie) {}

void Episodio::mostrar() const {
    if (IDSerie == 21) {
        int IDs[] = {101, 102, 103};
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
    } else if (IDSerie == 22) {
        int IDs[] = {201, 202, 203};
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