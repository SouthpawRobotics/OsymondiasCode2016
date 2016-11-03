#include "Main.h"

void Launcher ( void )
{
    upButton = GetJoystickDigital ( 2 , 5 , 2 ) ; 
    downButton = GetJoystickDigital ( 2 , 5 , 1 ) ; 
    onButton = GetJoystickDigital ( 2 , 6 , 2 ) ; 
    offButton = GetJoystickDigital ( 2 , 6 , 1 ) ; 
    if(onButton == 1){
        launcherState = 1;
    } else if (offButton == 1){
        launcherState = 0;
    }
    if(upButton == 1 && downButton != 1 && lastUpButton != 1){
        launcherSpeed = launcherSpeed + 1;
    } else if (upButton != 1 && downButton == 1 && lastDownButton != 1){
        launcherSpeed = launcherSpeed - 1;
    }
    lastUpButton = upButton;
    lastDownButton = downButton;
    if(launcherSpeed > 125) launcherSpeed = 125;
    if(launcherSpeed < 0) launcherSpeed = 0;
    if(launcherState == 1) {
        SetMotor ( 4 , launcherSpeed ) ; 
        SetMotor ( 5 , launcherSpeed ) ; 
        SetMotor ( 8 , launcherSpeed ) ; 
        SetMotor ( 7 , launcherSpeed * -1) ; 
    } else {
        SetMotor ( 4 , 0 ) ; 
        SetMotor ( 5 , 0 ) ; 
        SetMotor ( 8 , 0 ) ; 
        SetMotor ( 7 , 0 ) ;
    }
    SetLCDText ( 1 , 1 , "Teleop Enabled" , launcherState ) ; 
    SetLCDText ( 1 , 2 , "Speed = %d" , launcherSpeed ) ;
}




















