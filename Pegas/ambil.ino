void ambil() {
  // baca sensor luar
  bcsLuar();
  // naik
  int naik = 0;
  naik = (sLuar - 30) * 50; // 50 putar per cm
  Serial.println("[n]");
  //Serial.print (naik);
  //Serial.println("]");
  posisi1 = naik;
  simpanposisi1 = posisi1;
  //  magnet nyala
  digitalWrite(Rly, 1);
}
