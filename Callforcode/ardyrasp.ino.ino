int LDRPin = 0;
int valor;

int min = 0;
int max = 1023;

int boton = 8;

void setup () {
      Serial.begin(9600);
      pinMode( boton, INPUT );
}

void loop () {
      if(Serial.available()) {
            char c = Serial.read();
            if (c=='B') {
                  valor = digitalRead(boton);
                  if (valor == 0) {
                        Serial.println("Boton no pulsado");
                  } else {
                        Serial.println("Boton pulsado");
                  }
            } else if (c=='L') {
                  valor = analogRead(LDRPin);
                  valor = map(valor, min, max, 0, 100);
                  Serial.println(valor);
            } else if (c=='P') {
                  Serial.println(analogRead(1));
            }
      }
}
