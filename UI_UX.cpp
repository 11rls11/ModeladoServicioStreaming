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
            case 1: {
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

void UI_UX::mostrarMenuSeleccion(int opcion) {
    switch (opcion) {
        case 1: {
            cout << "\nPelículas disponibles" << endl;
            Pelicula peliculas;
            peliculas.mostrar();
            int numeroPelicula;
            cout << "\nSelecciona una película (introduc el número de la película): ";
            cin >> numeroPelicula;

            if (numeroPelicula >= 1 && numeroPelicula <= 20) {
                mostrarMenuAccion(opcion, numeroPelicula);
            } else {
                cout << "Número de película no válido" << endl;
            }
            break;
        }
        default:
            cout << "Opción no válida" << endl;
    }
}

void UI_UX::mostrarMenuAccion(int opcion, int IDVideo) {
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
                    realizarReseña(IDVideo);
                    break;
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
            break;
        }
    }
}

void UI_UX::realizarReseña(int IDVideo) {
    double calificacion;
    cout << "Introduce tu calificación (0.0 - 5.0): ";
    cin >> calificacion;
    while (calificacion < 0.0 || calificacion > 5.0) {
        cout << "Calificación inválida. Introduce un valor entre 0.0 y 5.0: ";
        cin >> calificacion;
    }
    if (IDVideo >= 1 && IDVideo <= 20) {
        Video::guardarCalificacion(IDVideo, calificacion);
    }
}