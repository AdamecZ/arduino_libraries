/* 
 * File:   Przekaznik.h
 * Author: AdamecZ adamec(a)gmx.net
 *
 * Created 22.12.2016
 */

#ifndef PRZEKAZNIK_H
#define PRZEKAZNIK_H

#include <Arduino.h>

class Przekaznik{
  protected:
    boolean OnOff;//info czy  pracuje
    unsigned long CzasUruchomienia;//czas zalaczenia przekaznika
    byte pinPrzekaznika;//pin przekaznika 
    boolean OnStanem;// czy załaczany stanem LOW-0 czy HIGH-1
  public:
    void Init(byte pinP,boolean LowHigh);
    boolean OnPrzekaznik();
     
    boolean OnPrzekaznik(boolean On);
    boolean OffTimePrzekaznik(unsigned long CzasOff);
  
};
#endif
