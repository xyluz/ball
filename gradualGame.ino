/*
 * Team B Related Configs
 * 1. Each Player Button, 5 players in total
 * 2. Player Button State Return Checker, to know what value to send to Max APP 
 * 3. Button State Checker to update the value of Button Stater Return
 * 4. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

#define playerA1Button 2  //player 1 button, send 1 to max 
#define playerA2Button 3  //player 2 button, send 2 to max
#define playerA3Button 4  //player 3 button, send 3 to max
#define playerA4Button 5  //player 4 button, send 4 to max
#define playerA5Button 6  //player 5 button, send 5 to max

#define playerA1Led 38  //player 1 led, 
#define playerA2Led 39  //player 2 led, 
#define playerA3Led 40  //player 3 led, 
#define playerA4Led 41  //player 4 led, 
#define playerA5Led 42 //player 5 led, 

#define playerA1Relay 27  //player 1 relay, 
#define playerA2Relay 22 //player 2 relay, 
#define playerA3Relay 37  //player 3 relay, 
#define playerA4Relay 23  //player 4 relay, 
#define playerA5Relay 25 //player 5 relay, 

int playerA1State, playerA2State, playerA3State, playerA4State, playerA5State = 1;
int playerA1StateReturn, playerA2StateReturn, playerA3StateReturn, playerA4StateReturn, playerA5StateReturn = 1;

/*
 * Team B Related Configs9
 * 1. Each Player Button, 5 players in total
 * 2. Player Button State Return Checker, to know what value to send to Max APP 
 * 3. Button State Checker to update the value of Button Stater Return
 * 4. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

#define playerB1Button 14  //player 6 button, send 6 to max 
#define playerB2Button 15  //player 7 button, send 7 to max
#define playerB3Button 16  //player 8 button, send 8 to max
#define playerB4Button 17  //player 9 button, send 9 to max
#define playerB5Button 18  //player x button, send x to max

#define playerB1Led 43  //player 6 led,  
#define playerB2Led 44  //player 7 led, 
#define playerB3Led 45  //player 8 led, 
#define playerB4Led 46  //player 9 led, 
#define playerB5Led 47 //player 10 led, 

#define playerB1Relay 30  //player 1 relay, 
#define playerB2Relay 31 //player 2 relay, 
#define playerB3Relay 33  //player 3 relay, //not correct, replace with 33
#define playerB4Relay 32  //player 4 relay, 
#define playerB5Relay 34 //player 5 relay, 

int playerB1State, playerB2State, playerB3State, playerB4State, playerB5State = 1;
int playerB1StateReturn, playerB2StateReturn, playerB3StateReturn, playerB4StateReturn, playerB5StateReturn = 1;

/*660567
 * Admin Related Configs
 * 1. Reset Button
 * 2. Correct Answer Button
 * 3. Wrong Answer Button
 * 4. Pause / Play CountDown Button
 * 5. Default Value is set to 1 to follow the arduino button convention, where 0 is high and 1 is low.
 */

//original fixed

#define resetButton 8  //reset game / timer button -- send r to max
#define correctButton 9  //when answer is correct -- sends c to max
#define wrongButton 10  //when answer is wrong -- send w to max
#define playButton 11  //when answer is wrong -- send b to max

#define resetLed 48 //reset led,

int resetState, correctState, wrongState, playState = 1; 
int resetStateReturn, wrongStateReturn, correctStateReturn, playStateReturn = 1;

int resetLedState, playerButtonActive;

void setup(){
/*
 * Admin Related Functionalities, Set Button Mode
 */
 
  pinMode(resetButton,INPUT_PULLUP); 
  pinMode(correctButton, INPUT_PULLUP); 
  pinMode(wrongButton, INPUT_PULLUP);
  pinMode(playButton, INPUT_PULLUP); 

  pinMode(resetLed, OUTPUT);

/*
 * Team A Button initialization
 */
  pinMode(playerA1Button, INPUT_PULLUP); 
  pinMode(playerA2Button, INPUT_PULLUP); 
  pinMode(playerA3Button, INPUT_PULLUP); 
  pinMode(playerA4Button, INPUT_PULLUP); 
  pinMode(playerA5Button, INPUT_PULLUP);

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
   pinMode(playerB1Button, INPUT_PULLUP); 
   pinMode(playerB2Button, INPUT_PULLUP); 
   pinMode(playerB3Button, INPUT_PULLUP); 
   pinMode(playerB4Button, INPUT_PULLUP); 
   pinMode(playerB5Button, INPUT_PULLUP); 
  
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

    /*
   * Just to be sure, reset all buttons.
   * 1. Team A
   * 2. Team B
   * 3. Admin 
   * 4. Flash reset LED
  */
   resetStateReturn = 1;
  
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
   playerButtonActive = 1;
   
}

void loop(){
/*
 * Begin Program: check restart button state, if its not restarted, then print default
 */

resetState = digitalRead(resetButton);

if( resetState == 0 ){
    
  //reset button is pressed
  resetStateReturn = 0;  //Keep reset persistent until another button is pressed  

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

   playerButtonActive = 1;

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

   digitalWrite(resetLed, HIGH); //Make reset led go on
   
   delay(10); //added delay to make the thing stay up a bit
    
   Serial.println("r"); //sent to Max to show that reset button has been pressed

  }

if( resetStateReturn == 0 ){ //if game reset is done, it means the app is ready

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

    if( 
      playerA1StateReturn == 1 && 
      playerA2StateReturn != 0 &&
      playerA3StateReturn != 0 &&
      playerA4StateReturn != 0 &&
      playerA5StateReturn != 0 &&
      playerB1StateReturn != 0 &&
      playerB2StateReturn != 0 &&
      playerB3StateReturn != 0 &&
      playerB4StateReturn != 0 &&
      playerB5StateReturn != 0 
  
      ){
      
        playerA1State = digitalRead(playerA1Button); 
        
      }
      
       if( 
        playerA2StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
       ){
      
        playerA2State = digitalRead(playerA2Button); 
      
      }
      
      if( 
        playerA3StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
        
        ){

        playerA3State = digitalRead(playerA3Button); 
      
      }
      
      if( 
        playerA4StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0  
        ){

        playerA4State = digitalRead(playerA4Button); 
      
      }
      
      if( 
        playerA5StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
        
        ){

        playerA5State = digitalRead(playerA5Button); 
      
      }
      
      if( 
        playerB1StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&        
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
        
        ){

        playerB1State = digitalRead(playerB1Button); 
      
      }
      
      if( 
        playerB2StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&       
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
        
        ){

        playerB2State = digitalRead(playerB2Button); 
      
      }
      
      if( 
        playerB3StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&       
        playerB4StateReturn != 0 &&
        playerB5StateReturn != 0 
        
        ){

        playerB3State = digitalRead(playerB3Button); 
      
      }
      
      if(
         
        playerB4StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&        
        playerB5StateReturn != 0 
        
        ){

        playerB4State = digitalRead(playerB4Button); 
      
      }
      
      if( 
        
        playerB5StateReturn == 1 &&
        playerA1StateReturn != 0 &&
        playerA2StateReturn != 0 &&
        playerA3StateReturn != 0 &&
        playerA4StateReturn != 0 &&
        playerA5StateReturn != 0 &&
        playerB1StateReturn != 0 &&
        playerB2StateReturn != 0 &&
        playerB3StateReturn != 0 &&
        playerB4StateReturn != 0 
        
        ){

        playerB5State = digitalRead(playerB5Button); 
      
      }     
      
      
    if( playerA1State == 0 ){      
            
        playerA1StateReturn = 0;
        
    }
    if( playerA2State == 0 ){     
       
        playerA2StateReturn = 0;
        
    }
    if( playerA3State == 0 ){
      
        playerA3StateReturn = 0;
        
    }
    if( playerA4State == 0 ){
      
        playerA4StateReturn = 0;
        
    }
    if( playerA5State == 0 ){
      
        playerA5StateReturn = 0;
        
    }
    if( playerB1State == 0 ){
      
        playerB1StateReturn = 0;
        
    }
    if( playerB2State == 0 ){
      
        playerB2StateReturn = 0;
        
    }
    if( playerB3State == 0 ){
      
        playerB3StateReturn = 0;
        
    }
    if( playerB4State == 0 ){
      
        playerB4StateReturn = 0;
        
    }
    if( playerB5State == 0 ){
      
        playerB5StateReturn = 0;
        
    }

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
            
          }        
    

          /*after all the logic above, now send proper commands to max from arduino. 
           * Then light corresponding led
           * Also Turn relay to Low, Turn the reset off           * 
           */

          if( playerA1StateReturn == 0 ){
                       
            digitalWrite(playerA1Relay, LOW);
            digitalWrite(playerA1Led, HIGH); 
            digitalWrite(resetLed, LOW);  
             

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);          
           
            digitalWrite(playerA2Led, LOW);
            digitalWrite(playerA3Led, LOW);
            digitalWrite(playerA4Led, LOW);
            digitalWrite(playerA5Led, LOW);

            
            digitalWrite(playerA2Relay, HIGH);
            digitalWrite(playerA3Relay, HIGH);
            digitalWrite(playerA4Relay, HIGH);
            digitalWrite(playerA5Relay, HIGH);

            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);
             
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;             

            playerButtonActive = 0;
            
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(1); //player 1 button is active
//              }
     

          }
          
          if( playerA2StateReturn == 0 ){
            

            //digitalWrite(playerA1Button, HIGH);

            digitalWrite(playerA2Relay, LOW);
            digitalWrite(playerA2Led, HIGH);
            digitalWrite(resetLed, LOW);               
                     

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);          
           
            digitalWrite(playerA1Led, LOW);
            digitalWrite(playerA3Led, LOW);
            digitalWrite(playerA4Led, LOW);
            digitalWrite(playerA5Led, LOW);

            digitalWrite(playerA1Relay, HIGH);
            digitalWrite(playerA3Relay, HIGH);
            digitalWrite(playerA4Relay, HIGH);
            digitalWrite(playerA5Relay, HIGH);

            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

             playerA1StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1; 

             
             playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(2);
//              }
         
              
          }
          
          if( playerA3StateReturn == 0 ){
            
            digitalWrite(playerA3Relay, LOW);
            digitalWrite(playerA3Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;            
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;
          
            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
          
            digitalWrite(playerA1Led, LOW);
            digitalWrite(playerA2Led, LOW);
            digitalWrite(playerA4Led, LOW);
            digitalWrite(playerA5Led, LOW);

            digitalWrite(playerA1Relay, HIGH);
            digitalWrite(playerA2Relay, HIGH);
            digitalWrite(playerA4Relay, HIGH);
            digitalWrite(playerA5Relay, HIGH);

            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(3);
//              }
  
              
          }
          
          if( playerA4StateReturn == 0 ){

            digitalWrite(playerA4Relay, LOW);
            digitalWrite(playerA4Led, HIGH);
            digitalWrite(resetLed, LOW);

           playerA1StateReturn = 1; 
           playerA2StateReturn = 1;
           playerA3StateReturn = 1;
           playerA5StateReturn = 1;
        
           playerB1StateReturn = 1;
           playerB2StateReturn = 1;
           playerB3StateReturn = 1; 
           playerB4StateReturn = 1;
           playerB5StateReturn = 1;

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
          
            digitalWrite(playerA1Led, LOW);           
            digitalWrite(playerA4Led, LOW);
            digitalWrite(playerA2Led, LOW);
            digitalWrite(playerA5Led, LOW);

            digitalWrite(playerA1Relay, HIGH);
            digitalWrite(playerA3Relay, HIGH);
            digitalWrite(playerA2Relay, HIGH);
            digitalWrite(playerA5Relay, HIGH);

            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
              Serial.println(4);
//              }

              
          }
          
          if( playerA5StateReturn == 0 ){

            digitalWrite(playerA5Relay, LOW);
            digitalWrite(playerA5Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;            
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
          
            digitalWrite(playerA1Led, LOW);
            digitalWrite(playerA2Led, LOW);
            digitalWrite(playerA3Led, LOW);
            digitalWrite(playerA4Led, LOW); 

            digitalWrite(playerA1Relay, HIGH);
            digitalWrite(playerA3Relay, HIGH);
            digitalWrite(playerA4Relay, HIGH);
            digitalWrite(playerA2Relay, HIGH);

            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(5);
//              }

              
          }
          
          if( playerB1StateReturn == 0 ){

            digitalWrite(playerB1Relay, LOW);
            digitalWrite(playerB1Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;          
      
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;
   
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
            
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
            
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(6);
//              }

              
          }
          if( playerB2StateReturn == 0 ){

            digitalWrite(playerB2Relay, LOW);
            digitalWrite(playerB2Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;             
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;
             
            digitalWrite(playerB1Led, LOW);            
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
            
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
            
            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(7);
//              }

              
          }
          
          if( playerB3StateReturn == 0 ){

            digitalWrite(playerB3Relay, LOW);
            digitalWrite(playerB3Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;      
             playerB4StateReturn = 1;
             playerB5StateReturn = 1;

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);          
            digitalWrite(playerB4Led, LOW);
            digitalWrite(playerB5Led, LOW);
            
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
            
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(8);
//              }

              
          }
          
          if( playerB4StateReturn == 0 ){

            digitalWrite(playerB4Relay, LOW);
            digitalWrite(playerB4Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB5StateReturn = 1;

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB5Led, LOW);
            
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
            
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB1Relay, HIGH);
            digitalWrite(playerB5Relay, HIGH);

            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
            Serial.println(9);
//              }

              
          }
          
          if( playerB5StateReturn == 0 ){

            digitalWrite(playerB5Relay, LOW);
            digitalWrite(playerB5Led, HIGH);
            digitalWrite(resetLed, LOW);

             playerA1StateReturn = 1; 
             playerA2StateReturn = 1;
             playerA3StateReturn = 1;
             playerA4StateReturn = 1;
             playerA5StateReturn = 1;
          
             playerB1StateReturn = 1;
             playerB2StateReturn = 1;
             playerB3StateReturn = 1; 
             playerB4StateReturn = 1;

            digitalWrite(playerB1Led, LOW);
            digitalWrite(playerB2Led, LOW);
            digitalWrite(playerB3Led, LOW);
            digitalWrite(playerB4Led, LOW);
                       
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
            
            digitalWrite(playerB2Relay, HIGH);
            digitalWrite(playerB3Relay, HIGH);
            digitalWrite(playerB4Relay, HIGH);
            digitalWrite(playerB1Relay, HIGH);

            
            playerButtonActive = 0;
            //only produce this if admin wrong / correct button is not active
//            if(
//              correctStateReturn == 1 &&
//              wrongStateReturn == 1 &&
//              playStateReturn == 1
//              ){
                   Serial.println("x");
//                }
           

              
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

         //now check if admin button state is active and set the return state for consistency
         if( wrongState == 0 ) {
          
             wrongStateReturn = 0;
             
          }else if( correctState == 0 ){
            
             correctStateReturn = 0;
             
          }else if( playState == 0 ){
            
             playStateReturn = 0;
             
          }
        
        } 
          
      //ensure a player button is active before allowing 
          if(playerButtonActive == 0){

              if( correctStateReturn == 0 ){   
         
                  Serial.println("c");      
                
                }else if( wrongStateReturn == 0 ){              
                  
                  Serial.println("w");
      
                   
                }else if( playStateReturn == 0 ){
                  
                  Serial.println("b");
                   
                }
            
            }
      
  }else{
    
    Serial.println("u"); //unknown command sent to max

    
    }

}

