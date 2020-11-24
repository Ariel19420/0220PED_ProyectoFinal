#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct jugador {
    string Apodo;
    int edad;
    int puntuacion;
};

typedef struct jugador jugadorPuntuacion;

void ordenamiento (queue<jugadorPuntuacion>Jugadores_c){
    queue<jugadorPuntuacion> Copia;
    jugadorPuntuacion Jugador;
    jugadorPuntuacion Jugador2;
    jugadorPuntuacion cambio;
    queue<jugadorPuntuacion> final;
    int tamano;
    Copia=Jugadores_c;
    do
    {
        queue<jugadorPuntuacion> Comparador;
        cambio=Copia.front();
        Copia.pop();
        tamano = Copia.size();
        for(int i=0;i<tamano;i++){
            Jugador=Copia.front();
            Copia.pop();
            if(Jugador.edad<cambio.edad){
                Comparador.push(cambio);
                cambio=Jugador;
            }
            else
            {
                Comparador.push(Jugador);
            }
        }
        final.push(cambio);

        Copia=Comparador;
    } while (Copia.size()>0);

    int max_jugadores = final.size();
    for (int i= 0; i < max_jugadores; i++)
    {
        Jugador2=final.front();
        cout<<"\nNombre del jugador " << i+1 << ": "<< Jugador2.Apodo<< ". Edad del jugador es de: "
        <<Jugador2.edad<< ". Talla de zapatos es de: "<<Jugador2.puntuacion <<endl;
        final.pop();
    }
}
