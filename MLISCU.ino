/*
 * AUTHOR : JICKSON JOHN
 * scu based MLI , teensy 4.1 - 600mhz
 * arduino ide  ,compiler optimisation as fastest
 * 1V on H-M
 * 3V on M-L
 * sc1 parallel-series on 6,7
 * sc2 parallel-series on 8,9
 */
 
//define output pins and leds
const int b11=0,b12=1,b21=2,b22=3,b31=4,b32=5,clp=6,cls=7,chp=8,chs=9,led = LED_BUILTIN;

//define mosfet arms H,M,L ; p for positive output , scu unit p for parallel and s for serial

inline void HP() __attribute__((always_inline)); 
inline void HN() __attribute__((always_inline));
inline void MP() __attribute__((always_inline));
inline void MN() __attribute__((always_inline));
inline void LP() __attribute__((always_inline));
inline void LN() __attribute__((always_inline));
inline void CLP() __attribute__((always_inline));
inline void CLS() __attribute__((always_inline));
inline void CHP() __attribute__((always_inline));
inline void CHS() __attribute__((always_inline));

void CLP(){        
        digitalWrite(cls,LOW);
        delayMicroseconds(1);
        digitalWrite(clp,HIGH);
}
void CLS(){
        digitalWrite(clp,LOW);
        delayMicroseconds(1);
        digitalWrite(cls,HIGH);
}
void CHP(){
        digitalWrite(chs,LOW);
        delayMicroseconds(1);
        digitalWrite(chp,HIGH);
}
void CHS(){
        digitalWrite(chp,LOW);
        delayMicroseconds(1);
        digitalWrite(chs,HIGH);
}
void HP(){
         // b11 on ,b12 off
        digitalWrite(b12,LOW);
        delayMicroseconds(1);
        digitalWrite(b11,HIGH);
}
void HN(){
        //b12 on ,b11 off
        digitalWrite(b11,LOW);
        delayMicroseconds(1);
        digitalWrite(b12,HIGH);
}
void MP(){
        //b22 on ,b21 off
        digitalWrite(b21,LOW);
        delayMicroseconds(1);
        digitalWrite(b22,HIGH);
}
void MN(){
        //b21 on ,b22 off
        digitalWrite(b22,LOW);
        delayMicroseconds(1);
        digitalWrite(b21,HIGH);
}
void LP(){
        //b31 on ,b32 off
        digitalWrite(b32,LOW);
        delayMicroseconds(1);
        digitalWrite(b31,HIGH);
}
void LN(){
        //b31 on ,b32 off
        digitalWrite(b31,LOW);
        delayMicroseconds(1);
        digitalWrite(b32,HIGH);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(b11,OUTPUT);
  pinMode(b12,OUTPUT);
  pinMode(b21,OUTPUT);
  pinMode(b22,OUTPUT);
  pinMode(b31,OUTPUT);
  pinMode(b32,OUTPUT);
  pinMode(clp,OUTPUT);
  pinMode(cls,OUTPUT);
  pinMode(chp,OUTPUT);
  pinMode(chs,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(10,OUTPUT);
  /* debug
  Serial.begin(9600);
  while(!Serial);
  delay(2000);
  // */ 
}
void voltage_level(int x)
 {
  switch(x)
  {
      case 0: { // 0V  b11,b21,b31 
        HP();
        MN();
        LP();
        CLP();
        CHP();
        break;
        }
      case 1: {// 1V 
       HP();
       MP();
       LN();
       CLP();
       CHP();
        break;
        }
      case -1: {//-1V
       HN();
       MN();
       LP();
       CLP();
       CHP();
        break;
        }
      case 2: {// 1v+sc1
        HP();
        MP();
        LN();
        CLS();
        CHP();
        break;
        } 
      case -2: {// -1+sc1
        HN();
        MN();
        LP();
        CLS();
        CHP();
        break;
        } 
      case 3: { //3v 
       HN();
       MP();
       LP();
       CLP();
       CHP();
        break;
        }
      case -3: { //-3v 
       HP();
       MN();
       LN();
       CLP();
       CHP();
        break;
        }
      case 4: {// 3V+1V;
       HP();
       MP();
       LP();
       CLP();
       CHP();
        break;
        }
      case -4: {// -3V-1v
       HN();
       MN();
       LN();
       CLP();
       CHP();
        break;
        }
      case 5 :  { // 3V+1V+sc1 
       HP();
       MP();
       LP();
       CLS();
       CHP();
        break;
        }
      case -5 :  { // -3V-1V+sc1 
       HN();
       MN();
       LN();
       CLS();
       CHP();
        break;
        }
      case 6 :  { // 3V+sc2  b11,b21,b31 
        
        HN();
        MP();
        LP();
        CLP();
        CHS();
        break;
        }
      case -6 :  { // -3V+sc2  b11,b21,b31 
        
        HP();
        MN();
        LN();
        CLP();
        CHS();
        break;
        }
      case 7 :  { // +3V+sc2+1v
        
        HP();
        MP();
        LP();
        CLP();
        CHS();
        break;
        }
      case -7 :  { // -3V+sc2-1v
        
        HN();
        MN();
        LN();
        CLP();
        CHS();
        break;
        }
      case 8 :  { // 3V+sc2+1v+sc1 
        
        HP();
        MP();
        LP();
        CLS();
        CHS();
        break;
        }
      case -8 :  { // -3V+sc2-1V+sc1 
        
        HN();
        MN();
        LN();
        CLS();
        CHS();
        break;
        }
  }
  
 }
void loop() {
  int i ;
  // put your main code here, to run repeatedly:
  // led_inbuild on
  digitalWrite(led,HIGH);
 /* // debug purpose
  // char d = "7"; //debug
 while(1)
  {
  for(i=-8;i<=8;i++)
  {
    Serial.print("input : \n");
    Serial.println(i);
    delay(10);
    voltage_level(i);   
    }   // end of if
    
    
  }
  */ //end of debug
  while(1)
  {digitalWrite(10,HIGH);
      for(i=-8;i<=8;i++){ //= not needed
        voltage_level(i);
        delayMicroseconds(580); //580 trail and error
        //delay(10);
      }
   digitalWrite(10,LOW);
      for(i=8;i>=-8;i--){
        voltage_level(i);
        delayMicroseconds(580);
       // delay(10);
      }  
  } //*/ 
}
