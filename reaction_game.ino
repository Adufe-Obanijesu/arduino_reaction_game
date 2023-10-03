int led1 = D1;
int led2 = D2;
int led3 = D3;
int led4 = D4;

int button1 = D5;
int button2 = D6;
int button3 = D7;
int button4 = D8;

int delayTime = 3000;
int score = 0;
int counterNumber = 0;

//int litLED;
int pressedButton = 0;

int toLightUp;
int toLightUpPin;

void setup() {
  // put your setup code here, to run once:

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(14), buttonOneInterrupt, FALLING);          // Initialize an interrupt for button. Pin 2 corresponds to value 0. Runs checkValidity function.
  attachInterrupt(digitalPinToInterrupt(12), buttonTwoInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(13), buttonThreeInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(15), buttonFourInterrupt, FALLING);

  Serial.begin(9600);
  Serial.println("Serial Monitor is on");

}

void loop() {
  // put your main code here, to run repeatedly:

  pressedButton = 0;

  toLightUp = random(1, 5);
  verifyPin(toLightUp);

  if(pressedButton != 0){
    Serial.println("Game Over!!!");
    Serial.print("Your final score is ");
    Serial.println(score);
    
    resetValues();
    
    // Stop function
  } else {
    digitalWrite(toLightUpPin, HIGH);
    
    delay(delayTime);
    
    if (pressedButton != toLightUp || pressedButton == 0) {
      Serial.println("Game Over!!!");
      Serial.print("Your final score is ");
      Serial.println(score);
      
      resetValues();

      //Stop function
    } else {
      score++;
      counterNumber++;
  
      Serial.print("Score is ");
      Serial.println(score);
  
      if (counterNumber % 10 == 0 && counterNumber % 5 == 0) {
        nextLevel();
      }
    }
  }

}

void verifyPin(int pin) {
  if (pin == 1) {
    toLightUpPin = D5;
  }
  if (pin == 2) {
    toLightUpPin = D6;
  }
  if (pin == 3) {
    toLightUpPin = D7;
  }
  if (pin == 4) {
    toLightUpPin = D8;
  }
}

void nextLevel() {
  delayTime = delayTime / 2;
}

void resetValues() {
  score = 0;
  counterNumber = 0;
  delayTime = 3000;
}


void buttonOneInterrupt() {
  delay(200);

  pressedButton = 1;
}

void buttonTwoInterrupt() {
  delay(200);

  pressedButton = 2;
}

void buttonThreeInterrupt() {
  delay(200);

  pressedButton = 3;
}

void buttonFourInterrupt() {
  delay(200);

  pressedButton = 4;
}
