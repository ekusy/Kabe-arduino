
//モータの値の変換に使う数値
//baseが変換前、mapが変換後の値の範囲
const int baseMin = 0, baseMax = 200, mapMin = 0, mapMax = 100;



//圧力センサの閾値
const int pressThreshold[4] = {660, 520, 500, 800};
//----------ここまで定数宣言-------------------------


//----------ここから関数-----------------------------


void sendValue() {
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
    s.concat(String(sendValue[k]));
    //Serial.print(sendValue[k]);
    //Serial.print(",");
  }
  Serial.println(s);
  //Serial.println(analogRead(A4));
  delay(50);
}

