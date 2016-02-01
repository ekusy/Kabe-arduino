//ジャッキで使用するピン
const int jackUp = 22, jackDown = 24;

//ウィンチで使用するピン
const int winchUp = 26, winchDown = 28;

//落下機構のドリルで使用するピン
const int drillForword = 32, drillReverse = 34;

//モータの読み取りに使用するピン
const int motorPin[2] = {A0, A1};

//モータの値の変換に使う数値
//baseが変換前、mapが変換後の値の範囲
const int baseMin = 0, baseMax = 200, mapMin = 0, mapMax = 100;

//圧力センサの読み取りに使用するピン
const int pressPin[4] = {A4, A5, A6, A7};

//圧力センサの閾値
const int pressThreshold[4] = {660, 520, 500, 800};
//----------ここまで定数宣言-------------------------


//----------ここから関数-----------------------------
void sendvalue() {
  int motorSensorValue[2] = { -1, -1};
  int pressSensorValue[4] = { -1, -1, -1, -1};
  int sendValue[6] = { -1, -1, -1, -1, -1, -1};
  for (int i = 0; i < 2; i++) {
    motorSensorValue[i] = analogRead(motorPin[i]);
    sendValue[i] = motorSensorValue[i];
  }

  for (int i = 0; i < 4; i++) {
    pressSensorValue[i] = analogRead(pressPin[i]);
    if (pressSensorValue[i] >= pressThreshold[i]) {
      sendValue[i + 2] = 1;
    }
    else {
      sendValue[i + 2] = 0;
    }
  }

  String s = "";
  for (int k = 0; k < 6; k++) {
    if (k != 0)
      s.concat(",");
    s.concat(String(signal[k]));
    //Serial.print(signal[k]);
    //Serial.print(",");
  }
  Serial.println(s);
  //Serial.println(analogRead(A4));
  delay(50);
}

