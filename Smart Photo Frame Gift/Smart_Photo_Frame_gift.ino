#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "TMRpcm.h"

#define TFT_CS  10  // Chip select line for TFT display
#define TFT_RST  8  // Reset line for TFT (or see below...)
#define TFT_DC   9  // Data/command line for TFT
#define SD_CS    4  // Chip select line for SD card

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//adding buttion for secret space
const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

TMRpcm tmrpcm;

void setup(void) {
//initialize speaker pin
 tmrpcm.speakerPin=9;
 // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
//speaker part
if(!SD.begin(SD_CS))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);
tmrpcm.play("test.wav");
//lcd part
  tft.initR(INITR_REDTAB);

  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
    return;
  }
  Serial.println("OK!");

  tft.setRotation(0); // Horizontal ,,, put 1 for Landscape

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && HIGH && HIGH)  
  {

 bmpDraw("x1.bmp", 0, 0);
  delay(3000);
  bmpDraw("x2.bmp", 0, 0);
  delay(3000);
  bmpDraw("x3.bmp", 0, 0);
  delay(3000);
  bmpDraw("x4.bmp", 0, 0);
  delay(3000);
   bmpDraw("x5.bmp", 0, 0);
  delay(3000);
   bmpDraw("x6.bmp", 0, 0);
  delay(3000);
   bmpDraw("x7.bmp", 0, 0);
  delay(3000);
   bmpDraw("x8.bmp", 0, 0);
  delay(3000);
   bmpDraw("x9.bmp", 0, 0);
  delay(3000);
   bmpDraw("x10.bmp", 0, 0);
  delay(3000);
   bmpDraw("x11.bmp", 0, 0);
  delay(3000);
   bmpDraw("x12.bmp", 0, 0);
  delay(3000);
   bmpDraw("x13.bmp", 0, 0);
  delay(3000);
   bmpDraw("x14.bmp", 0, 0);
  delay(3000);
   bmpDraw("x15.bmp", 0, 0);
  delay(3000);
  bmpDraw("x16.bmp", 0, 0);
  delay(3000);
   bmpDraw("x17.bmp", 0, 0);
  delay(3000);
   bmpDraw("x18.bmp", 0, 0);
  delay(3000);
   bmpDraw("x19.bmp", 0, 0);
  delay(3000);
   bmpDraw("x20.bmp", 0, 0);
  delay(3000);
   bmpDraw("x21.bmp", 0, 0);
  delay(3000);
   bmpDraw("x22.bmp", 0, 0);
  delay(3000);
   bmpDraw("x23.bmp", 0, 0);
  delay(3000);
   bmpDraw("x24.bmp", 0, 0);
  delay(3000);
 } 
 else {

 bmpDraw("r1.bmp",0,0);
  delay(3000);
 bmpDraw("r2.bmp",0,0);
  delay(3000);
  bmpDraw("r3.bmp",0,0);
  delay(3000);
  bmpDraw("r4.bmp",0,0);
  delay(3000);
  bmpDraw("r5.bmp",0,0);
  delay(3000);
  bmpDraw("r6.bmp",0,0);
  delay(3000);
  bmpDraw("r7.bmp",0,0);
  delay(3000);
  bmpDraw("r8.bmp",0,0);
  delay(3000);
  bmpDraw("r9.bmp",0,0);
  delay(3000);
  bmpDraw("r10.bmp",0,0);
  delay(3000);
  bmpDraw("r11.bmp",0,0);
  delay(3000);
  bmpDraw("r12.bmp",0,0);
  delay(3000);
  bmpDraw("r13.bmp",0,0);
  delay(3000);
  bmpDraw("r14.bmp",0,0);
  delay(3000);
  bmpDraw("r15.bmp",0,0);
  delay(3000);
  bmpDraw("r16.bmp",0,0);
  delay(3000);
  bmpDraw("r17.bmp",0,0);
  delay(3000);
  bmpDraw("r18.bmp",0,0);
  delay(3000);
  bmpDraw("r19.bmp",0,0);
  delay(3000);
  bmpDraw("r20.bmp",0,0);
  delay(3000);
  bmpDraw("r21.bmp",0,0);
  delay(3000);
  bmpDraw("r22.bmp",0,0);
  delay(3000);
  bmpDraw("r23.bmp",0,0);
  delay(3000);
  bmpDraw("r24.bmp",0,0);
  delay(3000);
  bmpDraw("r25.bmp",0,0);
  delay(3000);
  bmpDraw("r26.bmp",0,0);
  delay(3000);
  }
}


#define BUFFPIXEL 20

void bmpDraw(char *filename, uint8_t x, uint8_t y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();

  if((x >= tft.width()) || (y >= tft.height())) return;

  Serial.println();
  Serial.print("Loading image '");
  Serial.print(filename);
  Serial.println('\'');

  // Open requested file on SD card
  if ((bmpFile = SD.open(filename)) == NULL) {
    Serial.print("File not found");
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.print("File size: "); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print("Image Offset: "); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print("Header size: "); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print("Bit Depth: "); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        Serial.print("Image size: ");
        Serial.print(bmpWidth);
        Serial.print('x');
        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x+w-1, y+h-1);

        for (row=0; row<h; row++) { // For each scanline...

          // Seek to start of scan line.  It might seem labor-
          // intensive to be doing this on every line, but this
          // method covers a lot of gritty details like cropping
          // and scanline padding.  Also, the seek only takes
          // place if the file position actually needs to change
          // (avoids a lot of cluster math in SD library).
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each pixel...
            // Time to read more pixel data?
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format, push to display
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            tft.pushColor(tft.Color565(r,g,b));
          } // end pixel
        } // end scanline
        Serial.print("Loaded in ");
        Serial.print(millis() - startTime);
        Serial.println(" ms");
      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println("BMP format not recognized.");
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

uint16_t read16(File f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}
