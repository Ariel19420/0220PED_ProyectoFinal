#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct per{
    string nombre;
    int edad;
    float talla;
    string apodo;
    int puntuacion;
};

typedef struct per p;

bool orden(int jugadores,struct per p1[],p p2);

queue <p> o,o1;
p p1,p2;


bool orden(int jugadores, p p1[], p p2){
    bool continuar=true;
    p p3;
    string opcion;
    int n=0,m=0,op=0,pun=0,a=0,s=15,se=12 ;

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

        for(int i=0;i<jugadores;i++){
            for(int j=i+1;j<jugadores;j++){
                p3=p1[i];
                p1[i]=p1[j];
                p1[j]=p3;
            }
        }
        cout<<"-- Se ha ordenado la cola de mayor edad a menor edad --"<<endl<<endl;;
        break;

        case 2:
        for(int i=0;i<jugadores;i++){
            cout<<"-- Ingrese la opcion que desee para ingresar a los jugadores --"<<endl;
            cout<<p1[i].nombre;

        }
        break;

        case 3:
        cout<<"-- Ingrese el numero de rondas que desea jugar --"<<endl;
        cout<<"-- El numero de rondas no puede ser mayor que 10 --"<<endl;
        cin>>m;

        if(m<=10 && m>=1){
            for(int j=0;j<m;j++){
                for (int i=0;i<jugadores;i++){
                    cout<<"-- Ingrese el tipo de puntuacion que realizo  "<<p1[i].apodo<<" de la ronda "<<i+1<<" --"<<endl;
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
                            p1[i].puntuacion+=a;
                        }
                        break;

                        case 2:
                        p1[i].puntuacion+=s;
                        break;

                        case 3:
                        p1[i].puntuacion+=se;
                        break;
                    }

                }
            }
        }

        else{
            cout<<"-- No se ha alcanzado el numero minimo de rondas para jugar --"<<endl;
        }

        for(int i=0;i<jugadores;i++){
            o.push(p1[i]);
        }

        if(!o.empty()){
            o1=o;
            while(!o1.empty()){
                p2=o1.front();
                cout<<"El nombre es: "<<p2.nombre<<endl;
                cout<<"La puntacion es:"<<p2.puntuacion<<endl;
                o1.pop();
                cout<<endl;
            }
        }

        for(int i=0;i<jugadores;i++){
            if(p1[i].puntuacion>p1[i+1].puntuacion){
                cout<<"-- El ganador es: "<<p1[i].nombre<<" --"<<endl;
                break;
            }

            else if(p1[i].puntuacion<p1[i+1].puntuacion)
            {
                cout<<"-- El ganador es: "<<p1[i+1].nombre<<" --"<<endl;
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

        for(int i=0;i<jugadores;i++){
            p1[i].puntuacion=0;
            o.push(p1[i]);
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