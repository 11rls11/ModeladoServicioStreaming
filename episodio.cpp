#include "episodio.h"

Episodio::Episodio() : Video(0, "", 0, "", 0.0), numeroTemporada(0), numeroEpisodio(0) {}

Episodio::Episodio(int ID, string nombre, int duracion, string genero, double calificacion,
                   int numeroTemporada, int numeroEpisodio) 
    : Video(ID, nombre, duracion, genero, calificacion), 
      numeroTemporada(numeroTemporada), numeroEpisodio(numeroEpisodio) {}

void Episodio::imprimir(ostream& salida, const Video &episodio) const {
    if (episodio.getCalificacion() == 0.0) {
        salida << "T" << numeroTemporada << "E" << numeroEpisodio 
        << ": " << episodio.getNombre() << " | " 
        << Video::convertirTiempoEnHorasYMinutos(episodio.getDuracion()) << " | ";
    } else {
        salida << "T" << numeroTemporada << "E" << numeroEpisodio 
        << ": " << episodio.getNombre() << " | " << Video::convertirTiempoEnHorasYMinutos(episodio.getDuracion())
        << " | " << "Calificación: " << episodio.getCalificacion();
    }
}

void Episodio::mostrar() const {
    switch (ID) {
        case 21: {
            int IDs[] = {2101, 2102, 2103};
            string nombres[] {"Pilot", "Cat's in the Bag...", "...And the Bag's in the River"};
            int duraciones[] {58, 48, 48};
            int temporadas[] {1, 1, 1};
            int episodios[] {1, 2, 3};

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de Breaking Bad:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        }
        case 22: {
            int IDs[] = {2201, 2202, 2203};
            string nombres[] {"Winter Is Coming", "The Kingsroad", "Lord Snow"};
            int duraciones[] {62, 56, 58};
            int temporadas[] {1, 1, 1};
            int episodios[] {1, 2, 3};

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de Game of Thrones:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        }
        case 23: {
            int IDs[] = {2301};
            string nombres[] {"The Vanishing of Will Byers"};
            int duraciones[] {49};
            int temporadas[] {1};
            int episodios[] {1}; 

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de Stranger Things:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        } 
        case 24: {
            int IDs[] = {2401};
            string nombres[] {"Pilot"};
            int duraciones[] {22};
            int temporadas[] {1};
            int episodios[] {1}; 

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de The Office:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        }
        case 26: {
            int IDs[] = {2601};
            string nombres[] {"Wolferton Splash"};
            int duraciones[] {56};
            int temporadas[] {1};
            int episodios[] {1}; 

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de The Crown:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        }
        case 27: {
            int IDs[] = {2701};
            string nombres[] {"Descenso"};
            int duraciones[] {57};
            int temporadas[] {1};
            int episodios[] {1}; 

            Episodio *episodiosSerie = new Episodio[3];

            int n = sizeof(IDs)/sizeof(IDs[0]);

            cout << "\nEpisodios de The Crown:" << endl;
            for (int i = 0; i < n; i++) {
                double calificacionPromedio = Video::calcularPromedioCalificacion(IDs[i]);
                episodiosSerie[i] = Episodio(IDs[i], nombres[i], duraciones[i], "", calificacionPromedio, temporadas[i], episodios[i]);
                cout << episodiosSerie[i] << endl;
            }
            delete[] episodiosSerie;
            break;
        }
        default:
            cout << "No hay episodios disponibles para esta serie." << endl;
            break;
    }
}

int Episodio::getNumeroDeEpisodios(const int &serieID) {
    switch (serieID) {
        case 21: return 3;
        case 22: return 3; 
        case 23: return 1;
        case 24: return 1;
        case 26: return 1;
        case 27: return 1;
        default: return 0;
    }
}

bool Episodio::hayEpisodios(const int &ID) {
    switch (ID) {
        case 21:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
            return true;
        default:
            return false;
    }
}