#include <Braille.h>

int numBotoes = 6;
int bot[6] = {2, 3, 4, 8, 9, 10};
void setup()
{
  for(int i=0; i<numBotoes;i++){
    pinMode(bot[i], INPUT_PULLUP);
  }
    Serial.begin(9600); //Inicia a serial com um baud rate de 9600
}

void loop()
{

  int VETE1[]={0,0,0,0,0,0};
  int state[numBotoes] = {0};
  char letra;
  int test = 0;
  int count = 0;
  for(int i=0;i<numBotoes;i++){
    state[i] = digitalRead(bot[i]);
    if(state[i] != LOW){
      test = 1 ;
    }
  }
   if(test != 0){
     
        while(test != 0){
          for(int i =0; i<numBotoes;i++){
            state[i] = digitalRead(bot[i]);
            if(state[i] == LOW){
              count ++;
            }
          }
          if(count == numBotoes){
            test = 0;
          }
          if(digitalRead(bot[0])!= LOW){
            VETE1[0] =1;
          }
          if(digitalRead(bot[1])!= LOW){
            VETE1[1] =1;
          }
          if(digitalRead(bot[2])!= LOW){
            VETE1[2] =1;
          }
          if(digitalRead(bot[0])!= LOW && digitalRead(bot[1])!= LOW){
            
          VETE1[0]=1;
          VETE1[1]=1;
          }    
          if(digitalRead(bot[0])!= LOW && digitalRead(bot[2])!= LOW){
            
          VETE1[0]=1;
          VETE1[2]=1;
          }
          
          if(digitalRead(bot[2])!= LOW && digitalRead(bot[1])!= LOW){
          VETE1[1]=1;
          VETE1[2]=1;
          }
      
          if(digitalRead(bot[0])!= LOW && digitalRead(bot[1])!= LOW && digitalRead(bot[2])!= LOW){
          VETE1[0] = 1;
          VETE1[1] = 1;
          VETE1[2] = 1;
          }
          
          if(digitalRead(bot[3])!= LOW){
            VETE1[3] =1;
            
          }
          if(digitalRead(bot[4])!= LOW){
            VETE1[4] =1;
          }
          if(digitalRead(bot[5])!= LOW){
            VETE1[5] =1;
          }
          if(digitalRead(bot[3])!= LOW && digitalRead(bot[4])!= LOW){
            
          VETE1[3]=1;
          VETE1[4]=1;
          }    
          if(digitalRead(bot[3])!= LOW && digitalRead(bot[5])!= LOW){
            
          VETE1[3]=1;
          VETE1[5]=1;
          }
          
          if(digitalRead(bot[4])!= LOW && digitalRead(bot[5])!= LOW){
          VETE1[4]=1;
          VETE1[5]=1;
          }
      
          if(digitalRead(bot[3])!= LOW && digitalRead(bot[4])!= LOW && digitalRead(bot[5])!= LOW){
          VETE1[3] = 1;
          VETE1[4] = 1;
          VETE1[5] = 1;
          }
        
       }
     
      
     
      letra = decodeChar(VETE1);
       /*for(int i =0; i<6;i++){
        Serial.print(VETE1[i]);
       }*/
       
      Serial.print(letra);
      
      
    delay(100);  
   }        
  delay(100); //Aguarda 100 milissegundos

}

