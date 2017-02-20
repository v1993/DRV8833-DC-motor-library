/*
   pinA и pinB - это пины, задающие направление вращения. Условно примем, что pinA задаёт вращение по часовой стрелке.
*/
#include <MotorLib.h>

Motor::Motor (byte pin1, byte pin2)
{
  pinA = pin1;
  pinB = pin2;
  pinMode ((pinA, pinB), OUTPUT);
  digitalWrite ((pinA, pinB), LOW);
  //motorSpeed = 0;
}

void Motor::brakeMotor()
{
  digitalWrite ((pinA, pinB), HIGH);
}

void Motor::coastMotor()
{
  digitalWrite ((pinA, pinB), LOW);
  }

void Motor::runMotor()
{
  if (motorSpeed == 0)
    brakeMotor();
  else if (motorSpeed > 0)
  {
    digitalWrite (pinA, LOW);
    analogWrite (pinB, motorSpeed);
  }
  else if (motorSpeed < 0)
  {
    digitalWrite (pinB, LOW);
    analogWrite (pinA, abs(motorSpeed));
  }
}

void Motor::setMotorSpeed(int s)
{
  motorSpeed = s;
  if ((motorSpeed >= -255) && (motorSpeed <= 255))
    runMotor();
  else
  {
    constrain (motorSpeed, -255, 255);
    runMotor();
  }
}
