#include <iostream>
#include <fstream>
using namespace std;

class Premiados{

    public:
        int ordem;
        bool ganhou;
 
        Premiados();
        void getvalue(int k);
};

Premiados::Premiados() // Construtor default
{
    ordem = 0;
    ganhou = false;
}

void Premiados:: getvalue(int k){
    this->ordem = k;
}

int main(){

    //abrir arquivo
    ifstream in("quermesse.in");

    // Abrir o arquivo de saída
    ofstream out("quermesse.out");

    int k, n = 1;
    int a, b;
    int aux = 0;
    int j;
    //while ler numero de partidas e n de partidas
    while (in >> k && k != 0) {
        Premiados lidos[k];
        aux = 0;
    //for numero de partidas, le os dados 
    out << "Teste "<< n << endl;

        for(int i = 0; i < k; i++){
            in >> j;
            lidos[i].getvalue(j);
    }
    
        for(int j = 0; j < k; j++){
            if(lidos[j].ordem == j+1){
                lidos[j].ganhou = true;
                out << lidos[j].ordem;
                aux++;
        }}
        if(aux == 0)
            out << "Nenhum";
       
        out << endl << endl;
        n++;
    }
    
    in.close();
    out.close();

    return 0;
}