int pin=13;
int incomingByte = 0; 
void setup() {
  pinMode(pin,OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
void Trans(int a);
void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    // say what you got:
    Trans(incomingByte);
  }
}

void c_space();
void s_space();
void w_space();
void dot();
void dash();

void Trans(int a)
{
  switch(a){
    case 'a':dot(); dash(); break;
    case 'b':dash();dot();dot();dot();break;
    case 'c':dash();dot();dash();dot();break;
    case 'd':dash();dot();dot();break;
    case 'e':dot();break;
    case 'f':dot();dot();dash();dot();break;
    case 'g':dash();dash();dot();break;
    case 'h':dot();dot();dot();dot();break;
    case 'i':dot();dot();break; 
    case 'j':dot();dash();dash();dash();break;
    case 'k':dash();dot();dash();break;
    case 'l':dot();dash();dot();dot();break;
    case 'm':dash();dash();break;
    case 'n':dash();dot();break;
    case 'o':dash();dash();dash();break;
    case 'p':dot();dash();dash();dot();break;
    case 'q':dash();dash();dot();dash();break;
    case 'r':dot();dash();dot();break;
    case 's':dot();dot();dot();break;
    case 't':dash();break;
    case 'u':dot();dot();dash();break;
    case 'v':dot();dot();dot();dash();break;
    case 'w':dot();dash();dash();break;
    case 'x':dash();dot();dot();dash();break;
    case 'y':dash();dot();dash();dash();break;
    case 'z':dash();dash();dot();dot();break;
    case ' ':w_space();break;
    case '\n':s_space();break;
  }
  c_space();
}

void c_space()
{
  digitalWrite(pin,LOW);
  delay(750);
}

void s_space()
{
  digitalWrite(pin,LOW);
  delay(2500);
}

void w_space()
{
  digitalWrite(pin,LOW);
  delay(1750);
}

void dot()
{
  digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(250);
}

void dash()
{
  digitalWrite(pin,HIGH);
  delay(750);
  digitalWrite(pin,LOW);
  delay(250);
}
