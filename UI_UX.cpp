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
            Video *peliculas = Pelicula::getPeliculas();
            
            for (int i = 0; i < 20; i++) {
                cout << (i + 1) << " - " << peliculas[i] << endl;
            }
            
            mostrarMenuSubseleccion(opcion, peliculas);
            delete[] peliculas;
            break;
        }
        case 2: {
            cout << "\nSeries disponibles:" << endl;
            Video *series = Serie::getSeries();
            
            for (int i = 0; i < 20; i++) {
                cout << (i + 1) << " - " << series[i] << endl;
            }
            
            mostrarMenuSubseleccion(opcion, series);
            delete[] series;
            break;
        }
        default:
            cout << "Opción no válida" << endl;
    }
}

void UI_UX::mostrarMenuSubseleccion(const int &opcion, Video* &videos) {
    int eleccion;
    string tipoVideo = (opcion == 1) ? "Películas" : "Series";
    
    cout << "¿Quieres filtrar " << tipoVideo << " por género? (1. Sí / 2. No): ";
    cin >> eleccion;

    switch (eleccion) {
        case 1: {
            string genero;
            mostrarGenerosDisponibles(opcion);
            cout << "Escribe el género a filtrar: ";
            getline(cin, genero);

            if (genero.empty()) {
                getline(cin, genero);
            }
            
            int* indicesFiltrados = new int[20];
            int cantidadFiltrados = 0;
            
            for (int i = 0; i < 20; i++) {
                if (videos[i].getGenero() == genero) {
                    indicesFiltrados[cantidadFiltrados] = i;
                    cantidadFiltrados++;
                }
            }
            
            if (cantidadFiltrados == 0) {
                cout << "No se encontraron " << tipoVideo << " del género: " << genero << endl;
                delete[] indicesFiltrados;
                return;
            }
            
            cout << "\n" << tipoVideo << " del género " << genero << ":" << endl;
            for (int i = 0; i < cantidadFiltrados; i++) {
                cout << (i + 1) << " - " << videos[indicesFiltrados[i]] << endl;
            }
            
            int seleccion;
            cout << "\nSelecciona una " << ((opcion == 1) ? "película" : "serie") 
                 << " (introduce el número): ";
            cin >> seleccion;
            
            if (seleccion >= 1 && seleccion <= cantidadFiltrados) {
                int IDFiltado = indicesFiltrados[seleccion - 1] + 1;
                mostrarMenuAccion(opcion, IDFiltado);
            } else {
                cout << "Número no válido" << endl;
            }
            
            delete[] indicesFiltrados;
            break;
        }
        case 2: {
            int ID;
            cout << "\nSelecciona una " << ((opcion == 1) ? "película" : "serie") 
                 << " (introduce el número): ";
            cin >> ID;
             
            if (ID >= 1 && ID <= 20) {
                mostrarMenuAccion(opcion, ID);
            } else {
                cout << "Número no válido" << endl;
            }
            break;
        }
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}

void UI_UX::mostrarGenerosDisponibles(const int &opcion) {
    Video* contenido = nullptr;
    
    if (opcion == 1) {
        contenido = Pelicula::getPeliculas();
    } else if (opcion == 2) {
        contenido = Serie::getSeries();
    }
    
    if (contenido) {
        cout << "\nGéneros disponibles:" << endl;
        string generos[20];
        int contadorGeneros = 0;
        
        for (int i = 0; i < 20; i++) {
            bool yaExiste = false;
            for (int j = 0; j < contadorGeneros; j++) {
                if (contenido[i].getGenero() == generos[j]) {
                    yaExiste = true;
                    break;
                }
            }
            if (!yaExiste) {
                generos[contadorGeneros] = contenido[i].getGenero();
                cout << (contadorGeneros + 1) << " - " << generos[contadorGeneros] << endl;
                contadorGeneros++;
            }
        }
        
        delete[] contenido;
    }
}

void UI_UX::mostrarMenuAccion(const int &opcion, int &ID) {
    switch (opcion) {
        case 1: {
            int accion;
            cout << "\n¿Qué quieres hacer con la película?" << '\n'
                << "1. Ver" << '\n'
                << "2. Reseñar" << '\n'
                << "Elige una opción: ";
            cin >> accion;

            switch (accion) {
                case 1: {
                    Video *pelicula = new Pelicula(ID, "", 0, "", 0.0);
                    pelicula->mostrar();
                    delete pelicula;
                    break;
                }
                case 2:
                    realizarResenia(ID);
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
                    ID += 20;
                    Episodio *episodio = new Episodio(ID, "", 0, "", 0.0, 0, 0);
                    episodio->mostrar();
                    
                    if (Episodio::hayEpisodios(ID)) {
                        int numeroEpisodio;
                        cout << "\nSelecciona un episodio: ";
                        cin >> numeroEpisodio;
                        int totalDeEpisodios = Episodio::getNumeroDeEpisodios(ID);
                        if (numeroEpisodio >= 1 && numeroEpisodio <= totalDeEpisodios) {
                            cout << "Reproduciendo episodio..." << endl;
                            int reseñar;
                            cout << "¿Quieres reseñar este episodio? (1. Sí / 2. No): ";
                            cin >> reseñar;
                            if (reseñar == 1) {
                                ID = ID * 100 + numeroEpisodio;
                                realizarResenia(ID);
                            }
                        } else {
                            cout << "Número de episodio no válido" << endl;
                        }
                    }
                    delete episodio;
                    break;
                }
                case 2:
                    ID += 20;
                    realizarResenia(ID);
                    break;
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
            break;
        }
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}

void UI_UX::realizarResenia(int &ID) {
    double calificacion;
    cout << "Introduce tu calificación (0.0 - 5.0): ";
    cin >> calificacion;
    while (calificacion < 0.0 || calificacion > 5.0) {
        cout << "Calificación inválida. Introduce un valor entre 0.0 y 5.0: ";
        cin >> calificacion;
    }
    
    if (ID > 2100) {
        Video::guardarCalificacion(ID, calificacion);
        ID /= 100;
        Video::guardarCalificacion(ID, calificacion);
    } else {
        Video::guardarCalificacion(ID, calificacion);
    }
}
