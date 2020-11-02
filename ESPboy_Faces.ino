/*
Faces - 18 emotions of Anki Cozmo
Port for ESPboy project by RomanS
www.espboy.com
*/

/***************************************************
Copyright (c) 2020 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#include "ESPboyInit.h"
#include "Face.h"

#define WIDTH  80 //it's HEIGHT on ESPboy
#define HEIGHT 128 //it's WIDTH on ESPboy
#define EYE 40


ESPboyInit myESPboy;
TFT_eSprite Buffer = TFT_eSprite(&myESPboy.tft);
Face face(Buffer, HEIGHT, WIDTH, EYE);

String emotionName[] = {
  "Normal",
  "Angry",
  "Glee",
  "Happy",
  "Sad",
  "Worried",
  "Focused",
  "Annoyed",
  "Surprised",
  "Skeptic",
  "Fustrated",
  "Unimpressed",
  "Sleepy",
  "Suspicious",
  "Squint",
  "Furious",
  "Scared",
  "Awe"};


void setup(void) {
  myESPboy.begin("ESPboy Faces");
  
  Buffer.setColorDepth(8);
  Buffer.createSprite(WIDTH, HEIGHT);
  face.Expression.GoTo_Normal();
  face.Behavior.Clear();
  myESPboy.tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  myESPboy.tft.setTextSize(2);
}


void loop() {
 static uint32_t counter=millis();
 static uint8_t emotionno=0;
 static uint8_t emotionflag=1;

 if (millis()-counter > 3000) {
   counter=millis();
   emotionno=random(EMOTIONS_COUNT);
   emotionflag=1;
 }
 
  if(emotionflag){
    emotionflag = 0;
    face.Behavior.Clear();
    face.Behavior.SetEmotion((eEmotions)emotionno, 1.0);
    myESPboy.tft.fillRect(0, 110, 128, 28, TFT_BLACK);
    myESPboy.tft.drawString(emotionName[emotionno],(128-(emotionName[emotionno].length()*12))/2, 110);
  }

  face.Update();
  delay(10);
}
