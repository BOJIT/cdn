#include <Keyboard.h> //

int SerialCode;

int latchPin = 8;
int clockPin = 16;
int dataPin = 14;
int Read1 = 2;
int Read2 = 3;
int Read3 = 4;
int Read4 = 5;
int Read5 = 6;

int refresh = 2;
int debounce = 30;
int Column1[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LastColumn1[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int Column2[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LastColumn2[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int Column3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LastColumn3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int Column4[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LastColumn4[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int Column5[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LastColumn5[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

byte scan1 = 0;
byte scan2 = 0;

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, scan2);
   shiftOut(dataPin, clockPin, LSBFIRST, scan1);
   digitalWrite(latchPin, HIGH);
}

void setup() 
{

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(Read1, INPUT);
//  Serial.begin (9600);
  Serial1.begin(9600);
  Keyboard.begin();
}
void loop() {

//////////Encoder//////////
  if (Serial1.available()) {
    SerialCode = Serial1.read();
    Keyboard.write(SerialCode);
  }

/////////////1/////////////
  
   delay(refresh);
   updateShiftRegister();
   scan1 = B10000000;
   scan2 = B00000000;   
   Column1[0] = digitalRead(Read1);
      if (Column1[0] != LastColumn1[0])
          {
            if (Column1[0] == 1)
              {
                Keyboard.write(45); // ESC. RELEASE Key
              }
            delay(debounce); 
          }
      LastColumn1[0] = Column1[0];
   Column2[0] = digitalRead(Read2);
      if (Column2[0] != LastColumn2[0])
          {
            if (Column2[0] == 1)
              {
                Keyboard.write(96); // Add Swap Arrow Key Flash
              }
            delay(debounce); 
          }
      if (Column2[0] != LastColumn2[0])
          {
            if (Column2[0] == 0)
              {
                Keyboard.write(96); // Add Swap Arrow Key Flash
              }
            delay(debounce); 
          }
      LastColumn2[0] = Column2[0];
   Column3[0] = digitalRead(Read3);
      if (Column3[0] != LastColumn3[0])
          {
            if (Column3[0] == 1)
              {
                Keyboard.write(41); // Flash Button 4 ON
              }
            delay(debounce); 
          }
     if (Column3[0] != LastColumn3[0])
          {
            if (Column3[0] == 0)
              {
                Keyboard.write(42); // Flash Button 4 OFF
              }
            delay(debounce); 
          }
      LastColumn3[0] = Column3[0];
   Column4[0] = digitalRead(Read4);
      if (Column4[0] != LastColumn4[0])
          {
            if (Column4[0] == 1)
              {
                Keyboard.write(43); // Flash Button 8 ON
              }
            delay(debounce); 
          }
     if (Column4[0] != LastColumn4[0])
          {
            if (Column4[0] == 0)
              {
                Keyboard.write(44); // Flash Button 8 OFF
              }
            delay(debounce); 
          }
      LastColumn4[0] = Column4[0];
   Column5[0] = digitalRead(Read5);
      if (Column5[0] != LastColumn5[0])
          {
            if (Column5[0] == 1)
              {
               // Keyboard.write(65); //??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
              }
            delay(debounce); 
          }
      LastColumn5[0] = Column5[0];

/////////////2//////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B01000000;
   Column1[1] = digitalRead(Read1);
      if (Column1[1] != LastColumn1[1])
          {
            if (Column1[1] == 1)
              {
                Keyboard.press(128); // F8 Beam Key
                Keyboard.press(106);
                Keyboard.release(106);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[1] = Column1[1];
   Column2[1] = digitalRead(Read2);
      if (Column2[1] != LastColumn2[1])
          {
            if (Column2[1] == 1)
              {
                Keyboard.write(68); // DEL. Key
              }
            delay(debounce); 
          }
      LastColumn2[1] = Column2[1];
   Column3[1] = digitalRead(Read3);
      if (Column3[1] != LastColumn3[1])
          {
            if (Column3[1] == 1)
              {
                Keyboard.write(102); // Pause Button 4
              }
            delay(debounce); 
          }
      LastColumn3[1] = Column3[1];
   Column4[1] = digitalRead(Read4);
      if (Column4[1] != LastColumn4[1])
          {
            if (Column4[1] == 1)
              {
                Keyboard.write(107); // Pause Button 8
              }
            delay(debounce); 
          }
      LastColumn4[1] = Column4[1];
   Column5[1] = digitalRead(Read5);
      if (Column5[1] != LastColumn5[1])
          {
            if (Column5[1] == 1)
              {
             //   Keyboard.write(65); //???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
              }
            delay(debounce); 
          }
      LastColumn5[1] = Column5[1];

/////////////3/////////////
  
   delay(refresh);
   updateShiftRegister();
   scan1 = B00100000;
   Column1[2] = digitalRead(Read1);
      if (Column1[2] != LastColumn1[2])
          {
            if (Column1[2] == 1)
              {
                Keyboard.press(128); // F4 Patch Key
                Keyboard.press(116);
                Keyboard.release(116);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[2] = Column1[2];
   Column2[2] = digitalRead(Read2);
      if (Column2[2] != LastColumn2[2])
          {
            if (Column2[2] == 1)
              {
                Keyboard.write(98); // Fan Key
              }
            delay(debounce); 
          }
      LastColumn2[2] = Column2[2];
   Column3[2] = digitalRead(Read3);
      if (Column3[2] != LastColumn3[2])
          {
            if (Column3[2] == 1)
              {
                Keyboard.write(52); // Select Button 4
              }
            delay(debounce); 
          }
      LastColumn3[2] = Column3[2];
   Column4[2] = digitalRead(Read4);
      if (Column4[2] != LastColumn4[2])
          {
            if (Column4[2] == 1)
              {
                Keyboard.write(55); // Select Button 7
              }
            delay(debounce); 
          }
      LastColumn4[2] = Column4[2];
   Column5[2] = digitalRead(Read5);
      if (Column5[2] != LastColumn5[2])
          {
            if (Column5[2] == 1)
              {
              //  Keyboard.write(65); //????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
              }
            delay(debounce); 
          }
      LastColumn5[2] = Column5[2];

/////////////4/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B00010000; 
   Column1[3] = digitalRead(Read1);
      if (Column1[3] != LastColumn1[3])
          {
            if (Column1[3] == 1)
              {
                Keyboard.press(128); // F7 Colour Key
                Keyboard.press(107);
                Keyboard.release(107);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[3] = Column1[3];
   Column2[3] = digitalRead(Read2);
      if (Column2[3] != LastColumn2[3])
          {
            if (Column2[3] == 1)
              {
                Keyboard.write(73); // Include Key
              }
            delay(debounce); 
          }
      LastColumn2[3] = Column2[3];
   Column3[3] = digitalRead(Read3);
      if (Column3[3] != LastColumn3[3])
          {
            if (Column3[3] == 1)
              {
                Keyboard.write(100); // Pause Button 3
              }
            delay(debounce); 
          }
      LastColumn3[3] = Column3[3];
   Column4[3] = digitalRead(Read4);
      if (Column4[3] != LastColumn4[3])
          {
            if (Column4[3] == 1)
              {
                Keyboard.write(106); // Pause Button 7
              }
            delay(debounce); 
          }
      LastColumn4[3] = Column4[3];
   Column5[3] = digitalRead(Read5);
      if (Column5[3] != LastColumn5[3])
          {
            if (Column5[3] == 1)
              {
                Keyboard.write(91); // Page Up Key
              }
            delay(debounce); 
          }
      LastColumn5[3] = Column5[3];

/////////////5/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B00001000;
   Column1[4] = digitalRead(Read1);
      if (Column1[4] != LastColumn1[4])
          {
            if (Column1[4] == 1)
              {
                Keyboard.write(61); // F3 Key CLOSE WINDOW
              }
            delay(debounce); 
          }
      LastColumn1[4] = Column1[4];
   Column2[4] = digitalRead(Read2);
      if (Column2[4] != LastColumn2[4])
          {
            if (Column2[4] == 1)
              {
                Keyboard.write(77); // Move Key
              }
            delay(debounce); 
          }
      LastColumn2[4] = Column2[4];
   Column3[4] = digitalRead(Read3);
      if (Column3[4] != LastColumn3[4])
          {
            if (Column3[4] == 1)
              {
                Keyboard.write(51); // Select Button 3
              }
            delay(debounce); 
          }
      LastColumn3[4] = Column3[4];
   Column4[4] = digitalRead(Read4);
      if (Column4[4] != LastColumn4[4])
          {
            if (Column4[4] == 1)
              {
                Keyboard.write(56); // Select Button 8
              }
            delay(debounce); 
          }
      LastColumn4[4] = Column4[4];
   Column5[4] = digitalRead(Read5);
      if (Column5[4] != LastColumn5[4])
          {
            if (Column5[4] == 1)
              {
                Keyboard.write(78); // Next Head Key
              }
            delay(debounce); 
          }
      LastColumn5[4] = Column5[4];
      
/////////////6/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B00000100; 
   Column1[5] = digitalRead(Read1);
      if (Column1[5] != LastColumn1[5])
          {
            if (Column1[5] == 1)
              {
                Keyboard.press(128); // Play Back Key
                Keyboard.press(108);
                Keyboard.release(108);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[5] = Column1[5];
   Column2[5] = digitalRead(Read2);
      if (Column2[5] != LastColumn2[5])
          {
            if (Column2[5] == 1)
              {
                Keyboard.write(82); // Record Key
              }
            delay(debounce); 
          }
      LastColumn2[5] = Column2[5];
   Column3[5] = digitalRead(Read3);
      if (Column3[5] != LastColumn3[5])
          {
            if (Column3[5] == 1)
              {
                Keyboard.write(50); // Select Button 2
              }
            delay(debounce); 
          }
      LastColumn3[5] = Column3[5];
   Column4[5] = digitalRead(Read4);
      if (Column4[5] != LastColumn4[5])
          {
            if (Column4[5] == 1)
              {
                Keyboard.write(54); // Select Button 6
              }
            delay(debounce); 
          }
      LastColumn4[5] = Column4[5];
   Column5[5] = digitalRead(Read5);
      if (Column5[5] != LastColumn5[5])
          {
            if (Column5[5] == 1)
              {
                Keyboard.write(48); // Select Button 10
              }
            delay(debounce); 
          }
      LastColumn5[5] = Column5[5];

/////////////7/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B00000010; 
   Column1[6] = digitalRead(Read1);
      if (Column1[6] != LastColumn1[6])
          {
            if (Column1[6] == 1)
              {
                Keyboard.write(47); // Layout 1
              }
            delay(debounce); 
          }
      LastColumn1[6] = Column1[6];
   Column2[6] = digitalRead(Read2);
      if (Column2[6] != LastColumn2[6])
          {
            if (Column2[6] == 1)
              {
                Keyboard.write(66); // Blind Key
              }
            delay(debounce); 
          }
      LastColumn2[6] = Column2[6];
   Column3[6] = digitalRead(Read3);
      if (Column3[6] != LastColumn3[6])
          {
            if (Column3[6] == 1)
              {
                Keyboard.write(115); // Pause Button 2
              }
            delay(debounce); 
          }
      LastColumn3[6] = Column3[6];
   Column4[6] = digitalRead(Read4);
      if (Column4[6] != LastColumn4[6])
          {
            if (Column4[6] == 1)
              {
                Keyboard.write(104); // Pause Button 6
              }
            delay(debounce); 
          }
      LastColumn4[6] = Column4[6];
   Column5[6] = digitalRead(Read5);
      if (Column5[6] != LastColumn5[6])
          {
            if (Column5[6] == 1)
              {
                Keyboard.write(59); // Pause Button 10
              }
            delay(debounce); 
          }
      LastColumn5[6] = Column5[6];

/////////////8/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan1 = B00000001; 
   Column1[7] = digitalRead(Read1);
      if (Column1[7] != LastColumn1[7])
          {
            if (Column1[7] == 1)
              {
                Keyboard.press(128); // Intensity Key
                Keyboard.press(103);
                Keyboard.release(103);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[7] = Column1[7];
   Column2[7] = digitalRead(Read2);
      if (Column2[7] != LastColumn2[7])
          {
            if (Column2[7] == 1)
              {
                Keyboard.write(35); // Encoder Button C
              }
            delay(debounce); 
          }
      LastColumn2[7] = Column2[7];
   Column3[7] = digitalRead(Read3);
      if (Column3[7] != LastColumn3[7])
          {
            if (Column3[7] == 1)
              {
                Keyboard.write(97); // Pause Button 1
              }
            delay(debounce); 
          }
      LastColumn3[7] = Column3[7];
   Column4[7] = digitalRead(Read4);
      if (Column4[7] != LastColumn4[7])
          {
            if (Column4[7] == 1)
              {
                Keyboard.write(103); // Pause Button 5
              }
            delay(debounce); 
          }
      LastColumn4[7] = Column4[7];
   Column5[7] = digitalRead(Read5);
      if (Column5[7] != LastColumn5[7])
          {
            if (Column5[7] == 1)
              {
                Keyboard.write(108); // Pause Button 9
              }
            delay(debounce); 
          }
      LastColumn5[7] = Column5[7];

//////////Encoder//////////
  if (Serial1.available()) {
    SerialCode = Serial1.read();
    Keyboard.write(SerialCode);
  }
  
/////////////9/////////////
      
   delay(refresh);
   updateShiftRegister();
   scan2 = B10000000;
   scan1 = B00000000; 
   Column1[8] = digitalRead(Read1);
      if (Column1[8] != LastColumn1[8])
          {
            if (Column1[8] == 1)
              {
                Keyboard.write(39); // Encoder Button X
              }
            delay(debounce); 
          }
      LastColumn1[8] = Column1[8];
   Column2[8] = digitalRead(Read2);
      if (Column2[8] != LastColumn2[8])
          {
            if (Column2[8] == 1)
              {
                Keyboard.write(33); // Encoder Button A
              }
            delay(debounce); 
          }
      LastColumn2[8] = Column2[8];
   Column3[8] = digitalRead(Read3);
      if (Column3[8] != LastColumn3[8])
          {
            if (Column3[8] == 1)
              {
                Keyboard.write(49); // Select Button 1
              }
            delay(debounce); 
          }
      LastColumn3[8] = Column3[8];
   Column4[8] = digitalRead(Read4);
      if (Column4[8] != LastColumn4[8])
          {
            if (Column4[8] == 1)
              {
                Keyboard.write(53); // Select Button 5
              }
            delay(debounce); 
          }
      LastColumn4[8] = Column4[8];
   Column5[8] = digitalRead(Read5);
      if (Column5[8] != LastColumn5[8])
          {
            if (Column5[8] == 1)
              {
                Keyboard.write(57); // Select Button 9
              }
            delay(debounce); 
          }
      LastColumn5[8] = Column5[8];

/////////////10/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B01000000; 
   Column1[9] = digitalRead(Read1);
      if (Column1[9] != LastColumn1[9])
          {
            if (Column1[9] == 1)
              {
                Keyboard.write(37); // Encoder Button E
              }
            delay(debounce); 
          }
      LastColumn1[9] = Column1[9];
   Column2[9] = digitalRead(Read2);
      if (Column2[9] != LastColumn2[9])
          {
            if (Column2[9] == 1)
              {
                Keyboard.write(34); // Encoder Button B
              }
            delay(debounce); 
          }
      LastColumn2[9] = Column2[9];
   Column3[9] = digitalRead(Read3);
      if (Column3[9] != LastColumn3[9])
          {
            if (Column3[9] == 1)
              {
                Keyboard.write(113); // Go Button 1
              }
            delay(debounce); 
          }
      LastColumn3[9] = Column3[9];
   Column4[9] = digitalRead(Read4);
      if (Column4[9] != LastColumn4[9])
          {
            if (Column4[9] == 1)
              {
                Keyboard.write(116); // Go Button 5
              }
            delay(debounce); 
          }
      LastColumn4[9] = Column4[9];
   Column5[9] = digitalRead(Read5);
      if (Column5[9] != LastColumn5[9])
          {
            if (Column5[9] == 1)
              {
                Keyboard.write(111); // Go Button 9
              }
            delay(debounce); 
          }
      LastColumn5[9] = Column5[9];

/////////////11/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00100000; 
   Column1[10] = digitalRead(Read1);
      if (Column1[10] != LastColumn1[10])
          {
            if (Column1[10] == 1)
              {
                Keyboard.write(38); // Encoder Button F
              }
            delay(debounce); 
          }
      LastColumn1[10] = Column1[10];
   Column2[10] = digitalRead(Read2);
      if (Column2[10] != LastColumn2[10])
          {
            if (Column2[10] == 1)
              {
                Keyboard.write(36); // Encoder Button D
              }
            delay(debounce); 
          }
      LastColumn2[10] = Column2[10];
   Column3[10] = digitalRead(Read3);
      if (Column3[10] != LastColumn3[10])
          {
            if (Column3[10] == 1)
              {
                Keyboard.write(94); // Flash Button 1 ON
              }
            delay(debounce); 
          }
      if (Column3[10] != LastColumn3[10])
          {
            if (Column3[10] == 0)
              {
                Keyboard.write(95); // Flash Button 1 OFF
              }
            delay(debounce); 
          }
      LastColumn3[10] = Column3[10];
   Column4[10] = digitalRead(Read4);
      if (Column4[10] != LastColumn4[10])
          {
            if (Column4[10] == 1)
              {
                Keyboard.write(63); // Flash Button 5 ON
              }
            delay(debounce); 
          }
      if (Column4[10] != LastColumn4[10])
          {
            if (Column4[10] == 0)
              {
                Keyboard.write(89); // Flash Button 5 OFF
              }
            delay(debounce); 
          }
      LastColumn4[10] = Column4[10];
   Column5[10] = digitalRead(Read5);
      if (Column5[10] != LastColumn5[10])
          {
            if (Column5[10] == 1)
              {
                Keyboard.write(123); // Flash Button 9 ON
              }
            delay(debounce); 
          }
      if (Column5[10] != LastColumn5[10])
          {
            if (Column5[10] == 0)
              {
                Keyboard.write(124); // Flash Button 9 OFF
              }
            delay(debounce); 
          }
      LastColumn5[10] = Column5[10];

/////////////12/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00010000; 
   Column1[11] = digitalRead(Read1);
      if (Column1[11] != LastColumn1[11])
          {
            if (Column1[11] == 1)
              {
                Keyboard.write(40); // Encoder Button Y
              }
            delay(debounce); 
          }
      LastColumn1[11] = Column1[11];
   Column2[11] = digitalRead(Read2);
      if (Column2[11] != LastColumn2[11])
          {
            if (Column2[11] == 1)
              {
                Keyboard.write(67); // Copy Key
              }
            delay(debounce); 
          }
      LastColumn2[11] = Column2[11];
   Column3[11] = digitalRead(Read3);
      if (Column3[11] != LastColumn3[11])
          {
            if (Column3[11] == 1)
              {
                Keyboard.write(119); // Go Button 2
              }
            delay(debounce); 
          }
      LastColumn3[11] = Column3[11];
   Column4[11] = digitalRead(Read4);
      if (Column4[11] != LastColumn4[11])
          {
            if (Column4[11] == 1)
              {
                Keyboard.write(121); // Go Button 6
              }
            delay(debounce); 
          }
      LastColumn4[11] = Column4[11];
   Column5[11] = digitalRead(Read5);
      if (Column5[11] != LastColumn5[11])
          {
            if (Column5[11] == 1)
              {
                Keyboard.write(112); // Go Button 10
              }
            delay(debounce); 
          }
      LastColumn5[11] = Column5[11];

/////////////13/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00001000;
   Column1[12] = digitalRead(Read1);
      if (Column1[12] != LastColumn1[12])
          {
            if (Column1[12] == 1)
              {
                Keyboard.press(128); // Home Key
                Keyboard.press(114);
                Keyboard.release(114);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[12] = Column1[12];
   Column2[12] = digitalRead(Read2);
      if (Column2[12] != LastColumn2[12])
          {
            if (Column2[12] == 1)
              {
                Keyboard.write(76); // Locate Key
              }
            delay(debounce); 
          }
      LastColumn2[12] = Column2[12];
   Column3[12] = digitalRead(Read3);
      if (Column3[12] != LastColumn3[12])
          {
            if (Column3[12] == 1)
              {
                Keyboard.write(101); // Go Button 3
              }
            delay(debounce); 
          }
      LastColumn3[12] = Column3[12];
   Column4[12] = digitalRead(Read4);
      if (Column4[12] != LastColumn4[12])
          {
            if (Column4[12] == 1)
              {
                Keyboard.write(117); // Go Button 7
              }
            delay(debounce); 
          }
      LastColumn4[12] = Column4[12];
   Column5[12] = digitalRead(Read5);
      if (Column5[12] != LastColumn5[12])
          {
            if (Column5[12] == 1)
              {
                Keyboard.write(80); // Previous Head Button
              }
            delay(debounce); 
          }
      LastColumn5[12] = Column5[12]; 

/////////////14/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00000100; 
   Column1[13] = digitalRead(Read1);
      if (Column1[13] != LastColumn1[13])
          {
            if (Column1[13] == 1)
              {
                Keyboard.press(128); // Position Key
                Keyboard.press(112);
                Keyboard.release(112);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[13] = Column1[13];
   Column2[13] = digitalRead(Read2);
      if (Column2[13] != LastColumn2[13])
          {
            if (Column2[13] == 1)
              {
                Keyboard.write(88); // Clear Prog. Key
              }
            delay(debounce); 
          }
      LastColumn2[13] = Column2[13];
   Column3[13] = digitalRead(Read3);
      if (Column3[13] != LastColumn3[13])
          {
            if (Column3[13] == 1)
              {
                Keyboard.write(69); // Flash Button 2 ON
              }
            delay(debounce); 
          }
      if (Column3[13] != LastColumn3[13])
          {
            if (Column3[13] == 0)
              {
                Keyboard.write(71); // Flash Button 2 OFF
              }
            delay(debounce); 
          }
      LastColumn3[13] = Column3[13];
   Column4[13] = digitalRead(Read4);
      if (Column4[13] != LastColumn4[13])
          {
            if (Column4[13] == 1)
              {
                Keyboard.write(84); // Flash Button 6 ON
              }
            delay(debounce); 
          }
      if (Column4[13] != LastColumn4[13])
          {
            if (Column4[13] == 0)
              {
                Keyboard.write(86); // Flash Button 6 OFF
              }
            delay(debounce); 
          }
      LastColumn4[13] = Column4[13];
   Column5[13] = digitalRead(Read5);
      if (Column5[13] != LastColumn5[13])
          {
            if (Column5[13] == 1)
              {
                Keyboard.write(72); // Flash Button 10 ON
              }
            delay(debounce); 
          }
      if (Column5[13] != LastColumn5[13])
          {
            if (Column5[13] == 0)
              {
                Keyboard.write(64); // Flash Button 10 OFF
              }
            delay(debounce); 
          }
      LastColumn5[13] = Column5[13];

/////////////15/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00000010;
   Column1[14] = digitalRead(Read1);
      if (Column1[14] != LastColumn1[14])
          {
            if (Column1[14] == 1)
              {
                Keyboard.write(92); // Layout 2
              }
            delay(debounce); 
          }
      LastColumn1[14] = Column1[14];
   Column2[14] = digitalRead(Read2);
      if (Column2[14] != LastColumn2[14])
          {
            if (Column2[14] == 1)
              {
                Keyboard.write(83); // Set Key
              }
            delay(debounce); 
          }
      LastColumn2[14] = Column2[14];
   Column3[14] = digitalRead(Read3);
      if (Column3[14] != LastColumn3[14])
          {
            if (Column3[14] == 1)
              {
                Keyboard.write(74); // Flash Button 3 ON
              }
            delay(debounce); 
          }
      if (Column3[14] != LastColumn3[14])
          {
            if (Column3[14] == 0)
              {
                Keyboard.write(75); // Flash Button 3 OFF
              }
            delay(debounce); 
          }
      LastColumn3[14] = Column3[14];
   Column4[14] = digitalRead(Read4);
      if (Column4[14] != LastColumn4[14])
          {
            if (Column4[14] == 1)
              {
                Keyboard.write(79); // Flash Button 7 ON
              }
            delay(debounce); 
          }
      if (Column4[14] != LastColumn4[14])
          {
            if (Column4[14] == 0)
              {
                Keyboard.write(81); // Flash Button 7 OFF
              }
            delay(debounce); 
          }
      LastColumn4[14] = Column4[14];
   Column5[14] = digitalRead(Read5);
      if (Column5[14] != LastColumn5[14])
          {
            if (Column5[14] == 1)
              {
                Keyboard.write(93); // Page Down Key
              }
            delay(debounce); 
          }
      LastColumn5[14] = Column5[14];

/////////////16/////////////

   delay(refresh);
   updateShiftRegister();
   scan2 = B00000001; 
   Column1[15] = digitalRead(Read1);
      if (Column1[15] != LastColumn1[15])
          {
            if (Column1[15] == 1)
              {
                Keyboard.press(128); // Cue Key
                Keyboard.press(113);
                Keyboard.release(113);
                Keyboard.release(128);
              }
            delay(debounce); 
          }
      LastColumn1[15] = Column1[15];
   Column2[15] = digitalRead(Read2);
      if (Column2[15] != LastColumn2[15])
          {
            if (Column2[15] == 1)
              {
                Keyboard.write(85); // Update Key
              }
            delay(debounce); 
          }
      LastColumn2[15] = Column2[15];
   Column3[15] = digitalRead(Read3);
      if (Column3[15] != LastColumn3[15])
          {
            if (Column3[15] == 1)
              {
                Keyboard.write(114); // Go Button 4
              }
            delay(debounce); 
          }
      LastColumn3[15] = Column3[15];
   Column4[15] = digitalRead(Read4);
      if (Column4[15] != LastColumn4[15])
          {
            if (Column4[15] == 1)
              {
                Keyboard.write(105); // Go Button 8
              }
            delay(debounce); 
          }
      LastColumn4[15] = Column4[15];
   Column5[15] = digitalRead(Read5);
      if (Column5[15] != LastColumn5[15])
          {
            if (Column5[15] == 1)
              {
               // Keyboard.write(65); //???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
              }
            delay(debounce); 
          }
      LastColumn5[15] = Column5[15];
   
}

