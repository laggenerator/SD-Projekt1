#include "dynamic_array.hh"

// Nawet nie wiem co pisać kod się sam tłumaczy w tej pięknej polszczyźnie

DynamicArray::DynamicArray() : dane(nullptr), rozmiar(0), pojemnosc(0) {}

DynamicArray::~DynamicArray() {
    if(dane){
        free(dane);
    }
}

// void DynamicArray::resize(std::size_t nowa_pojemnosc){
//     int *nowe_dane = new int[nowa_pojemnosc];
//     for(std::size_t i=0;i<rozmiar;i++){
//         nowe_dane[i] = dane[i];
//     }
//     delete[] dane;
//     dane = nowe_dane;
//     pojemnosc = nowa_pojemnosc;
// }

void DynamicArray::shrink(){
    if(rozmiar < pojemnosc / 2 && pojemnosc > 0){
        int *nowe_dane = static_cast<int*>(realloc(dane, pojemnosc / 2 * sizeof(int)));
        if(!nowe_dane){
            throw std::bad_alloc();
        }

        dane = nowe_dane;
        pojemnosc = pojemnosc / 2;
    }
}

void DynamicArray::resize(std::size_t nowa_pojemnosc){
    if(nowa_pojemnosc == 0){
        free(dane);
        dane = nullptr;
        rozmiar = 0;
        pojemnosc = 0;
        return;
    }
    
    int *nowe_dane = static_cast<int*>(realloc(dane, nowa_pojemnosc * sizeof(int)));
    if(!nowe_dane){
        throw std::bad_alloc();
    }

    dane = nowe_dane;
    pojemnosc = nowa_pojemnosc;
    // if(nowa_pojemnosc > rozmiar){ // Ustawia nowe miejsca na 0, zamiast farmazonów
    //     std::memset(dane + rozmiar, 0, (nowa_pojemnosc - rozmiar) * sizeof(int));
    // }
}

void DynamicArray::push_back(int wartosc){
    if(rozmiar == pojemnosc){
        resize(pojemnosc == 0 ? 1 : pojemnosc * 2);
    }
    dane[rozmiar++] = wartosc;
}

void DynamicArray::push_front(int wartosc){
    if(rozmiar == pojemnosc){
        resize(pojemnosc == 0 ? 1 : pojemnosc * 2);
    }
    for(std::size_t i=rozmiar;i>0;i--){
        dane[i] = dane[i-1];
    }
    dane[0]=wartosc;
    rozmiar++;
}
void DynamicArray::push_at(unsigned int n, int wartosc){
    if(n > rozmiar) throw std::out_of_range("n jest poza zakresem tablicy");
    if(rozmiar == pojemnosc){
        resize(pojemnosc == 0 ? 1 : pojemnosc * 2);
    }
    for(std::size_t i=rozmiar;i>n;i--){
        dane[i] = dane[i-1];
    }
    dane[n] = wartosc;
    rozmiar++;
}

int DynamicArray::remove_back(){
    if(rozmiar == 0) throw std::out_of_range("Tablica jest pusta");
    int wartosc = dane[rozmiar--];
    shrink();
    return wartosc;
}

int DynamicArray::remove_front(){
    if(rozmiar == 0) throw std::out_of_range("Tablica jest pusta");
    int wartosc = dane[0];
    for(std::size_t i=0;i<rozmiar - 1;i++){
        dane[i] = dane[i+1];
    }
    rozmiar--;
    shrink();
    return wartosc;
}

int DynamicArray::remove_at(unsigned int n){
    if(n >= rozmiar) throw std::out_of_range("n jest poza zakresem tablicy");
    int wartosc = dane[n];
    for(std::size_t i=n;i<rozmiar - 1;i++){
        dane[i] = dane[i+1];
    }
    rozmiar--;
    shrink();
    return wartosc;
}

int DynamicArray::find(int wartosc){
    for(std::size_t i=0;i<rozmiar;i++){
        if(dane[i] == wartosc) return i;
    }
    return -1;
}
int DynamicArray::at_position(unsigned int n){
    if(n >= rozmiar) throw std::out_of_range("n jest poza zakresem tablicy");
    return dane[n];
}

void DynamicArray::_show(){
    std::cout << "[";
    for(std::size_t i=0;i<rozmiar;i++){
        std::cout << dane[i];
        if(i != rozmiar - 1) std::cout << "; ";
    }
    std::cout << "]\n";
}