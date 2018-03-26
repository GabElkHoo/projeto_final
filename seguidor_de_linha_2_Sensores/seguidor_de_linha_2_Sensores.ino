//pinos
int motorEsq1 = 1;
int motorEsq2 = 3;
int motorDir1 = 2;
int motorDir2 = 4;
int sensorE = 5;
int sensorD = 6;
const int trigger = 7;
const int echo = 8;
float distance;
int i;
long duration; 

int pinoledverm = 14;
int pinoledverd = 15;
int pinoledazul = 16;

int pushBRed = 17;
int pushBBlue = 18;
int pushBGreen = 19;

//pinos para sensor RGB
const int s0 = 9;
const int s1 = 11;
const int s2 = 12;
const int s3 = 13;
const int sensorOut = 10;

void setup() {
  pinMode(pinoledverm, OUTPUT);
  pinMode(pinoledverd, OUTPUT);
  pinMode(pinoledazul, OUTPUT);
  pinMode(motorEsq1, OUTPUT);
  pinMode(motorEsq2, OUTPUT);
  pinMode(motorDir1, OUTPUT);
  pinMode(motorDir2, OUTPUT);
  pinMode(sensorE, INPUT);
  pinMode(sensorD, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pinoledverm, OUTPUT);
  pinMode(pinoledverd, OUTPUT);
  pinMode(pinoledazul, OUTPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  pinMode(pushBRed, INPUT);
  pinMode(pushBBlue, INPUT);
  pinMode(pushBGreen, INPUT);
}

void loop()
{
  seguirLinha();
    for(i=0; i<2; i++){
    andarFrente(1000*(5*i+10),150);
    parar();
    delay(8000);
    }
    if(checarDistancia =< 10){
      parar();
      delay(500);
    }
  }
}

void andarFrente(int tempo, int pwm){
  digitalWrite(motorEsq1, pwm);
  digitalWrite(motorEsq2, LOW);
  digitalWrite(motorDir1, pwm);
  digitalWrite(motorDir2, LOW);
  delay(tempo);
}

void girarEsq(int tempo, int pwm){
  digitalWrite(motorEsq1, LOW);
  digitalWrite(motorEsq2, pwm);
  digitalWrite(motorDir1, pwm);
  digitalWrite(motorDir2, LOW);
  delay(tempo);
}

void girarDir(int tempo, int pwm){
  digitalWrite(motorEsq1, pwm);
  digitalWrite(motorEsq2, LOW);
  digitalWrite(motorDir1, LOW);
  digitalWrite(motorDir2, pwm);
  delay(tempo);
}

void seguirLinha(){
  bool leituraE = digitalRead(sensorE);
  bool leituraD = digitalRead(sensorD);
  if(!leituraE && !leituraD){
    andarFrente(3, 150);
  }
  else if (leituraE){
    girarEsq(5, 150);
  }
  else (leituraD){
    girarDir(5, 150);
  }
  else if (leituraE && leituraD){ //cruzamento
    parar()
    delay(500)
  }
}

void parar(){
  digitalWrite(motorEsq1, LOW);
  digitalWrite(motorEsq2, LOW);
  digitalWrite(motorDir1, LOW);
  digitalWrite(motorDir2, LOW);
}

void checarDistancia(distance){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.017;
}

void rotas(){
  if (pushBRed(HIGH))
  {
    
  }
}
