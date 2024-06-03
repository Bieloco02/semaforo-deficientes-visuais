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
    delay(1000);
    amarelo();
    vermelho();
    delay(10);

 }
}
void alerta(){
  for(int i=35; i<220; i++)   { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); // alerta.
    } 
    delay(100);
    for(int i=35; i<220; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); }
    delay(100);
    for(int i=35; i<220; i++) { 
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
  //acende o vermelho 
  for(int i=221; i<256; i++) { 
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
   for(int i=284; i<299; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    }
    for(int i=266; i<282; i++) { 
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
    for(int i=266; i<282; i++) { 
    pixels.setPixelColor(i, pixels.Color(0,0, 0));
    pixels.show();
    }
}


void verde(){
    for(int i=284; i<299; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();
    }
  for(int i=0; i<35; i++)   { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show(); //pedrest
}
}
