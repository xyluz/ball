/*
 * Load libraries, LiquidCrystal for LCD
 * Wire.h for ... no idea what its for, i saw it in a tutorial
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


int in1 = 11;

/*
 * Team B Related Configs
 * 1. Each Player Button, 5 players in total
 * 2. Player Button State Return Checker, to know what value to send to Max APP 
 * 3. Button State Checker to update the value of Button Stater Return
 * 4. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

#define playerA1Button 1  //player 1 button, send 1 to max
#define playerA2Button 2  //player 2 button, send 2 to max
#define playerA3Button 3  //player 3 button, send 3 to max
#define playerA4Button 4  //player 4 button, send 4 to max
#define playerA5Button 5  //player 5 button, send 5 to max

#define playerA1Led 6  //player 1 led, 
#define playerA2Led 7  //player 2 led, 
#define playerA3Led 8  //player 3 led, 
#define playerA4Led 9  //player 4 led, 
#define playerA5Led 10 //player 5 led, 

#define playerA1Relay 11  //player 1 relay, 
#define playerA2Relay 12 //player 2 relay, 
#define playerA3Relay 13  //player 3 relay, 
#define playerA4Relay 14  //player 4 relay, 
#define playerA5Relay 15 //player 5 relay, 

int playerA1State, playerA2State, playerA3State, playerA4State, playerA5State = 1;
int playerA1StateReturn, playerA2StateReturn, playerA3StateReturn, playerA4StateReturn, playerA5StateReturn = 1;

/*
 * Team B Related Configs
 * 1. Each Player Button, 5 players in total
 * 2. Player Button State Return Checker, to know what value to send to Max APP 
 * 3. Button State Checker to update the value of Button Stater Return
 * 4. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

#define playerB1Button 16  //player 6 button, send 6 to max
#define playerB2Button 17  //player 7 button, send 7 to max
#define playerB3Button 18  //player 8 button, send 8 to max
#define playerB4Button 19  //player 9 button, send 9 to max
#define playerB5Button 20  //player x button, send x to max

#define playerB1Led 21  //player 6 led, 
#define playerB2Led 22  //player 7 led, 
#define playerB3Led 23  //player 8 led, 
#define playerB4Led 24  //player 9 led, 
#define playerB5Led 25 //player 10 led, 

#define playerB1Relay 26  //player 1 relay, 
#define playerB2Relay 27 //player 2 relay, 
#define playerB3Relay 28  //player 3 relay, 
#define playerB4Relay 29  //player 4 relay, 
#define playerB5Relay 30 //player 5 relay, 

int playerB1State, playerB2State, playerB3State, playerB4State, playerB5State = 1;
int playerB1StateReturn, playerB2StateReturn, playerB3StateReturn, playerB4StateReturn, playerB5StateReturn = 1;

/*
 * Admin Related Configs
 * 1. Reset Button
 * 2. Correct Answer Button
 * 3. Wrong Answer Button
 * 4. Pause / Play CountDown Button
 * 5. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

#define resetButton 31  //reset game / timer button -- send r to max
#define correctButton 32  //when answer is correct -- sends c to max
#define wrongButton 33  //when answer is wrong -- send w to max
#define playButton 34  //when answer is wrong -- send b to max

#define resetLed 35 //reset led,

int resetState, correctState, wrongState, playState = 1; 
int resetStateReturn, wrongStateReturn, correctStateReturn, playStateReturn = 1;


void setup(){
/*
 * Admin Related Functionalities, Set Button Mode
 */
 
  pinMode(resetButton,INPUT); 
  pinMode(correctButton, INPUT); 
  pinMode(wrongButton, INPUT);
  pinMode(playButton, INPUT); 

  pinMode(resetLed, OUTPUT);

/*
 * Team A Button initialization
 */
  pinMode(playerA1Button, INPUT); 
  pinMode(playerA2Button, INPUT); 
  pinMode(playerA3Button, INPUT); 
  pinMode(playerA4Button, INPUT); 
  pinMode(playerA5Button, INPUT);

  pinMode(playerA1Led, OUTPUT);
  pinMode(playerA2Led, OUTPUT);
  pinMode(playerA3Led, OUTPUT);
  pinMode(playerA4Led, OUTPUT);
  pinMode(playerA5Led, OUTPUT);

  pinMode(playerA1Relay, OUTPUT);
  pinMode(playerA2Relay, OUTPUT);
  pinMode(playerA3Relay, OUTPUT);
  pinMode(playerA4Relay, OUTPUT);
  pinMode(playerA5Relay, OUTPUT);
   
/*
 * Team B Button initialization
 */
   pinMode(playerB1Button, INPUT); 
   pinMode(playerB2Button, INPUT); 
   pinMode(playerB3Button, INPUT); 
   pinMode(playerB4Button, INPUT); 
   pinMode(playerB5Button, INPUT); 
  
   pinMode(playerB1Led, OUTPUT);
   pinMode(playerB2Led, OUTPUT);
   pinMode(playerB3Led, OUTPUT);
   pinMode(playerB4Led, OUTPUT);
   pinMode(playerB5Led, OUTPUT);

   pinMode(playerB1Relay, OUTPUT);
   pinMode(playerB2Relay, OUTPUT);
   pinMode(playerB3Relay, OUTPUT);
   pinMode(playerB4Relay, OUTPUT);
   pinMode(playerB5Relay, OUTPUT);
  
  /*
   * 1. Initialize Serial
   * 2. Turn off all relay 
   * 3. Turn off all LED 
   * 4. Relay, HIGH IS LOW, LOW IS HIGH
   */
  Serial.begin(9600);

  digitalWrite(resetLed, LOW);
  
  digitalWrite(playerA1Led, LOW);
  digitalWrite(playerA2Led, LOW);
  digitalWrite(playerA3Led, LOW);
  digitalWrite(playerA4Led, LOW);
  digitalWrite(playerA5Led, LOW);

  digitalWrite(playerA1Relay, HIGH);
  digitalWrite(playerA2Relay, HIGH);
  digitalWrite(playerA3Relay, HIGH);
  digitalWrite(playerA4Relay, HIGH);
  digitalWrite(playerA5Relay, HIGH);
  
  digitalWrite(playerB1Led, LOW);
  digitalWrite(playerB2Led, LOW);
  digitalWrite(playerB3Led, LOW);
  digitalWrite(playerB4Led, LOW);
  digitalWrite(playerB5Led, LOW);

  digitalWrite(playerB1Relay, HIGH);
  digitalWrite(playerB2Relay, HIGH);
  digitalWrite(playerB3Relay, HIGH);
  digitalWrite(playerB4Relay, HIGH);
  digitalWrite(playerB5Relay, HIGH);
  

}

void loop(){
/*
 * Begin Program: check restart button state, if its not restarted, then print default
 */
 
resetState = digitalRead(resetButton);

if( resetState == 0 ){
  
  //reset button is pressed
  resetStateReturn = 0;  //Keep reset persistent until another button is pressed

  /*
   * Just to be sure, reset all buttons.
   * 1. Team A
   * 2. Team B
   * 3. Admin 
   * 4. Flash reset LED
   */
  
   playerA1State = 1; 
   playerA2State = 1; 
   playerA3State = 1; 
   playerA4State = 1; 
   playerA5State = 1; 

   playerA1StateReturn = 1; 
   playerA2StateReturn = 1;
   playerA3StateReturn = 1;
   playerA4StateReturn = 1;
   playerA5StateReturn = 1;
   
   playerB1State = 1; 
   playerB2State = 1; 
   playerB3State = 1; 
   playerB4State = 1; 
   playerB5State = 1; 
   
   
   playerB1StateReturn = 1;
   playerB2StateReturn = 1;
   playerB3StateReturn = 1; 
   playerB4StateReturn = 1;
   playerB5StateReturn = 1;
   
   correctStateReturn = 1; 
   wrongStateReturn = 1;
   playStateReturn = 1; 

   digitalWrite(resetLed, HIGH);
   
   delay(10); //added delay to make the thing stay up a bit
    
   Serial.println("r"); //sent to Max to show that reset button has been pressed

  }

if( resetState == 0 ){ //if game reset is done, it means the app is ready

    /*
     * Check player buttons, 
     * if any player pressed button, 
     * send the player number to max
     * and start checking for admin buttons
     * if any admin button is pressed, send appropriate code to max
     * 
     */
    /*
     * 
     * 1. Check if button state is not already read
     * 2. Read Team A button state if 1 is false
     * 3. Read Team B button state if 1 is false
     */

    if( playerA1StateReturn == 1 ){
      
        playerA1State = digitalRead(playerA1Button); 
        
      }else if( playerA2StateReturn == 1 ){

        playerA2State = digitalRead(playerA2Button); 
      
      }else if( playerA3StateReturn == 1 ){

        playerA3State = digitalRead(playerA3Button); 
      
      }else if( playerA4StateReturn == 1 ){

        playerA4State = digitalRead(playerA4Button); 
      
      }else if( playerA5StateReturn == 1 ){

        playerA5State = digitalRead(playerA5Button); 
      
      }else if( playerB1StateReturn == 1 ){

        playerB1State = digitalRead(playerB1Button); 
      
      }else if( playerB2StateReturn == 1 ){

        playerB2State = digitalRead(playerB2Button); 
      
      }else if( playerB3StateReturn == 1 ){

        playerB3State = digitalRead(playerB3Button); 
      
      }else if( playerB4StateReturn == 1 ){

        playerB4State = digitalRead(playerB4Button); 
      
      }else if( playerB5StateReturn == 1 ){

        playerB5State = digitalRead(playerB5Button); 
      
      } 
    

    if( playerA1State == 0 ){
      
        playerA1StateReturn = 0;
        
    }else if( playerA2State == 0 ){
      
        playerA2StateReturn = 0;
        
    }else if( playerA3State == 0 ){
      
        playerA3StateReturn = 0;
        
    }else if( playerA4State == 0 ){
      
        playerA4StateReturn = 0;
        
    }else if( playerA5State == 0 ){
      
        playerA5StateReturn = 0;
        
    }else if( playerB1State == 0 ){
      
        playerB1StateReturn = 0;
        
    }else if( playerB2State == 0 ){
      
        playerB2StateReturn = 0;
        
    }else if( playerB3State == 0 ){
      
        playerB3StateReturn = 0;
        
    }else if( playerB4State == 0 ){
      
        playerB4StateReturn = 0;
        
    }else if( playerB5State == 0 ){
      
        playerB5StateReturn = 0;
        
    }else{

      //continue countdown then, but ensure that no button return state has been set
       if(
          playerA1StateReturn == 1 && 
          playerA2StateReturn == 1 &&
          playerA3StateReturn == 1 && 
          playerA4StateReturn == 1 &&
          playerA5StateReturn == 1 &&
          playerB1StateReturn == 1 && 
          playerB2StateReturn == 1 &&
          playerB3StateReturn == 1 && 
          playerB4StateReturn == 1 &&
          playerB5StateReturn == 1 
          ){
              Serial.println("b"); //send begin count down to max
          }else{

            //return unrecognized command
            Serial.println("u");
            
            }
        
    }

    //check if any player button is active, then begin looking at the admin button to receive commands

    if(
      
        playerA1StateReturn == 0 ||
        playerA2StateReturn == 0 ||
        playerA3StateReturn == 0 ||
        playerA4StateReturn == 0 ||
        playerA5StateReturn == 0 ||
        playerB1StateReturn == 0 ||
        playerB2StateReturn == 0 ||
        playerB3StateReturn == 0 ||
        playerB4StateReturn == 0 ||
        playerB5StateReturn == 0 
        
      ){

        correctState = digitalRead(correctButton);
        wrongState = digitalRead(wrongButton);
        playState = digitalRead(playButton);
        
        }

        //now check if admin button state is active and set the return state for consistency
         if( wrongState == 0 ) {
          
             wrongStateReturn = 0;
             
          }else if( correctState == 0 ){
            
             correctStateReturn = 0;
             
          }else if( playState == 0 ){
            
             playStateReturn = 0;
             
          }else{
            
            //this is not necessary, but just reset the return state of the admin buttons
             correctStateReturn = 1;
             wrongStateReturn = 1; 
             playStateReturn = 1;
             
          }

          /*after all the logic above, now send proper commands to max from arduino. 
           * Then light corresponding led
           * Also Turn relay to Low           * 
           */

          if( playerA1StateReturn == 0 ){ 

            digitalWrite(playerA1Relay, LOW);
            digitalWrite(playerA1Led, HIGH);   
            Serial.println(1); //player 1 button is active

          }else if( playerA2StateReturn == 0 ){

            digitalWrite(playerA2Relay, LOW);
            digitalWrite(playerA2Led, HIGH);
            Serial.println(2);
              
          }else if( playerA3StateReturn == 0 ){
            
            digitalWrite(playerA3Relay, LOW);
            digitalWrite(playerA3Led, HIGH);
            Serial.println(3);
              
          }else if( playerA4StateReturn == 0 ){

            digitalWrite(playerA4Relay, LOW);
            digitalWrite(playerA4Led, HIGH);
            Serial.println(4);
              
          }else if( playerA5StateReturn == 0 ){

            digitalWrite(playerA5Relay, LOW);
            digitalWrite(playerA5Led, HIGH);
            Serial.println(5);
              
          }else if( playerB1StateReturn == 0 ){

            digitalWrite(playerB1Relay, LOW);
            digitalWrite(playerB1Led, HIGH);
            Serial.println(6);
              
          }else if( playerB2StateReturn == 0 ){

            digitalWrite(playerB2Relay, LOW);
            digitalWrite(playerB2Led, HIGH);
            Serial.println(7);
              
          }else if( playerB3StateReturn == 0 ){

            digitalWrite(playerB3Relay, LOW);
            digitalWrite(playerB3Led, HIGH);
            Serial.println(8);
              
          }else if( playerB4StateReturn == 0 ){

            digitalWrite(playerB4Relay, LOW);
            digitalWrite(playerB4Led, HIGH);
            Serial.println(9);
              
          }else if( playerB5StateReturn == 0 ){

            digitalWrite(playerB5Relay, LOW);
            digitalWrite(playerB5Led, HIGH);
            Serial.println("x");
              
          }else if( correctStateReturn == 0 ){   
         
            Serial.println("c");
          
          }else if( wrongStateReturn == 0 ){              
            
            Serial.println("w");
             
          }else if( playStateReturn == 0 ){
            
            Serial.println("b");
             
          }else{
             Serial.println("u"); //unknown command sent to max
          }
          
      
  }else{
    
    Serial.println("u"); //unknown command sent to max
    
    }

}

