/* 
 * File:   Fotorezystor.h
 * Author: Adamec_Z
 * mail: adamec(a)gmx.net
 * Created on 24.12.2016
 */

#ifndef FOTOREZYSTOR_H
#define FOTOREZYSTOR_H

#include <Arduino.h>

class Fotorezystor{
  protected:
    byte lightPin;  //define a pin for Photo resistor
    uint8_t ciemnosc;
    boolean StanCiemnosci;
    boolean StanPIR; // Jeśli PIR wykrył ruch jest true jeżeli zakończył wykrywanie ruchu jest w FALSE;
  public:
    void Begin( byte pin);
    
    boolean SprawdzajStanPIR();
    boolean UstawStanPIR(boolean stan);
    float Odczyt();
    boolean SprawdzajCiemnosc( uint8_t poziomCiemnosci);
    
    float PrzeliczNaVolt();
    uint8_t PoziomCiemnosciGraf();
    uint8_t PoziomCiemnosciGraf(byte poziom);
    
};

#endif /* FOTOREZYSTOR_H */

