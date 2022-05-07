const int ledR = 13;
const int ledG = 12;
const int button1 = 11;
const int button2 = 10;
char BYTE;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  BYTE = Serial.read();
  if(digitalRead(button1) == LOW && BYTE == '1'){
    if(digitalRead(ledG) == LOW)
      Serial.println("Led-Green activated!\n");
    digitalWrite(ledG, HIGH);
  }else if(digitalRead(button2) == LOW && BYTE == '2'){
    if(digitalRead(ledR) == LOW)
      Serial.println("Led-Red activated!\n");
    digitalWrite(ledR, HIGH);
  }else if(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && BYTE == '0'){
    if(digitalRead(ledR) == HIGH && digitalRead(ledG) == HIGH)
      Serial.println("Led-Red & Led-Green desactivated\n");
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
  }
}
