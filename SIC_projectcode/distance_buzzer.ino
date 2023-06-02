#define BUZZER_PIN1 3
#define BUZZER_PIN2 2

#define echoPin1 7
#define trigPin1 6
#define echoPin2 8
#define trigPin2 9

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN1, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(BUZZER_PIN2, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  Serial.println(Ultrasonic_1());
  int cm_1 = Ultrasonic_1();
  int cm_2 = Ultrasonic_2();
  //เงื่อนไขbuzzerตัวที่1
  if (cm_1 < 60 && cm_1 != 0) {     //เมื่อวัตถเข้าใกลสียงเตือนดังถี่ขึ้น
    digitalWrite(BUZZER_PIN1, HIGH);  //ปิดเสียงเตือน
    delay(cm_1 * 16);
    digitalWrite(BUZZER_PIN1, LOW);   //เปิดเสียงเตือน
    delay(cm_1 * 16);
  }
  else {                              //เมื่อห่างมากกว่า 60 cm จะไม่มีเสียง
    digitalWrite(BUZZER_PIN1, LOW);   //ปิดเสียงเตือน
    delay(500); 
  }
//เงื่อนไขbuzzerตัวที่2
  if (cm_2 < 60 && cm_2 != 0) {     //เมื่อวัตถเข้าใกลสียงเตือนดังถี่ขึ้น
    digitalWrite(BUZZER_PIN2, HIGH);  //ปิดเสียงเตือน
    delay(cm_2 * 16);
    digitalWrite(BUZZER_PIN2, LOW);   //เปิดเสียงเตือน
    delay(cm_2 * 16);
  }
  else {                              //เมื่อห่างมากกว่า 60 cm จะไม่มีเสียง
    digitalWrite(BUZZER_PIN2, LOW);   //ปิดเสียงเตือน
    delay(500); 
  }
}
//ฟังชั่นอัลตร้าโซนิกตัวที่ 1 
int Ultrasonic_1() {
  long duration, distance;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration / 58.2;
  return distance;
}
//ฟังชั่นอัลตร้าโซนิกตัวที่ 2
int Ultrasonic_2() {
  long duration, distance;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration / 58.2;
  return distance;
}
