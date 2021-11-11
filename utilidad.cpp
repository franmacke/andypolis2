#include "utilidad.h"

string Utilidad::minuscula(string palabra) {
    for (unsigned int i = 0; i < palabra.length(); i++) {
        palabra[i] = (char) tolower(palabra[i]);
    }

    return palabra;
}

string Utilidad::capitalizar(string palabra) {
    palabra[0] = (char) toupper(palabra[0]);

    for (unsigned int i = 1; i < palabra.length(); i++) {
        palabra[i] = (char) tolower(palabra[i]);
    }

    return palabra;
}

string Utilidad::mayuscula(string palabra) {
    for (unsigned int i = 0; i < palabra.length(); i++) {
        palabra[i] = (char) toupper(palabra[i]);
    }
    return palabra;
}

bool Utilidad::es_numero(string numero) {
    bool validacion = true;
    int contador = 0;
    while (validacion && contador < (int) numero.length()) {
        validacion = isdigit(numero[contador]);
        contador++;
    }

    return validacion;
}