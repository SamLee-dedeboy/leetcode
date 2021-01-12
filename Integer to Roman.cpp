#include <iostream>
using namespace std;
string intToRoman(int num) {
    string res;
    int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;
    //M
    int dM = num/M;
    num -= dM*M;
    for(int i = 0; i < dM; i++) {
        res += "M";
    }
    //D
    int dD = num/D;
    num -= dD*D;
    //C
    int dC = num/C;
    num -= dC*C;
    if(dD == 1 && dC == 4) {
        res += "CM";
    } else {
        for(int i = 0; i < dD; i++) {
            res += "D";
        }
        if(dC == 4) {
            res += "CD";
        } else {
            for(int i = 0; i < dC; i++) {
                res += "C";
            }
        }
    }
    
    //L
    int dL = num/L;
    num -= dL*L;
    //X
    int dX = num/X;
    num -= dX*X;
    if(dL == 1 && dX == 4) {
        res += "XC";
    } else {
        for(int i = 0; i < dL; i++) {
            res += "L";
        }
        if(dX == 4) {
            res += "XL";
        } else {
            for(int i = 0; i < dX; i++) {
                res += "X";
            }
        }
    }
    //V
    int dV = num/V;
    num -= dV*V;
    //I
    int dI = num/I;
    num -= dI*I;
    if(dV == 1 && dI == 4) {
        res += "IX";
    } else {
        for(int i = 0; i < dV; i++) {
            res += "V";
        }
        if(dI == 4) {
            res += "IV";
        } else {
            for(int i = 0; i < dI; i++) {
                res += "I";
            }
        }
    }
    //printf("%d %d %d %d %d %d %d\n",dM,dD,dC,dL,dX,dV,dI);
    return res;
}
int main() {
    cout << intToRoman(3);
}