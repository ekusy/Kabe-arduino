//ジャッキで使用するピン
const int jackUpPin = 22, jackDownPin = 24;

//ウィンチで使用するピン
const int winchUpPin = 26, winchDownPin = 28;

//落下機構のドリルで使用するピン
const int drillPin = 30;

//モータの読み取りに使用するピン
const int motorPin[2] = {A0, A1};

//圧力センサの読み取りに使用するピン
const int pressPin[4] = {A4, A5, A6, A7};

//自動停止機構
const int DRILL = 0, JACK = 1, WINCH = 2;
const int OLD = 0, NEW = 1;
unsigned long safeTime = 4500;
unsigned long time_old[3] = { -1, -1, -1};
unsigned long time_new[3] = {0, 0, 0};

//機構作動開始時間と現在時間
unsigned long timeStart, timeNow;





