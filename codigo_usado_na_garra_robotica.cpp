#include <Servo.h>

// Definição dos servos e pinos
Servo servo1; // Servo para "direita e esquerda"
Servo servo2; // Servo para "para cima e para baixo"
Servo servo3; // Servo para "para frente e para trás"
Servo servoGarra; // Servo para abrir e fechar a garra

const int servo1Pin = 2;
const int servo2Pin = 3;
const int servo3Pin = 4;
const int servoGarraPin = 5;

// Definição dos pinos dos botões
const int buttonDireitaPin = A0; 
const int buttonEsquerdaPin = A1; 
const int buttonCimaPin = A2; 
const int buttonBaixoPin = A3; 
const int buttonFrentePin = A4; 
const int buttonTrasPin = A5; 
const int buttonGarraPin = 8;

// Ângulos iniciais dos servos
int angle1 = 90; // Direita e esquerda
int angle2 = 0; // Para cima e para baixo
int angle3 = 90; // Para frente e para trás
int angleGarra = 45; // Abrir e fechar a garra

// Variável para evitar múltiplos acionamentos do botão
bool garraPressionado = false;

void setup() {
  // Anexar os servos aos pinos
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servoGarra.attach(servoGarraPin);

  // Configuração dos pinos dos botões
  pinMode(buttonDireitaPin, INPUT_PULLUP);
  pinMode(buttonEsquerdaPin, INPUT_PULLUP);
  pinMode(buttonCimaPin, INPUT_PULLUP);
  pinMode(buttonBaixoPin, INPUT_PULLUP);
  pinMode(buttonFrentePin, INPUT_PULLUP);
  pinMode(buttonTrasPin, INPUT_PULLUP);
  pinMode(buttonGarraPin, INPUT_PULLUP);

  // Definir posições iniciais dos servos
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servoGarra.write(angleGarra);
}

void loop() {
  // Controle do servo1 (direita e esquerda)
  if (digitalRead(buttonDireitaPin) == LOW) {
    angle1 = constrain(angle1 + 5, 0, 180); // Movimenta para a direita
  }
  if (digitalRead(buttonEsquerdaPin) == LOW) {
    angle1 = constrain(angle1 - 5, 0, 180); // Movimenta para a esquerda
  }
  servo1.write(angle1);

  // Controle do servo2 (para cima e para baixo)
  if (digitalRead(buttonCimaPin) == LOW) {
    angle2 = constrain(angle2 + 5, 0, 180); // Movimenta para cima
  }
  if (digitalRead(buttonBaixoPin) == LOW) {
    angle2 = constrain(angle2 - 5, 0, 180); // Movimenta para baixo
  }
  servo2.write(angle2);

  // Controle do servo3 (para frente e para trás)
  if (digitalRead(buttonFrentePin) == LOW) {
    angle3 = constrain(angle3 + 5, 0, 180); // Movimenta para frente
  }
  if (digitalRead(buttonTrasPin) == LOW) {
    angle3 = constrain(angle3 - 5, 0, 180); // Movimenta para trás
  }
  servo3.write(angle3);

   // Controle da garra (abre e fecha)
  if (digitalRead(buttonGarraPin) == LOW) {
    if (!garraPressionado) {
      // Alterna entre abrir e fechar dependendo do ângulo atual
      if (angleGarra == 60) {
        angleGarra = 45; // Fecha a garra
      } else if (angleGarra == 45) {
        angleGarra = 60; // Abre a garra
      }
      servoGarra.write(angleGarra);
      garraPressionado = true; // Marca o botão como pressionado
    }
  } else {
    garraPressionado = false; // Reseta o estado quando o botão é solto
  }
  

  delay(20); // Pequeno atraso para suavizar o movimento
} 
