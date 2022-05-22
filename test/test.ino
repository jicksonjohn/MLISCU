const int b11=0,b12=1,b21=2,b22=3,b31=4,b32=5,clp=6,cls=7,chp=8,chs=9,led = LED_BUILTIN;
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
  
}

void loop() {
  int i ;
  // put your main code here, to run repeatedly:
  // led_inbuild on
  digitalWrite(led,HIGH);
  for(i=0;i<10;i++)
  {
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    delay(500);
  } 
}
