#include "GFunction.h"

#define EPS 1e-5
#define sqr(x) (x)*(x)
using namespace std;


int main(){
    /// f(x) = a[0] + a[1]*x + a[2]*x^2 + .. + a[n-1]*x^(n-1) + a[n]*x^n
    GFunction f = {-10000, 75, -3, 0, 1};
    int A = -11, B = -10;
    int M1 =  max(abs(fDerivationAt(f, 2, A)), abs(fDerivationAt(f, 2, B)));
    int M2 =  min(abs(fDerivationAt(f, 1, A)), abs(fDerivationAt(f, 1, B)));
    double x0 = 0.0, x = 0.0;
    cout << M1 << " " << M2 << endl;
         if (fDerivationAt(f, 0, A) < 0 && fDerivationAt(f, 1, A) > 0 && fDerivationAt(f, 2, A) < 0) x0 = A;
    else if (fDerivationAt(f, 0, A) > 0 && fDerivationAt(f, 1, A) < 0 && fDerivationAt(f, 2, A) > 0) x0 = A;
    else if (fDerivationAt(f, 0, B) > 0 && fDerivationAt(f, 1, B) > 0 && fDerivationAt(f, 2, B) < 0) x0 = B;
    else x0 = B;
    while (1){
        x = x0 - fDerivationAt(f, 0, x0)*1.0/fDerivationAt(f, 1, x0);
        if ((double)sqr(x-x0)*M1*1.0/(2.0*M2) < EPS) break;
        x0 = x;
    }
    cout << x;
}
