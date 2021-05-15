#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>   //includes 32 bit integer

using namespace std;

//https://stackoverflow.com/questions/3318410/pragma-pack-effect
#pragma pack(2)  //aligns the memory storage for the struct below in two byte boundaries to avoid any efficiency padding from the compiler

// the Header is 14 bytes which is the size of the header.
// the point of the structure is to just have a label set to the different
// parts of the header.  #pragmapack(2) ensures these are just bytes set in order with
// no padding
// http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
struct BitmapFileHeader {
	char header[2]{ 'B', 'M' };
	int32_t fileSize;
	int32_t reserved{ 0 }; //this is just set to zero with {}
	int32_t dataOffset;

};



#endif /* BITMAPFILEHEADER_H_ */