void initPin() {
  pinMode(jackUpPin, OUTPUT);
  pinMode(jackDownPin, OUTPUT);

  pinMode(winchUpPin, OUTPUT);
  pinMode(winchDownPin, OUTPUT);

  pinMode(drillPin, OUTPUT);

  digitalWrite(drillPin, LOW);
  digitalWrite(jackUpPin, LOW);
  digitalWrite(jackDownPin, LOW);
  digitalWrite(winchUpPin, LOW);
  digitalWrite(winchDownPin, LOW);
  
  for (int i = 0; i < 2; i++)
    pinMode(motorPin[i], INPUT);

  for (int i = 0; i < 4; i++)
    pinMode(pressPin[i], INPUT);

  timeStart = -1;
  timeNow = 0;
}

