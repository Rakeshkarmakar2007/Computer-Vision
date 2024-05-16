String arrivingdatabyte;  

void setup( )  
{  
Serial.begin(9600);  
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
}  
void loop( )  
{  
if(Serial.available( ) > 0) 
 {  
    arrivingdatabyte = Serial.readStringUntil( '\n');
    if(arrivingdatabyte=="1")
     { 
       digitalWrite(7,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(5,LOW);  
       digitalWrite(4,LOW);
       digitalWrite(3,LOW); 
     }  
     if(arrivingdatabyte=="2")
     { 
       digitalWrite(7,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(5,LOW);  
       digitalWrite(4,LOW);
       digitalWrite(3,LOW);
           
     } 
      if(arrivingdatabyte=="3")
     { 
       digitalWrite(7,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(5,HIGH);  
       digitalWrite(4,LOW);
       digitalWrite(3,LOW);
            
     } 
      if(arrivingdatabyte=="4")
     { 
       digitalWrite(7,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(5,HIGH);  
       digitalWrite(4,HIGH);
       digitalWrite(3,LOW);
              
     } 
      if(arrivingdatabyte=="5")
     { 
       digitalWrite(7,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(5,HIGH);  
       digitalWrite(4,HIGH);
       digitalWrite(3,HIGH);
           
     } 
     if(arrivingdatabyte=="0")
     { 
       digitalWrite(7,LOW);
       digitalWrite(6,LOW);
       digitalWrite(5,LOW);  
       digitalWrite(4,LOW);
       digitalWrite(3,LOW);
           
     }      
  }
 Serial.println(arrivingdatabyte);  
}