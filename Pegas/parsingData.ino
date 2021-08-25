void parsingData()
{
  int j = 0;
  //kirim data yang telah diterima sebelumnya
  //Serial.print("data masuk : ");
  //Serial.print(dataIn);
  //Serial.print("\n");

  //inisialisasi variabel, (reset isi variabel)
  dt[j] = "";
  //proses parsing data
  for (int i = 1; i < dataIn.length(); i++)
  {
    //pengecekan tiap karakter dengan karakter ([]) dan (,)
    if ((dataIn[i] == ']') || (dataIn[i] == ',') || (dataIn[i] == '['))
    {
      //increment variabel j, digunakan untuk merubah index array penampung
      j++;
      dt[j] = ""; //inisialisasi variabel array dt[j]
    }
    else
    {
      //proses tampung data saat pengecekan karakter selesai.
      dt[j] = dt[j] + dataIn[i];
    }
  }
}
