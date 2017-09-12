#define echoPin 13                                //Pino 13 recebe o pulso do echo  
#define trigPin 12                               //Pino 12 envia o pulso para gerar o echo  

void setup()  
{  
   Serial.begin(9600);                             //inicia a porta serial  
   pinMode(echoPin, INPUT);             // define o pino 13 como entrada (recebe)  
   pinMode(trigPin, OUTPUT) ;          // define o pino 12 como saida (envia)  
   pinMode(4, OUTPUT);                   // define o pino 4 como saida (envia)  
   pinMode(2, OUTPUT);                // pino de saida 2 do led 
}  
void loop()  
{   
    digitalWrite(trigPin, LOW);            //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0   
    delayMicroseconds(2);                 // delay de 2 microssegundos 
    digitalWrite(trigPin, HIGH);        //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1 
    delayMicroseconds(10);                                          //delay de 10 microssegundos
    digitalWrite(trigPin, LOW);                                   //seta o pino 12 com pulso baixo novamente  
    long duration = pulseIn(echoPin,HIGH);           //pulseInt lê o tempo entre a chamada e o pino entrar em high
long distancia = duration /29 / 2 ;                    //Esse calculo é baseado em s = v . t, lembrando que o tempo                   vem dobrado
                                                                                        //porque é o tempo de ida e volta do ultrassom 
    Serial.print("Distancia em CM: ");  
    Serial.println(distancia);  
    if (distancia < 80)
    { 
      digitalWrite(4,  HIGH);
      tone(8,440);
      delay(50);
      noTone(8);
      delay(50);
       digitalWrite(2,  HIGH);
         delay (distancia * 2);
         digitalWrite(2,  LOW);
         delay (distancia * 2);
    }
    else
       if (distancia < 100)
       {
         digitalWrite(4,  HIGH);
         tone(8,440);
         delay(100);
         noTone(8);
         delay(100);
         digitalWrite(2,  HIGH);
         delay (distancia * 5);
         digitalWrite(2,  LOW);
         delay (distancia * 5);
       }
    digitalWrite(4, LOW);
    delay(100);                                   
}

