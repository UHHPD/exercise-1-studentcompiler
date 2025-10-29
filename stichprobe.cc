#include <iostream>
#include <cmath>
#include <fstream>


int main(){

    std::ifstream fin("datensumme.txt");

    const int N = 234;
    double a[N];
    double a_i;
    int i = 0;
    double sum = 0;

    while (fin >> a_i && i < N){
        a[i] = a_i;
        sum += a_i;
        i++;
    }

    double mean = sum / N;

    double var = 0;

    for (int i = 0; i < N; i++){
        var += pow(a[i] - mean ,2);
    }

    var /= N;

    double sd = sqrt(var);

    std::cout << sum << std::endl;
    std::cout << mean << std::endl;
    std::cout << var << std::endl;
    std::cout << sd << std::endl;
}