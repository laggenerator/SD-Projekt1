#include "generator.hh"
#include <random>

void generujDane(int* tablica, size_t rozmiar, int seed, int min, int max){
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> dist(min, max);

    for (size_t i = 0; i < rozmiar; ++i) {
        tablica[i] = dist(generator);
    }
}
