#define faseA 0
#define faseB 1
#define relay 4
#define rpwm 2
#define lpwm 3

int counter = 0;
int stateA;
int stateAend;
float sudutraw, sudut;
int del = 200;

String dataIn;
String dt[10];
boolean parsing = false;

int i, gerakm;
int jmlData = 300;
int data[500];
unsigned int waktu ;

void setup() {
  Serial.begin(9600);
  dataIn = "";

  pinMode(faseA, INPUT_PULLUP);
  pinMode(faseB, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  stateAend = digitalRead(faseA);
}

void loop() {

  bacaEncoder();
  deteksiData();
  translate();
  Serial.print("sudut: ");
  Serial.println(sudutraw);

  //delay(50);
}

void bacaEncoder()
{
  stateA = digitalRead(faseA); // baca status awal dari fase A
  // kalo kondisi state fase A sekarang dan sebelumnya berbeda, berarti ada pulsa yang masuk guys
  if (stateA != stateAend) {
    // kalo state fase B berbeda dengan state fase A, berarti encoder berputar searah jarum jam
    if (digitalRead(faseB) != stateA) {
      counter ++;
    } else {
      counter --;
    }
    //Serial.println(counter);
    sudutraw = counter / 2;
  }
  stateAend = stateA; //update state dari fase
}

void parsingData()
{
  int j = 0;
  dt[j] = "";
  for (int i = 1; i < dataIn.length(); i++)
  {
    if ((dataIn[i] == ']') || (dataIn[i] == ',') || (dataIn[i] == '['))
    {
      j++;
      dt[j] = ""; //inisialisasi variabel array dt[j]
    }
    else
    {
      dt[j] = dt[j] + dataIn[i];
    }
  }
}

void deteksiData()
{
  if (Serial.available() > 0)
  {
    char inChar = (char)Serial.read();
    //char inChar = *udr;
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
}

void translate()
{
  if (dt[0] == "z") {
    Serial.print("[relay HIGH ");
    Serial.println("]");
    int a = dt[1].toInt();
    digitalWrite(relay, a );
    dt[0] = "";

  }

  if (dt[0] == "a") {
    digitalWrite(relay, 0 );
    Serial.print("[gerak");
    Serial.println("]");
    gerakm = dt[1].toInt();
    // gerakm = constrain(gerakm, -10, 10);
    //for(i=0; i<=gerakm; i++){
    waktu = millis();
    while (i <= abs(gerakm) && gerakm < 0) {
      bacaEncoder();
      analogWrite(rpwm, 0);
      analogWrite(lpwm, 80);
      Serial.println(i);
      // delay(del);
      if (millis() - waktu >= del) {
        i++;
        waktu = millis();
      }

    }
    while (i <= abs(gerakm) && gerakm > 0) {
      bacaEncoder();
      analogWrite(rpwm, 80);
      analogWrite(lpwm, 0);
      Serial.println(i);
      //delay(del);
      if (millis() - waktu >= del) {
        i++;
        waktu = millis();
      }

    }
    analogWrite(rpwm, 0);
    analogWrite(lpwm, 0);

    dt[0] = "";
    i = 0;
  }
  if (dt[0] == "b") {
    Serial.print("[relay Mati ");
    Serial.println("]");
    digitalWrite(relay, HIGH );
    dt[0] = "e";
  }
  //  if (dt[0] == "c") {
  //    del = dt[1].toInt();
  //    dt[0] = "";
  //  }

  if (dt[0] == "e") {
    int u = 0;
    waktu = millis();
    while (u <= jmlData) {
      bacaEncoder();
      if ( millis() - waktu >= 100 ) {
        //bacaEncoder();
        data[u] = sudutraw;
        // Serial.println(u);

        Serial.println( sudutraw);
        u++;
        waktu = millis();
      }
    }
    dt[0] = "";
  }
  if (dt[0] == "d") {
    for (int i = 0; i < jmlData ; i++) {
      Serial.print("[e,");
      Serial.print(i);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print(data[i]);
      Serial.print("]");
    }
    Serial.println();
    dt[0] = "";

  }

}
