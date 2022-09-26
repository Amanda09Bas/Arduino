int valorE;
int valorD;
int velD=5;
int motorD=4;
int velE=6;
int motorE=7;
int sensorD=A1;
int sensorE=A0;
int maxD=0;
int minD=1023;
int maxE=0;
int minE=1023;
int mediaD;
int mediaE;
int tempo=1000;
int A;
int B;
int V1;
int C;
int D;
int V2;
int V3;
   
void setup(){ 
   Serial.begin(9600); 
// Definindo os pinos
  pinMode(sensorE, INPUT);
  pinMode(sensorD, INPUT);
  pinMode(motorE, OUTPUT);
  pinMode(motorD, OUTPUT);
// Inicialmente motores parados
  digitalWrite(motorE, LOW); 
  digitalWrite(motorD, LOW);
}

// Inicializando o programa
void loop(){
    while(millis()<10000)
  
  // Fazendo a leitura analógica dos sensores das linhas
  valorE = analogRead(sensorE);
  valorD = analogRead(sensorD);
  
  // Calulado a média dos valores e calibrando para seguir as linhas
  if (valorD>maxD)
   {
     maxD=valorD;
   }
   if (valorD<minD)
   {
     minD=valorD;
   }
   if (valorE>maxE)
   {
     maxE=valorE;
   }
   if (valorE<maxE)
   {
     minE=valorE;
   }
   mediaD=(maxD-minD)/2;
   mediaE=(maxE-minE)/2; 
   
  // Preto = pino do sensor com valor baixo,0
  // Branco = pino do sensor com valor alto,1
  
  // Funcionamento do motor de acordo com a média
   if (millis()<=2500)
   {
/* shield motor 2*/
//Adotando a velocidade do robo como 65, pois esta é ideal.
A=HIGH;  V1=65;  
B=LOW;   V2=65;
   }
   if (millis()>2500 && millis()<7500)
   {
/* shield motor 2*/
A=LOW;  V1= 65;
B=HIGH; V2=65;
   }
   if (millis()>7500 && millis()<10000)
   {
/* shield motor 2*/
A=HIGH;  V1= 65;
B=LOW;   V2=65;
   }
//Redefinindo os parâmetros, depois de calibrados
 digitalWrite(motorD,A);
 analogWrite(velD,V1);
 digitalWrite(motorE,B);
 analogWrite(velE,V2);
 delay(tempo);
 Serial.println("mediaD");
 Serial.println(mediaD);
 Serial.println("mediaE");
 Serial.println(mediaE);
 Serial.println("valorD");
 Serial.println(valorD);
 Serial.println("valorE");
 Serial.println(valorE);

//Funcionamento do Robo
if (valorE >= mediaE ){   // se o pino do sensor esquerdo :Branco
    if(valorD >= mediaD){ // se o pino do sensor motorEito :Branco
      digitalWrite(motorE, HIGH); //Segue em frente
      digitalWrite(motorD, HIGH);
      delay(tempo);
    }
    else{ // se pino do sensor motorEito:Preto
      digitalWrite(motorE, LOW); // Desliga motor esquerdo
      digitalWrite(motorD, HIGH);  // Liga motor motorEito
      delay(tempo); // mantem a função por alguns seg alguns segundos
    }
  }
  else{ // pino do sensor esquerdo:Preto
    if(valorD >= 153){ // se o pino do sensor motorEito:Preto
      digitalWrite(motorE, HIGH);  // Liga motor esquerdo
      digitalWrite(motorD, LOW); // Desliga motor motorEito
      delay(tempo); // mantem a função por alguns seg alguns segundos
    }
    else{ // pino do sensor esquerdo:Preto
          // pino do sensor motorEito :Preto
      digitalWrite(motorE, HIGH); // Liga  motores
      digitalWrite(motorD, LOW);
      delay(tempo); //mantem a função por alguns  segundos
    }
  }
}



  
  
  
