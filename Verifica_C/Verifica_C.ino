int rosso = 11;
int giallo = 10;
int blu = 9;
int verde = 8;
  
int durata = 0;   //variabile del tempo di accensione

void setup() {
  // put your setup code here, to run once:
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (8, OUTPUT);

  Serial.begin(9600);

  richiediValori();
}

void loop() {
  // put your main code here, to run repeatedly:
  //accendo il rosso e spengo il verde perchè alla fine del loop il verde è acceso e quindi mettendolo qui si spegne e contemporaneamte il rosso si accende
  digitalWrite(verde, LOW);
  digitalWrite(rosso, HIGH);
  delay(durata);
  
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, HIGH);
  delay(durata*2);
  
  digitalWrite(giallo, LOW);
  digitalWrite(blu, HIGH);
  delay(durata);
  
  digitalWrite(blu, LOW);
  digitalWrite(verde, HIGH);
  delay(durata*3);
}

void richiediValori()
{
  Serial.println("Quanti secondi devono rimanere accesi i led? Il rosso e il blu stanno accessi per il tempo scelto ma il giallo e il verde stanno accessi corrispettivamente il doppio e il triplo del tempo scelto");
  while (Serial.available() == 0) {};
  durata = Serial.readString().toInt()*1000;  //moltiplico per mille così all'utente batsa inserire il numero di secondi desiderati
}
