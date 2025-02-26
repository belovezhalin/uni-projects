#include <cstdio>
#include "Przedmiot.h"

#include <iostream>
#include <string>
using namespace std;

Przedmiot::Przedmiot() {}

Przedmiot::Przedmiot(string nazwa, double objetosc, double waga) :nazwa(nazwa), objetosc(objetosc), waga(waga) {
    cout << "Konstruktor Przedmiot" << endl;}

Przedmiot::~Przedmiot() {
    cout << "Destruktor Przedmiot" << endl;}

void Przedmiot::wyswietl() const {
    cout << "Nazwa: " << nazwa << endl;
    cout << "Objetosc: " << objetosc << endl;
    cout << "Waga: " << waga << endl;}

string Przedmiot::getNazwa() const {
    return nazwa;}

void Przedmiot::setNazwa(string nazwa) {
    this->nazwa = nazwa;}

double Przedmiot::getObjetosc() const{
    return objetosc;}

void Przedmiot::setObjetosc(double objetosc) {
    if (objetosc < 0) cout << "Niepoprawna wartosc objetosci" << endl;
    this->objetosc = objetosc;}

double Przedmiot::getWaga() const {
    return waga;}

void Przedmiot::setWaga(double waga) {
    if (waga < 0) cout << "Niepoprawna wartosc wagi" << endl;
    this->waga = waga;}