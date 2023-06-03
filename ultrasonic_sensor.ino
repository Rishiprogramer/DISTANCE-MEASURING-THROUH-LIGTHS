
int inches = 0;

int cm = 0;
int ledr = 13;
int ledy = 12;
int ledg = 11;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
 
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
}

void loop()
{
 
  cm = 0.01723 * readUltrasonicDistance(7, 8);
  
  inches = (cm / 2.54);
  delay(10); 
  
  if(cm <= 20){
    digitalWrite(ledg, LOW);
    delay(0.1);
    digitalWrite(ledy, LOW);
    delay(0.1);
    digitalWrite(ledr,HIGH);
    delay(0.1);
    
    
    }
   else if(cm >=20 && cm <=40){
      
      digitalWrite(ledg, LOW);
      delay(0.1);
      digitalWrite(ledr,LOW);
      delay(0.1);
      digitalWrite(ledy, HIGH);
      delay(0.1);
      
      }
    else if(cm >=41 && cm <=50){
      
      digitalWrite(ledr,LOW);
      delay(0.1);
      digitalWrite(ledy, LOW);
      delay(0.1);
      digitalWrite(ledg, HIGH);
      delay(0.1);
      }
     else{
      digitalWrite(ledr,LOW);
      delay(0.1);
      digitalWrite(ledy, LOW);
      delay(0.1);
      digitalWrite(ledg, LOW);
      delay(0.1);
      }

  
}
