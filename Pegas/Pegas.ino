
#include <SharpIR.h>
#include <AccelStepper.h>

#define s1 A1
#define s2 A0
#define model 20150
#define Rly 12
#define ena 6
#define cw 7
#define clk 8
#define sw1 3
#define sw2 2

/*Komunikasi:
  ("[a,200] > motor 1 begerak sejauh 200");
  ("[m,0] > magnet nyala");
  ("[m,1] > magnet mati");
  ("[b] > ambil");
  ("[c] > lepas");
  ("[d] > data");

  ir: the pin where your sensor is attached
  model: an int that determines your sensor:
      1080 for GP2Y0A21Y
      20150 for GP2Y0A02Y
      (working distance range according to the datasheets)
*/
SharpIR IR1(s1, model); // sensor nol pegas
SharpIR IR2(s2, model); // sensor gerakan pegas
//motortipe, clk, cw
AccelStepper stepper1 = AccelStepper(1, clk, cw);

int sLuar = 0;
String dataIn;
String dt[10];
boolean parsing = false;
int data[200] = {};
int dataAkhir[100] = {};
int jeda = 5;
unsigned long endTime = 0;
int posisi1 = 0, simpanposisi1 = 0, awal = 0;
bool take = false;

void bcsLuar();
void bcGerakan();
void parsingData();
void ambil();
void (*reset) (void) = 0;

void setup() {
  // put your setup code here, to run once:
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(500.0);

  stepper1.moveTo(awal); // stepper naik sebanyak "awal" default 250
  while ((stepper1.currentPosition() != awal) && (stepper1.distanceToGo() != 0)) {
    stepper1.run();
  }
  posisi1 = awal;
  awal = 0;

  Serial.begin(115200);
  pinMode (9, INPUT);
  pinMode (sw1, INPUT_PULLUP);
  pinMode (sw2, INPUT_PULLUP);
  pinMode (10, INPUT);
  pinMode (11, INPUT);
  pinMode (Rly, OUTPUT);
  bcsLuar();
  //  Serial.print("sLuar = ");
  //  Serial.println (sLuar);

}


void loop() {
  // while (digitalRead(sw1) == 1 || digitalRead(sw2) == 1) {
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

  // perintah perintah
  // baca data
  if (dt[0] == "u") {
    dt[0] = "";
    bcGerakan();
  }

  // coba relay
  if (digitalRead(11) == LOW) {
    digitalWrite(Rly, 1);
    //      Serial.println("rly 1");
  }
  if (digitalRead(10) == LOW) {
    digitalWrite(Rly, 0);
    //      Serial.println("rly 0");
  }

  // relay aktif dan lepas
  if (dt[0] == "m") {
    digitalWrite(Rly, dt[1].toInt());
  }

  // geraka naik turun stepper
  if (dt[0] == "a") {
    bcsLuar();
    posisi1 = simpanposisi1 + dt[1].toInt();
    //Serial.println(dt[1].toInt());
    Serial.println("[A]");
    //Serial.print(sLuar);
    // Serial.print(posisi1);
    awal = 0;
    simpanposisi1 = posisi1;
    //Serial.println("]");
    dt[0] = "";
    //Serial.println("=====================================");
  }

  if (dt[0] == "b" && take == false) {
    Serial.println("[B]");
    take = true;
    posisi1 += 10000;
    digitalWrite(Rly, 1);
    // ambil();
    dt[0] = "";
  }
  if (dt[0] == "c") {
    //lepas
    Serial.println("[C]");
    take = false;
    bcsLuar();
    digitalWrite(Rly, 0);
    bcGerakan();
    dt[0] = "";
  }
  // tampilkan data
  if (dt[0] == "d") {
    for (int q = 2; q < 100; q++) {
      Serial.print("[p,");
      Serial.print(q - 2);
      Serial.print(",");
      Serial.print(q - 2);
      Serial.print(",");
      Serial.print(dataAkhir[q]);
      Serial.print("]");
    }
    Serial.println("");
    dt[0] = "";
  }
  if (dt[0] == "e") {
    dt[0] = "";
    bcsLuar();
    Serial.print("[e,");
    Serial.print(sLuar);
    Serial.print("]");
    Serial.println("");
  }
  stepper1.moveTo(posisi1);
  while ((stepper1.currentPosition() != posisi1) && (stepper1.distanceToGo() != 0)) {
    stepper1.run();
    if (digitalRead(sw1) == 0 ) {
      stepper1.stop();
      simpanposisi1 = posisi1 = stepper1.currentPosition() + 250;
    }
    else if ( digitalRead(sw2) == 0) {
      stepper1.stop();
      simpanposisi1 = posisi1 = stepper1.currentPosition() - 250;
    }
  }

  //  reset();

}
