
void safeFunction(){
  //自動停止機構　作動から一定時間で停止する
  for (int i = 0; i < 3; i++) {
    time_new[i] = millis(); //現在時刻更新
    if (time_old[i] != -1) {  //時間が入っている＝機構作動中
      if ( (time_new[i] - time_old[i]) > safeTime ) { //作動から一定時間(safeTime)経過してたら
        time_old[i] = -1; //作動時刻をリセット
        switch (i) {  //
          case DRILL: //ドリル停止
            digitalWrite(drillPin, LOW);
            break;
          case JACK:  //ジャッキ停止
            digitalWrite(jackUpPin, LOW);
            digitalWrite(jackDownPin, LOW);
            break;
          case WINCH: //ウィンチ停止
            digitalWrite(winchUpPin, LOW);
            digitalWrite(winchDownPin, LOW);
            break;
        }
        delay(10);
      }
    }
  }
}
