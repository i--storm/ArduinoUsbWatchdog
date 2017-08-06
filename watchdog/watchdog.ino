int LedPin = 17;
int ResetPin = 10;
int val = 0;
int count = 0;
int startDelay = 12;//seconds
void setup() 
{
  Serial.begin(9600);
  pinMode(LedPin,OUTPUT);
  pinMode(ResetPin,OUTPUT);
  
  for(int i=0; i< startDelay; i++){
    Serial.println(i);
    int rest=blink(1);
    delay(1000-rest);
  }
  Serial.println("Watchdog started");
}

void loop() 
{  
  int rest=0;

  if (count > 10){
    Serial.println("RESETTING!!!");
    digitalWrite(LedPin,LOW); 
    digitalWrite(ResetPin,HIGH);
    //rest=blink(4);
  }else{  
    if (Serial.available() > 0) 
    {    
      val = Serial.read();
      if (val == 'H'){          
          digitalWrite(ResetPin,LOW);
          rest=blink(2);
          Serial.println("OK...");          
          count = 0;
      }else{
          count++ ;        
          rest=blink(3);
      }
    }else{
        count++ ;       
        rest=blink(3);
    }  
  }
  
  delay (1000-rest);
   
  
}

int blink(int num){  
  int sum=0;
  for(int i=1; i<=num; i++){
    digitalWrite(LedPin, LOW);
    delay(100);
    digitalWrite(LedPin, HIGH);
    delay(100);   
    sum=sum+200;
  }
  return sum;
}

