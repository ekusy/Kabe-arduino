

//シリアル通信受信部分
void readValue(){
  if (Serial.available() > 0) { //受信データがあれば
    char  c = Serial.read();  //バッファからデータ受信
    Serial.flush(); //バッファ消去
    judge(c); //動作判定
  }
}
/************ドリル判定関数************/
void judge(char c) {
  if (c == '0') { //全機構停止
    digitalWrite(drillPin, LOW);
    digitalWrite(jackUpPin, LOW);
    digitalWrite(jackDownPin, LOW);
    digitalWrite(winchUpPin, LOW);
    digitalWrite(winchDownPin, LOW);
    delay(10);
  }
  else if (c == '1') { //ドリル正転
    digitalWrite(drillPin, HIGH);
    delay(10);
    time_old[DRILL] = millis();
  }

  else if (c == '3') {  //ドリル停止
    digitalWrite(drillPin, LOW);
    delay(10);
    time_old[DRILL] = -1;
  }
  else if (c == '4') {  //ジャッキ上げ（頭下げ）
    digitalWrite(jackDownPin, LOW);
    delay(10);
    digitalWrite(jackUpPin, HIGH);
    time_old[JACK] = millis();
  }
  else if (c == '5') {  //ジャッキ下げ（頭上げ）
    digitalWrite(jackUpPin, LOW);
    delay(10);
    digitalWrite(jackDownPin, HIGH);
    time_old[JACK] = millis();
  }
  else if (c == '6') {  //ジャッキ停止
    digitalWrite(jackUpPin, LOW);
    digitalWrite(jackDownPin, LOW);
    delay(10);
    time_old[JACK] = -1;
  }
  else if (c == '7') {  //ウィンチ出し（ハンモック下げ）
    digitalWrite(winchDownPin, LOW);
    delay(10);
    digitalWrite(winchUpPin, HIGH);
    time_old[WINCH] = millis();
  }
  else if (c == '8') {  //ウィンチ巻き（ハンモック上げ）
    digitalWrite(winchUpPin, LOW);
    delay(10);
    digitalWrite(winchDownPin, HIGH);
    time_old[WINCH] = millis();
  }
  else if (c == '9') {
    digitalWrite(winchUpPin, LOW);
    digitalWrite(winchDownPin, LOW);
    delay(10);
    time_old[WINCH] = -1;
  }
}


