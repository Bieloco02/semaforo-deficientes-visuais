#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#define PIN        6  // pino de controle da fita de led
#define NUMPIXELS 300 // número de leds presentes na fita
#define motor 8 // define porta do vibracall
#define Sensor 5 // define porta do sensor infravermelho

/*Instancia a fita de led
======================================================================= */
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo myservo;
int pos = 0;

int Estado;
void setup() {
  pixels.begin(); // Inicializa a fita de led
  pixels.clear(); // apaga todos os leds
  pinMode(Sensor, INPUT); //inclui o sensor infravermelho
  pinMode(motor, OUTPUT); // inclui o vibracall
  myservo.attach(9);
}

void loop() {
  Estado = digitalRead(Sensor);
  Serial.println(Estado);
  if (Estado) {
    verde();
  }
  else {
    delay(1000);
    amarelo();
    vermelho();
    delay(10);

 }
}
void alerta(){
  for(int i=35; i<205; i++)   { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); // alerta.
    } 
    delay(100);
    for(int i=35; i<205; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); }
    delay(100);
    for(int i=35; i<205; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); }
    delay(4000);
  digitalWrite(motor, LOW);
  delay(3567);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0,0, 0));
    pixels.show(); //pedrest
    } 
  delay(657);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
  delay(657);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); //pedrest
    } 
  delay(657);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
  delay(657);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); //pedrest
  }
  delay(657);
    for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
  delay(657);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); //pedrest
  }
  delay(657);
    for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
  delay(657); 
    pixels.clear();
    for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
}
//função para acendimento do sinal vermelho dos carros
void vermelho(){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                    // waits 15ms for the servo to reach the position
  }
  //acende o vermelho 
  for(int i=210; i<250; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   
    }
    delay(3000);
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show(); //pedrest
    } 
     digitalWrite(motor, HIGH);//liga o vibracall
    alerta();
    delay(500);
}//fim função vermelho

//função para acendimento do sinal amarelo dos carros
void amarelo(){
   for(int i=280; i<300; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    }
    for(int i=255; i<275; i++) { 
    pixels.setPixelColor(i, pixels.Color(255,191, 0));
    pixels.show();
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
    pixels.show();
    }
}


void verde(){
    for (pos = 180; pos >= 0; pos -= 1) {
 myservo.write(pos);
delay(15);
}
    for(int i=280; i<300; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();
    }
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); //pedrest
}
}
