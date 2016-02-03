void initPin() {
  pinMode(jackUpPin, OUTPUT);
  pinMode(jackDownPin, OUTPUT);

  pinMode(winchUpPin, OUTPUT);
  pinMode(winchDownPin, OUTPUT);

  pinMode(drillPin, OUTPUT);

  for (int i = 0; i < 2; i++)
    pinMode(motorPin[i], INPUT);

  for (int i = 0; i < 4; i++)
    pinMode(pressPin[i], INPUT);

  timeStart = -1;
  timeNow = 0;
}

