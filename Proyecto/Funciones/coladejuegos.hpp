#include <iostream>
#include <queue>
#include <string>
#include "Lista_Jugadores.hpp"

using namespace std;

struct jug{
    string nombre;
    int edad;
    int puntuacion;
};


typedef struct jug j;

bool orden(vector <jugador> Jugadores);
void pasardatos(vector <jugador> Jugadores, vector <jugador> gg, jugador jj, jug j);

queue <jug> o;
queue <jug> o1;

j j1, j2;
jugador jj,jj2;
vector<jugador>Jugadores;
vector<jugador>gg;

int main(){
    menuListaJugadores(Jugadores);
    pasardatos(Jugadores, gg,jj,j1);
    orden (Jugadores);
    return 0;
}

void pasardatos(vector <jugador> Jugadores, vector <jugador> gg, jugador jj, jug j11){
    if(!Jugadores.empty()){
        gg=Jugadores;
        for(int i=0;i<Jugadores.size();i++){
            jj2=gg.front();
            gg.erase(gg.begin());
            j1.nombre=jj2.Apodo;
            j1.edad=jj2.edad;
            o.push(j1);
        }
    }

}

bool orden(vector <jugador> Jugadores){
    bool continuar=true;
    j j3;
    string opcion;
    int n=0,pr=0,m=0,op=0,pun=0,a=0,s=15,se=12 ;

    do{
    cout<<"-- Ingrese la opcion que desee --"<<endl<<endl;
    cout<<"-- 1) Ordenar a los jugadores por edad --"<<endl;
    cout<<"-- 2) Ordenar a los jugadores por preferecia --"<<endl;
    cout<<"-- 3) Iniciar juego --"<<endl;
    cout<<"-- 4) Finalizar el juego --"<<endl;
    cin>>n;
    cin.ignore();

    switch(n){
        case 1:

        while(!o.empty()){
            o.pop();
        }

        for(int i=0;i<Jugadores.size();i++){
            for(int j=i+1;j<Jugadores.size();j++){
                j3=j1;
                j1=j1;
                j1=j3;
            }
        }
        cout<<"-- Se ha ordenado la cola de mayor edad a menor edad --"<<endl<<endl;;
        break;

        case 2:
        cout<<"-- Ingrese la opcion que desee para ingresar a los jugadores --"<<endl;
        for(int i=0;i<Jugadores.size();i++){
            cout<<j1.nombre<<endl;
            cin>>pr;
        }
        break;

        case 3:
        cout<<Jugadores.size()<<endl;
        cout<<"-- Ingrese el numero de rondas que desea jugar --"<<endl;
        cout<<"-- El numero de rondas no puede ser mayor que 10 --"<<endl;
        cin>>m;

        if(m<=10 && m>=1){
            for(int j=0;j<m;j++){
                for (int i=0;i<Jugadores.size();i++){
                    cout<<"-- Ingrese el tipo de puntuacion que realizo  "<<j1.nombre<<" de la ronda "<<i+1<<" --"<<endl;
                    o.pop();
                    cout<<"-- 1) Abierto --"<<endl;
                    cout<<"-- 2) Strike --"<<endl;
                    cout<<"-- 3) Semi-pleno --"<<endl;
                    cin>>op;
                    cout<<endl;

                    switch(op){
                        case 1:
                        cout<<"-- Ingrese el numero de bolos que logro derribar --"<<endl;
                        cout<<"-- No pueden ser mas de 10 --"<<endl;
                        cin>>a;
                        if(a>=1 && a<=10){
                            j1.puntuacion+=a;
                        }
                        break;

               
                        case 2:
                        j1.puntuacion+=s;
                        break;

                        case 3:
                        j1.puntuacion+=se;
                        break;
                    }

                    
                }
            }
        }

        else{
            cout<<"-- No se ha alcanzado el numero minimo de rondas para jugar --"<<endl;
        }

        if(!o.empty()){
            o1=o;
            while(!o1.empty()){
                j2=o1.front();
                cout<<"El nombre es: "<<j2.nombre<<endl;
                cout<<"La puntacion es:"<<j2.puntuacion<<endl;
                o1.pop();
                cout<<endl;
            }
        }

        for(int i=0;i<Jugadores.size();i++){
            if(j1.puntuacion>j1.puntuacion){
                cout<<"-- El ganador es: "<<j1.nombre<<" --"<<endl;
                break;
            }

            else if(j1.puntuacion<j1.puntuacion)
            {
                cout<<"-- El ganador es: "<<j1.nombre<<" --"<<endl;
                break;
            }

            else{
                cout<<"-- Han quedado empatados --"<<endl;
                break;
            }
            
        }

        while(!o.empty()){
            o.pop();
        }

        for(int i=0;i<Jugadores.size();i++){
            j1.puntuacion=0;
            o.push(j1);
        }

        cout<<"-- ¿Desea continuar jugandoo?, ingrese si o no --"<<endl;
        cin>>opcion;
        if(opcion=="si" || opcion== "Si"){
            return true;
        }

        else{
            cout<<"-- El juego ha finalizado --"<<endl;
        }
        break;

        case 4:
        continuar=false;
        break;
    }
    }while(continuar==true);

}


