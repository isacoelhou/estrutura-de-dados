#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Abrir o arquivo de entrada
    ifstream in("cola.in");

    // Abrir o arquivo de saída
    ofstream out("cola.out");

    // Ler os dados de entrada e escrever os resultados na saída
    int k, n = 1;
    double a_trem, b_trem, a_caminhao, b_caminhao;
    while (in >> k && k != 0) {
        in >> a_trem >> b_trem >> a_caminhao >> b_caminhao;
        double custo_trem = a_trem + b_trem * k;
        double custo_caminhao = a_caminhao + b_caminhao * k;
        out << "Teste " << n++ << endl;
        if (custo_trem < custo_caminhao || (custo_trem - custo_caminhao) < 1.00) {
            out << "envie por trem" << endl;
        } else {
            out << "envie por caminhao" << endl;
        }
        out << endl;
    }

    // Fechar os arquivos
    in.close();
    out.close();

    return 0;
}
