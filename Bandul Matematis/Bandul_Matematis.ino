#define faseA 0
#define faseB 1
#define relay 2
#define rpwm 9
#define lpwm 10

int counter = 0; 
int stateA;
int stateAend;  
float sudutraw, sudut;

String dataIn;
String dt[10];
boolean parsing = false;

int i, gerakm;

void setup() {
  Serial.begin(9600);
  dataIn="";
  
  pinMode(faseA, INPUT_PULLUP);
  pinMode(faseB, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  stateAend = digitalRead(faseA);
}

void loop() {
      
  bacaEncoder();
  deteksiData();
  translate();
  //Serial.print("sudut: ");
  Serial.println(sudutraw);
  
  //delay(50);
}

void bacaEncoder()
{
  stateA = digitalRead(faseA); // baca status awal dari fase A
   // kalo kondisi state fase A sekarang dan sebelumnya berbeda, berarti ada pulsa yang masuk guys
   if (stateA != stateAend){     
     // kalo state fase B berbeda dengan state fase A, berarti encoder berputar searah jarum jam
     if (digitalRead(faseB) != stateA) { 
       counter ++;
     } else {
       counter --;
     }
     //Serial.println(counter);
     sudutraw = counter;
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
  if (dt[0] == "a") {
    Serial.print("[relay HIGH ");
    Serial.println("]");
    digitalWrite(relay, HIGH);
    dt[0] = "";
    
  }
  if (dt[0] == "b") {
    Serial.print("[relay LOW");
    Serial.println("]");
    digitalWrite(relay, LOW);
  
    dt[0] = "";
    
  }  
  if (dt[0] == "c") {
    gerakm = dt[1].toInt();  
    
    //for(i=0; i<=gerakm; i++){
    while(i<=gerakm){
      analogWrite(rpwm,80);
      analogWrite(lpwm,0);
      Serial.println(i);
      delay(500);
      i++;  
    }
     analogWrite(rpwm,0);
    analogWrite(lpwm,0);
    
    dt[0] = "";
   i=0;
  }
  if (dt[0] == "d") {
    gerakm = dt[1].toInt();  
    //Serial.println("[gerak kiri]");
    //for(i=0; i<=gerakm; i++){
    while(i<=gerakm){  
      analogWrite(rpwm,0);
      analogWrite(lpwm,80);
      Serial.println(i);
      delay(500);
      i++;  
    }
    analogWrite(rpwm,0);
    analogWrite(lpwm,0);
      
    dt[0] = "";
    i=0;
   
  }
}
