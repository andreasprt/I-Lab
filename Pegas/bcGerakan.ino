void bcGerakan() {

  // ambil data metode MAV(Moving Average)
  int p = 0;
  
  for (int j = 0; j < 100; j++) { //baca 100 data
    dataAkhir[j] = 0;
    while (p < 10) {
      if (jeda <= millis() - endTime ) {
        endTime = millis();
        dataAkhir[j] += IR2.distance() ;
        p++;
      }
    }
    p = 0;
    dataAkhir[j] = sLuar - (dataAkhir[j] / 10);
  }
  Serial.println("[S]");
}
