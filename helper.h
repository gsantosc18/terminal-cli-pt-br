#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getAllTyped(string command);

void removePositionVect(vector<string> *vect, int pos);

bool contemValor(vector<string> lista, string value);

#endif // HELPER_H_INCLUDED
