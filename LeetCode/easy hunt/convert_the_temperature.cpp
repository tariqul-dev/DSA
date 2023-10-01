#include <bits/stdc++.h>

using namespace std;

/*
Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00

*/

vector<double> convertTemperature(double celsius)
{
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;
    vector<double> result;
    result.push_back(kelvin);
    result.push_back(fahrenheit);

    return result;
}

int main()
{
    double celsius = 36.50;

    for (auto t : convertTemperature(celsius))
        cout << t << " ";
    cout << endl;

    return 0;
}