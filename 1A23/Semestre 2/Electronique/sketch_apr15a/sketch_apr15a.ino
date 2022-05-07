const int ledR = 12;
const int ledG = 8;
const int buttonR = 13;
const int buttonG = 7;
char BYTE;

void setup()
{
  pinMode(ledR ,OUTPUT);
  pinMode(ledG ,OUTPUT);
  pinMode(buttonR , INPUT_PULLUP);
  pinMode(buttonG , INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  BYTE = Serial.read();
  if(digitalRead(buttonR) == LOW && BYTE == '1'){
    digitalWrite(ledR, HIGH);
  }else if(digitalRead(buttonG) == LOW && BYTE == '2'){
    digitalWrite(ledG, HIGH);
  }else if(BYTE == '0' && digitalRead(buttonR) == HIGH && digitalRead(buttonG) == HIGH){
    digitalWrite(ledR, LOW);
  }
}
