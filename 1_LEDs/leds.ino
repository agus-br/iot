
bool on = false;

const int led_10_sec = 2;
const int led_8_sec = 4;
const int led_5_sec = 7;
const int led_2_sec = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led_10_sec, OUTPUT);
  pinMode(led_8_sec, OUTPUT);
  pinMode(led_5_sec, OUTPUT);
  pinMode(led_2_sec, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'a')
      on = true;
    //digitalWrite(a, HIGH);

    if (c == 'b')
      on = false;
    //digitalWrite(a, LOW);
  }

  if (on) {
    digitalWrite(led_10_sec, HIGH);

    delay(2000);
    digitalWrite(led_8_sec, HIGH);
    digitalWrite(led_2_sec, HIGH);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(1000);
    digitalWrite(led_5_sec, HIGH);

    delay(1000);
    digitalWrite(led_2_sec, HIGH);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);  // Here has been 10 secons
    digitalWrite(led_10_sec, LOW);
    digitalWrite(led_8_sec, LOW);
    digitalWrite(led_5_sec, LOW);
    digitalWrite(led_2_sec, HIGH);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);
    digitalWrite(led_2_sec, HIGH);

    delay(1000);
    digitalWrite(led_5_sec, HIGH);

    delay(1000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);
    digitalWrite(led_8_sec, HIGH);

    delay(2000);  //20
    digitalWrite(led_2_sec, HIGH);
    digitalWrite(led_10_sec, HIGH);
    digitalWrite(led_5_sec, LOW);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);
    digitalWrite(led_2_sec, HIGH);
    digitalWrite(led_8_sec, LOW);

    delay(1000);
    digitalWrite(led_5_sec, LOW);

    delay(1000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);
    digitalWrite(led_2_sec, HIGH);

    delay(2000);  // 30
    digitalWrite(led_2_sec, HIGH);
    digitalWrite(led_10_sec, LOW);

    delay(2000);
    digitalWrite(led_2_sec, HIGH);
    digitalWrite(led_8_sec, HIGH);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(1000);
    digitalWrite(led_5_sec, HIGH);

    delay(1000);
    digitalWrite(led_2_sec, HIGH);

    delay(2000);
    digitalWrite(led_2_sec, LOW);

    delay(2000);  // 40
    digitalWrite(led_10_sec, HIGH);
    digitalWrite(led_8_sec, LOW);
    digitalWrite(led_5_sec, LOW);
    digitalWrite(led_2_sec, HIGH);
  }
}
