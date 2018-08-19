#include"fileData.h"
#include<string>
#include<fstream>
#include<Windows.h>
#include<iostream>
#include<vector>

fileData::fileData(string &name){
	//getting data 
	ifstream picture(name, ios_base::binary);
	picture.read(&idLength, 1);
	picture.read(&colorMapType, 1);
	picture.read(&dataTypeCode, 1);
	picture.read((char*)&colorMapOrigin, 2);
	picture.read((char*)&colorMapLength, 2);
	picture.read(&colorMapDepth, 1);
	picture.read((char*)&xOrigin, 2);
	picture.read((char*)&yOrigin, 2);
	picture.read((char*)&width, 2);
	picture.read((char*)&height, 2);
	picture.read(&bitsPerPixel, 1);
	picture.read(&imageDescriptor, 1);
	//each pixel has 3 values associated with it R,G,B
	size = 3 * width * height;
	pixelData = new unsigned char[size];
	//first component is blue,green,red
	for (int i = 0; i < size; i++) {
		picture.read((char*)&pixelData[i], 1);
	}
	int count = 0; 
	//FIXME 
	unsigned char pixels[600][512][3];
	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			for (int c = 0; c < 3; c++) {
				pixels[i][j][c] = pixelData[count];
				count++;
			}
		}
	}
	
	//image viewing 
		HWND myconsole = GetActiveWindow();
		HDC mydc = GetDC(myconsole);
			for (int i = 0; i <height; i++) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)pixels[j][i][2],(int) pixels[j][i][1],(int)pixels[j][i][0]));
				}
			}
		ReleaseDC(myconsole, mydc);
	}



unsigned char* fileData::getPixelData() {
	return pixelData;
}
int fileData::getSize() {
	return size;
}
int fileData::getHeight() {
	return height;
}
int fileData::getWidth() {
	return width;
}

