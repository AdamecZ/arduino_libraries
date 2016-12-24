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
        
        this->StanCiemnosci=true; 
      }
      else{
        this->StanCiemnosci=false;
         
      }
      return this->StanCiemnosci;  
    }
    
float Fotorezystor::PrzeliczNaVolt(){
      float v=this->Odczyt()*5/255;
      
      return v;
    }
// prezrobienie poziomu z ADC na wyswielacz LCD 16*X
String Fotorezystor::PoziomCiemnosciGraf(){
      byte znak;
      String text="";
      int poziom=this->Odczyt()/16;
      for (byte l=0;l<=16;l++){
       if(l<=poziom){
        znak=0xFF;
       }
       else{
        znak=32;
       }
       text=text+((char)znak);
      }
      
      return text;
    }
String Fotorezystor::PoziomCiemnosciGraf(byte poziom){
      byte znak;
      String text="";
      for (byte l=0;l<=16;l++){
        
       
       if(l<=poziom){
        znak=0xFF;
       }
       else{
        znak=32;
       }
       text=text+(char)znak;
      }
      
      return text;
    }
    



