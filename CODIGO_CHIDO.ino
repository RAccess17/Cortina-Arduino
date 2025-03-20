#include <AFMotor.h>
const int Trigger1 = A5;   //Pin digital 2 para el Trigger del sensor
const int Echo1 = A4;
int Trigger2 = 2;   //Pin digital 2 para el Trigger del sensor
int Echo2 = 13;   //Pin digital 3 para el Echo del sensor
const int lsUP = A0;
const int lsDWN = A1;
String var;
AF_DCMotor motor(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);//inicializamos la comunicación
  motor.setSpeed(225);
  pinMode(Trigger1, OUTPUT); //pin como salida
  pinMode(Echo1, INPUT);  //pin como entrada
  pinMode(Trigger2, OUTPUT); //pin como salida
  pinMode(Echo2, INPUT);  //pin como entrada
  pinMode(lsUP, INPUT);
  pinMode(lsDWN,INPUT);
  digitalWrite(Trigger1, LOW);
  digitalWrite(Trigger2, LOW);//Inicializamos el pin con 0
}
 
void loop()
{
  long t1; //tiempo que demora en llegar el eco
  long d1; //distancia en centimetros
  long t2; //tiempo que demora en llegar el eco
  long d2; //distancia en centimetros
 
  digitalWrite(Trigger1, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger1, LOW);
  t1 = pulseIn(Echo1, HIGH); //obtenemos el ancho del pulso
  d1 = t1/59;
 
  digitalWrite(Trigger2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger2, LOW);
  t2 = pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
  d2 = t2/59;                //escalamos el tiempo a una distancia en cm
  
  if (digitalRead(lsUP) == HIGH) {
    Serial.println("Limite UP alcanzado!");
  }
  if (digitalRead(lsDWN) == HIGH) {
    Serial.println("Limite DWN alcanzado!");
  }
  Serial.print(d1);      //Enviamos serialmente el valor de la distancia
  Serial.print(" ");      //Enviamos serialmente el valor de la distancia
  Serial.print(d2);      //Enviamos serialmente el valor de la distancia
  Serial.println();

  if (d1 < 18 || d2 < 18 || var.indexOf("S") > 0) {
    motor.run(RELEASE);
    Serial.println("STOP!!");
    if (var.indexOf("S") > 0) {
      var = ""; // Limpia la variable var después de usarla
    }
    delay(100);
    return; // Sale del loop y vuelve a empezar
  }
  
  if (digitalRead(lsDWN) == HIGH) {
      var == "";
      motor.run(BACKWARD);
      delay(10);
      motor.run(RELEASE);
      return;
  }
  if (digitalRead(lsUP) == HIGH) {
      var == "";
      motor.run(FORWARD);
      delay(10);
      motor.run(RELEASE);
      return;
  }

  // Si no hay condición de parada, revisa si hay comandos seriales
  if (Serial.available() > 0) {
    var = Serial.readString();
    if (var == "UP") {
      motor.run(BACKWARD);
      Serial.println("UP!");
      delay(100);
      return;
    }
    else if (var == "DOWN") {
      motor.run(FORWARD);
      Serial.println("DOWN!");
      delay(100);
      return;
    }
    else if (var == "AU" && digitalRead(lsUP) != HIGH) {
      motor.run(BACKWARD);
      return;
    }
    else if (var == "AD" && digitalRead(lsDWN) != HIGH) {
      motor.run(FORWARD);
      return;
    }
    else if (var == "MU" && digitalRead(lsUP) != HIGH) {
      motor.run(BACKWARD);
      delay(50);
      motor.run(RELEASE);
      var == "";
      return;
    }
    else if (var == "MD" && digitalRead(lsDWN) != HIGH) {
      motor.run(FORWARD);
      delay(10);
      motor.run(RELEASE);
      var == "";
      return;
    }
    
  }
  
  delay(100);          //Hacemos una pausa de 100ms
  
}