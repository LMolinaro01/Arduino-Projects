int Estado;
int Vm = 7;
int Am = 6;
int Vd = 5;
int T;

void setup()
{
  pinMode(11,INPUT);
  pinMode(Vm,OUTPUT);
  pinMode(Am,OUTPUT);
  pinMode(Vd,OUTPUT);

  T = millis();
  Estado = 0;
  
  Serial.begin(9600);
  
}

void loop()
{
  	if (Estado == 0 && ((millis()-T)>=3000)) {Estado =1; T = millis();}
  	if (Estado == 1 && (((millis()-T)>=1000) || digitalRead(11))) {Estado = 2; T = millis();}
  	if (Estado == 2 && ((millis()-T)>=1000)) {Estado =3; T = millis();}
  	if (Estado == 3 && ((millis()-T)>=500)) {Estado =0; T = millis();}

    if(Estado == 0){
      digitalWrite(Am, LOW);
      digitalWrite(Vm, HIGH);
    }

    if(Estado == 1){
      digitalWrite(Vm, LOW);
      digitalWrite(Vd, HIGH);
    }                               

    if(Estado == 2){
      digitalWrite(Vm, LOW);
      digitalWrite(Vd, HIGH);
    }

    if(Estado == 3){
      digitalWrite(Vd, LOW);
      digitalWrite(Am, HIGH);
    }                               
}
