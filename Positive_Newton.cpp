#include "GFunction.h"

#define EPS 1e-5
#define sqr(x) (x)*(x)
using namespace std;


int main(){
    /// f(x) = a[0] + a[1]*x + a[2]*x^2 + .. + a[n-1]*x^(n-1) + a[n]*x^n
    GFunction f = {1, 2, 3};
    int n = 6;
    double a = 0, b = 1;
    double h = (b - a)/n;
    vector<double> y;

    for (int i = 0; i <= n; ++i) y.push_back(fValueAt(f, a + i*h));
    double I = y[0] + y[n];
    for (int i = 1; i < n; ++i){
        I += y[i]*(i%3 == 0 ? 2.0 : 3.0);
    }
    I *= 3.0*h/8;
    cout << I << endl;
    double M = max(abs(fDerivationAt(f, 4, a)), abs(fDerivationAt(f, 4, b)));
    double e = M*(b-a)*sqr(sqr(h))/80.0;
    cout << e << endl;
}
