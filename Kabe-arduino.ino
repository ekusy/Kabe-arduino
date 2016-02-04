/*
 1または2にするとシリアルモニターでセンサーの値を確認できるモードになる
 1でモータセンサ、2で圧力センサ
 確認後は0に戻して書き込み直すように
 */
int testMode = 0;

void setup() {
  // put your setup code here, to run once:
  initPin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sendValue();
  readValue();
  safeFunction();
}


