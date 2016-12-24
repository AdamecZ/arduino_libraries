#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

int cont = 0;
TM1637Display display(CLK, DIO);

void setup()
{
  display.setBrightness(0xF);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);

}

void loop()
{
  uint8_t segto;
  display.showNumberDec(cont, true);
  delay(500);
  cont++;
  segto = 0x80 | display.encodeDigit((cont / 100)%10);
  display.setSegments(&segto, 1, 1);
  delay(500);
  //if (++cont == 10000)
  //   cont = 0;
}
