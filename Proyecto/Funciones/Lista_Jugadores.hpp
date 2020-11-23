#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct jugador {
    string Apodo; 
    int edad;
    double talla;
};

void menuListaJugadores (vector<jugador> &Jugadores){
        int select1; jugador Player; int eliminacion=0; int cont_a=0; int cont_n=0; ;int terminar=0; int max_jugadores=0;
        jugador Player2; float total_a; float total_n;
        vector <jugador> Copia;
        int Ptotal;
        Jugadores.clear();
        while(terminar!=5){
            cout << "\n********** MENU **********" << endl;
            cout << "1. Ingresar jugador" << endl;
            cout << "2. Eliminar jugador" << endl;
            cout << "3. Ver todos los datos de los jugadores" << endl;
            cout << "4. Eliminar todos los jugadores" << endl;
            cout << "5. Procesar jugadores y factura" << endl<< ">";
            cin>> select1;
            cin.ignore();
            switch (select1)
            {
                case 1:
                if(Jugadores.size()<=5){
                    Player.Apodo=" ";Player.edad=0;Player.talla=0;
                    cout<< "\nIngrese nombre del jugador"<< endl << ">"; 
                    getline (cin, Player.Apodo);
                    cout<< "\nIngrese edad del jugador"<< endl << ">";
                    cin>> Player.edad;
                    cin.ignore();
                    cout<< "\nIngrese su talla de zapato "<< endl << ">";
                    cin>> Player.talla;
                    cin.ignore();
                        if (Player.edad>=18){
                            cont_a++;
                        }
                        else{
                            cont_n++;
                        }
                    Jugadores.push_back(Player);
                    max_jugadores++;
                    cout<< "\nJugador agragado con exito"<< endl;
                }
                else{
                    cout<< "\nMaximo de jugadores alcanzado para este juego"<< endl;
                }
                break;
                case 2:
                    if(!Jugadores.empty()){
                    cout<< "\nIngrese la posicion del jugador que quiere eliminar"<< endl<< ">";
                    cin>> eliminacion;
                    cin.ignore();
                    switch (eliminacion){
                        case 1:
                        if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else
                            {
                                Jugadores.erase(Jugadores.begin()); 
                                max_jugadores--;
                                cout<<"\nJugador eliminado con exito"<<endl;
                            }
                        break;
                        case 2:
                            if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else{
                            Jugadores.erase(Jugadores.begin()+1); 
                            max_jugadores--;
                            cout<<"\nJugador eliminado con exito"<<endl;
                            }
                        break;
                        case 3:
                            if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else
                            {
                                Jugadores.erase(Jugadores.begin()+2);
                            
                            max_jugadores--;
                            cout<<"\nJugador eliminado con exito"<<endl;
                            }
                            
                            
                        break;
                        case 4:
                            if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else
                            {
                                Jugadores.erase(Jugadores.begin()+3);
                            max_jugadores--;
                            cout<<"\nJugador eliminado con exito"<<endl;
                            }
                            
                            
                        break;
                        case 5:
                            if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else
                            {
                                Jugadores.erase(Jugadores.begin()+4);
                            
                            max_jugadores--;
                            cout<<"\nJugador eliminado con exito"<<endl;
                            }
                            
                            
                        break;
                        case 6:
                            if(eliminacion>Jugadores.size()){
                                cout<<"\nNo hay jugador en esta posicion para eliminar"<<endl;
                            }
                            else
                            {
                                Jugadores.erase(Jugadores.begin()+5);
                            
                            max_jugadores--;
                            cout<<"\nJugador eliminado con exito"<<endl;
                            }
                            
                            
                        break;
                        default:
                            cout<< "\nEsa no es una posicion validad"<< endl;
                        break;
                    }
                }
                    else
                    {
                        cout<< "\nError no hay nada en la lista"<<endl;
                    }
                break;
                case 3:
                    if(!Jugadores.empty()){
                        Copia=Jugadores;
                        for(int i=0 ;i<max_jugadores;i++){
                        Player2=Copia.front();
                        Copia.erase(Copia.begin());
                        cout<< "\nJugador #"<< i+1 <<" nombre: "<<Player2.Apodo<<" Edad: "<< Player2.edad<<" Talla: "<<Player2.talla<<endl;
                        }
                    }
                    else
                    {
                        cout<< "\nError no hay jugadores registrados "<<endl;
                    }
                    
                break;
                    case 4:
                        if (!Jugadores.empty()){
                        Jugadores.clear();
                        }
                        else
                        {
                            cout<<"\nError no hay jugadores registrados "<<endl;
                        }
                        break;
                        case 5:
                            if (!Jugadores.empty())
                            {
                            cout<< "\nProcesando..." << endl; 
                            terminar=5; 
                            total_a=cont_a*6.80;
                            total_n=cont_n*3.40;
                            Ptotal=total_a+total_n;
                            cout<< "\n********** Factura **********"<<endl;
                            cout<< "Total Adultos:"<< "\t"<< cont_a << endl;
                            cout<< "Total menores"<< "\t"<< cont_n << endl;
                            cout<< "Total a pagar por adultos"<< "\t"<< total_a << endl;
                            cout<< "Total a pagar por menores"<< "\t"<< total_n << endl;
                            cout<< "Total final de paga "<< "\t"<< Ptotal << endl;
                            } 
                            else
                            {
                                cout<<"\nError no hay jugadores registrados "<<endl;
                            }
                            break;
                            default:
                            cout<< "\nOpcion no valida"<< endl;
                            break;
            }
        }
}
