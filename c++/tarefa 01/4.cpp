#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class fazenda {
public:
    int x1, y1, x2, y2;

    void givevaluex1(int x) {
        this->x1 = x;
    }
    void givevaluey1(int x) {
        this->y1 = x;
    }
    void givevaluex2(int x) {
        this->x2 = x;
    }
    void givevaluey2(int x) {
        this->y2 = x;
    }

};

class meteoro {
public:
    int c1, c2;
};

int main() {
    int n, teste = 1;

    ifstream in("meteoros.in");
    ofstream out("meteoro.out");

    while (true) {
        int a,b,c,d;
        in >> a >> b >> c >> d;
        if (!(a && b  && c  && d)) {
            break;
        }

        fazenda atual;
        atual.givevaluex1(a);
        atual.givevaluey1(b);
        atual.givevaluex2(c);
        atual.givevaluey2(d);

        in >> n;
        meteoro now[n];
        int count = 0;
        
        for (int w = 0; w < n; w ++) {
            in >> now[w].c1 >> now[w].c2;
            if (((now[w].c1 >= atual.x1) && ( now[w].c1 <= atual.x2) && (now[w].c2 <= atual.y1) && (now[w].c2 >= atual.y2))){
                count++;
            }
                
        }

        out << "Teste " << teste++ << endl << count << endl << endl;
    }

    in.close();
    out.close();

    return 0;
}
