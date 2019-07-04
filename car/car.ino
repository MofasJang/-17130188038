void setup() {
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);// opens serial port, sets data rate to 9600 bps
}
int income=0;
void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    income = Serial.read();
    switch(income){
      case 'f':forward(); break;
        case 'b':backward(); break;
        case 'l':left(); break;
        case 'r':right();  break;
        case 's':stop(); break;
        default: break;
    }
    
  }
}
void forward(){
  digitalWrite(13,LOW);//13端口为左转向灯
  digitalWrite(12,LOW);//12端口为左转向灯
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
void backward(){
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}

void left(){
  digitalWrite(12,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  while(Serial.available() == 0){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);  }
  
 

}
void right(){
  digitalWrite(13,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  while(Serial.available() == 0){
    digitalWrite(12,HIGH);
    delay(500);
  digitalWrite(12,LOW);
    delay(500);  }
  
}
void stop(){
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
}
