#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)  //To pack a class is to place its members directly after each other in memory

struct BitmapInfoHeader {
	int32_t headerSize{ 40 };			//this is the size of the this struct/BitmapInfoHeader.  This is the DIB Header, just set to 40 bytes
	int32_t width;
	int32_t height;
	int16_t planes{ 1 };
	int16_t bitsPerPixel{ 24 };
	int32_t compression{ 0 };
	int32_t dataSize{ 0 };
	int32_t horizontalResolution{ 2400 };
	int32_t verticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantColors{ 0 };

};





#endif /* BITMAPINFOHEADER_H_ */
