#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Sorvete{
    private:
        int x, y;
    public:
        Sorvete();
        void givevaluex(int x);
        void givevaluey(int y);
        int getvaluex();
        int getvaluey();
        
};

Sorvete::Sorvete (){
    this->x = 0;
    this->y = 0;
}

void Sorvete::givevaluex(int x){
    this->x = x;
}

void Sorvete::givevaluey(int y){
    this->y = y;
}

int Sorvete:: getvaluex(){
    return (this->x);
}

int Sorvete:: getvaluey(){
    return (this->y);
}



int main(){

    ifstream in("sorvete.in");
    ofstream out("sorvete.sol");

    int k, sorveteiros , metros, n = 1;
    int x, y;
    int start, end;
    

    while (true) {
        in >> metros;
        in >> sorveteiros;
        Sorvete praia[sorveteiros];
    if (!(metros && sorveteiros))
        break;

    vector<int> vetx;
    vector<int> vety;
    out << "Teste " << n << endl;

    for(int i = 0; i < sorveteiros; i++){
        in >> x;
        in >> y;
        praia[i].givevaluex(x);
        praia[i].givevaluey(y);
        vetx.push_back(praia[i].getvaluex());
        vety.push_back(praia[i].getvaluey());
    }

    
    sort(vetx.begin(), vetx.end());
    sort(vety.begin(), vety.end());
    
    start = vetx[0];
    end = vety[0];

    for(int i = 1; i < sorveteiros; i ++){
        if(end >= vetx[i]){
            end = vety[i];
        }
        else{
            
            out << start << " " << end << endl;
            start = vetx[i];
            end = vety[i];
        }
    }
    out << start << " " << end << endl << endl ;
            
    n++;
    }
    
    in.close();
    out.close();

    return 0;
}

