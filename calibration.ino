String str[] = {"A0=", "A1=", "A2=", "A3=", "A4=", "A5="};
void calibrationMode(int _mode) {
  int motorSensorValue[2] = { -1, -1};
  int pressSensorValue[4] = { -1, -1, -1, -1};
  int values[6] = { -1, -1, -1, -1, -1, -1};
  for (int i = 0; i < 2; i++) {
    motorSensorValue[i] = analogRead(motorPin[i]);
    values[i] = motorSensorValue[i];
  }

  for (int i = 0; i < 4; i++) {
    pressSensorValue[i] = analogRead(pressPin[i]);
    values[i + 2] = pressSensorValue[i];
  }
  if (_mode == 1) {
    String s = "";
    for (int i = 0; i < 6; i++) {
      if (i != 0)
        s.concat(",");
      s.concat(str[i]);
      s.concat(String(values[i]));
    }
    Serial.println(s);
  }
  if (_mode == 2) {
    for (int i = 1; i < 2; i++) {
      values[i] =  map(motorSensorValue[i], baseMin[i], baseMax[i], mapMin, mapMax);
      Serial.print(str[i]);
      Serial.print(motorSensorValue[i]);
      Serial.print(" map=");
      Serial.print(values[i]);
      Serial.print(" : ");
    }
    Serial.println("");
  }
}

