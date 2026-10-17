#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double g(const double x);

int main()
{
    double zp, zk, z, dz;
    int n;

    cout << "zp = "; cin >> zp;
    cout << "zk = "; cin >> zk;
    cout << "n = "; cin >> n;

    dz = (zk - zp) / n;

    cout << fixed;
    cout << "---------------------------------" << endl;
    cout << "|" << setw(10) << "z" << " |"
        << setw(18) << "Result" << " |" << endl;
    cout << "---------------------------------" << endl;

    z = zp;
    while (z <= zk + dz / 2.0)
    {
        double res = g(2 * z) + pow(g(2 * z + z * z), 2) + g(1.5);

        cout << "|" << setw(10) << setprecision(2) << z << " |"
            << setw(18) << setprecision(5) << res << " |" << endl;

        z += dz;
    }
    cout << "---------------------------------" << endl;

    return 0;
}

double g(const double x)
{
    if (abs(x) >= 1)
    {
        return sin(x) / (cos(x) + 2);
    }
    else
    {
        double S = 0;
        double a = 1;
        S = a;

        for (int n = 1; n <= 6; n++)
        {
            double R = (x * x) / n;
            a *= R;
            S += a;
        }
        return S;
    }
}