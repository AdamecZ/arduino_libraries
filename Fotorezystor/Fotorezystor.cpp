/* 
 * File:   Fotorezystor.h
 * Author: Adamec_Z
 * mail: adamec(a)gmx.net
 * Created on 24.12.2016
 */


#include <Fotorezystor.h>

void Fotorezystor::Begin( byte pin){
      this->lightPin=pin;
      this->ciemnosc=250;
      this->StanCiemnosci=false;//false jasno, true ciemno
      this->StanPIR=false;
    }
boolean Fotorezystor::SprawdzajStanPIR(){
      return this->StanPIR;
    }
boolean Fotorezystor::UstawStanPIR(boolean stan){
      this->StanPIR=stan;
      return this->StanPIR;
    }
float Fotorezystor::Odczyt(){
      return analogRead(this->lightPin)/4;
    } 
boolean Fotorezystor::SprawdzajCiemnosc( uint8_t poziomCiemnosci){
      this->ciemnosc= poziomCiemnosci;
      if((this->Odczyt()) > this->ciemnosc ){    
        Serial.println("high");
        this->StanCiemnosci=true; 
      }
      else{
        this->StanCiemnosci=false;
        Serial.println("low"); 
      }
      return this->StanCiemnosci;  
    }
    
float Fotorezystor::PrzeliczNaVolt(){
      float v=this->Odczyt()*5/255;
      Serial.println(v);
      return v;
    }
uint8_t Fotorezystor::PoziomCiemnosciGraf(){
      byte znak;
      int poziom=this->Odczyt()/16;
      for (byte l=0;l<=16;l++){
        //Serial.print((char)221);
       // Serial.print("|");
       if(l<=poziom){
        znak=0xFF;
       }
       else{
        znak=32;
       }
       lcd.print((char)znak);
      }
      //Serial.println(" ");
      return poziom;
    }
uint8_t Fotorezystor::PoziomCiemnosciGraf(byte poziom){
      byte znak;
      
      for (byte l=0;l<=16;l++){
        //Serial.print((char)221);
       // Serial.print("|");
       if(l<=poziom){
        znak=0xFF;
       }
       else{
        znak=32;
       }
       lcd.print((char)znak);
      }
      //Serial.println(" ");
      return poziom;
    }
    



