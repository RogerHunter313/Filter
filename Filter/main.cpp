#include <iostream>
//#include <cstdint>   //https://www.cplusplus.com/reference/cstdint/
#include <fstream>  //https://www.cplusplus.com/reference/fstream/fstream/
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

#include <math.h>

using namespace std;

// prototype 


int main() {
	// First, we are just going to create a bitmap, created.bmp from scratch

	// instantiate the BitmapFileHeader struct
	BitmapFileHeader fileHeader;

	// set the size and dataOffset in our fileHeader
	// the info of the bmp being created can be seen by opening the bmp and using the HEX-Editor plugin in notepad++
	// the first two hex symbols should always be 42 and 4d for the hex codes of B and M  https://www.ascii-code.com/ a byte in Hex is two digits
	fileHeader.fileSize = 0x0000005a; // this looks like 5a 00 00 00 in notepad++ because of the way the values are read
	fileHeader.dataOffset = 0x00000036;  //offset from beginnining of file to the beginning of the bitmap data, can check in notepad

	ofstream createdBMP; //virtual file created (not file accessible in windows created yet)

	createdBMP.open("created.bmp"); //make the virtual file real with designated name

	// this is writing some data in our new file. https://www.cplusplus.com/reference/ostream/ostream/write/
	// the arguments of write are (address of array cast to a char pointer, how many characters to write)
	createdBMP.write((char*)&fileHeader, sizeof(fileHeader));

	// a struct is created for in the infoheader in the same manner as the file header
	BitmapInfoHeader infoHeader;

	infoHeader.width = 0x00000003;  //making a small bmp with width and height set to 3 pixels
	infoHeader.height = 0x00000003;

	createdBMP.write((char*)&infoHeader, sizeof(infoHeader));

	//at this point we have both headers written and now we need to enter pixel data.  it's just RGB per pixel, but things are entered
	//in the file in reverse order so enter "BGR"
	int pWidth = infoHeader.width;
	int pHeight = infoHeader.height;

	// now we must include row padding. bits representing bitmap pixels are packed in rows
	// the size of each row is round up to a multiple of 4 bytes.  padding must be appended
	// to the end of rows in order to bring up the length of the rows to a multiple of four bytes
	// result is the length of bytes in the rows with the added padding
	int row_padded =pWidth * 3 + ( 4 - ((pWidth * 3) % 4)); // (pWidth * 3) + 4 - remainder(pWidth * 3 / 4)
	cout << "bytes in a row without padding: " << pWidth * 3 << endl;
	cout << "row padded: " << row_padded << endl;

	// i'm keeping this code I found below because apparently it does the same thing with bitwise operators...
	// int row_padded = (pWidth * 3 + 3) & (~3);
	// cout << "row padded 2 : " << row_padded << endl;

	char red = 0x00;
	char green = 0x00;
	char blue = 0xff;

	//fill every pixel in our new 3x3 bmp with the same color, .write goes in reverse order like a stream
	for (int i = 0; i < (row_padded * 3); i += 3) {
		createdBMP.write((char*)&blue, sizeof(blue));
		createdBMP.write((char*)&green, sizeof(green));
		createdBMP.write((char*)&red, sizeof(red));
	}

	createdBMP.close();


	return 0;
}