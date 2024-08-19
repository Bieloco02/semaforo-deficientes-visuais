#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6          // pino de controle da fita de led
#define NUMPIXELS 300  // número de leds presentes na fita
#define motor 8        // define porta do vibracall
#define Sensor 5       // define porta do sensor infravermelho
int pos = 0;           //define pos como valendo 0
Servo myservo;         // nomeia o servo como myservo

#define PIN 6          // pino da fita de led
#define NUMPIXELS 300  // número de leds presentes na fita
#define motor 8        // define porta do vibracall
#define Sensor 5       // define porta do sensor infravermelho


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int Estado;
void setup() {

  pixels.begin();          // Inicializa a fita de led
  pixels.clear();          // apaga todos os leds
  pinMode(Sensor, INPUT);  //inclui o sensor infravermelho
  pinMode(motor, OUTPUT);  // inclui o vibracall
  myservo.attach(9);       //inclui o servo motor

  pixels.begin();          // Inicia a fita de led
  pixels.clear();          // apaga todos os leds
  pinMode(Sensor, INPUT);  //inclui o sensor infravermelho
  pinMode(motor, OUTPUT);  // inclui o vibracall
  myservo.attach(9);
}

void loop() {
  Estado = digitalRead(Sensor);  //nomeia estado como sendo a leitura do sensor infravermelho
  Serial.println(Estado);
  if (Estado) {  // se o sensor nao estiver lendo nenhum objeto ele liga as luzes do semaforo verde
    verde();
  } else {  //se o sensor fazer a leitura de algum objeto
    delay(1000);
    amarelo();
    vermelho();
    delay(10);
  }
}
<<<<<<< HEAD
void alerta(){
  
  for(int i=35; i<205; i++)   { 
=======
void alerta() {
  for (int i = 35; i < 205; i++) {
>>>>>>> 8ba4ab595c218ce5d5f1177393f27679c7617892
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show();  // alerta.
  }
  delay(100);
  for (int i = 35; i < 205; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
<<<<<<< HEAD
    pixels.show(); }

    delay(100);

    for(int i=35; i<205; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); }

    delay(4000);
  digitalWrite(motor, LOW);
  delay(3567);
  for(int r=0; r<7; r++){
    for(int i=0; i<35; i++)   { 
      pixels.setPixelColor(i, pixels.Color(0,0, 0));
      pixels.show(); //pedrest
    } 
    
    delay(657);
    for(int i=0; i<35; i++)   { 
      pixels.setPixelColor(i, pixels.Color(250, 0, 0));
      pixels.show(); //pedrest
    } 
    delay(657);
  }
  pixels.clear();
  
=======
    pixels.show();
  }
  delay(100);
  for (int i = 35; i < 205; i++) {
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show();
  }
  delay(4000);
  digitalWrite(motor, LOW);
  delay(3567);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
  delay(657);
  pixels.clear();
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
>>>>>>> 8ba4ab595c218ce5d5f1177393f27679c7617892
}

//função para acendimento do sinal vermelho dos carros
<<<<<<< HEAD
void vermelho(){
  
    // waits 15ms for the servo to reach the position
  //acende o vermelho 
  for(int i=210; i<250; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   
    }
    delay(3000);
    myservo.write(90);
    delay(15);
  for(int i=0; i<35; i++)   { 
=======
void vermelho() {
  for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }
  //acende o vermelho
  for (int i = 210; i < 250; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }
  delay(3000);
  for (int i = 0; i < 35; i++) {
>>>>>>> 8ba4ab595c218ce5d5f1177393f27679c7617892
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();  //pedrest
  }
  digitalWrite(motor, HIGH);  //liga o vibracall
  alerta();
  delay(500);
}  //fim função vermelho

//função para acendimento do sinal amarelo dos carros
void amarelo() {
  for (int i = 280; i < 300; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
  for (int i = 255; i < 275; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 191, 0));
    pixels.show();
<<<<<<< HEAD
    }
    //vibra pra avisar que esta funcionando
    digitalWrite(motor, HIGH);
    delay(340);
    digitalWrite(motor, LOW);
    delay(80);
    digitalWrite(motor, HIGH);
    delay(340);
    digitalWrite(motor, LOW);
    delay(1600);
    for(int i=255; i<275; i++) { 
    pixels.setPixelColor(i, pixels.Color(0,0, 0));
    pixels.show(  );
    }  
}  
  
  
void verde(){  
 myservo.write(pos);
delay(100);  
  
    for(int i=280; i<300; i++){ 
=======
  }
  //vibra pra avisar que esta funcionando
  digitalWrite(motor, HIGH);
  delay(340);
  digitalWrite(motor, LOW);
  delay(80);
  digitalWrite(motor, HIGH);
  delay(340);
  digitalWrite(motor, LOW);
  delay(1600);
  for (int i = 255; i < 275; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}


void verde() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  for (int i = 280; i < 300; i++) {
>>>>>>> 8ba4ab595c218ce5d5f1177393f27679c7617892
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();
  }
  for (int i = 0; i < 35; i++) {
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
<<<<<<< HEAD
    pixels.show(); //pedrest
    
}
=======
    pixels.show();  //pedrest
  }
>>>>>>> 8ba4ab595c218ce5d5f1177393f27679c7617892
}
