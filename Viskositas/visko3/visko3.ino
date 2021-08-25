//#include <f401reMap.h>
//
//int ar1 = pinMap(2);
//int ar2 = pinMap(3);
//int ar3 = pinMap(4);
//int ar4 = pinMap(5);
//
//int al1 = pinMap(6);
//int al2 = pinMap(7);
//int al3 = pinMap(8);
//int al4 = pinMap(9);
//
//int br1 = pinMap(10);
//int br2 = pinMap(11);
//int br3 = pinMap(12);
//int br4 = pinMap(13);
//
//int bl1 = pinMap(14);
//int bl2 = pinMap(15);
//int bl3 = pinMap(16);
//int bl4 = pinMap(17);


int ar1 = 0;
int ar2 = 1;
int ar3 = 2;
int ar4 = 3;

int al1 = 4;
int al2 = 5;
int al3 = 6;
int al4 = 7;

int br1 = 8;
int br2 = 9;
int br3 = 10;
int br4 = 11;

int bl1 = 12;
int bl2 = 13;
int bl3 = A0;
int bl4 = A1;


int jarakR = 0;
int jarakL = 0;
int fixJarakR, fixJarakL;
int pjKaca = 50;
unsigned long waktu = 0, hasil = 0;
bool timerR = false;
bool timerL = false;
String dt = "";

void setup() {
  Serial.begin(115200);
  pinMode(ar1, INPUT);
  pinMode(ar2, INPUT);
  pinMode(ar3, INPUT);
  pinMode(ar4, INPUT);

  pinMode(al1, INPUT);
  pinMode(al2, INPUT);
  pinMode(al3, INPUT);
  pinMode(al4, INPUT);

  pinMode(br1, INPUT);
  pinMode(br2, INPUT);
  pinMode(br3, INPUT);
  pinMode(br4, INPUT);

  pinMode(bl1, INPUT);
  pinMode(bl2, INPUT);
  pinMode(bl3, INPUT);
  pinMode(bl4, INPUT);


}

void loop() {
  // baca serial
  while (Serial.available() > 0)
  {
    char inChar = (char)Serial.read();
    dt += inChar;
  }
  // Serial.print("dt");
  Serial.println(dt);
  //sensor kanan Atas
  if (dt == "ar1") {
    waktu = millis();
    timerR = true;
    jarakR = pjKaca + 30;
    Serial.println("ar1 masuk");
  }
  if (dt == "ar2") {
    waktu = millis();
    timerR = true;
    jarakR = pjKaca +  20;
    Serial.println("ar2 masuk");
  }
  //  if (digitalRead(ar3) == 1) {
  //    waktu = millis();
  //    timerR = true;
  //    jarakR = pjKaca +  10;
  //  }
  //  if (digitalRead(ar4) == 1) {
  //    waktu = millis();
  //    timerR = true;
  //    jarakR =  pjKaca;
  //  }
  //
  //  // sensor kiri ATAS
  //  if (digitalRead(al1) == 1) {
  //    waktu = millis();
  //    timerL = true;
  //    jarakL =  pjKaca  + 30;
  //  }
  //  if (digitalRead(al2) == 1) {
  //    waktu = millis();
  //    timerL = true;
  //    jarakL = pjKaca +  20;
  //  }
  //  if (digitalRead(al3) == 1) {
  //    waktu = millis();
  //    timerL = true;
  //    jarakL = pjKaca +  10;
  //  }
  //  if (digitalRead(al4) == 1) {
  //    waktu = millis();
  //    timerL = true;
  //    jarakL = pjKaca ;
  //  }

  //  4 sensor bawah Kanan
  while (timerR == true || timerL == true) {
    if (digitalRead(br1) == 1) {
      hasil = millis() - waktu;
      fixJarakR = jarakR;
      timerR = false;
    }
    if (digitalRead(br2) == 1) {
      hasil = millis() - waktu;
      fixJarakR = jarakR  + 10;
      timerR = false;
    }
    if (digitalRead(br3) == 1) {
      hasil = millis() - waktu;
      fixJarakR = jarakR  + 20;
      timerR = false;
    }
    if (digitalRead(br4) == 1) {
      hasil = millis() - waktu;
      fixJarakR = jarakR  + 30;
      timerR = false;
    }

    // kiri Bawah
    if (digitalRead(bl1) == 1) {
      hasil = millis() - waktu;
      fixJarakL  = jarakL;
      timerL = false;
    }
    if (digitalRead(bl2) == 1) {
      hasil = millis() - waktu;
      fixJarakL  = jarakL + 10;
      timerL = false;
    }
    if (digitalRead(bl3) == 1) {
      hasil = millis() - waktu;
      fixJarakL  = jarakL + 20;
      timerL = false;
    }
    if (digitalRead(bl4) == 1) {
      hasil = millis() - waktu;
      fixJarakL  = jarakL + 30;
      timerL = false;
    }

  }
  //  Serial.print("jarak L = ");
  //  Serial.println (fixJarakL);
  //  Serial.print("jarak R = ");
  //  Serial.println (fixJarakR);
}
