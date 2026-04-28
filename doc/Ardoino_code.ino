const int button1 = 6;
const int button2 = 8;

const int led1 = 5;
const int led2 = 7;

unsigned long startZeit;
bool spielLaeuft = false;

void setup() {
  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  
}

void loop() {


  if (!spielLaeuft) {
    if (digitalRead(button1) == LOW || 
    digitalRead(button2) == LOW) {

      Serial.println("Spiel startet!");
      for (int i = 0; i < 4; i++) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(250);

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        delay(250);
      }



      delay(random(1500,6000));

    
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);


      startZeit = millis();
      spielLaeuft = true;
    }
  }

  if (spielLaeuft && digitalRead(button1) == LOW) {

    unsigned long zeit = millis() - startZeit;

    Serial.print("Spieler 1 gewinnt! Zeit: ");
    Serial.print(zeit);
    Serial.println(" ms");

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    spielLaeuft = false;

    Serial.println("Zum Neustarten Button drücken.");
    delay(2000);
  }

  if (spielLaeuft && digitalRead(button2) == LOW) {

    unsigned long zeit = millis() - startZeit;

    Serial.print("Spieler 2 gewinnt! Zeit: ");
    Serial.print(zeit);
    Serial.println(" ms");

    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);

    spielLaeuft = false;

    Serial.println("Zum Neustarten bitte Button drücken.");
    delay(2000);
  }
}