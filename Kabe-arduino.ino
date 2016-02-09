/*
  testModeを1にするとシリアルモニターでセンサーの値を確認できるモードになる
  終わったら0に戻すように
*/
//#include "const.h"
int testMode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initPin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (testMode > 0) {
    calibrationMode(testMode);
  }
  else {
    sendValue();
    readValue();
    safeFunction();
    //Serial.println("test");
  }
  delay(16);
}


