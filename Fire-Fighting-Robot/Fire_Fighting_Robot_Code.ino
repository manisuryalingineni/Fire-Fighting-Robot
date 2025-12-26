/* FIRE FIGHTING ROBOT CODE */ 
#define FLAME_SENSOR_1 2 //PIN 2 
#define FLAME_SENSOR_2 8 //PIN 8 
#define FLAME_SENSOR_3 12 //PIN 12 
#define ENA 9 
#define IN1 3 
#define IN2 4 
#define IN3 5 
#define IN4 6 
#define ENB 10 
#define relay 13 
int speed = 105; 
void setup() 
{ 
pinMode(FLAME_SENSOR_1, INPUT); 
pinMode(FLAME_SENSOR_2, INPUT); 
pinMode(FLAME_SENSOR_3, INPUT); 
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
pinMode(relay,OUTPUT); 
pinMode(ENA, OUTPUT); 
pinMode(ENB, OUTPUT); 
digitalWrite(relay,LOW); 
Serial.begin(9600); 
} 

void loop() 
{ 
int flame_detected_Center = digitalRead(FLAME_SENSOR_1); 
int flame_detected_Left = digitalRead(FLAME_SENSOR_2); 
int flame_detected_Right = digitalRead(FLAME_SENSOR_3); 
if (flame_detected_Center == HIGH &&flame_detected_Left == HIGH 
&&flame_detected_Right == HIGH) 
{ 
Serial.println("No Fire detected! moving robot.."); 
moveForward(); 
} 
if(flame_detected_Center == LOW &&flame_detected_Left == HIGH 
&&flame_detected_Right == HIGH) 
{ 
Serial.println("fire detected. stop robot..."); 
stopRobot(); 
digitalWrite(relay,HIGH); 
delay(5000); 
digitalWrite(relay,LOW); 
} 
if(flame_detected_Left == LOW &&flame_detected_Center == HIGH 
&&flame_detected_Right == HIGH) 
{ 
Serial.println("fire detected. Moving left..."); 
stopRobot(); 
delay(1000); 
moveLeft(); 
delay(1000); 
stopRobot(); 
delay(5000); 
digitalWrite(relay,HIGH); 
delay(5000); 
digitalWrite(relay,LOW); 
moveRight(); 

delay(1000); 
stopRobot(); 
delay(500); 
} 
if(flame_detected_Right == LOW &&flame_detected_Center == HIGH 
&&flame_detected_Left == HIGH) 
{ 
Serial.println("fire detected. Moving right..."); 
stopRobot(); 
delay(1000); 
moveRight(); 
delay(2000); 
stopRobot(); 
delay(5000); 
digitalWrite(relay,HIGH); 
delay(5000); 
digitalWrite(relay,LOW); 
moveLeft(); 
delay(2000); 
stopRobot(); 
delay(500); 
} 
delay(300); // Short delay for stability 
} 
void moveForward() 
{ 
analogWrite(ENA , speed); 
analogWrite(ENB , speed); 
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW); 
} 

void moveBackward() 
{ 
analogWrite(ENA , speed); 
analogWrite(ENB , speed); 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH); 
} 
void stopRobot() 
{ 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW); 
} 
void moveLeft() 
{ 
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH); 
} 
void moveRight() 
{ 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4,LOW); 
}