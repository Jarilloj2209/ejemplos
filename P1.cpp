#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>
//#include <arduino.h>
using namespace std;
/*int dato(){
    int A0;
    int ai = analogRead(A0);
    return ai;
}*/



std::basic_string<char> fecha(){
    auto t =std::time(nullptr);
    auto tm= *std::localtime(&t);
    std::ostringstream oss;
    oss<<std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto fch = oss.str();
    std::cout<<fch<<std::endl;
    return fch;
    }



int var;
int main() {
    std::cout << "Si es la primera vez que se utiliza el programa, configurar el máximo permitido, de lo contrario, todos los datos positivos seran considerados anomalos" << std::endl;
    fstream lec;
    lec.open("lecuras anomalas.txt", ios::out|ios::in);
    //dato();
    int dato=15;
    int q;
    cout<<"Desea reestablecer el parametro máximo para los datos?(si=1,no=2)"<<endl;
    cin>>q;
    if (q==1){
        cout<<"Limite máximo permitido para los datos"<<endl;
        cin>>var;
    }else{
        cout<<"error al seleccionar máximo permitido"<<endl;
    }

    if (dato>var){
        if (lec.is_open()){
            cout<<"El fichero esta abierto"<<endl;
            lec<<&fecha<<":::::"<<dato<<endl;
        }
        else {
            cout << "Error al abrir fichero" << endl;
            exit(1);
        }
    }






    return 0;
}
