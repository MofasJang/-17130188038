
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
  if(Serial.available()>0){
    income=Serial.read();
    digitalWrite(6,LOW);
  delay(20);
  digitalWrite(5,BCD(income,3));
  digitalWrite(4,BCD(income,2));
  digitalWrite(3,BCD(income,1));
  digitalWrite(2,BCD(income,0));
  delay(20);
  digitalWrite(6,HIGH);
  delay(20);
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
