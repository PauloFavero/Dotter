#include <Braille.h>



void setup()
{
  Serial.begin(9600); //Inicia a serial com um baud rate de 9600
}

void loop()
{
  long tecladoA0=0;
  long tecladoA1 =0; //Cria variável para ler o teclado ligado ao pino A0
  int VETE1[]={0,0,0,0,0,0};
  char letra;
  
  for(int i=0;i<100;i++) //Laço para fazer 100 leituras
  {
      tecladoA0 =tecladoA0 + analogRead(A0);
      tecladoA1 =tecladoA1 + analogRead(A1); //Soma a leitura anterior com a leitura atual de A0
  }
    
 tecladoA0 = tecladoA0/100;   
 tecladoA1 = tecladoA1/100;
   if((tecladoA0 >=100) || (tecladoA1 >= 100)){
     
        while((analogRead(A0) >= 100) || (analogRead(A1) >= 100)){
          if(abs(analogRead(A0)-298) <= 40){
            VETE1[0] =1;
          }
          if(abs(analogRead(A0)-534) <= 25){
            VETE1[1] =1;
          }
          if(abs(analogRead(A0)-440) <= 20){
            VETE1[2] =1;
          }
          if(abs(analogRead(A0)-644) <=19){
            
          VETE1[0]=1;
          VETE1[1]=1;
          }    
          if(abs(analogRead(A0)-562) <=15){
            
          VETE1[0]=1;
          VETE1[2]=1;
          }
          
          if(abs(analogRead(A0)-675) <=10){
          VETE1[1]=1;
          VETE1[2]=1;
          }
      
          if(abs(analogRead(A0)-731) <=20){
          VETE1[0] = 1;
          VETE1[1] = 1;
          VETE1[2] = 1;
          }
          
          if(abs(analogRead(A1)-603) <=40){
            VETE1[3] =1;
            
          }
          if(abs(analogRead(A1)-321) <= 12){
            VETE1[4] =1;
          }
          if(abs(analogRead(A1)-501) <=10){
            VETE1[5] =1;
          }
          if(abs(analogRead(A1)-722) <= 15){
            
          VETE1[3]=1;
          VETE1[4]=1;
          }    
          if(abs(analogRead(A1)-752) <= 10){
            
          VETE1[3]=1;
          VETE1[5]=1;
          }
          
          if(abs(analogRead(A1)-648) <= 10){
          VETE1[4]=1;
          VETE1[5]=1;
          }
      
          if(abs(analogRead(A1) - 826) <= 6){
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

