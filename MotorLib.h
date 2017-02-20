#ifndef MotorLib_h
#define MotorLib_h

#include <Arduino.h>
//#include <WProgram.h>

class Motor {
  private:
    int motorSpeed;
    byte pinA, pinB;
    void runMotor();

  public:
    Motor(byte pin1, byte pin2);
    void brakeMotor();
    void coastMotor();
    void setMotorSpeed(int s);
};
#endif
