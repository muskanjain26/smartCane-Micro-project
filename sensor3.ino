#define trigPin3 7
#define echoPin3 6  //left
#define trigPin2 3
#define echoPin2 4  //middle
#define trigPin1 9
#define echoPin1 8 //right
#define buzzer 13

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() 
{
long duration1, duration2, duration3, distance1 , distance2, distance3;

digitalWrite(trigPin1, LOW); 
delayMicroseconds(2); 

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); 

digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH); //right


digitalWrite(trigPin2, LOW); 
delayMicroseconds(2); 

digitalWrite(trigPin2, HIGH);
delayMicroseconds(10); 

digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH); //middle

digitalWrite(trigPin3, LOW); 
delayMicroseconds(2); 

digitalWrite(trigPin3, HIGH);
delayMicroseconds(10); 

digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH); //left

distance1 = (duration1/2) / 29.1;
distance2 = (duration2/2) / 29.1;
distance3 = (duration3/2) / 29.1;

Serial.write(distance1);


if (distance1 < 10 )
{

tone(buzzer, 450, 50);

digitalWrite(buzzer,HIGH);

} else
{
  digitalWrite(buzzer,LOW);
}
delay(500);

if (distance2 < 100 and distance2>50 )
{

tone(buzzer, 100, 100);

digitalWrite(buzzer,HIGH);

}

else

if (distance2 < 50 and distance2>30 )
{

tone(buzzer, 500, 500);

digitalWrite(buzzer,HIGH);

}

else

if (distance2 < 30 )
{

tone(buzzer, 1000, 1000);

digitalWrite(buzzer,HIGH);

} else
{
  digitalWrite(buzzer,LOW);
}
delay(500);


if (distance3 < 10 )
{

tone(buzzer, 850, 100);

digitalWrite(buzzer,HIGH);

} else
{
  digitalWrite(buzzer,LOW);
}

delay(500);
}
