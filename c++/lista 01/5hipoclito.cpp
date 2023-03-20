#include <iostream>
#include <fstream>
using namespace std;

int main(){

    int saldo[1000];
    //abrir arquivo
    ifstream in("saldo.in");

    // Abrir o arquivo de saída
    ofstream out("saldo.out");

    int k, n = 1;
    int a, b;
    int aux1 = 0, aux2 = 0;
    int pos1, pos2;
    //while ler numero de partidas e n de partidas
    while (in >> k && k != 0) {
        aux1 = 0;
        aux2 = 0;
        pos1 = 0;
        pos2 = 0;
    //for numero de partidas, le os dados 
        for(int i = 0; i < k; i++){
            in >> a >> b;
        // calcula saldo de todas e armazena num vetor
            saldo[i] = a - b;
    }
        for(int j = 0; j < k; j++){
            if(saldo[j] > aux1){
                aux1 = saldo[j];
                pos1 = j+1;}
            else if (saldo[j] == aux1)
                pos2 = j+1;
        }

        out << "teste "<< n << ":"<< endl;

        if(aux1 <= 0){
             out << "nenhum" << endl;
        }
        else if (pos1 == pos2){
            out << pos1 << endl;
            }
        else{
            out << pos1 << " " << pos2 << endl;
            }
        n++;
        out << "\n";
        }
    
    in.close();
    out.close();

    return 0;
}