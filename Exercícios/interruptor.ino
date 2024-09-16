bool botaoNaoFoiSolto = false;
bool ledAceso = false;

void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  bool botao = digitalRead(3);

  if (botao){
    if (ledAceso && !botaoNaoFoiSolto){
      digitalWrite(6, LOW);
      ledAceso = false;
      delay(1000);
    }
    if (!ledAceso && !botaoNaoFoiSolto){
      digitalWrite(6, HIGH);
      ledAceso = true;
      delay(1000);
    }
    botaoNaoFoiSolto = true;
  }
  else{
    botaoNaoFoiSolto = false;
  }

}
