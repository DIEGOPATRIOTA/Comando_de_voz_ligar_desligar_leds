/**
 * Projetos Arduino
 * 
 * @author diego patriota
 * @link https://github.com/diegopatriota
 * 19/05/2016 
 */

//variáveis
String voz;
int 
led1 = 10,
led2 = 11,
led3 = 12,  
led4 = 13;  

//função   
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH); 
}

//função
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     
}

   
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  
}


//Loop para execução de funcionalidade   
void loop() {
  while (Serial.available()){
  delay(10);
  char c = Serial.read();
  voz += c;
  }  
  if (voz.length() > 0) {
    Serial.println(voz); 
  
       if(voz == "ligar tudo"  ) {allon();}
  else if(voz == "desligar tudo"){alloff();}
    
  else if(voz == "ligar lâmpada 1") {digitalWrite(led1, HIGH);} 
  else if(voz == "ligar lâmpada 2") {digitalWrite(led2, HIGH);}
  else if(voz == "ligar lâmpada 3") {digitalWrite(led3, HIGH);}
  else if(voz == "ligar lâmpada 4") {digitalWrite(led4, HIGH);}
    
  else if(voz == "desligar lâmpada 1") {digitalWrite(led1, LOW);} 
  else if(voz == "desligar lâmpada 2") {digitalWrite(led2, LOW);}
  else if(voz == "desligar lâmpada 3") {digitalWrite(led3, LOW);}
  else if(voz == "desligar lâmpada 4") {digitalWrite(led4, LOW);}
    
  voz="";

  }
} 
