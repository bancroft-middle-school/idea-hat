
long oldPosition  = -999;
long newPosition = 0;

int readMotor(){
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    return newPosition;
  }
}


void motorAttach(){
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);
}

void motorWrite(int value) {
  analogWrite(pwmPin, motorSpeed);
  Serial.println( readMotor() );
  
  if (readMotor() < value) {

  digitalWrite(forwardPin, HIGH);
  digitalWrite(backwardPin, LOW);
  } 
  else if (readMotor() > value) {

  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, HIGH);
  }
  else {
   digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, LOW);
  }
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      motorWrite(150);
      delay(25);
  }
}



