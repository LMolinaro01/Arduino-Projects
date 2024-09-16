//sistema com eventos discretos

int Estado;
int BotaoLiga = 3;
int BotaoDesliga = 4;
int Ldr = A0;
int valorldr = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(BotaoLiga, INPUT);
  pinMode(BotaoDesliga, INPUT);
  pinMode (Ldr, INPUT);
  
  Serial.begin(9600);
  
  Estado = 1; //Módulo de Inicialização
}

void loop()
{
  	valorldr = analogRead(Ldr);
  	
  	Serial.print("Valor lido pelo LDR = ");
   	Serial.println(valorldr);
  
    //Módulo dinâmico
  	if (Estado == 1 && valorldr <= 200){Estado = 2;}
  	if (Estado == 2 && valorldr >= 200){Estado = 1;}
  	if (Estado == 1 && digitalRead(BotaoLiga)){Estado = 3;}
  	if (Estado == 3 && digitalRead(BotaoDesliga)){Estado = 1;}
  
    //Módulo de Ações
	if (Estado == 2) {digitalWrite(2, HIGH);}
  	if (Estado == 1) {digitalWrite(2, LOW);}
  	if (Estado == 3) {digitalWrite(2, HIGH);}
                                    
}