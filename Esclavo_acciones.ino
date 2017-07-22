//CODIGO ESCLAVO CONTROLADOR 2 (ARDUINO MEGA)
int led = 21;
int Dato = 0;
//int n = 4095;
String d;
int inc = 0;
int bandera = 0;

  int COHETE_1 = 9;
  int COHETE_2 = 8;
  int c = 0;
  int valor_1 = 0;
  int valor_2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

  pinMode (COHETE_1,INPUT);
}

void loop() {
  if (Serial.available()>0)
    {
    inc = Serial.read();
    }
  if (inc == '1')
    bandera = 1;
  if (inc == '2')
    bandera = 2;

 switch (bandera){
  case 1:
  envio();
  break;

  case 2:
  recepcion();
  break;
 }
}

void envio(){
  digitalWrite(led,HIGH);
  valor_1=digitalRead(COHETE_1);
  valor_2=digitalRead(COHETE_2);
  bitWrite(c,0,valor_1);
  bitWrite(c,1,valor_2);
  d = String (c);
      Serial.print("%");
      Serial.print(d);
      Serial.print("/");
  delay(200);
  bandera = 0;    
  inc = 0;
}

void recepcion(){

}

/*
void ejemplo(){
  int a;
  }
*/


