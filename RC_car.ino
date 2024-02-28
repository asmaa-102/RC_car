
//#include<SoftwareSerial.h>

#define m1a  7
#define m1b  6
#define m2a  5
#define m2b  4
#define ena  9
#define enb  10

char val;
//SoftwareSerial myserial (Tx,Rx);
void setup() 
{  
pinMode(m1a, OUTPUT);  
pinMode(m1b, OUTPUT);  
pinMode(m2a, OUTPUT);  
pinMode(m2b, OUTPUT);  
Serial.begin(9600);
}

void loop()
{
  analogWrite(ena, 98);
  analogWrite(enb, 100);
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
    else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
  
    else if(val == 'L') //Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(val == 'R') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
  
}
