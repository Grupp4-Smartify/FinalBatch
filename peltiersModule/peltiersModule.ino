int relayPin = 8;
int potPin = A1;
int tempPin = A0;
float tempVal = 0;
int potVal = 0;
int potRes = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
  pinMode(potPin,INPUT);
  pinMode(tempPin,INPUT);

  digitalWrite(relayPin,LOW);
}

void loop() {
    potRead();
    tempRead();
    potRes = map(potVal, 0, 1023, 20, 60);

    Serial.print("Temp: ");
    Serial.print(tempVal);
    Serial.print(", RealPot: ");
    Serial.print(potRes);
    Serial.print(", Pot: ");
    Serial.println(potVal);

    if(potRes<tempVal){
      digitalWrite(relayPin,HIGH);      
    }else{
      digitalWrite(relayPin,LOW);      
    }

    delay(200);
}
