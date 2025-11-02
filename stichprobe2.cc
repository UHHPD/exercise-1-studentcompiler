#include <iostream>
#include <cmath>
#include <fstream>
#include <string>


const int N = 234;
const int sample_size = 9;

double computeMean(const double data[], int start, int end) {
    double sum = 0;
    for (int i = start; i < end; ++i) {
        sum += data[i];
    }
    return sum / (end - start);
}

double computeVariance(const double data[], int start, int end, double mean, int corr) {
    double sumSq = 0;
    for (int i = start; i < end; ++i) {
        sumSq += std::pow(data[i] - mean, 2);
    }
    return sumSq / (end - start - corr);
}

int main() {

    std::ifstream fin("datensumme.txt");
    double data[N];
    int n = 0;
    double value;
    while (fin >> value && n < N) {
        data[n] = value;
        n++;
    }
    fin.close();

    int numSamples = n / sample_size;

    std::ofstream MWout("mittelwerte.txt");
    std::ofstream VARout("varianzen.txt");

    double means[numSamples];
    double variances[numSamples];
    double variances_corr[numSamples];

    // mean and variance for each sample
    for (int s = 0; s < numSamples; ++s) {
        int start = s * sample_size;
        int end = start + sample_size;

        double mean = computeMean(data, start, end);
        double var = computeVariance(data, start, end, mean, 0);
        double var_corr = computeVariance(data, start, end, mean, 1);

        means[s] = mean;                        // assign values of calculated mean to means[s] (sample1, sample2 etc.)
        variances[s] = var;
        variances_corr[s] = var_corr;

        MWout << mean << "\n";
        VARout << var << "\n";
    }

    // mean of means
    double meanOfMeans = 0;
    for (int i = 0; i < numSamples; ++i){
        meanOfMeans += means[i];
    }
    meanOfMeans /= numSamples;

    // mean of variances
    double meanOfVars = 0;
    for (int i = 0; i < numSamples; ++i){
        meanOfVars += variances[i];
    }
    meanOfVars /= numSamples;

    double meanOfVars_corr = 0;
    for (int i = 0; i < numSamples; ++i){
        meanOfVars_corr += variances_corr[i];
    }
    meanOfVars_corr /= numSamples;

    std::cout << "Mean of the means:     " << meanOfMeans << '\n';
    std::cout << "Mean of the variances: " << meanOfVars << '\n';
    std::cout << "Mean of the variances (corrected): " << meanOfVars_corr << '\n';

}
