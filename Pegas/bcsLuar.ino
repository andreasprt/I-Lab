void bcsLuar() {
  // baca sensor luar
  int bufdata[200] = {};
  int error = 0;
  for (int a = 0; a < 200 ; a++) {
    bufdata[a] = IR1.distance();
    delay(1);
    error = error + bufdata[a];

  }
  error = error / 200;
  if (error <= 10 ) {
    sLuar = error + 2;
  }
  if (error > 10 && error < 20 ) {
    sLuar = error - (-1);
  }
  if (error >= 20 && error <= 30 ) {
    sLuar = error - (-6);
  }
  if (error > 30 && error <= 40 ) {
    sLuar = error - (-7);
  }
  if (error > 40 && error <= 50 ) {
    sLuar = error - (-6);
  }
  if (error > 50 && error <= 60 ) {
    sLuar = error - (-5);
  }
  if (error > 60 && error <= 70 ) {
    sLuar = error - (-3);
  }
  if (error > 70 && error <= 80 ) {
    sLuar = error - (-1);
  }
  if (error > 80 && error <= 90 ) {
    sLuar = error - (4);
  }
  if (error > 90 && error <= 100 ) {
    sLuar = error - (6);
  }
  if (error > 100 && error <= 110 ) {
    sLuar = error - (14);
  }
  if (error > 110 && error <= 120 ) {
    sLuar = error - (17);
  }
  if (error > 120 && error <= 130 ) {
    sLuar = error - (21);
  }
  if (error > 130 && error <= 140 ) {
    sLuar = error - (27);
  }
  if (error > 140 && error <= 150 ) {
    sLuar = error - (36);
  }
  if (error > 150 && error <= 160 ) {
    sLuar = error - (42);
  }
  if (error > 160 && error <= 170 ) {
    sLuar = error - (47);
  }
  //  Serial.print("error = ");
  //  Serial.println (error);
  //  Serial.print("sLuar = ");
  //  Serial.println (sLuar);
}
