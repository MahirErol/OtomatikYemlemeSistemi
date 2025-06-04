#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <RTClib.h>

// Parçalar
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C adresi 0x27 olabilir
Servo servo;
RTC_DS3231 rtc;

// Pin tanımları
#define TRIG_PIN 9
#define ECHO_PIN 8
#define BUZZER_PIN 7
#define SERVO_PIN 6

// Zamanlama
unsigned long previousMillis = 0;
const long interval = 10000; // 10 saniye

int feedCount = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Otomatik Yemleme");
  delay(2000);
  lcd.clear();

  // Servo
  servo.attach(SERVO_PIN);
  servo.write(0);

  // HC-SR04
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // RTC
  if (!rtc.begin()) {
    lcd.print("RTC bulunamadi!");
    while (1);
  }
/*
  if (rtc.lostPower()) {
    DateTime now = DateTime(F(_DATE), F(TIME_));
    now = now + TimeSpan(3 * 3600); // Türkiye için düzeltme
    rtc.adjust(now);
  }*/
}

void loop() {
  unsigned long currentMillis = millis();

  // Yemleme zamanı geldiyse
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Yem Veriliyor...");
    feedFish(); // Servo hareketi
    feedCount++;
    delay(2000); // Mesaj görünsün
  }

  // Mesafe ölç
  long distance = getDistance();

  if (distance > 12) {
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Yem Bitti !");
    delay(2000);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  updateLCD();
  delay(200);
}

void feedFish() {
  servo.write(70);
  delay(300);
  servo.write(0);
}

void updateLCD() {
  DateTime now = rtc.now();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(now.hour() < 10 ? "0" : ""); lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute() < 10 ? "0" : ""); lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second() < 10 ? "0" : ""); lcd.print(now.second());

  lcd.setCursor(0, 1);
  lcd.print("Yemler: ");
  lcd.print(feedCount);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}