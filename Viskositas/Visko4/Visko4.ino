void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

int jarakR = 0;
int jarakL = 0;
int fixJarakR, fixJarakL;
int pjKaca = 50;
unsigned long waktu = 0, hasil = 0;
bool timerR = false;
bool timerL = false;
String dt = "";


void loop() {
  if (Serial.available()) // if there is data comming
  {
    dt = Serial.readStringUntil('\n'); // read string until meet newline character

// yang kanan

    if (dt == "ar1")
    {
      waktu = millis();
      timerR = true;
      jarakR = pjKaca + 30;
      Serial.println("ar1 masuk");

    }
    else if (dt == "ar2")
    {
      waktu = millis();
      timerR = true;
      jarakR = pjKaca +  20;
      Serial.println("ar2 masuk");

    }

    else if (dt == "ar3")
    {
      waktu = millis();
      timerR = true;
      jarakR = pjKaca +  10;
      Serial.println("ar3 masuk");

    }
    else if (dt == "ar4")
    {
      waktu = millis();
      timerR = true;
      jarakR = pjKaca;
      Serial.println("ar4 masuk");

    }
    else if (dt == "br1" && timerR == true)
    {
      hasil = millis() - waktu;
      fixJarakR = jarakR;
      timerR = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakR);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
    else if (dt == "br2" && timerR == true)
    {
      hasil = millis() - waktu;
      fixJarakR = jarakR + 10;
      timerR = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakR);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
 else if (dt == "br3" && timerR == true)
    {
      hasil = millis() - waktu;
      fixJarakR = jarakR + 20;
      timerR = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakR);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
     else if (dt == "br4" && timerR == true)
    {
      hasil = millis() - waktu;
      fixJarakR = jarakR + 30;
      timerR = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakR);
      Serial.print("waktu ");
      Serial.println(hasil);
    }

// yang kiri
if (dt == "al1")
    {
      waktu = millis();
      timerL = true;
      jarakL = pjKaca + 30;
      Serial.println("al1 masuk");

    }
    else if (dt == "al2")
    {
      waktu = millis();
      timerL = true;
      jarakL = pjKaca +  20;
      Serial.println("al2 masuk");

    }

    else if (dt == "al3")
    {
      waktu = millis();
      timerL = true;
      jarakL = pjKaca +  10;
      Serial.println("all masuk");

    }
    else if (dt == "al4")
    {
      waktu = millis();
      timerL = true;
      jarakL= pjKaca;
      Serial.println("aL4 masuk");

    }
    else if (dt == "bl1" && timerL == true)
    {
      hasil = millis() - waktu;
      fixJarakL = jarakL;
      timerL = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakL);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
    else if (dt == "bl2" && timerL== true)
    {
      hasil = millis() - waktu;
      fixJarakL = jarakR + 10;
      timerL = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakL);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
 else if (dt == "bl3" && timerL == true)
    {
      hasil = millis() - waktu;
      fixJarakL = jarakL + 20;
      timerL = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakL);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
     else if (dt == "bl4" && timerL == true)
    {
      hasil = millis() - waktu;
      fixJarakL = jarakL + 30;
      timerL = false;
      Serial.print("jarak antar sensor = ");
      Serial.println(fixJarakL);
      Serial.print("waktu ");
      Serial.println(hasil);
    }
    
  }

}
