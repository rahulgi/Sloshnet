#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7);

int NUM_PUMPS = 8;
int testDrank[] = {0,1,0,0,0,0,0,0};

void setup() {
  mySerial.begin(9600);
  stopPump(0);
  //for (int i = 0; i < NUM_PUMPS; i++) {
  //  stopPump(i);
  //}
  for (int i = 0; i < NUM_PUMPS; i++) {
    pourPortions(i, testDrank[i]);
    delay(1000);
  }
}

void loop() {
  
}

void pourPortions(int pumpNum, int servings) {
  if (servings > 0) {
    runPump(pumpNum);
    delay(750 * servings);
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
