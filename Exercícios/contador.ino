void setup() {
  Serial.begin(9600);
}


void loop() {

 
   for(int i=0; i<=10; i++)
  {
    if (i % 2 == 0){
      Serial.println(i);
      delay(1000); 
    }

  }

  int i= 9;

  while (i!=0)
  {
    if (i % 2 == 0){
      Serial.println(i);
      delay(1000);
    }

    i--;
  }

  for(int i=0; i<=10; i++)
  {
    if (i % 2 != 0){
      Serial.println(i);
      delay(1000);
    }

  }

 int n= 7;

  while (n!=0)
  {
    if (n % 2 != 0){
      Serial.println(n);
      delay(1000);
    }

    n--;
  }
}

   

