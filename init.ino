void init() {
  pinMode(jackUp, OUTPUT);
  pinMode(jackDown, OUTPUT);

  pinMode(winchUp, OUTPUT);
  pinMode(winchDown, OUTPUT);

  pinMode(drillForword, OUTPUT);
  pinMode(drillReverse, OUTPUT);

  for (int i = 0; i < 2; i++)
    pinMode(motorPin[i], INPUT);

  for (int i = 0; i < 4; i++)
    pinMode(pressPin[i], INPUT);

  timeStart = -1;
  timeNow = 0;
}

