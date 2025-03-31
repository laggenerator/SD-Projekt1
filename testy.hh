#ifndef TESTY_H
#define TESTY_H

#include "generator.hh"
#include "list.hh"
#include "dynamic_array.hh"
#include <fstream>
#include <iostream>
#include <chrono>

int push_front();
int push_back();
int push_at();

int remove_front();
int remove_back();
int remove_at();

int find();
int at_position();

#endif