/** Encabezado:
 * @file main.ino
 * @brief Código de Arduino del Sonar
 * @author [Victor Caro Pastor](https://github.com/Vicaro1)
 * @version  V1.3
 * @date  28-08-2024
*/
// Añadir la libreria del servo
#include <Servo.h>. 

// Define los pines Tirg y Echo del Sensor Ultrasónico
const int trigPin = 10;
const int echoPin = 11;

// Variables para la duración y la distancia
long duracion;
int distancia;

// Crea un objeto servo para controlar el servomotor
Servo miServo; 

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNCIONES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Función para calcular la distancia medida por el sensor Ultrasónico
int calculateDistance()
{
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2);
 // Poner el trigPin en estado HIGH durante 10 microsegundos
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Leee el echoPin, devuelve el tiempo de viaje de la onda sonora en microsegundos
 duracion = pulseIn(echoPin, HIGH); 
 distancia= duracion*0.034/2;
 return distanciq;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() 
{
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 Serial.begin(9600);
 myServo.attach(12);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() 
{
  // gira el servomotor de 15 a 165 grados
  for(int i=15;i<=165;i++)
  {  
  miServo.write(i);
  delay(30);
  
  // Llama a una función para calcular la distancia medida por el sensor Ultrasónico para cada grado
  distance = calculateDistance();
  
  Serial.print(i);         // Envía el grado actual al Puerto Serie
  Serial.print(",");       // Envía el carácter de adición justo al lado del valor anterior necesario más tarde en el IDE de Processing para la indexación
  Serial.print(distancia); // Envía el valor de la distancia al Puerto Serie
  Serial.print(".");       // Envía el carácter de adición justo al lado del valor anterior necesario más tarde en el IDE de Processing para la indexación
  }
 
  // Repite las líneas anteriores de 165 a 15 grados
  for(int i=165;i>15;i--)
  {  
   miServo.write(i);
   delay(30);
   distance = calculateDistance();
   Serial.print(i);
   Serial.print(",");
   Serial.print(distancia);
   Serial.print(".");
  }
}
