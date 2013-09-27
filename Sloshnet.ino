#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7);

int NUM_PUMPS = 8;
int testDrank[] = {0,1,0,0,0,0,0,0};

int CLEANING_CYCLE[] = {10,10,10,10,10,10,10,10};
int TEQUILA_SUNRISE[] = {1,4,0,0,0,0,0,0};
                        // Vodka, OJ
void setup() {
  mySerial.begin(9600);
  for (int i = 0; i < NUM_PUMPS; i++) {
    pourPortions(i, TEQUILA_SUNRISE[i]);
    delay(1000);
  }
}

void loop() {
  // This could eventually listen for a button press 
  // or text or something that will trigger a drink to be poured
}

void pourPortions(int pumpNum, int servings) {
  if (servings > 0) {
    runPump(pumpNum);
    delay(1500 * servings);
    stopPump(pumpNum);
  }
}

void runPump(int num) {
  uint8_t runner[] = {255, num, 200};
  mySerial.write(runner, sizeof(runner));
  mySerial.flush();
}

void stopPump(int num) {
  uint8_t stopper[] = {255, num, 0};
  mySerial.write(stopper, sizeof(stopper));
  mySerial.flush();
}
