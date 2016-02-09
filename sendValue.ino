

//----------ここまで定数宣言-------------------------


//----------ここから関数-----------------------------


void sendValue() {
  int motorSensorValue[2] = { -1, -1};
  int pressSensorValue[4] = { -1, -1, -1, -1};
  int sendValue[6] = { 0,0,0,0,0,0};
  for (int i = 0; i < 2; i++) {
    motorSensorValue[i] = analogRead(motorPin[i]);
    sendValue[i] = map(motorSensorValue[i],baseMin[i],baseMax[i],mapMin,mapMax);
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
  
}

