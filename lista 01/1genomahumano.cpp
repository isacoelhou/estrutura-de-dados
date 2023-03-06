#include <iostream>
#include <string>
#include <algorithm>

std::string converte(std::string trocar){

    for(int i = 0; i < trocar.size(); i++){
        if (trocar[i] == 'A') trocar[i] = 'T';
        else if (trocar[i] == 'T') trocar[i] = 'A';
        else if (trocar[i] == 'G') trocar[i] = 'C';
        else if (trocar[i] == 'C') trocar[i] = 'G';
    }
    return trocar;
}

std::vector<int> achasub(std::string cheia, std::string sub){
    std::vector<int> ocorrencias;
    size_t pos = 0;

    while ((pos = cheia.find(sub, pos)) != std::string::npos) {
        ocorrencias.push_back(pos);
        pos += sub.size();
    }

    return ocorrencias;
}

int main(){

    std::string string;
    std::string sub;
    std::string invertida;

    string = "TCATATGCAAATAGCTGCATACCGA";
    sub = "CATA";
    invertida = sub;
    std::reverse(invertida.begin(), invertida.end());
    invertida = converte(invertida);

    int tamanho = string.size();
    std::vector<int> ninv, nsub;

    ninv = achasub(string, invertida);
    nsub = achasub(string, sub);

    FILE *pont_arq;
            pont_arq = fopen("genoma.out", "a+"); 
        if(pont_arq == NULL)
        {
            printf("Erro na abertura do arquivo!");
            return 1;
        }
        fseek(pont_arq, 0, SEEK_END);
        int i=1;
        fprintf(pont_arq, "\nTeste %d:\nOcorrencia direta: %d\nOcorrencia complementar invertida: %d\n", i, nsub[i]+1);

}  
