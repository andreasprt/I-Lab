/*
   Copyright 2020
   Murry Raditya, Andreas, Halen.
   penggunaan library sensor:
  2 to 15 cm GP2Y0A51SK0F  use 1080
  4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
  10 to 80 cm GP2Y0A21YK0F  use 1080
  10 to 150 cm GP2Y0A60SZLF use 10150
  20 to 150 cm GP2Y0A02YK0F use 20150
  100 to 550 cm GP2Y0A710K0F  use 100550
  Komunikasi:
  ("[a,200] > motor 1 begerak sejauh 200");
  ("[b,200] > motor 2 begerak sejauh 200");
  ("[c,200] > motor 3 begerak sejauh 200");
  ("[d,0] > selenoid nyala");
  ("[d,1] > selenoid mati");
  ("[e] > menampilkan jarak SL1 1 dan SL2");
  ("[t] > menampilkan waktu");
  ("[g] > lepas beban ");
  ("[h] > ambil beban");

*/
#include <AccelStepper.h>
#include <SharpIR.h>

#define IR1 A1 // define signal pin
#define IR2 A2 // define signal pin
// buat limitSwitch
#define Sw_m1_kanan  46
#define Sw_m1_kiri  47

#define Sw_m2_kanan  48
#define Sw_m2_kiri  49

#define Sw_m3_kanan  50
#define Sw_m3_kiri  51

#define model1 20150 // for GP2Y0A21YK0F  used 1080
#define model2 20150 // for GP2Y0A21YK0F  used 1080
// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            430 for GP2Y0A41SK

int bcdata = 30, flag = 0;
int a = 128;
int s1 [40];
int s2 [40];

int hitungs1, hitungs2;
SharpIR SharpIR1(IR1, model1);
SharpIR SharpIR2(IR2, model2);
//SharpIR SharpIR(IR, model);


byte SP1 = 3;
byte SP2 = 2;
int rly = 10;

int dis1, dis2;


float sj1 = 0, sj2 = 0;
boolean timer = false;

unsigned long startTime;
unsigned long endTime;
unsigned long duration;
byte timerRunning;

//motortipe, step, dir
AccelStepper stepper1 = AccelStepper(1, 5, 4);
AccelStepper stepper2 = AccelStepper(1, 7, 6);
AccelStepper stepper3 = AccelStepper(1, 9, 8);

// ====================================================
//                PARSING DATA SERIAL (string & int)
// ====================================================

String dataIn;
String dt[10];
boolean parsing = false;

void bctimer();
void parsingData();
void bacajarak();
void inisialisasi_sw_batasLGA();
void bounceLGA();
void buffer_data();


void setup()
{
  pinMode (SP1, INPUT);
  pinMode (SP2, INPUT);
  pinMode (rly, OUTPUT);

  pinMode (Sw_m1_kanan, INPUT_PULLUP);
  pinMode (Sw_m1_kiri, INPUT_PULLUP);
  pinMode (Sw_m2_kanan, INPUT_PULLUP);
  pinMode (Sw_m2_kiri, INPUT_PULLUP);
  pinMode (Sw_m3_kanan, INPUT_PULLUP);
  pinMode (Sw_m3_kiri, INPUT_PULLUP);

  Serial.begin(115200);

  digitalWrite(rly, HIGH);
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(1000.0);

  stepper2.setMaxSpeed(1000.0);
  stepper2.setAcceleration(1000.0);

  stepper3.setMaxSpeed(2000.0);
  stepper3.setAcceleration(2000.0);
  dataIn = "";
  //
  //  Serial.println("Cara penggunaan");
  //  Serial.println("[a,200] > motor 1 begerak sejauh 200");
  //  Serial.println("[b,200] > motor 2 begerak sejauh 200");
  //  Serial.println("[c,200] > motor 3 begerak sejauh 200");
  //  Serial.println("[d,0] > selenoid nyala");
  //  Serial.println("[d,1] > selenoid mati");
  //  Serial.println("[e] > menampilkan jarak SL1 1 dan SL2");
  //  Serial.println("[t] > menampilkan waktu");
  //  Serial.println("=====================================");

}

char data;
String ambil, buffdt;
int posisi1, posisi2, posisi3;
float ns1, ns2;
int rly1, rly2;
int sw1, sw2, sw3, sw4;
int bouncing = 300;

void loop()
{
  inisialisasi_sw_batasLGA();
  //  Serial.print ("s1 = ");
  //  Serial.println (digitalRead(SP1));
  //  Serial.print ("s2 = ");
  //  Serial.println (digitalRead(SP2));
  //  delay (200);
  bctimer();
  /*
  if (duration>0) {
    Serial.print("[t,");
    Serial.print(duration);
    Serial.println("]");
    duration=0;
  }
  */

  buffer_data();

  stepper1.moveTo(posisi1); //moveTo
  stepper2.moveTo(posisi2);
  stepper3.moveTo(posisi3);

  hitungs1 = 0;
  hitungs2 = 0;
  bounceLGA();

}

void inisialisasi_sw_batasLGA()
{

  sw1 = digitalRead(Sw_m1_kanan);
  sw2 = digitalRead(Sw_m1_kiri);
  sw3 = digitalRead(Sw_m2_kanan);
  sw4 = digitalRead(Sw_m2_kiri);

}

void bounceLGA()
{
  while ((stepper1.currentPosition() != posisi1) && (stepper1.distanceToGo() != 0)) {
    stepper1.run();

    if (digitalRead(Sw_m1_kanan) == 0 || digitalRead(Sw_m1_kiri) == 0) {
      stepper1.stop();
      posisi1 = stepper1.currentPosition();
      if (posisi1 > 0) {
        posisi1 = posisi1 - bouncing;
      }
      if (posisi1 < 0) {
        posisi1 = posisi1 + bouncing;
      }
    }
  }
  while ((stepper2.currentPosition() != posisi2) && (stepper2.distanceToGo() != 0)) {
    stepper2.run();

    if (digitalRead(Sw_m2_kanan) == 0 || digitalRead(Sw_m2_kiri) == 0) {
      stepper2.stop();
      posisi2 = stepper2.currentPosition();
      if (posisi2 > 0) {
        posisi2 = posisi2 - bouncing;
      }
      if (posisi2 < 0) {
        posisi2 = posisi2 + bouncing;
      }
    }
  }
  while ((stepper3.currentPosition() != posisi3) && (stepper3.distanceToGo() != 0)) {
    stepper3.run();

    if (digitalRead(Sw_m3_kanan) == 0 || digitalRead(Sw_m3_kiri) == 0) {
      stepper3.stop();
      posisi3 = stepper3.currentPosition();
      if (posisi3 > 0) {
        posisi3 = posisi3 - bouncing;
      }
      if (posisi3 < 0) {
        posisi3 = posisi3 + bouncing;
      }
    }
  }
}

void bctimer()
{

  if (digitalRead(SP1) == LOW && timer == false) {

    timer = true ;
    startTime = millis(); //millis
    timerRunning = 1;
    // Serial.println("timer mulai");

  }

  if (digitalRead(SP2) == LOW && timer == true) {


    endTime = millis();
    timerRunning = 0;
    duration = endTime - startTime;
    //    Serial.print("t");
    //    Serial.println(duration);
    //  Serial.println("timer mati");
    //    Serial.println("-----------------");
    timer = false;
  }


}

void bacajarak() {

  for (int i = 0; i <= a; i = i + 1) {
    dis1 += SharpIR1.distance();
    dis2 += SharpIR2.distance();
  }

  hitungs1 = dis1 / a;
  hitungs2 = dis2 / a;
  Serial.print("[e,");  // returns it to the serial monitor
  Serial.print(hitungs1);
  Serial.println("]");
  Serial.print("[f,"); // returns it to the serial monitor
  Serial.print(hitungs2);
  Serial.println("]");
  dis1 = 0;
  dis2 = 0;
}

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

void buffer_data()
{

  if (Serial.available() > 0)
  {
    char inChar = (char)Serial.read();
    dataIn += inChar;
    if (inChar == '\n') {
      parsing = true;
    }
  }

  if (parsing)
  {
    parsingData();
    parsing = false;
    dataIn = "";
  }

  if (dt[0] == "a") {
    posisi1 += dt[1].toInt();
    Serial.print("[a,");
    Serial.print(posisi1);
    Serial.println("]");
    dt[0] = "";
    //Serial.println("=====================================");

  }
  if (dt[0] == "b") {
    posisi2 += (-1 * dt[1].toInt());
    Serial.print("[b,");
    Serial.print(posisi2);
    Serial.println("]");
    dt[0] = "";
    //Serial.println("=====================================");

  }
  if (dt[0] == "c") {
    posisi3 = (-1 * dt[1].toInt());
    Serial.print("[c,");
    Serial.print(posisi3);
    Serial.println("]");

    dt[0] = "";
    //Serial.println("=====================================");

  }
  if (dt[0] == "e") {
    //Serial.println("jaraknya bro");
    bacajarak();
    dt[0] = "";
    //Serial.println("=====================================");
  }

  if (dt[0] == "t") {
    //    Serial.println("waktu");
    Serial.print("[t,");
    Serial.print(duration);
    Serial.println("]");
    duration = 0;
    dt[0] = "";
    //Serial.println("=====================================");
  }

  // langsungan
  if (dt[0] == "g") {
    //c,100   d,0 c,0
    stepper3.moveTo(-100);
    stepper3.runToPosition();
    digitalWrite(rly, 0);
    stepper3.moveTo(0);
    stepper3.runToPosition();
    digitalWrite(rly, 1);

    dt[0] = "";
    //Serial.println("=====================================");
  }
  if (dt[0] == "h") {
    //c,0 d,0 c 10000 d1 c0
    stepper3.moveTo(0);
    stepper3.runToPosition();
    digitalWrite(rly, 0);
    stepper3.moveTo(-10000);
    stepper3.runToPosition();
    digitalWrite(rly, 1);
    stepper3.moveTo(0);
    stepper3.runToPosition();

    dt[0] = "";
    //Serial.println("=====================================");
  }

  if (dt[0] == "d") {
    int state_rly = dt[1].toInt();
    if (state_rly > 1) state_rly = 1;
    //posisi3=-200;
    Serial.print("[d,");
    Serial.print(state_rly);
    Serial.println("]");
    digitalWrite(rly, state_rly);
    dt[0] = "";
    //Serial.println("=====================================");

  }
  if (dt[0] == "z") {

    posisi3 = 500;
    //delay(500);
    //digitalWrite(rly,0);
    //delay(1000);
    posisi3 = -8000;
    digitalWrite(rly, 1);
    delay(500);
    posisi3 = 0;
    dt[0] = "";
    Serial.println("[z]");
  }
}
