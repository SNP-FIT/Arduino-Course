int led1Pin = 8;
int led2Pin = 9;
int led3Pin = 10;

int button1Pin = 7;
int button2Pin = 6;

int level = 0;  //0 - 3

int lastButton1State = 1;
int lastButton2State = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentButton2State = digitalRead(button2Pin);
  if (currentButton2State == 0 && lastButton2State == 1) {
    if (level < 3) {
      level++;
    }
  }
  int currentButton1State = digitalRead(button1Pin);
  if (currentButton1State == 0 && lastButton1State == 1) {
    if (level > 0) {
      level--;
    }
  }

  if(level == 0){
    digitalWrite(led1Pin , LOW);
    digitalWrite(led2Pin , LOW);
    digitalWrite(led3Pin , LOW);
  }else if(level == 1){
    digitalWrite(led1Pin , HIGH);
    digitalWrite(led2Pin , LOW);
    digitalWrite(led3Pin , LOW);
  }else if(level == 2){
    digitalWrite(led1Pin , HIGH);
    digitalWrite(led2Pin , HIGH);
    digitalWrite(led3Pin , LOW);
  }else{
    digitalWrite(led1Pin , HIGH);
    digitalWrite(led2Pin , HIGH);
    digitalWrite(led3Pin , HIGH);
  }

  Serial.println(level);
  lastButton1State = currentButton1State;
  lastButton2State = currentButton2State;
  delay(100);
}
