int LMotor_1 = 9;
int LMotor_2 = 10;
int RMotor_1 = 5;
int RMotor_2 = 6;
int IR_RECEIVER = 17;


void setup() {

  pinMode(RMotor_1, OUTPUT);
  pinMode(LMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(LMotor_2, OUTPUT);

}

void loop() {
  int ldrcenter = digitalRead(16);
  int ldrright = digitalRead(15);
  int ldrleft = digitalRead(14);
  int R_OBST_SENSOR = digitalRead(18);
  int L_OBST_SENSOR = digitalRead(19);

if (R_OBST_SENSOR == LOW) {
  move_stop();
  delay(500);
  move_backward();
  delay(100);
  turn_right();
  delay(100);
} else if (L_OBST_SENSOR == LOW) {
  move_stop();
  delay(500);
  move_backward();
  delay(100);
  turn_left();
  delay(100);
} else {
  if (ldrright == LOW && ldrleft == HIGH && ldrcenter == HIGH) {
    move_forward();
    delay(100);
  }
  else if (ldrright == LOW && ldrleft == HIGH) {
    turn_right();
    delay(100);
  }
  else if (ldrright == HIGH && ldrleft == LOW) {
    turn_left();
    delay(100);
  }
  else if (ldrright == LOW && ldrleft == LOW && ldrcenter == LOW) {
    move_stop();
    digitalWrite(IR_RECEIVER, HIGH);
  } else {
    move_forward();
    delay(100);
  }
}
  delay(100);

}

void move_forward() {
  analogWrite(RMotor_2, 0);
  analogWrite(LMotor_2, 0);
  analogWrite(RMotor_1, 200);
  analogWrite(LMotor_1, 150);
}

void move_backward() {
  analogWrite(RMotor_1, 0);
  analogWrite(LMotor_1, 0);
  analogWrite(RMotor_2, 215);
  analogWrite(LMotor_2, 185);

}

void turn_right() {
  analogWrite(RMotor_2, 0);
  analogWrite(LMotor_1, 0);
  analogWrite(RMotor_1, 215);
  analogWrite(LMotor_2, 185);
}

void turn_left() {
  analogWrite(RMotor_1, 0);
  analogWrite(LMotor_2, 0);
  analogWrite(RMotor_2, 215);
  analogWrite(LMotor_1, 185);
  
}

void move_stop() {
  analogWrite(RMotor_1, 0);
  analogWrite(RMotor_2, 0);
  analogWrite(LMotor_1, 0);
  analogWrite(LMotor_2, 0);
}
