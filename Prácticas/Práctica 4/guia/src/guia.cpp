/**
 * @author Mario García Márquez
 * @file guia.cpp
 * @brief implementacion de guia.h
 */

#include "../include/guia.h"

#include <iostream>

Guia_Tlf::iterator Guia_Tlf::begin() {
    return Guia_Tlf::iterator(datos.begin());
}

Guia_Tlf::iterator Guia_Tlf::end() { return Guia_Tlf::iterator(datos.end()); }

Guia_Tlf::const_iterator Guia_Tlf::cbegin() const {
    return Guia_Tlf::const_iterator(datos.cbegin());
}

Guia_Tlf::const_iterator Guia_Tlf::cend() const {
    return Guia_Tlf::const_iterator(datos.cend());
}

Guia_Tlf::Guia_Tlf(const Guia_Tlf &gt) { *this = gt; }

std::string &Guia_Tlf::operator[](const std::string &nombre) {
    return this->datos[nombre];
}

void Guia_Tlf::borrar(const std::string &nombre) { this->datos.erase(nombre); }

std::pair<std::map<std::string, std::string>::iterator, bool> Guia_Tlf::insert(
    std::string nombre, std::string tlf) {
    // Comprobamos si existe
    auto it = this->datos.find(nombre);
    bool insertado = false;

    if (it == this->datos.end()) {
        this->datos[nombre] = tlf;
        it = this->datos.find(nombre);
        insertado = true;
    }

    // Return
    return {it, insertado};
}

std::pair<std::map<std::string, std::string>::iterator, bool> Guia_Tlf::insert(
    std::pair<std::string, std::string> p) {
    return insert(p.first, p.second);
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf &g) {
    Guia_Tlf rv(*this);
    for (auto it = g.cbegin(); it != g.cend(); ++it) {
        rv.insert(*it);
    }

    return rv;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf &g) {
    Guia_Tlf rv(*this);
    for (auto it = g.cbegin(); it != g.cend(); ++it) {
        rv.borrar((*it).first);
    }

    return rv;
}

std::ostream &operator<<(std::ostream &os, Guia_Tlf &g) {
    for (auto it = g.cbegin(); it != g.cend(); ++it) {
        os << (*it).first << '\t' << (*it).second << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Guia_Tlf &g) {
    g.datos.clear();
    std::pair<std::string, std::string> aInsertar;
    while (is) {
        is >> aInsertar;
        if (is) g.insert(aInsertar);
    }

    return is;
}

void Guia_Tlf::Merge(const Guia_Tlf &g, const Guia_Tlf &h) {
    *this = *this + g;
    *this = *this + h;
}

bool Guia_Tlf::Modificar(std::string nombre, std::string nuevoNumero) {
    if (datos.find(nombre) != datos.end()) {
        datos[nombre] = nuevoNumero;
        return true;
    }
    return false;
}

std::vector<std::pair<const std::string, std::string>> Guia_Tlf::Indice(
    const char letra) const {
    std::vector<std::pair<const std::string, std::string>> rv;
    bool EnRango;
    for (auto it : datos) {
        if (!it.first.empty()) {
            if (it.first[0] == letra)
                EnRango = true;
            else
                EnRango = false;
        } else {
            EnRango = false;
        }

        if (EnRango) rv.push_back(it);
    }

    return rv;
}

std::vector<std::pair<const std::string, std::string>> Guia_Tlf::Rango(
    Guia_Tlf::const_iterator principio, Guia_Tlf::const_iterator end) const {
    std::vector<std::pair<const std::string, std::string>> rv;
    for (auto it = principio; it != this->cend() && it != end; ++it) {
        rv.push_back(*it);
    }

    return rv;
}

Guia_Tlf &Guia_Tlf::operator=(const Guia_Tlf &gt) = default;

Guia_Tlf::iterator::iterator(std::map<std::string, std::string>::iterator it) {
    this->it = it;
}

Guia_Tlf::iterator::iterator() {}

Guia_Tlf::iterator::iterator(const Guia_Tlf::iterator &it) { this->it = it.it; }

Guia_Tlf::iterator &Guia_Tlf::iterator::operator=(
    const Guia_Tlf::iterator &it) {
    this->it = it.it;
    return *this;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator++() {
    ++(this->it);
    return *this;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator--() {
    --this->it;
    return *this;
}

std::pair<const std::string, std::string> &Guia_Tlf::iterator::operator*() {
    return *it;
}

bool Guia_Tlf::iterator::operator!=(const Guia_Tlf::iterator &it) const {
    return this->it != it.it;
}

bool Guia_Tlf::iterator::operator==(const Guia_Tlf::iterator &it) const {
    return this->it == it.it;
}

Guia_Tlf::const_iterator::const_iterator(
    std::map<std::string, std::string>::const_iterator it) {
    this->it = it;
}

Guia_Tlf::const_iterator::const_iterator() {}

Guia_Tlf::const_iterator::const_iterator(const Guia_Tlf::const_iterator &it) {
    this->it = it.it;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator=(
    const Guia_Tlf::const_iterator &it) {
    this->it = it.it;
    return *this;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator++() {
    ++(this->it);
    return *this;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator--() {
    --this->it;
    return *this;
}

std::pair<const std::string, std::string> Guia_Tlf::const_iterator::operator*()
    const {
    return *it;
}

bool Guia_Tlf::const_iterator::operator!=(
    const Guia_Tlf::const_iterator &it) const {
    return this->it != it.it;
}

bool Guia_Tlf::const_iterator::operator==(
    const Guia_Tlf::const_iterator &it) const {
    return this->it == it.it;
}

std::istream &operator>>(std::istream &is,
                         std::pair<std::string, std::string> &d) {
    getline(is, d.first, '\t');
    getline(is, d.second);
    return is;
}

