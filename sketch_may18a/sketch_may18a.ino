#define ledVermelho 4
#define ledAmarelo 3
#define ledVerde 2
#define Sensor 5
#define motor 8
#define predeston 6
#define predestoff 7
int Estado;
void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(Sensor, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(predeston, OUTPUT);
  pinMode(predestoff, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Estado = digitalRead(Sensor);
  Serial.println(Estado);
  if (!Estado) {
    comPedestre();
  }
  else {
    semPedestre();
  }
}
void semPedestre() {
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(motor, LOW);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(predestoff, HIGH);
  digitalWrite(predeston, LOW);
}
void comPedestre() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(2000);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(predeston, HIGH);
  digitalWrite(predestoff, LOW);
  digitalWrite(motor, HIGH);
  digitalWrite(ledVermelho, HIGH);
  delay(4000);
  digitalWrite(motor, LOW);
  delay(550);
  digitalWrite(predeston, LOW);
  
  for (int i = 1; i < 4; i++) {
    digitalWrite(predestoff, HIGH);
    delay(450);
    digitalWrite(predestoff, LOW);
    delay(450);
  };
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(predestoff, HIGH);
  delay(7855);
}
