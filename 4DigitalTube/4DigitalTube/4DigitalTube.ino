int income=0;
int count=0;
int openpin;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
}
void loop()
{
  openpin=count+8;
  if(Serial.available()>0){
    income=Serial.read();
    digitalWrite(openpin,LOW);
  delay(20);
  digitalWrite(5,BCD(income,3));
  digitalWrite(4,BCD(income,2));
  digitalWrite(3,BCD(income,1));
  digitalWrite(2,BCD(income,0));
  delay(20);
  digitalWrite(openpin,HIGH);
  delay(20);
  count++;
  }
}
char BCD(int d,int n)
{
  if((d>>n)&1){
    return HIGH;
  }
  else{
    return LOW;
  }
}
