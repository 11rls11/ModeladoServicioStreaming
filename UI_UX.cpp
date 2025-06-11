#include "UI_UX.h"

UI_UX::UI_UX() {}

void UI_UX::mostrarMenuPrincipal() {
    int opcion = 0;

    while (opcion != 3) {
        cout << "¿Qué quieres ver hoy?" << '\n'
            << "1. Películas" << '\n'
            << "2. Series" << '\n'
            << "3. Salir" << '\n'
            << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            case 2: {
                mostrarMenuSeleccion(opcion);
                break;
            }
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    }
}

void UI_UX::mostrarMenuSeleccion(const int &opcion) {
    switch (opcion) {
        case 1: {
            cout << "\nPelículas disponibles:" << endl;
            Video *peliculas = new Pelicula();
            peliculas->mostrar();
            delete peliculas;
            
            int numeroPelicula;
            cout << "\nSelecciona una película (introduce el número): ";
            cin >> numeroPelicula;

            if (numeroPelicula >= 1 && numeroPelicula <= 20) {
                mostrarMenuAccion(opcion, numeroPelicula);
            } else {
                cout << "Número de película no válido" << endl;
            }
            break;
        }
        case 2: {
            cout << "\nSeries disponibles:" << endl;
            Video *series = new Serie();
            series->mostrar();
            delete series;
            
            int numeroSerie;
            cout << "\nSelecciona una serie (introduce el número): ";
            cin >> numeroSerie;

            if (numeroSerie >= 1 && numeroSerie <= 20) {
                mostrarMenuAccion(opcion, numeroSerie);
            } else {
                cout << "Número de serie no válido" << endl;
            }
            break;
        }
        default:
            cout << "Opción no válida" << endl;
    }
}

void UI_UX::mostrarMenuAccion(const int &opcion, const int &numero) {
    switch (opcion) {
        case 1: {
            int accion;
            cout << "\n¿Qué quieres hacer con la película?" << '\n'
                << "1. Ver" << '\n'
                << "2. Reseñar" << '\n'
                << "Elige una opción: ";
            cin >> accion;

            switch (accion) {
                case 1:
                    cout << "Reproduciendo película..." << endl;
                    break;
                case 2:
                    realizarReseña(numero);
                    break;
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
            break;
        }
        case 2: {
            int accion;
            cout << "\n¿Qué quieres hacer con la serie?" << '\n'
                << "1. Ver episodios" << '\n'
                << "2. Reseñar serie" << '\n'
                << "Elige una opción: ";
            cin >> accion;

            switch (accion) {
                case 1: {
                    int IDSerie = numero + 20;
                    Episodio episodio(0, "", 0, "", 0.0, 0, 0, IDSerie);
                    episodio.mostrar();

                    int numeroEpisodio;
                    cout << "\nSelecciona un episodio (1-3): ";
                    cin >> numeroEpisodio;
                    if (numeroEpisodio >= 1 && numeroEpisodio <= 3) {
                        cout << "Reproduciendo episodio..." << endl;
                        int reseñar;
                        cout << "¿Quieres reseñar este episodio? (1. Sí / 2. No): ";
                        cin >> reseñar;
                        if (reseñar == 1) {
                            int IDEpisodio = IDSerie * 100 + numeroEpisodio; // Ejemplo de ID único
                            realizarReseña(IDEpisodio);
                        }
                    } else {
                        cout << "Número de episodio no válido" << endl;
                    }
                    break;
                }
                case 2:
                    realizarReseña(numero + 20);
                    break;
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
            break;
        }
    }
}

void UI_UX::realizarReseña(const int &ID) {
    double calificacion;
    cout << "Introduce tu calificación (0.0 - 5.0): ";
    cin >> calificacion;
    while (calificacion < 0.0 || calificacion > 5.0) {
        cout << "Calificación inválida. Introduce un valor entre 0.0 y 5.0: ";
        cin >> calificacion;
    }
    
    Video::guardarCalificacion(ID, calificacion);
}