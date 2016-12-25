#include <Przekaznik.h>







#define pinRelayLight 5//pin przekaznika swiatła

#define pinLED 13// dioda LED


Przekaznik P;



void setup(void)
{

  P.Init(pinRelayLight,0);

  
 
}



void loop(void)
{ 
  // załacza , wyłącza przekaznik co 1 sek.
 for(unit8_t l=0;l<10;l++){
    P.OnPrzekaznik();
    delay(1000);
 }

 P.OnPrzekaznik(1);//załącz przekaznik
 delay(5000);
 P.OnPrzekaznik(0);//wyłącz przekaznik
 delay(5000);
 P.OnPrzekaznik(1);
 P.OffTimePrzekaznik(5000);//wyłącz po upływie 5 sek
 
}
