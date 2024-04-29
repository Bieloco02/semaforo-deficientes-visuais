#include <Adafruit_NeoPixel.h>

#define PIN        6  // pino de controle da fita de led
#define NUMPIXELS 300 // número de leds presentes na fita
#define motor 8 // define porta do vibracall
#define Sensor 5 // define porta do sensor infravermelho

/*Instancia a fita de led
======================================================================= */
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//#define DELAYVAL 0 // Tempo (em milisegundos) pausa entre pixeis
int Estado;
void setup() {
  pixels.begin(); // Inicializa a fita de led
  pixels.clear(); // apaga todos os leds
  pinMode(Sensor, INPUT); //inclui o sensor infravermelho
  pinMode(motor, OUTPUT); // inclui o vibracall

}

void loop() {
  Estado = digitalRead(Sensor);
  Serial.println(Estado);
  if (Estado) {
    verde();
  }
  else {
    amarelo();
    digitalWrite(motor, HIGH);
    delay(400);
    digitalWrite(motor, LOW);
    delay(100);
    digitalWrite(motor, HIGH);
    delay(400);
    digitalWrite(motor, LOW);
    delay(1900);
    vermelho();
    delay(10);

 }
}
//função para acendimento do sinal vermelho dos carros
void vermelho(){
  digitalWrite(motor, HIGH);
  for(int i=44; i<80; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    }//fim do for
  //acende o primeiro circulo 
  for(int i=0; i<15; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   // executa o acendimento dos leds na cor desejada.
    }//fim do for

  //acende o segundo circulo
    for(int i=19; i<35; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   // executa o acendimento dos leds na cor desejada.
    }
    alerta();
    delay(4000);
    digitalWrite(motor, LOW);
    delay(2000);
    
    /*for(int i=44; i<81; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    }//fim do for*/
}//fim função vermelho

//função para acendimento do sinal vermelho dos carros/
void amarelo(){
    pixels.clear(); // apaga todos os leds
    for(int i=44; i<60; i++) { 
    pixels.setPixelColor(i, pixels.Color(255,191, 0));
    pixels.show();   // executa o acendimento dos leds na cor desejada.
    }//fim do laço for
}//fim função amarelo


void verde(){
  for(int i=0; i<64; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
  for(int i=80; i<300; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
    for(int i=64; i<80; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();
    }
}//fim função verde
void alerta(){
  for(int i=80; i<300; i++)   { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); // alerta.
    } 
    delay(100);
    for(int i=80; i<300; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); }
    delay(100);
    for(int i=80; i<300; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); }
    delay(1000);
}
