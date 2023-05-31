
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial serialDoBluetooth(8,9);

Servo servo_01;
//Servo servo_02;


// Declarar as váriaveis das válvulas e intervalos

int valve3 = 3;
int valve4 = 4;
int motor = 7;

int valorDoBluetooth;
bool onAction = false;

void setup() 
{
  
  serialDoBluetooth.begin(9600);

  servo_01.attach(6);
  //servo_02.attach(6);
  

  pinMode(valve3, OUTPUT);
  pinMode(valve4, OUTPUT);
  pinMode(motor, OUTPUT);

  digitalWrite(valve3, LOW);
  digitalWrite(valve4, LOW);
  digitalWrite(motor, LOW);
  
}

void loop() 
{

      if (serialDoBluetooth.available())
  
    {
      valorDoBluetooth = serialDoBluetooth.read();
    }

      if (valorDoBluetooth=='B')
      {
        onAction = true;
      }

      
      
   if (onAction)
  {
  
      servo_01.write(45);
      delay(2000);    
      servo_01.write(0);
    

      digitalWrite(motor, HIGH);
      delay(2000);
      digitalWrite(motor, LOW);
    
      //servo_02.write(45);
      //delay(2000);
    
      //servo_02.write(0);
    
      digitalWrite(valve3, HIGH);
      delay(2000);
      digitalWrite(valve3, LOW);
    
      digitalWrite(valve4, HIGH);
      delay(2000);
      digitalWrite(valve4, LOW);

      onAction = false;

      exit(0);
  }
 
}
