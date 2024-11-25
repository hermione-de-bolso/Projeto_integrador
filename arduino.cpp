#include <Servo.h>  // Inclui a biblioteca de controle de servos

// Definir os servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Definir os pinos dos botões
const int cimaPin = 5;
const int baixoPin = 13;
const int esquerdaPin = 12;
const int direitaPin = 11;
const int garraPin = 6;

// Variáveis para armazenar o estado dos botões
int estadoCima = 0;
int estadoBaixo = 0;
int estadoEsquerda = 0;
int estadoDireita = 0;
int estadoGarra = 0;

// Posições iniciais dos servos (ângulos de 0 a 180 graus)
int pos1 = 90;  // Servo 1 (braço)
int pos2 = 90;  // Servo 2 (braço)
int pos3 = 90;  // Servo 3 (antebraço)
int pos4 = 90;  // Servo 4 (garra)

// Variável para controlar a abertura/fechamento da garra
bool garraAberta = true;

void setup() {
  // Inicializa os servos
  servo1.attach(7);  // Servo 1 no pino 7
  servo2.attach(8);  // Servo 2 no pino 8
  servo3.attach(9);  // Servo 3 no pino 9
  servo4.attach(10); // Servo 4 no pino 10

  // Define os pinos dos botões como entrada
  pinMode(cimaPin, INPUT);
  pinMode(baixoPin, INPUT);
  pinMode(esquerdaPin, INPUT);
  pinMode(direitaPin, INPUT);
  pinMode(garraPin, INPUT);
}

void loop() {
  // Lê o estado dos botões
  estadoCima = digitalRead(cimaPin);
  estadoBaixo = digitalRead(baixoPin);
  estadoEsquerda = digitalRead(esquerdaPin);
  estadoDireita = digitalRead(direitaPin);
  estadoGarra = digitalRead(garraPin);

  // Movimento para cima (servo1 e servo2)
  if (estadoCima == HIGH) {
    pos1 += 5;  // Aumenta a posição do servo 1
    pos2 -= 5;  // Aumenta a posição do servo 2 (movimento inverso)
    if (pos1 > 180) pos1 = 180;  // Limita o movimento a 180 graus
    if (pos2 < 0) pos2 = 0;      // Limita o movimento a 0 graus
    servo1.write(pos1);
    servo2.write(pos2);
    delay(100);
  }

  // Movimento para baixo (servo1 e servo2)
  if (estadoBaixo == HIGH) {
    pos1 -= 5;  // Diminui a posição do servo 1
    pos2 += 5;  // Diminui a posição do servo 2 (movimento inverso)
    if (pos1 < 0) pos1 = 0;      // Limita o movimento a 0 graus
    if (pos2 > 180) pos2 = 180;  // Limita o movimento a 180 graus
    servo1.write(pos1);
    servo2.write(pos2);
    delay(100);
  }

  // Movimento para a esquerda (servo3)
  if (estadoEsquerda == HIGH) {
    pos3 += 5;  // Aumenta a posição do servo 3
    if (pos3 > 180) pos3 = 180;  // Limita o movimento a 180 graus
    servo3.write(pos3);
    delay(100);
  }

  // Movimento para a direita (servo3)
  if (estadoDireita == HIGH) {
    pos3 -= 5;  // Diminui a posição do servo 3
    if (pos3 < 0) pos3 = 0;      // Limita o movimento a 0 graus
    servo3.write(pos3);
    delay(100);
  }

  // Controle da garra
  if (estadoGarra == HIGH) {
    // Alterna entre abrir e fechar a garra
    if (garraAberta) {
      pos4 = 0;  // Fechar a garra
      garraAberta = false;
    } else {
      pos4 = 90;  // Abrir a garra
      garraAberta = true;
    }
    servo4.write(pos4);
    delay(500);  // Atraso para não detectar múltiplas pressões
  }
}
