//-----------使用するピン関連---------------------
//ジャッキで使用するピン
const int jackUpPin = 1, jackDownPin = 3;

//ウィンチで使用するピン
const int winchUpPin = 5, winchDownPin = 7;

//落下機構のドリルで使用するピン
const int drillPin = 9;

//モータの読み取りに使用するピン
const int motorPin[2] = {A0, A1};

//圧力センサの読み取りに使用するピン
const int pressPin[4] = {A4, A5, A6, A7};

//-----------ここまでピンの宣言---------------------


//-----------ここからセンサの値取得用---------------------
//モータの値の変換に使う数値
//baseが変換前、mapが変換後の値の範囲
const int baseMin = 0, baseMax = 200, mapMin = 0, mapMax = 100;

//圧力センサの閾値
const int pressThreshold[4] = {660, 520, 500, 800};

//-----------ここまでセンサ取得用---------------------


//-----------ここから機器の自動停止制御用---------------------
//自動停止機構
const int DRILL = 0, JACK = 1, WINCH = 2;
const int OLD = 0, NEW = 1;
unsigned long safeTime = 4500;
unsigned long time_old[3] = { -1, -1, -1};
unsigned long time_new[3] = {0, 0, 0};

//機構作動開始時間と現在時間
unsigned long timeStart, timeNow;

//-----------ここまで機器の自動停止制御用---------------------





