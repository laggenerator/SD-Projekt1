#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

class DynamicArray {
    private:
        int *dane;
        std::size_t rozmiar;
        std::size_t pojemnosc;
    
        void resize(std::size_t nowa_pojemnosc);
    
    public:
        DynamicArray();
        ~DynamicArray();
    
        void push_back(int wartosc);
        void push_front(int wartosc);
        void push_at(unsigned int n, int wartosc);
      
        int remove_back();
        int remove_front();
        int remove_at(unsigned int n);
      
        int find(int wartosc);
        int at_position(unsigned int n);
      
        void _show();
    };
    

#endif