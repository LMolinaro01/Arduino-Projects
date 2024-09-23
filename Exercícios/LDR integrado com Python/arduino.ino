int Ldr = A0;
int valorldr;

void setup() {
  Serial.begin(9600);
  pinMode(Ldr, INPUT);
}

void loop() {
  delay(500);
  
  // Lê o valor do LDR (0 a 1023)
  valorldr = analogRead(Ldr);
  	
  // Envia o valor em dois bytes (int16)
  Serial.write(highByte(valorldr));  // Envia o byte mais significativo
  Serial.write(lowByte(valorldr));   // Envia o byte menos significativo

  delay(500);
}
