#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class macaco{
    private:
        int x1, y1, x2, y2;

    public:
        macaco();
        void givevaluex1(int x);
        void givevaluey1(int y);
        int getvaluex1();
        int getvaluey1();
        void givevaluex2(int x);
        void givevaluey2(int y);
        int getvaluex2();
        int getvaluey2();
        
};

macaco::macaco (){
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 0;
    this->y2 = 0;
}

void macaco::givevaluex1(int x){
    this->x1 = x;
}

void macaco::givevaluey1(int y){
    this->y1 = y;
}

void macaco::givevaluex2(int x){
    this->x2 = x;
}

void macaco::givevaluey2(int y){
    this->y2 = y;
}

int macaco:: getvaluex1(){
    return (this->x1);
}

int macaco:: getvaluey1(){
    return (this->y1);
}

int macaco:: getvaluex2(){
    return (this->x2);
}

int macaco:: getvaluey2(){
    return (this->y2);
}

int get_min(vector<int> args) {
    int min;
            min = args[0];
            for (int arg : args) {
                if (arg < min) min = arg;
            }
            return min;
        }


int main(){

    ifstream in("macaco.in");
    ofstream out("macaco.out");

    int k, j, m, p, o;
    int n = 1;
    int intx1, inty1, intx2, inty2;
    
    while(true){
        in >> k;
        
        if (k==0) break;
        
        macaco lidos[k];
        
        for(int i = 0; i < k; i++){
            for(int l = 0; l < 4; l++){
                in >> j;
                in >> m;
                in >> p;
                in >> o;
                lidos[i].givevaluex1(j);
                lidos[i].givevaluey1(m);
                lidos[i].givevaluex2(p);
                lidos[i].givevaluey2(o);
        }
    }

        intx1 = lidos[0].getvaluex1();
        inty1 = lidos[0].getvaluey1();
        intx2 = lidos[0].getvaluex2();
        inty2 = lidos[0].getvaluey2();
        
    
        for(int i = 1; i < k; i++){
            int a1 = lidos[i].getvaluex1();
            int a2 = lidos[i].getvaluey1();
            int b1 = lidos[i].getvaluex2();
            int b2 = lidos[i].getvaluey2();

            if(((intx1 > a1) && (intx1 < a2 ))|| ((a1 > intx1 && a1 < intx2))){
                if(((inty1 > b2) && (inty1 > b1)) || ((b1 > inty2) && (b1 < inty1))){
                    intx1 = get_min(vector<int>{intx1, a1});
                    intx2 = get_min(vector<int>{intx2, a2});
                    inty1 = get_min(vector<int>{inty1, b1});
                    inty2 = get_min(vector<int>{inty2, b2});
                    out << intx1 << " " << intx2 << " " << inty1 << " " << inty2 << endl << endl;
                    }
            } 

            
        }


}
    in.close();
    out.close();

    return 0;
}
