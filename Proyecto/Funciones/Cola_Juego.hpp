#include <iostream>
#include <queue>
#include <string>
#include "Lista_Jugadores.hpp"
#include "Ordenamiento_Cola.hpp"
#include "Cola_Bolas.hpp"
using namespace std;



//Llamada de funciones
bool jugadoresRondas(vector <ijugador> &listaJugadores, queue <jugadorPuntuacion> &colaEnJuego, queue <bolas> &coladebolas);
void subMenu (queue <jugadorPuntuacion> &orden);
void menuPuntuaciones (jugadorPuntuacion &traspasoPuntos);
jugadorPuntuacion comparadorGanador(queue <jugadorPuntuacion> colaEnJuego);
bool subMenuFinal ();

//Funciones

bool jugadoresRondas( vector <ijugador> &listaJugadores, queue <jugadorPuntuacion> &colaEnJuego, queue <bolas> &coladebolas){
int opcion = 0;
int rondas = 0;
bool juegoCancelado = false;
bool condicion = true;
jugadorPuntuacion ganador;

//Pasando info de lista a cola

vector <ijugador> copiaLista;
ijugador traspasoLista;
copiaLista = listaJugadores;

for (int i = 0; i < listaJugadores.size(); i++)
{
    jugadorPuntuacion traspasoCola;
    traspasoLista = copiaLista.front();
    traspasoCola.Apodo = traspasoLista.Apodo; 
    traspasoCola.edad = traspasoLista.edad;
    traspasoCola.puntuacion = 0;
    copiaLista.erase(copiaLista.begin());
    colaEnJuego.push(traspasoCola);
}

//Menu principal
bool continuarJuego;
do{
//Variables de mas adelante
    jugadorPuntuacion traspasoPuntos;
    cout << "\n********** MENU **********" << endl;
    cout << "1. Iniciar juego. (No hay reembolso)" << endl;
    cout << "2. Cancelar juego (Regresar a menu anterior)." << endl;
    cout << ">";
    cin >> opcion;
    cin.ignore();

    switch (opcion)
    {
    case 1:
        subMenu (colaEnJuego);
        cout<<"\nIngrese el numero de rondas que desea jugar (MAXIMO 10)"<<endl;
        cin >> rondas; cin.ignore();

        //Evaluacion para "rondas"

        if (rondas>=1 && rondas<=10)
        {
        for (size_t i = 0; i < rondas; i++)
        {
            cout << "\n*****Ronda " << i+1 << "*****" << endl;
                for (int i = 0; i < colaEnJuego.size(); i++)
                    {
                        traspasoPuntos = colaEnJuego.front();
                        cout << "\nJugador " << i+1 << " tirara";
                        bolasEnJuego(coladebolas);
                        cout << "\nJugador " << i+1 << " su puntuacion es: ";
                        menuPuntuaciones(traspasoPuntos);
                        colaEnJuego.pop();
                        colaEnJuego.push(traspasoPuntos);
                    }
        }
        ganador = comparadorGanador(colaEnJuego);
        cout << "\nEl ganador es: " << ganador.Apodo << endl;
        cout << "Puntos: " << ganador.puntuacion << endl;
        cout << "FELICIDADES!!!!!" << endl;
        condicion = false;
        continuarJuego = subMenuFinal();
        }
        else{
            cout << "\nError numero de rondas no valido volviendo al menu de juego"<<endl;
        }
        break;
    
    case 2:
        cout << "\nJuego cancelado (No se le cobrara la factura en caja)" << endl;
        condicion = false;
        return juegoCancelado;
        break;
    
    default:
    cout << "\nError, elija una opcion valida\n"; 
        break;
    
    }
}while (condicion);
return continuarJuego;
}


void subMenu (queue <jugadorPuntuacion> &orden){
    bool condicional = true;
    int opcion = 0;
do
{
    cout << "\n********** MENU **********" << endl;
    cout << "1. Mantener orden de entrada" << endl;
    cout << "2. Ordenar a los jugadores por edad." << endl;
    cout << ">";
    cin >> opcion;
    cin.ignore();

    switch (opcion)
    {
    case 1:
        cout << "\nOrden mantenido" << endl;
        condicional = false;
        break;
    
    case 2:
        cout << "\nOrden cambiado" << endl;
        ordenamiento(orden);
        condicional = false;
        break;
    
    default:
    cout << "\nError, elija una opcion valida\n"; 
        break;
    }
} while (condicional);

}

void menuPuntuaciones (jugadorPuntuacion &traspasoPuntos){
bool condicion = true;
int opcion = 0;
int puntos = 0;
do
{
    cout << "\n********** PUNTUACIONES **********" << endl;
    cout<<"1. Abierto"<<endl;
    cout<<"2. Strike"<<endl;
    cout<<"3. Semipleno"<<endl;
    cout << ">";
    cin >> opcion; cin.ignore();
    switch (opcion)
    {
    case 1:

        do{
        cout << "\nInserte la cantidad de puntos que anoto:" << endl; 
        cin >> puntos;
        if (puntos >=1 && puntos <=10){
        traspasoPuntos.puntuacion += puntos; 
        condicion = false;
        }
        else {
            cout << "\nError, cantidad introducida no valida" << endl;
        }
        }while(condicion);

        break;
    
    case 2:
        cout << "\nObtuvo 15 puntos." << endl;
        traspasoPuntos.puntuacion += 15;
        condicion = false;
        break;
    
    case 3:
        cout << "\nObtuvo 12 puntos." << endl;
        traspasoPuntos.puntuacion += 12;
        condicion = false;
        break;
    
    default:
        cout << "\nError, elija una opcion valida\n"; 
        break;
    }
} while (condicion);

}

jugadorPuntuacion comparadorGanador(queue <jugadorPuntuacion> colaEnJuego){
    jugadorPuntuacion ganador;
    jugadorPuntuacion comparado;
    ganador = colaEnJuego.front(); 
for (int i = 0; i < colaEnJuego.size(); i++)
{
    colaEnJuego.pop();
    comparado = colaEnJuego.front();
    if (ganador.puntuacion < comparado.puntuacion){
        ganador = comparado;
    }
}
return ganador;
}

bool subMenuFinal (){
char opcion;
cout << "\nDesea jugar de nuevo?" << endl;
cout << "'S': SI / 'N' : NO" << endl;
cout << ">";
cin >> opcion;
if (opcion == 'S'){
    cout << "Procesando..." << endl;
    cout << "AVISO: Se han mantenido sus datos. Si desea cambiarlos puede ir a lista y/o bolas de boliche para cambiar sus preferencias y procesar la nueva factura" << endl;
    return true;
}
else{
    cout << "\nGracias por jugar" << endl;
    return false;
}
}
