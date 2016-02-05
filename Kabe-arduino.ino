/*
  1または2にするとシリアルモニターでセンサーの値を確認できるモードになる
  1でモータセンサ、2で圧力センサ、3で現在の各ピンの様子
  確認後は0に戻して書き込み直すように
*/
#include "const.h"
int testMode = 1;

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
  }
}


