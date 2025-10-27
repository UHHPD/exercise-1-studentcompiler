#include <iostream>
#include <fstream>


int main() {
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");

    int zahl1, zahl2, sum;

    while(fin >> zahl1 >> zahl2){
        sum = zahl1 + zahl2;
        fout << sum << std::endl;
    }
    fin.close();
    fout.close();
}