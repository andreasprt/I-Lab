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
/*
  2 to 15 cm GP2Y0A51SK0F  use 1080
  4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
  10 to 80 cm GP2Y0A21YK0F  use 1080
  10 to 150 cm GP2Y0A60SZLF use 10150
  20 to 150 cm GP2Y0A02YK0F use 20150
  100 to 550 cm GP2Y0A710K0F  use 100550

*/
int bcdata = 30, flag = 0;
int a = 128;


int hitungs1, hitungs2;
SharpIR SharpIR1(IR1, model1);
SharpIR SharpIR2(IR2, model2);
//SharpIR SharpIR(IR, model);


byte SP1 = 2;
byte SP2 = 3;
int rly = 10;
int dis1, dis2;

// timer
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

int kec = 1000;
int akselerasi = 1000;

// ====================================================
//                PARSING DATA SERIAL (string & int)
// ====================================================

String dataIn;
String dt[10];
boolean parsing = false;

void bctimer();
void parsingData();
void bacajarak();


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
  stepper1.setMaxSpeed(kec);
  stepper1.setAcceleration(akselerasi);

  stepper2.setMaxSpeed(kec);
  stepper2.setAcceleration(akselerasi);

  stepper3.setMaxSpeed(kec);
  stepper3.setAcceleration(akselerasi);
  dataIn = "";

  Serial.println("Cara penggunaan");
  Serial.println("[a,200] > motor 1 begerak sejauh 200");
  Serial.println("[b,200] > motor 2 begerak sejauh 200");
  Serial.println("[c,200] > motor 3 begerak sejauh 200");
  Serial.println("[d,0] > selenoid nyala");
  Serial.println("[d,1] > selenoid mati");
  Serial.println("[e] > menampilkan jarak SL1 1 dan SL2");

  Serial.println("=====================================");

}

char data;
String ambil, buffdt;
int posisi1, posisi2, posisi3;
int sw1, sw2, sw3, sw4, sw5, sw6;
int bouncing = 300;

void loop()
{
  //posisi1=0;
  sw1 = digitalRead(Sw_m1_kanan);
  sw2 = digitalRead(Sw_m1_kiri);
  sw3 = digitalRead(Sw_m2_kanan);
  sw4 = digitalRead(Sw_m2_kiri);
  sw5 = digitalRead(Sw_m3_kanan);
  sw6 = digitalRead(Sw_m3_kiri);

  // cek sw

  //      Serial.print("Sw_m21_kanan = " );
  //      Serial.println(sw1);
  //      Serial.print("Sw_m1_kiri = ");
  //      Serial.println(sw2);
  //      Serial.print("Sw_m2_kanan = " );
  //      Serial.println(sw3);
  //      Serial.print("Sw_m2_kiri = ");
  //      Serial.println(sw4);
  //      Serial.print("Sw_m3_kanan = " );
  //      Serial.println(sw5);
  //      Serial.print("Sw_m3_kiri = ");
  //      Serial.println(sw6);
  bctimer();
  delay(20);
  if (duration >= 100)
  {
    Serial.print("t");
    Serial.println(duration);
    duration = 0;
  }

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
    posisi1 = dt[1].toInt();
    Serial.print("Motor 1 bergerak sejauh = ");
    Serial.println(posisi1);
    dt[0] = "";
    Serial.println("=====================================");

  }
  if (dt[0] == "b") {
    posisi2 = (-1 * dt[1].toInt());
    Serial.print("Motor 2 bergerak sejauh = ");
    Serial.println(posisi2);
    dt[0] = "";
    Serial.println("=====================================");

  }
  if (dt[0] == "c") {
    posisi3 = (-1 * dt[1].toInt());
    Serial.print("Motor 3 bergerak sejauh = ");
    Serial.println(posisi3);
    dt[0] = "";
    Serial.println("=====================================");

  }
  if (dt[0] == "e") {
    Serial.println("jaraknya bro");
    bacajarak();
    dt[0] = "";
    Serial.println("=====================================");

  }
  if (dt[0] == "d") {
    int state_rly = dt[1].toInt();
    if (state_rly > 1) state_rly = 1;
    Serial.print("posisi relay = ");
    Serial.println(state_rly);
    digitalWrite(rly, state_rly);
    dt[0] = "";
    Serial.println("=====================================");

  }
  stepper1.moveTo(posisi1); //moveTo
  stepper2.moveTo(posisi2);
  stepper3.moveTo(posisi3);


  hitungs1 = 0;
  hitungs2 = 0;

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

  if (digitalRead(SP1) == HIGH && timer == false) {

    timer = true ;
    startTime = millis(); //millis
    timerRunning = 1;
    //Serial.println("timer mulai");
  }

  if (digitalRead(SP2) == HIGH && timer == true) {
    endTime = millis();
    timerRunning = 0;
    duration = endTime - startTime;
  }
  if (digitalRead(SP1) == HIGH && timer == true) {
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
  Serial.print("SL1: ");  // returns it to the serial monitor
  Serial.println(hitungs1);
  Serial.print("SL2: ");  // returns it to the serial monitor
  Serial.println(hitungs2);
  dis1 = 0;
  dis2 = 0;
}

void parsingData()
{
  int j = 0;
  //kirim data yang telah diterima sebelumnya
  Serial.print("data masuk : ");
  Serial.println(dataIn);
  //Serial.print("\n");
  //inisialisasi variabel, (reset isi variabel)
  dt[j] = "";
  //proses parsing data
  for (int i = 1; i < dataIn.length(); i++)
  {
    //pengecekan tiap karakter dengan karakter (#) dan (,)
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


  //kirim data hasil parsing
  //    Serial.print("data 0 : ");
  //    Serial.print(dt[0]);
  //    Serial.print("\n");
  //    Serial.print("data 1 : ");
  //    Serial.print(dt[1]);
  //    Serial.print("\n");
  //    Serial.print("data 3 : ");
  //    Serial.print(dt[2].toInt());
  //    Serial.print("\n");
  //    Serial.print("data 4 : ");
  //    Serial.print(dt[3].toInt());
  //    Serial.print("\n");
  //    Serial.print("data 5 : ");
  //    Serial.print(dt[4].toInt());
  //    Serial.print("\n\n");

}
