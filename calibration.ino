void calibrationMode(int _mode) {
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

  if (_mode = 1) {
    serial.print("右手モータ：");
    serial.print(motorSensorValue[0]);
    serial.print("右手送信値：");
    serial.print(sendValue[0]);
    serial.print("左手モータ：");
    serial.print(motorSensorValue[1]);
    serial.print("左手送信値：");
    serial.print(sendValue[1]);
  }
  else if (_mode = 2) {
    String str[8] = {"右手圧力：", "右手送信値", "左手圧力：", "左手送信値", "右足圧力：", "右足送信値", "左足圧力：", "左足送信値"};
    for (int i = 0; i < 4; i++) {
      serial.print(str[i*2]);
      serial.print(pressSensorValue[i]);
      serial.print(str[i * 2 + 1]);
      serial.print(sendValue[i + 2]);
    }
    serial.println("");
  }
}

