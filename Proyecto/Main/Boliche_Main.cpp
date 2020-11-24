#include <vector>
#include <queue>
#include <iostream>
#include "Cola_Juego.hpp"

using namespace std;

int main (){
    bool llave1 = false;
    bool subLlave = true;
    bool llave2 = false;
    bool salida = false;
    bool condicion = true;
    int opcion = 0;
    queue <jugadorPuntuacion> colaEnJuego;
    vector <ijugador> listaJugadores;
    queue <bolas> colaBolasEnJuego;
    do{
    cout << "\nElija una opcion: " << endl;
    cout << "1. Ingresar a los jugadores." << endl;
    cout << "2. Ingresar las bolas de boliche que desee." << endl;
    cout << "3. Procesar juego (Debera haber llenado los campos anteriores)." << endl;
    cout << "4. Cancelar todo(No se cobrara)." << endl; 
    cout << ">";
    cin >> opcion; cin.ignore();
    switch (opcion)
    {
    case 1:
        if (!llave1){
        llave1 = menuListaJugadores(listaJugadores);
        subLlave = false;
        }
        else
        {
            cout << "\nYa se han procesado los datos de este campo" << endl;
        }
        
        break;
    
    case 2:

        if (!llave2 && subLlave != true ){
        llave2 = MenuBolas(listaJugadores.size(), colaBolasEnJuego);
        }
        else
        {
            cout << "\nError, puede ser que ya se han procesado los datos de este campo o no se ha procesado la factura" << endl;
        }
        subLlave = true;
        break;
    
    case 3:
        if (llave1 == true && llave2 == true)
        {
            salida = jugadoresRondas(listaJugadores, colaEnJuego, colaBolasEnJuego);
            if (salida == false){
                condicion = false;
            }
            else {
                llave1 = false;
                llave2 = false;
            }
        }
        else
        {
            cout << "\nDebe pasar por los campos anteriores. " << endl;
        }
        
        break;
    
    case 4: 
    cout << "\nVuelva pronto" << endl;
    condicion = false;
    break;
    
    default:   
        cout << "\nOpcion invalida." << endl; 
        break;
    }
    }while(condicion);
}

