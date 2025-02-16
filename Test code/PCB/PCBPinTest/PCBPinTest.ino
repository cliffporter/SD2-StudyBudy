#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Adafruit_TCA8418.h>
#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <string>
#include <Adafruit_SSD1306.h>


//Paramaters
// #define RFID_RESCAN_DELAY       1000
// #define RFID_SCAN_DELAY         200
// #define RFID_TAG                {0x93, 0xFE, 0xCF, 0x1D}
// #define RFID_CARD               {0x73, 0x9B, 0x17, 0x94}
// #define SERVO_UNLOCK_POSITION   180
// #define SERVO_LOCK_POSITION     0



// //Peripheral assignment
// //(using hardware I2C, SPI, UART)
#define OLED_DC             12
#define OLED_CS             13
#define OLED_RESET          2
// #define SCREEN_WIDTH        128
// #define SCREEN_HEIGHT       64
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//   &SPI, OLED_DC, OLED_RESET, OLED_CS);

// #define mySerial Serial1
// Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define RFID_CS             11 
#define RFID_RST            10              
// MFRC522 rfid(RFID_CS, RFID_RST);

#define SERVO_1             9
#define SERVO_2             7
#define SERVO_3             5
// Servo servo1;
// Servo servo2;
// Servo servo3;

// #define REED_1              5
// #define REED_2              6
// #define REED_3              7


// #define KEYPAD_ROWS         3
// #define KEYPAD_COLS         4
// Adafruit_TCA8418 tio;
// Adafruit_TCA8418 keypad;
// char keymap[KEYPAD_COLS][KEYPAD_ROWS] = {
//     {'#', '0', '*'},
//     {'9', '8', '7'},
//     {'6', '5', '4'},
//     {'3', '2', '1'},
// };


// //Globals
// struct Compartment {
//   int number;
//   bool isLocked;
//   bool openedEarly;
//   Servo servo;

//   bool usingTimer;
//   long unlockTime;  
//   int timerSeconds;
//   bool usingRFID;
//   byte authTag[10];
//   bool usingPin;
//   char pin[5];
//   bool usingFP;
//   int fpNum;
// };
// Compartment locker1;
// Compartment locker2;
// Compartment locker3;

// long lastRFIDScan;
// byte lastRFIDTag[10];

// char enteredPin[5];
// int pinIndex; 

// //State vars
// int currentState;
// Compartment * currentComp;


void setup() 
{
  Serial.begin(9600); 
  while (!Serial); //wait for serial to begin
  Serial.println("Serial Begin:");
  SPI.begin();

  pinMode(OLED_DC,OUTPUT);
  pinMode(OLED_CS,OUTPUT);
  pinMode(OLED_RESET,OUTPUT);
  pinMode(RFID_CS,OUTPUT);
  pinMode(RFID_RST,OUTPUT);
  pinMode(SERVO_1,OUTPUT);
  pinMode(SERVO_2,OUTPUT);
  pinMode(SERVO_3,OUTPUT);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);

  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);

  //Fingerprint sensor setup
//   finger.begin(57600);
//   delay(5);
//   if (finger.verifyPassword()) {
//     Serial.println("Found fingerprint sensor!");
//   } else {
//     Serial.println("Did not find fingerprint sensor :(");
//     while (1) { delay(1); }
//   }

//   //RFID setup
//   rfid.PCD_Init();	
// 	delay(4);			
// 	Serial.print("RFID "); //RFID Firmware Version: 0x92 = v2.0
//   rfid.PCD_DumpVersionToSerial();

//   //Servos
//   servo1.attach(SERVO_1);
//   servo2.attach(SERVO_2); 
//   servo3.attach(SERVO_3); 

//   //Locker setup
//   locker1 = createCompartment(1);
//   locker2 = createCompartment(2);
//   locker3 = createCompartment(3);
  
//   //TCA8418 I2C GPIO Expander/Keypad setup
//   if (! tio.begin(TCA8418_DEFAULT_ADDR, &Wire)) 
//   {
//     Serial.println("TCA8418 not found, check wiring & pullups!");
//     while (1);
//   }
//   if (! keypad.begin(TCA8418_DEFAULT_ADDR, &Wire)) 
//   {
//     Serial.println("keypad not found, check wiring & pullups!");
//     while (1);
//   }
//   keypad.matrix(KEYPAD_ROWS, KEYPAD_COLS);
//   tio.pinMode(REED_1, INPUT_PULLUP);
//   tio.pinMode(REED_2, INPUT_PULLUP);
//   tio.pinMode(REED_3, INPUT_PULLUP);
//   keypad.flush();

//   //Display setup
//   if(!display.begin(SSD1306_SWITCHCAPVCC)) {
//     Serial.println(F("SSD1306 allocation failed"));
//     for(;;); // Don't proceed, loop forever
//   }
//   display.clearDisplay();


//   //Globals init
//   pinIndex = 0;


//   //Lock servos (remove later)
//   // servoLock(1);
//   // delay(1000);
//   // servoLock(2);
//   // delay(1000);
//   // servoLock(3);

//   //Test unlocking
//   //byte tag[] = RFID_TAG;
//   //startLock(2, -1, tag, NULL, -1);
//   //Serial.println("Locker #2 locked with tag");

//   //startLock(1, 10, NULL, NULL, -1);
//   //Serial.println("Unlocking #1 in 10s");

//   //main drawViewMenu
//   currentState=0;

//   byte tag[] = RFID_TAG;
//   char  pin[5] = {'1','2','3','4','\0'};
//  // startLock(1, 20, NULL, pin, 1);
}

void loop() 
{
  digitalWrite(OLED_DC,LOW);
  digitalWrite(OLED_CS,LOW);
  digitalWrite(OLED_RESET,LOW);
  digitalWrite(RFID_CS,LOW);
  digitalWrite(RFID_RST,LOW);
  digitalWrite(SERVO_1,LOW);
  digitalWrite(SERVO_2,LOW);
  digitalWrite(SERVO_3,LOW);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  digitalWrite(A4,LOW);
  digitalWrite(A5,LOW);
  Serial.println("Flipped to low");
  delay(1000);
  digitalWrite(OLED_DC,HIGH);
  digitalWrite(OLED_CS,HIGH);
  digitalWrite(OLED_RESET,HIGH);
  digitalWrite(RFID_CS,HIGH);
  digitalWrite(RFID_RST,HIGH);
  digitalWrite(SERVO_1,HIGH);
  digitalWrite(SERVO_2,HIGH);
  digitalWrite(SERVO_3,HIGH);
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
  digitalWrite(A4,HIGH);
  digitalWrite(A5,HIGH);
  Serial.println("Flipped to high");
  delay(1000);
}

/*--------------------------------------------*/
/*---------------RFID FUNCTIONS---------------*/
/*--------------------------------------------*/

//check for an RFID tag
//returns a pointer to the byte array containing its uid
// byte * scanRFID() 
// {
//   //dont overwhelm the sensor
//   if( millis()-lastRFIDScan < RFID_SCAN_DELAY )
//     return NULL;

//   if ( ! rfid.PICC_IsNewCardPresent())  //If a new PICC placed to RFID reader continue
//     return NULL;
//   if ( ! rfid.PICC_ReadCardSerial())   //Since a PICC placed get Serial and continue
//     return NULL;
  
//   //A tag was found
//   byte * scanned = rfid.uid.uidByte;

//   //ignore the last scanned tag untill it has been removed for x seconds
//   if( memcmp(scanned, &lastRFIDTag, sizeof(scanned)) == 0 && millis()-lastRFIDScan < RFID_RESCAN_DELAY)
//   {
//     lastRFIDScan = millis();
//     return NULL;
//   }

//   Serial.print("Scanned tag: ");
//   printByteAr(scanned);
  
//   // byte card[] = RFID_CARD;
//   // byte tag[] = RFID_TAG;

//   // if( memcmp(scanned, card, sizeof(scanned)) == 0)
//   // {
//   //   Serial.println("card!");
//   // }
//   // else if ( memcmp(scanned, tag, sizeof(scanned)) == 0)
//   // {
//   //   Serial.println("tag!");
//   // }

//   //Save info to prevent rescaning
//   memcpy(lastRFIDTag, scanned, sizeof(scanned));
//   lastRFIDScan = millis();

//   //Check if this RFID tag is registered to a locker
//   // int lockerNum = checkForRegisteredRFID(scanned);
//   // if(lockerNum > 0)
//   //   unlock(lockerNum);

//   return scanned;
// }

// //Returns the locker number of the fist locker with a matching rfid tag
// //returns -1 if none
// int checkForRegisteredRFID(byte * scanned)
// {
//   //printByteAr(locker2.authTag);

//   if( locker1.usingRFID && memcmp(scanned, locker1.authTag, sizeof(scanned)) == 0)
//   {
//     return 1;
//   }
//   else if ( locker2.usingRFID && memcmp(scanned, locker2.authTag, sizeof(scanned)) == 0)
//   {
//     return 2;
//   }
//   else if ( locker3.usingRFID && memcmp(scanned, locker3.authTag, sizeof(scanned)) == 0)
//   {
//     return 3;
//   }
//   else
//   {
//     return -1;
//   }
// }
// //Print an array of bytes in hex
// void printByteAr(byte * b)
// {
//   Serial.print("0x");
//   char hexCar[2];
//   for (int i=0; i < sizeof(b); i++)
//   {
//      //Serial.print(b[i], HEX);
//     sprintf(hexCar, "%02X", b[i]);
//     Serial.print(hexCar);
//   }
//   Serial.println();
// }

// /*----------------------------------------------*/
// /*---------------LOCKER FUNCTIONS---------------*/
// /*----------------------------------------------*/

// //Configure and start lock
// void startLock(int lockerNumber)
// {
//   Compartment * comp = getLockerPointer(lockerNumber);

//   if(comp->usingTimer)
//   {
//     comp->unlockTime = millis() + ((comp->timerSeconds)*1000);
//     Serial.print("TIMER SECONDS:");    
//     Serial.println(comp->timerSeconds);
//   }
  
//   if((comp->usingTimer || comp->usingRFID || comp->usingPin || comp->usingFP) && !getReed(lockerNumber))
//   {
//     comp->isLocked = true;
//     servoLock(lockerNumber);
//   }
// }
// //Main unlock function
// void unlock ( Compartment * c )  //can call with pointer or number (see helpers)
// {
//   Serial.printf("Unlocking Locker %d\n", c->number);
//   servoUnlock(c->number);
//   clearLocker(c);

//   if(currentState==0) {
//     drawMainMenu();
//   }
// }

// //Initialize a Compartment
// Compartment createCompartment (int lockerNumber)
// {
//   Compartment newCom;
//   Servo srvo = getServo(lockerNumber);

//   newCom.number = lockerNumber;
//   newCom.isLocked = false;
//   newCom.openedEarly = false;
//   newCom.servo = srvo;

//   newCom.usingTimer = false;
//   newCom.unlockTime = -1;
//   newCom.timerSeconds = -1;
//   newCom.usingRFID = false;
//   newCom.usingPin = false;
//   newCom.usingFP = false;
//   newCom.fpNum = -1;
  
  
//   return newCom;
// }
// //Clear/ reinitialize a Compartment
// void clearLocker(Compartment * c)
// {
//   c->isLocked = false;
//   c->openedEarly = false;

//   c->usingTimer = false;
//   c->unlockTime = -1;
//   c->timerSeconds = -1;
//   c->usingRFID = false;
//   memset(c->authTag, 0, sizeof(c->authTag));
//   c->usingPin = false;
//   memset(c->pin, 0, sizeof(c->pin));
//   c->usingFP = false;
//   c->fpNum = -1;
// }
// //Check all compartments to see if their time is up, unlock if true. Also flip the tamper bit if compartment is locked and reed switch is open.
// void checkTimeUp()
// {
//   uint32_t time = millis();
  
//   if(locker1.usingTimer && (time >= locker1.unlockTime) )
//   {
//     unlock(&locker1);
//   }

//   if(locker2.usingTimer && (time >= locker2.unlockTime) )
//   {
//     unlock(&locker2);
//   }

//   if(locker3.usingTimer && (time >= locker3.unlockTime) )
//   {
//     unlock(&locker3);
//   }

//   if(locker1.isLocked && getReed(locker1.number) && !locker1.openedEarly)
//   {
//     locker1.openedEarly = true;
//   }

//   if(locker2.isLocked && getReed(locker2.number) && !locker2.openedEarly)
//   {
//     locker2.openedEarly = true;
//   }

//   if(locker3.isLocked && getReed(locker3.number) && !locker3.openedEarly)
//   {
//     locker3.openedEarly = true;
//   }
// }
// //Unlock a compartment, check for errors and clear its settings
// void unlock ( int lockerNumber )
// {
//   Compartment * comp = getLockerPointer(lockerNumber);
//   unlock(comp);
// }
// void setLockTime(Compartment * c, int seconds)
// {
//   c->usingTimer = true;
//   c->timerSeconds = seconds;
// }
// void setTamper(Compartment * c)
// {
//   c->openedEarly = true;
// }
// void clearTimer(Compartment * c)
// {
//   c->usingTimer = false;
//   c->timerSeconds = -1;
// }
// void setRFIDTag(Compartment * c, byte * tag)
// {
//   c->usingRFID = true;
//   memcpy(c->authTag, tag, sizeof(tag));  
// }
// void clearRFID(Compartment * c)
// {
//   c->usingRFID = false;
//   memset(c->authTag, 0, sizeof(c->authTag));  
// }
// void setPin(Compartment * c, char * pin)
// {
//   c->usingPin = true;
//   memcpy(c->pin, pin, sizeof(pin));
// }
// void clearPin(Compartment * c)
// {
//   c->usingPin = false;
//   memset(c->pin, 0, sizeof(c->pin));
// }
// void setFingerprint(Compartment * c, int fpNumber)
// {
//   c->usingFP = true;
//   c->fpNum = fpNumber;
// }
// void clearFP(Compartment * c)
// {
//   c->usingFP = false;
//   c->fpNum = -1;
// }
// //Returns the pointer of the locker specified
// Compartment * getLockerPointer(int lockerNumber)
// {
//   switch(lockerNumber)
//   {
//     case 1:
//     {
//       return &locker1;
//     }
//     case 2:
//     {
//       return &locker2;
//     }
//     case 3:
//     {
//       return &locker3;
//     }
//   }
//   return NULL;
// }
// //Read the value of a reed switch 0->closed 1->open
// int getReed(int lockerNumber)
// {
//   switch(lockerNumber)
//   {
//     case 1:
//     {
//       return tio.digitalRead(REED_1);
//     }
//     case 2:
//     {
//       return tio.digitalRead(REED_2);
//     }
//     case 3:
//     {
//       return tio.digitalRead(REED_3);
//     }
//   }
//   return -1;
// }


// /*---------------------------------------------*/
// /*---------------SERVO FUNCTIONS---------------*/
// /*---------------------------------------------*/

// //Get the servo object of the specified locker
// Servo getServo(int servoNumber)
// {
//   switch(servoNumber)
//   {
//     case 1:
//     {
//       return servo1;
//     }
//     case 2:
//     {
//       return servo2;
//     }
//     case 3:
//     {
//       return servo3;
//     }
//   }
//   Servo badServo;
//   return badServo;
// }
// //Move the servo to the unlock position
// void servoUnlock (int lockerNumber)
// {
//   Compartment * comp = getLockerPointer(lockerNumber);
//   comp->servo.write(SERVO_UNLOCK_POSITION);
// }
// //Move the servo to the lock position
// void servoLock (int lockerNumber)
// {
//   Compartment * comp = getLockerPointer(lockerNumber);
//   comp->servo.write(SERVO_LOCK_POSITION);
// }

// /*----------------------------------------------*/
// /*---------------KEYPAD FUNCTIONS---------------*/
// /*----------------------------------------------*/

// //Read the input on the keypad.
// //returns 0 if no input or the char of the pressed key.
// //clears input once read
// char checkKeypad()
// {
//   if (keypad.available() > 0)
//   {
//     // datasheet page 15 - Table 1
//     int k = keypad.getEvent();

//     // Serial.print("K: ");
//     // Serial.print(k, DEC);
//     // Serial.print("\t");
//     // printBinLZ(k);
//     // Serial.print("\t");
//     // Serial.print(k, HEX);
//     // Serial.println();

//     // we dont care about release events
//     if ( !(k & 0x80) ) 
//     {
//       keypad.flush();
//       return 0;
//     }

//     k &= 0x7F; //remove leading 1 -> 1000 0000
//     k--; // decrement for array

//     //check for invalid entries
//     if( k%10 >= KEYPAD_COLS || k/10 >= KEYPAD_ROWS )
//     {
//       keypad.flush();
//       return 0;
//     }

//     char pressed = keymap[k%10][k/10];
//     Serial.printf("User pressed %c", pressed);
//     Serial.println();

//     // Serial.print("Row: ");
//     // Serial.print((k%10)+1);
//     // Serial.print("\tCol: ");
//     // Serial.print((k/10)+1);
//     // Serial.println();
//     // Serial.println();

//     keypad.flush();
//     return pressed;
//   }

//   return 0;
// }
// //Print binary with leading zeros
// void printBinLZ(int n)
// {
//   for (int i = 0; i < 8; i++)
//   {
//         if (n < pow(2, i))
//               Serial.print(B0);
//   }
//   Serial.print(n, BIN);
// }


// /*--------------------------------------------------*/
// /*-------------------MENU FUNCTIONS-----------------*/
// /*--------------------------------------------------*/

// void mainMenu()
// {
//   Serial.println("MainMenu");
//   drawMainMenu();
//   char key;

//   if ( currentComp!=NULL )
//   {
//     currentComp = NULL;
//   }

//   while(1)
//   {
//     checkTimeUp();
//     key = checkKeypad();

//     if(key != 0 && (key=='1' || key=='2' || key=='3'))
//     {
//       //Serial.println("key is 123");
//       int currentLockerNum = key-48;
//       currentComp = getLockerPointer(currentLockerNum);

//       if(currentComp->isLocked) 
//       {
//         //Serial.println("locked");
//         //viewLockedMenu();
//         currentState = 1;
//         return;
//       }
//       else
//       {
//         //Serial.println("isntlocked");
//         //viewUnlockedMenu(comp);
//         currentState = 2;
//         return;
//       }
//     }

//     if(key != 0 && key=='*')
//     {
//       //Settings menu
//       currentState = 10;
//       return;
//     }
//   }
// }

// void viewLockedMenu()
// {
//   Serial.println("ViewLockedMenu");
//   int lockerNum = currentComp->number;
//   drawViewMenu(lockerNum);
//   drawTimer(lockerNum);
//   char key;

//   long timerLastUpdated = millis();
//   while(1)
//   {
//     key = checkKeypad();
//     checkTimeUp();
//     if (currentComp->isLocked == false)
//     {
//       //viewUnlockedMenu
//       currentState = 2;
//       return;
//     }
    
//     if( key=='*' )
//     {
//       //main menu
//       currentState = 0;
//       return;
//     }

//     //Update the clock on the display every 1s
//     if( millis()-timerLastUpdated >= 1000)
//     {
//       drawTimer(lockerNum);
//       timerLastUpdated = millis();
//     }
    
//     if( key=='#') //#: Unlock
//     {
//       //promptPinChallenge
//       currentState = 3;
//       return;
//     }
//   }  
// }

// void promptPinChallenge()
// {
//   Serial.println("PromptPinChallenge");
//   if(currentComp->usingPin)
//   {
//     drawPasscodeMenu();
    
//     while(1)
//     {
//       char key = checkKeypad();
//       checkTimeUp();

//       if( currentComp->isLocked==false )
//       {
//         //mainMenu
//         currentState = 0;
//         return;
//       }

//       if(key == '*')
//       {
//         clearPin();
//         //viewlockedmenu
//         currentState = 1;
//         return;
//       }

//       //make pin
//       if(key!=0 )
//       {
//         pinBuilder(key);
//         updatePasscode();
//       }
      
//       if(key=='#')
//       {
//         char * correctPin = currentComp->pin;
//         //compare
//         for(int i=0; i<4; i++)
//         {
//           //Serial.printf("i: %d ent: %c cor: %c\n", i, enteredPin[i], correctPin[i]);
//           if(enteredPin[i]!=correctPin[i]) // wrong pin
//           {
//             Serial.println("Incorrect Pin!");
//             //viewLockedMenu
//             //currentState = 1;

//             //dont change state, redraw pin
//             clearPin();
//             return;
//           }
//         }
//         Serial.println("Correct Pin :)");
//         clearPin();
//         //promptRFIDChallenge
//         currentState = 4;
//         return;
//       }
//     }
//   }
//   else //not using pin, skip
//   {
//     //promptRFIDChallenge
//     currentState = 4;
//     return;
//   }
// }

// void promptRFIDChallenge()
// {
//   if(currentComp->usingRFID)
//   {
//     Serial.println("PromptRFIDChallenge");
//     drawRFIDMenu();
    
//     while(1)
//     {
//       char key = checkKeypad();
//       checkTimeUp();

//       if( currentComp->isLocked==false )
//       {
//         //mainMenu
//         currentState = 0;
//         return;
//       }

//       if(key == '*')
//       {
//         clearPin();
//         //viewlockedmenu
//         currentState = 1;
//         return;
//       }

//       byte * tag = scanRFID();

//       // if( tag != NULL)
//       // {
//       //   printByteAr(tag);
//       //   printByteAr(currentComp->authTag);
//       // }

//       if( tag!=NULL && memcmp(tag, currentComp->authTag, sizeof(tag)) == 0 )
//       {
//         Serial.println("Correct tag :)");
//         //promptFingerChallenge
//         currentState = 5;
//         return;
//       }
//       else if ( tag!=NULL )
//       {
//         Serial.println("Wrong tag >:(");
//         //viewLockedMenu
//         currentState = 1;
//         return;
//       }
//     }
//   }
//   else //not using rfid, skip
//   {
//     //promptFingerChallenge
//     currentState = 5;
//     return;
//   }
// }

// void promptFingerChallenge()
// {
//   if(currentComp->usingFP)
//   {
//     Serial.println("PromptFingerPrintChallenge");
//     drawFingerprintMenu();
//     int lastResult = -10;

//     while(1)
//     {
//       char key = checkKeypad();
//       checkTimeUp();
//       if( currentComp->isLocked==false )
//       {
//         //mainMenu
//         currentState = 0;
//         return;
//       }

//       if(key == '*')
//       {
//         clearPin();
//         //viewlockedmenu
//         currentState = 1;
//         return;
//       }

//       int result = getFingerprintID();
//       //-2,0 remove prompt, try again
//       //-1 ignore, continue
//       //0 start enroll
//       //1 procede to unlock

//       if( result==-2 )
//       {
//         drawFingerprintRemoveMenu();
//       }
//       else if ( result==-1 && (lastResult==-2) )
//       {
//         drawFingerprintRetryMenu();
//       }
//       else if ( result>=0 )
//       {
//         //check that the id matches
//         if(result == currentComp->fpNum)
//         {
//           //unlock steps
//           unlock(currentComp->number);
//           //mainMenu
//           currentState = 0;
//           return;
//         }
//         else
//         {
//           Serial.println("Wrong finger >:(");
//           //viewLockedMenu
//           currentState = 1;
//           return;
//         }
//       }
//     }
//   }
//   else //not using finger print, skip
//   {
//     unlock(currentComp->number);
//     //mainMenu
//     currentState = 0;
//     return;
//   }
// }

// void viewUnlockedMenu()
// {
//   Serial.println("ViewUnlockedMenu");
//   int lockerNum = currentComp->number;
//   drawUnlockedMenu(lockerNum);
//   char key;

//   int changeLine = getReed(lockerNum);

//   while(1)
//   {
//     key = checkKeypad();
//     checkTimeUp();
//     if (currentComp->isLocked == true)
//     {
//       //viewLockedMenu
//       currentState = 1;
//       return;
//     }

//     if(changeLine != getReed(lockerNum))
//     {
//       changeLine = getReed(lockerNum);
//       drawExtraLine(lockerNum);
//     }

    
//     if( key=='*' )
//     {
//       clearLocker(currentComp);
//       //main menu
//       currentState = 0;
//       return;
//     }

//     if( key=='1' )
//     {
//       if(currentComp->usingTimer) 
//       {
//         //Don't change state, just disable timer and redraw screen
//         clearTimer(currentComp);
//         return;        
//       }
//       else
//       {
//         //Timer prompt
//         currentState = 6;
//         return;
//       }
//     }

//     if( key=='2' )
//     {
//       if(currentComp->usingPin) 
//       {
//         //Don't change state, just disable pin and redraw screen
//         clearPin(currentComp);
//         return;        
//       }
//       else
//       {
//         //Pin prompt
//         currentState = 7;
//         return;
//       }
//     }

//     if( key=='3' )
//     {
//       if(currentComp->usingRFID) 
//       {
//         //Don't change state, just disable pin and redraw screen
//         clearRFID(currentComp);
//         return;        
//       }
//       else
//       {
//         //Pin prompt
//         currentState = 8;
//         return;
//       }
//     }

//     if( key=='4' )
//     {
//       if(currentComp->usingFP) 
//       {
//         //Don't change state, just disable pin and redraw screen
//         clearFP(currentComp);
//         return;        
//       }
//       else
//       {
//         //Pin prompt
//         currentState = 9;
//         return;
//       }
//     }

//     if( key=='#' && (currentComp->usingTimer || currentComp->usingPin || currentComp->usingRFID || currentComp->usingFP) && !getReed(lockerNum))
//     {
//       startLock(lockerNum);

//       //Main menu
//       currentState = 0;
//       return;
//     }
//   }
// }

// void promptTimeEntry()
// {
//   Serial.println("PromptTimeEntry");
//   drawTimerMenu();
//   int timerIsFull = 0;

//   while(1)
//   {
//     char key = checkKeypad();
//     checkTimeUp();

//     if(key == '*')
//     {
//       clearPin();
//       //Unlocked menu
//       currentState = 2;
//       return;
//     }

//     //Write timer
//     if(key!=0 && key!='#')
//     {
//       timerIsFull = pinBuilder(key);
//       updateTimer();
//     }

//     if(key=='#' && timerIsFull)
//     {
//       int hours = (10*((int)enteredPin[0]-48)) + (int)enteredPin[1]-48;
//       int minutes = (10*((int)enteredPin[2]-48)) + (int)enteredPin[3]-48;
//       Serial.print("HOURS: ");
//       Serial.println(hours);
//       Serial.print("MINUTES: ");
//       Serial.println(minutes);
//       int seconds = ((hours*60)+minutes)*60;
//       if(seconds<1 || seconds>360000) {
//         //Reset pin and menu if time entered was 0 or >100 hours
//         clearPin();
//         return;
//       }
//       setLockTime(currentComp, seconds);
//       clearPin();

//       //Unlocked menu
//       currentState = 2;
//       return;    
//     }
//   }
// }

// void promptPinEntry()
// {
//   Serial.println("PromptPinEntry");
//   drawPasscodeMenu();
//   int pinIsFull = 0;

//   while(1)
//   {
//     char key = checkKeypad();
//     checkTimeUp();

//     if(key == '*')
//     {
//       clearPin();
//       //Unlocked menu
//       currentState = 2;
//       return;
//     }

//     if(key!=0 && key!='#')
//     {
//       pinIsFull = pinBuilder(key);
//       updatePasscode();
//     }

//     if(key=='#' && pinIsFull)
//     {
//       setPin(currentComp, enteredPin);
//       clearPin();

//       //Unlocked menu
//       currentState = 2;
//       return;    
//     }
//   }
// }

// void promptRFIDEntry()
// {
//   Serial.println("PromptRFIDEntry");
//   drawRFIDMenu();

//   while(1)
//   {
//     char key = checkKeypad();
//     checkTimeUp();

//     if(key == '*')
//     {
//       //Unlocked menu
//       currentState = 2;
//       return;
//     }

//     byte * tag = scanRFID();

//     if(tag != NULL)
//     {
//       setRFIDTag(currentComp, tag);

//       //Unlocked menu
//       currentState = 2;
//       return;
//     }
//   }
// }

// void promptFPEntry()
// {
//   Serial.println("PromptFPEntry");
//   drawFingerprintMenu();
//   int lastResult = -10;
//   bool sensorChecked = false;

//   while(1)
//   {
//     char key = checkKeypad();
//     checkTimeUp();

//     if(key == '*')
//     {
//       clearPin();
//       //Unlocked menu
//       currentState = 2;
//       return;
//     }

//     if(!sensorChecked)
//     {
//       int result = getFingerprintID();
//       //-2 remove prompt, try again
//       //-1 ignore, continue
//       //0 start enroll
//       //1 procede to unlock

//       if( result==-2 )
//       {
//         drawFingerprintRemoveMenu();
//       }
//       else if ( result==-1 && (lastResult==-2) )
//       {
//         drawFingerprintRetryMenu();
//       }
//       else if ( result>0 )
//       {
//         setFingerprint(currentComp, result);

//         //Unlocked menu
//         currentState = 2;
//         return;
//       }
//       else if (result == 0)
//       {
//         sensorChecked = true;
//       }
//     }
//     else
//     {
//       int result = getFingerprintEnroll(currentComp->number);
//       if(result == -2)
//       {
//         drawFingerprintRemoveMenu();
//         delay(1000);
//       }
//       else if(result == 1)
//       {
//         setFingerprint(currentComp, currentComp->number);

//         //Unlocked menu
//         currentState = 2;
//         return;
//       }
//     }
//   }
// }

// void settingsMenu()
// {
//   Serial.println("SettingsMenu");
//   drawSettings();

//   bool flip1 = locker1.openedEarly;
//   bool flip2 = locker2.openedEarly;
//   bool flip3 = locker3.openedEarly;

//   while(1)
//   {
//     char key = checkKeypad();
//     checkTimeUp();

//     if(key == '*')
//     {
//       //Main menu
//       currentState = 0;
//       return;
//     }

//     if(flip1 != locker1.openedEarly || flip2 != locker2.openedEarly || flip3 != locker3.openedEarly)
//     {
//       Serial.println("Entered menu if");
//       drawTamperMarks();
//       flip1 = locker1.openedEarly;
//       flip2 = locker2.openedEarly;
//       flip3 = locker3.openedEarly;
//     }    
//   }
// }

// //Add a character to the pin.
// //returns 1 if pin is now complete, 0 otherwise 
// int pinBuilder(char c)
// {
//   if( pinIndex < 4 && c != 0)
//   {
//     enteredPin[pinIndex] = c;
//     pinIndex++;
//     //Serial.println(enteredPin);
//   }
//   if (pinIndex == 4)
//   {
//     Serial.print("Full pin: ");
//     Serial.println(enteredPin);
//     return 1;
//   }
//   return 0;
// }

// void clearPin()
// {
//     memset(enteredPin, 0, sizeof(enteredPin));
//     pinIndex = 0;
// }


// /*---------------------------------------------------*/
// /*---------------FINGERPRINT FUNCTIONS---------------*/
// /*---------------------------------------------------*/

// //Scan sensor image, return -2 if error, return -1 if no finger placed, return 0 if no match, otherwise return first matching ID
// int getFingerprintID() 
// {
//   uint8_t p = finger.getImage();
//   switch (p) 
//   {
//     case FINGERPRINT_OK:
//       Serial.println("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       //Serial.println("No finger detected");
//       return -1;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return -2;
//     case FINGERPRINT_IMAGEFAIL:
//       Serial.println("Imaging error");
//       return -2;
//     default:
//       Serial.println("Unknown error");
//       return -2;
//   }

//   // OK success!

//   p = finger.image2Tz();
//   switch (p) 
//   {
//     case FINGERPRINT_OK:
//       Serial.println("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       Serial.println("Image too messy");
//       return -2;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return -2;
//     case FINGERPRINT_FEATUREFAIL:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     case FINGERPRINT_INVALIDIMAGE:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     default:
//       Serial.println("Unknown error");
//       return -2;
//   }

//   // OK converted!
//   p = finger.fingerSearch();
//   if (p == FINGERPRINT_OK) 
//   {
//     Serial.println("Found a print match!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
//     Serial.println("Communication error");
//     return -2;
//   } else if (p == FINGERPRINT_NOTFOUND) {
//     Serial.println("Did not find a match");
//     return 0;
//   } else {
//     Serial.println("Unknown error");
//     return -2;
//   }

//   // found a match!
//   Serial.print("Found ID #"); Serial.print(finger.fingerID);
//   Serial.print(" with confidence of "); Serial.println(finger.confidence);

//   return finger.fingerID;
// }

// //Enrolls fingerprint, returning -2 if there is an error, otherwise return 1
// int getFingerprintEnroll(int id) 
// {

//   int p = -1;
//   Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
//   drawFingerprintRetryMenu();
//   while (p != FINGERPRINT_OK) 
//   {
//     p = finger.getImage();
//     switch (p) 
//     {
//     case FINGERPRINT_OK:
//       Serial.println("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       Serial.println(".");
//       break;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       break;
//     case FINGERPRINT_IMAGEFAIL:
//       Serial.println("Imaging error");
//       break;
//     default:
//       Serial.println("Unknown error");
//       break;
//     }
//   }

//   // OK success!

//   p = finger.image2Tz(1);
//   switch (p) 
//   {
//     case FINGERPRINT_OK:
//       Serial.println("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       Serial.println("Image too messy");
//       return -2;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return -2;
//     case FINGERPRINT_FEATUREFAIL:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     case FINGERPRINT_INVALIDIMAGE:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     default:
//       Serial.println("Unknown error");
//       return -2;
//   }

//   Serial.println("Remove finger");
//   drawFingerprintRemoveMenu();
//   delay(1000);
//   p = 0;
//   while (p != FINGERPRINT_NOFINGER) 
//   {
//     p = finger.getImage();
//   }
//   Serial.print("ID "); Serial.println(id);
//   p = -1;
//   Serial.println("Place same finger again");
//   drawFingerprintRetryMenu();
//   while (p != FINGERPRINT_OK) 
//   {
//     p = finger.getImage();
//     switch (p) {
//     case FINGERPRINT_OK:
//       Serial.println("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       Serial.print(".");
//       break;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       break;
//     case FINGERPRINT_IMAGEFAIL:
//       Serial.println("Imaging error");
//       break;
//     default:
//       Serial.println("Unknown error");
//       break;
//     }
//   }

//   // OK success!

//   p = finger.image2Tz(2);
//   switch (p) 
//   {
//     case FINGERPRINT_OK:
//       Serial.println("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       Serial.println("Image too messy");
//       return -2;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return -2;
//     case FINGERPRINT_FEATUREFAIL:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     case FINGERPRINT_INVALIDIMAGE:
//       Serial.println("Could not find fingerprint features");
//       return -2;
//     default:
//       Serial.println("Unknown error");
//       return -2;
//   }

//   // OK converted!
//   Serial.print("Creating model for #");  Serial.println(id);

//   p = finger.createModel();
//   if (p == FINGERPRINT_OK) 
//   {
//     Serial.println("Prints matched!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) 
//   {
//     Serial.println("Communication error");
//     return -2;
//   } else if (p == FINGERPRINT_ENROLLMISMATCH) 
//   {
//     Serial.println("Fingerprints did not match");
//     return -2;
//   } else {
//     Serial.println("Unknown error");
//     return -2;
//   }

//   Serial.print("ID "); Serial.println(id);
//   p = finger.storeModel(id);
//   if (p == FINGERPRINT_OK) 
//   {
//     Serial.println("Stored!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) 
//   {
//     Serial.println("Communication error");
//     return -2;
//   } else if (p == FINGERPRINT_BADLOCATION) 
//   {
//     Serial.println("Could not store in that location");
//     return -2;
//   } else if (p == FINGERPRINT_FLASHERR) 
//   {
//     Serial.println("Error writing to flash");
//     return -2;
//   } else {
//     Serial.println("Unknown error");
//     return -2;
//   }

//   return 1;
// }

// /*-----------------------------------------------------*/
// /*-------------------DISPLAY FUNCTIONS-----------------*/
// /*-----------------------------------------------------*/

// //Draws a square with the compartment numer in it
// void drawSquare(int num, int x, int y) 
// {
//   display.fillRect(x, y, 30, 30, SSD1306_WHITE);

//   display.setTextSize(3);
//   display.setTextColor(SSD1306_BLACK);
//   display.cp437(true);

//   display.setCursor(x+8, y+4);
//   display.write(String(num).c_str());

//   display.display();
// }

// //Draws a lock with the compartment number, locked or unlocked based on input
// void drawLock(int lockNum, int x) 
// {
//   display.fillRect(x+4, 5, 22, 18, SSD1306_BLACK);
//   drawSquare(lockNum, x, 23);
//   if(getLockerPointer(lockNum)->isLocked) 
//   {
//     display.fillRect(x+4, 12, 22, 11, SSD1306_WHITE);
//     display.fillRect(x+10, 17, 10, 6, SSD1306_BLACK);
//   }
//   else 
//   {
//     display.fillRect(x+4, 5, 22, 18, SSD1306_WHITE);
//     display.fillRect(x+10, 10, 10, 6, SSD1306_BLACK);
//     display.fillRect(x+10, 16, 16, 7, SSD1306_BLACK);
//   }
//   display.display();
// }

// //Draws main menu with three locks
// void drawMainMenu() 
// {
//   display.clearDisplay();

//   drawLock(1, 9);
//   drawLock(2, 49);
//   drawLock(3, 89);
// }

// //Draws menu where user can select input methods
// void drawUnlockedMenu(int num) 
// {
//   display.clearDisplay();

//   drawSquare(num, 12, 5);

//   display.setTextSize(1);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   if(getLockerPointer(num)->usingTimer)
//   {
//     addChecks(1, true);
//   }
//   else
//   {
//     addChecks(1, false);
//   }

//   display.setCursor(70, 5);
//   display.write("1:Timer");

//   if(getLockerPointer(num)->usingPin)
//   {
//     addChecks(2, true);
//   }
//   else
//   {
//     addChecks(2, false);
//   } 

//   display.setCursor(70, 22);
//   display.write("2:Code");

//   if(getLockerPointer(num)->usingRFID)
//   {
//     addChecks(3, true);
//   }
//   else
//   {
//     addChecks(3, false);
//   }

//   display.setCursor(70, 39);
//   display.write("3:RFID");

//   if(getLockerPointer(num)->usingFP)
//   {
//     addChecks(4, true);
//   }
//   else
//   {
//     addChecks(4, false);
//   }

//   display.setCursor(70, 56);
//   display.write("4:FPrint");

//   display.setCursor(10, 56);
//   display.write("*:Back");

//   drawExtraLine(num);

//   display.display();
// }

// void drawExtraLine(int num)
// {
//   if(getLockerPointer(num)->usingTimer || getLockerPointer(num)->usingPin || getLockerPointer(num)->usingRFID || getLockerPointer(num)->usingFP)
//   {
//     if(getReed(currentComp->number))
//     {
//       drawLockOption(false);
//       drawClosePrompt(true);
//     }
//     else
//     {
//       drawClosePrompt(false);
//       drawLockOption(true);
//     }
//   }
//   else
//   {
//     drawClosePrompt(false);
//     drawLockOption(false);
//   }
//   display.display();
// }

// //If true, draw Lock option on the configuration screen, otherwise remove it
// void drawLockOption(bool isOff) 
// {
//   if(isOff)
//   {
//     display.setTextColor(SSD1306_WHITE);
//   }
//   else
//   {
//     display.setTextColor(SSD1306_BLACK);
//   }
//   display.setTextSize(1);
//   display.setCursor(10, 39);
//   display.write("#:Lock");

//   display.display();
// }

// void drawClosePrompt(bool isOff)
// {
//   if(isOff)
//   {
//     display.setTextColor(SSD1306_WHITE);
//   }
//   else
//   {
//     display.setTextColor(SSD1306_BLACK);
//   }
//   display.setTextSize(1);
//   display.setCursor(10, 39);
//   display.write("Close!");

//   display.display();
// }

// //Draws either a O or X for the line given, O if true, X if false
// void addChecks(int line, bool isOff) 
// {
//   display.setTextSize(1);
//   display.cp437(true);

//   display.setTextColor(SSD1306_BLACK);

//   if(isOff) 
//   {
//     switch(line)
//     {
//       case 1:
//         display.setCursor(60, 5);    
//         display.write("X");
//         break;

//       case 2:
//         display.setCursor(60, 22);
//         display.write("X");
//         break;

//       case 3:
//         display.setCursor(60, 39);
//         display.write("X");
//         break;

//       case 4:
//         display.setCursor(60, 56);
//         display.write("X");
//         break;

//       default:
//         break;
//     }
//   }
//   else
//   {
//     switch(line)
//     {
//       case 1:
//         display.setCursor(60, 5);
//         display.write("O");
//         break;

//       case 2:
//         display.setCursor(60, 22);
//         display.write("O");
//         break;

//       case 3:
//         display.setCursor(60, 39);
//         display.write("O");
//         break;

//       case 4:
//         display.setCursor(60, 56);
//         display.write("O");
//         break;

//       default:
//         break;
//     }
//   }

//   display.setTextColor(SSD1306_WHITE);

//   if(isOff)
//   {
//     switch(line)
//     {
//       case 1:
//         display.setCursor(60, 5);
//         display.write("O");
//         break;

//       case 2:
//         display.setCursor(60, 22);
//         display.write("O");
//         break;

//       case 3:
//         display.setCursor(60, 39);
//         display.write("O");
//         break;

//       case 4:
//         display.setCursor(60, 56);
//         display.write("O");
//         break;

//       default:
//         break;
//     }
//   }
//   else
//   {
//     switch(line)
//     {
//       case 1:
//         display.setCursor(60, 5);    
//         display.write("X");
//         break;

//       case 2:
//         display.setCursor(60, 22);
//         display.write("X");
//         break;

//       case 3:
//         display.setCursor(60, 39);
//         display.write("X");
//         break;

//       case 4:
//         display.setCursor(60, 56);
//         display.write("X");
//         break;

//       default:
//         break;
//     }
//   }
//   display.display();
// }

// //Draws menu where user inputs timer length
// void drawTimerMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(3);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(1, 20);
//   display.write("__");

//   display.setCursor(display.getCursorX(), 15);
//   display.write("h:");

//   display.setCursor(display.getCursorX(), 20);
//   display.write("__");

//   display.setCursor(display.getCursorX(), 15);
//   display.write("m");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.setCursor(75, 55);
//   display.write("#:Submit");

//   //remove later
//   // display.setTextSize(3);
//   // display.setCursor(1, 15);
//   // display.write("12  34");

//   display.display();
// }

// void updateTimer()
// {
//   display.setTextSize(3);
//   display.setCursor(1, 15);
//   display.write(enteredPin[0]);
//   display.write(enteredPin[1]);
//   display.write("  ");
//   display.write(enteredPin[2]);
//   display.write(enteredPin[3]);
//   display.display();
// }

// //Draws menu where user inputs passcode
// void drawPasscodeMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(3);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(30, 20);
//   display.write("____");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.setCursor(75, 55);
//   display.write("#:Submit");

//   //remove later
//   // display.setTextSize(3);
//   // display.setCursor(30, 15);
//   // display.write("1234");

//   display.display();
// }

// //Update the pin display using enteredPin
// void updatePasscode()
// {
//   display.setTextSize(3);
//   display.setCursor(30, 15);
//   display.write(enteredPin);
//   display.display();
// }
// //Draws menu where user is prompted to scan thir RFID tag
// void drawRFIDMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(2);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(10, 20);
//   display.write("Scan RFID");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.display();
// }

// //Draws screen where user is initially prompted to scan their finger
// void drawFingerprintMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(1,2);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(30, 10);
//   display.write("Place Finger");

//   display.setCursor(35, 30);
//   display.write("On Scanner");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.display();
// }

// //Draws screen where user is prompted to remove their finger
// void drawFingerprintRemoveMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(1,2);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(25, 10);
//   display.write("Remove Finger");

//   display.setCursor(28, 30);
//   display.write("From Scanner");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.display();
// }

// //Draws screen where user is prompted to re-place their finger on the scanner
// void drawFingerprintRetryMenu() 
// {
//   display.clearDisplay();

//   display.setTextSize(1,2);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setCursor(20, 10);
//   display.write("Re-Place Finger");

//   display.setCursor(35, 30);
//   display.write("On Scanner");

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.display();
// }

// //Draws menu where user can see compartment timer and choose to manually unlock
// void drawViewMenu(int num) 
// {
//   display.clearDisplay();

//   drawSquare(num, 5, 10);

//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);

//   display.setTextSize(1);

//   display.setCursor(5, 55);
//   display.write("*:Back");

//   display.setCursor(75, 55);
//   display.write("#:Unlock");

//   display.display();
// }

// //Draws timer on the ViewMenu screen, in the format _ _ h : _ _ m, writes "No Timer" if disabled
// void drawTimer(int num) 
// {
//   if(!(getLockerPointer(num)->usingTimer))
//   {
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(1);
//     display.setCursor(58, 21);
//     display.write("No Timer");
//     return;
//   }
//   uint32_t time = millis();

//   unsigned long seconds = (getLockerPointer(num)->unlockTime-time)/1000;
//   unsigned long minute = (seconds/60)%60;
//   unsigned long hour = (seconds/3600)%100;

//   String hours = String(hour);
//   String minutes = String(minute);

//   display.fillRect(40, 18, 86, 15, SSD1306_BLACK);

//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);
//   display.setTextSize(2);
//   display.setCursor(40, 18);
  
//   if(hour<10) 
//   {
//     display.write("0");
//   }
//   display.write(hours.c_str());
//   display.write("h:");

//   if(minute<10) 
//   {
//     display.write("0");
//   }
//   display.write(minutes.c_str());
//   display.write("m");

//   display.display();

// }

// //Draws settings menu that has vibration option and displays tamper detection
// void drawSettings()
// {
//   display.clearDisplay();

//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);
//   display.setTextSize(1);

//   display.setCursor(5,5);
//   display.write("#:Call Detection");

//   display.setCursor(5,15);
//   display.write("Early Entry:");

//   display.setCursor(5,25);
//   display.write("Locker 1:");
//   display.setCursor(5,35);
//   display.write("Locker 2:");
//   display.setCursor(5,45);
//   display.write("Locker 3:");

//   display.setCursor(85, 55);
//   display.write("*:Back");

//   drawTamperMarks();

//   display.display();
// }


// void drawTamperMarks()
// {
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);
//   display.setTextSize(1);

//   if(locker1.openedEarly)
//   {
//     display.setCursor(60,25);
//     display.write("X");
//   }
//   if(locker2.openedEarly)
//   {
//     display.setCursor(60,35);
//     display.write("X");
//   }
//   if(locker3.openedEarly)
//   {
//     display.setCursor(60,45);
//     display.write("X");
//   }
//   display.display();
// }

