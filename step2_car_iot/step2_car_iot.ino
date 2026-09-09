#include "thingProperties.h"
#include "AFMotor_R4.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int speed1 = 100;
int speed2 = 100;

void setup() {

  Serial.begin(9600);
  delay(1500); 
  initProperties();
  
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);

  message = "Ready";
}

void loop() {
  ArduinoCloud.update();
}

void onMessageChange()  {
  Serial.print("Message from Arduino Cloud: ");
  Serial.println(message);

  if (message == "Hello"){
    message = "Hi!, Hello from Arduino";
  }

  else if (message == "A")
  {
    Serial.println("Go to A Point");
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    delay(1000);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    Serial.println("Reaching A Point!");
  }
}