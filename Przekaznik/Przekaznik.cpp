/* 
 * File:   Przekaznik.cpp
 * Author: AdamecZ adamec(a)gmx.net
 *
 * Created 22.12.2016
 */
#include "Przekaznik.h"

    void Przekaznik::Init(byte pinP,boolean LowHigh){
      this->pinPrzekaznika=pinP;
      this->OnOff=false;
      this->OnStanem=LowHigh;
      pinMode(this->pinPrzekaznika, OUTPUT);	
    }
    boolean Przekaznik::OnPrzekaznik(){//tryb monostabilny
      if(!OnOff){
        digitalWrite(this->pinPrzekaznika,this->OnStanem);
        this->OnOff=true;
        CzasUruchomienia=millis();
        return true;
        
      }
      else{
        digitalWrite(this->pinPrzekaznika,!(this->OnStanem));
        this->OnOff=false;
        return false;
        
      }
    }
    boolean Przekaznik::OnPrzekaznik(boolean On){//tryb bistabilny
      if(On){
        digitalWrite(this->pinPrzekaznika,this->OnStanem);
        this->OnOff=true;
        CzasUruchomienia=millis();
        return false;
        
      }
      if(!On){
        digitalWrite(this->pinPrzekaznika,!(this->OnStanem));
        this->OnOff=false;
        return true;
        
      }
    }
    boolean Przekaznik::OffTimePrzekaznik(unsigned long CzasOff){
      //CzasOff w milisekundach Czas po jakim zostanie wyłączony przekaźnik
      //wyłacza przekaznik po upływie czasu   
      if(millis()-(this->CzasUruchomienia)>CzasOff){
        this->OnPrzekaznik(0);
        this->CzasUruchomienia=millis();
      }
    }
  
