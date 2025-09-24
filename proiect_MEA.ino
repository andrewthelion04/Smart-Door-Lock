#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Inițializează LCD-ul (adresa 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inițializează servomotoarele
Servo servoLatch;    // Servo de tip rotație continuă pentru încuietoare
Servo servoDoor;     // Servo normal pentru ușă

void setup() {
  // Atașează servourile la pini
  servoLatch.attach(9);
  servoDoor.attach(10);

  // Inițializează LCD-ul
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // Pasul 1: Afișare countdown
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door opening in:");

  for (int i = 5; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("      "); // șterge linia de jos
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(1000);
  }

  // Pasul 2: Deschide latch-ul
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Unlocking latch");

  servoLatch.write(0);  // Rotește într-un sens
  delay(300);           // Rotește 0.6 secunde
  servoLatch.write(90); // Oprește servo-ul

  delay(2000);          // Așteaptă 2 secunde

  // Pasul 3: Deschide ușa
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Opening door");

  servoDoor.write(80);   // Poziție inițială (ușa deschisă)
  delay(3000);          // Așteaptă cât timp se deschide
  servoDoor.write(90);   // Poziție inițială (ușa deschisă)

  delay(2000);

  // ✅ Nou: închidere ușă invers
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Closing door");

  servoDoor.write(100); // Învârte invers pentru închidere
  delay(3000);          // Așteaptă să se închidă
  servoDoor.write(90);  // Oprește servo-ul

  delay(2000);          // Pauză mică

  // ✅ Nou: închidere latch invers
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Locking latch");

  servoLatch.write(180);  // Rotește înapoi latch-ul
  delay(300);             // Același timp ca la deschidere
  servoLatch.write(90);   // Oprește latch-ul

  delay(2000);            // Pauză

  // Pasul final: afișează mesaj de ciclu complet
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cycle complete");

  delay(2000);            // Așteaptă 2 secunde

  return 0;
  // Ciclul reîncepe automat
}
