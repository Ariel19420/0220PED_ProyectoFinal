#include <stdio.h>
#include <queue>
#include<iostream>
#include<string>
using namespace std;

struct Bolas{
    string Color="";
    string talla="";
    };

typedef struct Bolas bolas;

void borrarcola(queue <bolas> &coladebolas);
bool MenuBolas(int b, queue <bolas> &coladebolas);
void pedirbolas(int a, queue <bolas> &coladebolas);
void vercola(queue <bolas> &coladebolas);


bool MenuBolas(int b, queue <bolas> &coladebolas){
    
    bool regresar=true;
    bool continuar=true;
    do{
    int opc=0 ;
    cout << "\n********** MENU **********" << endl;
    cout << "1. Pedir bolas(cantidad maxima por persona: 2)." << endl;
    cout << "2. Ver cola." << endl;
    cout << "3. Borrar cola." << endl;
    cout << "4. Procesar la cola." << endl;
    cout << ">";
    cin >> opc;cin.ignore();
    
    switch(opc){
    case 1: pedirbolas(b, coladebolas); break;
    case 2: vercola(coladebolas); break;
    case 3: borrarcola(coladebolas); break;
    case 4: if (!coladebolas.empty())
    {
        continuar = false;
        return true;
    }
    else
    {
        cout << "\nDebe llenar la cola para salir"<<endl;
    }
    
    default: cout << "\nIngrese una opcion valida..." << endl;
    
        
    }
    
    }while(continuar);
    
}

//Funciones

void pedirbolas(int a, queue <bolas> &coladebolas){
    bolas unabola;
    string talla;
    if (coladebolas.size()<a*2){
        for (int i=0; i<a; i++){
            cout << "\nJugador "<< i+1 << " escogera su par de bolas de boliche."<<endl;
            int condicion = 0;
            do{
                talla = "";
                cout << "\nIngrese la talla de la bola. " << endl; 
                cout << "(XS, S, M, L, XL)" ; cout << ">"; getline(cin,talla);
                if (talla == "XS" || talla == "S" || talla == "M" || talla == "L" || talla == "XL" ){ 
                unabola.talla=talla;
                int opc2=0;
                cout<<"\nIngrese el color de la bola. "<<endl;
                cout << "\n1.Verde\n2.Azul \n3.Naranja" << endl;
                cout << ">";
                cin>>opc2; cin.ignore();
    
                switch (opc2){
                    case 1: unabola.Color= "Verde";condicion++; break;
                    case 2: unabola.Color= "Azul";condicion++; break;
                    case 3: unabola.Color= "Naranja";condicion++; break;
                    default: cout<<"\nOpcion incorrecta... Ingrese la opcion de nuevo."<<endl;
                }
                }
                else{ cout<<"\nDato de talla incorrecto... Ingrese nuevamente."<<endl;
                }

                coladebolas.push(unabola);
            }while(condicion!=2);
            }
            }
        else{
        cout<<"Ha superado la cantidad maxima de bolas!"<<endl;
        }
    
    
}

void vercola(queue <bolas> &coladebolas){
    queue <bolas> copiaCola;
    bolas unabola;
    copiaCola = coladebolas;
    for (int i = 0; i < coladebolas.size(); i++)
    {   
        unabola = copiaCola.front();
        cout << "\n***** Bola " << i+1 <<"*****" << endl;
        cout << "Color: "<<" \tTalla:" << endl;
        cout << unabola.Color<< ".\t\t  " << unabola.talla << "." << endl;
        copiaCola.pop();
    }
}

void borrarcola(queue <bolas> &coladebolas){
    
    if (coladebolas.empty()){
        cout<<"No hay datos que borrar."<<endl;
    }else{
        cout<<"Borrando datos..."<<endl;
        while(!coladebolas.empty()){
        coladebolas.pop();
        }
    }
}

void bolasEnJuego (queue <bolas> &coladebolas){
    bool condicion = true;
    do{
    bolas unabola;
    bolas otrabola;
    char opcion;
    unabola = coladebolas.front();
    cout << "\nSe usara bola: " << unabola.Color << ". De talla: " << unabola.talla << endl;
    cout << "\nEsta seguro de usarla:\nSi: digite 'S'\nNo: digite 'N'"<<endl;
    cout << ">";
    cin >> opcion;
    if (opcion == 'S')
    {
        cout << "\n*BOLA LANZADA*"<<endl;
        otrabola = coladebolas.front();
        coladebolas.pop();
        coladebolas.push(otrabola);
        condicion = false;
    }
    else
    {
        cout << "\nPasando a siguiente bola en la cola..."<<endl;
        otrabola = coladebolas.front();
        coladebolas.pop();
        coladebolas.push(otrabola);
    }
    }while(condicion);

}
