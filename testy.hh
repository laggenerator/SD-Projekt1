#ifndef TESTY_H
#define TESTY_H

#include "generator.hh"
#include "list.hh"
#include "dynamic_array.hh"
#include <fstream>
#include <iostream>
#include <chrono>

int push_front(uint16_t seed, uint8_t proba);
int push_back(uint16_t seed, uint8_t proba);
int push_at(uint16_t seed, uint8_t proba);

int remove_front(uint16_t seed, uint8_t proba);
int remove_back(uint16_t seed, uint8_t proba);
int remove_at(uint16_t seed, uint8_t proba);

int find(uint16_t seed, uint8_t proba);
int at_position(uint16_t seed, uint8_t proba);

#endif