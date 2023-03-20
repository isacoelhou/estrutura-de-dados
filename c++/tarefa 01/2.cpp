#include <iostream>
#include <fstream>
using namespace std;

class Cedulas{

    public:
        int valor;
        int cinquenta;
        int dez;
        int cinco;
        int um;
        
        Cedulas();
        void Ced1();
        void getvalue(int k);
        void outs();
};

Cedulas::Cedulas(){
    valor = 0;
    cinquenta = 0;
    dez = 0;
    cinco = 0;
    um = 0;
}

void Cedulas::getvalue(int k){
    this->valor = k;
}



void Cedulas:: Ced1(){

    while(this->valor >= 50){
            this->cinquenta++;
            this->valor -= 50;
        }
        while(this->valor >= 10){
            this->dez++;
            this->valor -= 10;
        }
        while(this->valor >= 5){
            this->cinco++;
            this->valor -= 5;
            }
        while(this->valor >= 1){
            this->um++;
            this->valor -= 1;}
    return;
}


int main(){

    ifstream in("bit.in");
    ofstream out("bit.sol");

    int k, n = 1;
    int aux = 0;

    while (in >> k && k != 0) {
        Cedulas lidos;
        aux = 0;
   
        lidos.getvalue(k);
        lidos.Ced1();
    
        out << "Teste "<< n << endl;
        out << lidos.cinquenta<< " ";
        out << lidos.dez << " ";
        out << lidos.cinco << " ";
        out << lidos.um << " ";

            
        out << endl << endl;
        n++;
    }
    
    in.close();
    out.close();

    return 0;
}

