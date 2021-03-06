// Project9.cpp : Defines the entry point for the console application.
//
//FIXME optimize layout of the code 
#include<fstream>
#include<iostream>
#include<string>
#include<windows.h>
#include"fileData.h"
#include<map>
using namespace std;
//images avaliable to be read in and manipulated
void fileNames() {
	cout << "Type the name excluding the extension of the file/s you would like to open from the available list below" << endl;
	cout << '\n';
	cout << "car" <<"\t"<<"\t"<<" width: 512"<<" height: 512"<< endl;
	cout << "circles" << "\t"<<"\t"<<" width: 512" << " height: 512" << endl;
	cout << "layer_blue" << "\t" << " width: 600" << " height: 389" << endl;
	cout << "layer_green" << "\t" << " width: 600" << " height: 398" << endl;
	cout << "layer_red" << "\t" << " width: 600" << " height: 398" << endl;
	cout << "layer1" << "\t" <<"\t"<< " width: 512" << " height: 512" << endl;
	cout << "layer2" << "\t" <<"\t"<< " width: 512" << " height: 512" << endl;
	cout << "pattern1" << "\t" << " width: 512" << " height: 512" << endl;
	cout << "pattern2" << "\t" << " width: 512" << " height: 512" << endl;
	cout << "text" << "\t" <<"\t"<< " width: 512" << " height: 512" << endl;
	cout << "text2" << "\t" <<"\t"<< " width: 184" << " height: 384" << endl;
}
//image manipulation menu 
void alterImages() {
	cout << "1. Multiply" << endl;
	cout << "2. Subtract" << endl;
	cout << "3. Overlay" << endl;
	cout << "4. Screen blending mode" << endl;
}
//channel altering display
void channelAltering(){
	cout << "How would you like to adjust the channel?" << endl;
	cout << "1.add(+ number)/subtract(- number)" << endl;
	cout << "2. scale (>1 multiply) or(<1 divide)" << endl;
}
//numbers must stay in the range from 0-255 handling outofbounds numbers 
int overFlow(int &a) {
	if (a > 255) {
		a = 255;
	}
	else if (a < 0) {
		a = 0;
	}
	else {
		a = a;
	}
	return a;
}
float overFlow(float &a) {
	if (a > 255) {
		a = 255;
	}
	else if (a < 0) {
		a = 0;
	}
	else {
		a = a;
	}
	return a;
}
//altering the channels of a particular image function
unsigned char * channelMath(int channelAdjustment, unsigned char * pixelInfo, int size) {
	switch (channelAdjustment) {
		int Adjustment;
		int ChannelShift;
		unsigned char * pixelCombined;

	case 1:
		channelAltering();
		cin >> Adjustment;
		if (Adjustment == 1) {
			cout << "what number would you like to add or subtract to the green channel" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR green second index
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 1; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel += ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;
		}
		else if (Adjustment == 2) {
			cout << "what number would you like to scale the green channel by" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR second index
			//grab all the pixels and only alter the green ones later
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 1; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel *= ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;
		}
	case 2:
		channelAltering();
		cin >> Adjustment;
		if (Adjustment == 1) {
			cout << "what number would you like to add or subtract to the blue channel" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR blue is the first index
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 0; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel += ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;

		}
		else if (Adjustment == 2) {
			cout << "what number would you like to scale the blue channel by" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR second index
			//grab all the pixels and only alter the green ones later
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 0; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel *= ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;
			
		}
		else {
			cout << "error" << endl;
			unsigned char * a = new unsigned char[1];
			a[0] = 'a';
			return a;
		}

		break;
	case 3:
		channelAltering();
		cin >> Adjustment;
		if (Adjustment == 1) {
			cout << "what number would you like to add or subtract to the red channel" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR blue is the first index
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 2; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel += ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;

		}
		else if (Adjustment == 2) {
			cout << "what number would you like to scale the red channel by" << endl;
			cin >> ChannelShift;
			pixelCombined = new unsigned char[size];
			//BGR second index
			//grab all the pixels and only alter the green ones later
			for (int i = 0; i < size; i++) {
				pixelCombined[i] = pixelInfo[i];
			}
			for (int i = 2; i < size; i += 3) {
				int pixel = pixelInfo[i];
				pixel *= ChannelShift;
				pixel = overFlow(pixel);
				pixelCombined[i] = pixel;
			}
			return pixelCombined;
		}
		else {
			cout << "error" << endl;
			cout << "error" << endl;
			unsigned char * a = new unsigned char[1];
			a[0] = 'a';
			return a;
		}
		break;
	default:
		break;

	}
}
//FIXME clarification on error checking requirements 
int main()
{
	//file data 
	//pixel data per picture
	unsigned char* pixelInfo;
	unsigned char* pixelInfo2;
	unsigned char* pixelInfo3;
	//pixel data for storing a single channel per picture
	unsigned char* pictureOne;
	unsigned char* pictureTwo;
	unsigned char* pictureThree;
	//for selecting the desired channel
	int colorChannel;
	int colorChannel2;
	int colorChannel3;
	//storage container for altered pixels
	unsigned char* pixelCombined;
	//image sizing information
	int height;
	int width; 
	int size = 0;
	int count;

	//getting the correct Red Green and Blue channels when picking on channel from each of three images
	map <string, unsigned char *> RGBs;

	//viewing the picture 
	HWND myconsole = GetActiveWindow();
	HDC mydc = GetDC(myconsole);

	//menu options 
	int menuOption;
	string fileName;
	string fileName2;
	string fileName3;
	int imageAdjustment;
	int channelAdjustment;
	int channelAdjustment2;
	int channelAdjustment3;
	int channelNumber;
	int numberImageManipulations;
	int onePictureOption;
	cout << "How many tga files would you like to open 1, 2, or 3?" << endl;
	cin >> menuOption;

	if (menuOption == 1) {
		fileNames();
		cin >> fileName;
		//FIXME case consideration 
		fileName += ".tga";
		fileData picture(fileName);
		//get the pixel data 
		pixelInfo = picture.getPixelData();
		size = picture.getSize();
		height = picture.getHeight();
		width = picture.getWidth();
		cout << "height: " << height << " width: " << width << endl;
		//alter the channels
		cout << "1. Alter color channels" << endl;
		cout<<"2. Rotate image" << endl;
		cin >> onePictureOption;
		//alter the channels
		if (onePictureOption == 1) {
			cout << "How many channels would you like to alter?" << endl;
			cin >> channelNumber;
			//alter one channel
			if (channelNumber == 1) {
				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment;
				pixelCombined = channelMath(channelAdjustment, pixelInfo, size);
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);

			}
			//alter two channels
			else if (channelNumber == 2) {
				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment;
				pixelCombined = channelMath(channelAdjustment, pixelInfo, size);

				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment2;
				pixelCombined = channelMath(channelAdjustment2, pixelCombined, size);
				//display purposes
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
			}
			//alter three channels
			else if (channelNumber == 3) {
				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment;
				pixelCombined = channelMath(channelAdjustment, pixelInfo, size);

				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment2;
				pixelCombined = channelMath(channelAdjustment2, pixelCombined, size);

				cout << "Which channel would you like to alter?" << endl;
				cout << "1. Green" << endl;
				cout << "2. Blue" << endl;
				cout << "3. Red" << endl;
				cin >> channelAdjustment3;
				pixelCombined = channelMath(channelAdjustment3, pixelCombined, size);
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
			}
			else {
				cout << "error" << endl;
			}
		}
		//rotate the image 
		else if (onePictureOption==2) {
			count = 0;
			for (int i = 0; i <height; i++) {
				for (int j = width-1; j >=0; j--) {
					SetPixel(mydc, j, i, RGB((int)pixelInfo[count + 2], (int)pixelInfo[count + 1], (int)pixelInfo[count]));
					count += 3;
				}
			}
			ReleaseDC(myconsole, mydc);
		}
		else {
			cout << "error" << endl;
		}

	}
	//2 images
	else if (menuOption == 2) {
		cout << "note you must select images of the same size" << endl;
		fileNames();
		cin >> fileName;
		cin >> fileName2;
		fileName += ".tga";
		fileName2 += ".tga";
		fileData picture(fileName);
		fileData picture2(fileName2);
		//pixel data for each image 
		pixelInfo = picture.getPixelData();
		pixelInfo2 = picture2.getPixelData();
		size = picture.getSize();
		height = picture.getHeight();
		width = picture.getWidth();
		pixelCombined = new unsigned char[size];
			cout << "Image manipulation options?" << endl;
			alterImages();
			cin >> imageAdjustment;
			switch (imageAdjustment) {
				//multiply method 
			case 1:
				for (int i = 0; i < size; i++) { 
					float pixel1 = (float)pixelInfo[i];
					float pixel2 = (float)pixelInfo2[i];
					pixel1 /= 255;
					pixel2 /= 255;
					float pixelCombo = pixel1 * pixel2 * 255;
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
				break;
				//subtract method 
			case 2:
				for (int i = 0; i < size; i++) {
					int pixel1 = (int)pixelInfo[i];
					int pixel2 = (int)pixelInfo2[i];
					int pixelCombo = pixel2 - pixel1;
					pixelCombo = overFlow(pixelCombo);
					pixelCombined[i] = (unsigned char)pixelCombo;

				}
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
				break;
				//overlay blending 
			case 3:
				float pixelCombo;
				for (int i = 0; i < size; i++) {
					float pixel1 = (float)pixelInfo[i];
					float pixel2 = (float)pixelInfo2[i];
					pixel1 /= 255;
					pixel2 /= 255;
					if (pixel2 <= .5) {
						pixelCombo = 2 * pixel1*pixel2 * 255;
						pixelCombo = overFlow(pixelCombo);
						pixelCombined[i] = (unsigned char)pixelCombo;
					}
					else {
						pixelCombo = 1 - 2 * (1 - pixel1)*(1 - pixel2);
						pixelCombo *= 255;
						pixelCombo = overFlow(pixelCombo);
						pixelCombined[i] = (unsigned char)pixelCombo;
					}
				}
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
				break;
				//screen blending
			case 4:
				for (int i = 0; i < size; i++) {
					float pixel1 = (float)pixelInfo[i];
					float pixel2 = (float)pixelInfo2[i];
					pixel1 /= 255;
					pixel2 /= 255;
					float pixelCombo = (1 - (1 - pixel1)*(1 - pixel2)) * 255;
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
				count = 0;
				for (int i = height - 1; i >= 0; i--) {
					for (int j = 0; j < width; j++) {
						SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
						count += 3;
					}
				}
				ReleaseDC(myconsole, mydc);
				break;
			default:
				break;
			}
	
	}
	//3 pictures selected to manipulate
	else if (menuOption == 3) {
		cout << "note you must select images of the same size" << endl;
		fileNames();
		cin >> fileName;
		cin >> fileName2;
		cin >> fileName3;
		fileName += ".tga";
		fileName2 += ".tga";
		fileName3 += ".tga";
		fileData picture(fileName);
		fileData picture2(fileName2);
		fileData picture3(fileName3);
		//pixel data for each image 
		pixelInfo = picture.getPixelData();
		pixelInfo2 = picture2.getPixelData();
		pixelInfo3 = picture3.getPixelData();
		//might matter FIXME
		size = picture.getSize();
		height = picture.getHeight();
		width = picture.getWidth();
		pixelCombined = new unsigned char[size];
		cout << "Image manipulation options for the first two images?" << endl;
		alterImages();
		cout << "5. Combine one channel from each picture to make a new picture" << endl;
		cin >> imageAdjustment;
		switch (imageAdjustment) {
			//multiply method 
		case 1:
			for (int i = 0; i < size; i++) {
				//FIXME 
				float pixel1 = (float)pixelInfo[i];
				float pixel2 = (float)pixelInfo2[i];
				pixel1 /= 255;
				pixel2 /= 255;
				float pixelCombo = pixel1 * pixel2 * 255;
				pixelCombined[i] = (unsigned char)pixelCombo;
			}
			
			break;
			//subtract method 
		case 2:
			for (int i = 0; i < size; i++) {
				int pixel1 = (int)pixelInfo[i];
				int pixel2 = (int)pixelInfo2[i];
				int pixelCombo = pixel2 - pixel1;
				pixelCombo = overFlow(pixelCombo);
				pixelCombined[i] = (unsigned char)pixelCombo;

			}
			break;
			//overlay blending 
		case 3:
			float pixelCombo;
			for (int i = 0; i < size; i++) {
				float pixel1 = (float)pixelInfo[i];
				float pixel2 = (float)pixelInfo2[i];
				pixel1 /= 255;
				pixel2 /= 255;
				if (pixel2 <= .5) {
					pixelCombo = 2 * pixel1*pixel2 * 255;
					pixelCombo = overFlow(pixelCombo);
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
				else {
					pixelCombo = 1 - 2 * (1 - pixel1)*(1 - pixel2);
					pixelCombo *= 255;
					pixelCombo = overFlow(pixelCombo);
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
			}
			break;
			//screen blending
		case 4:
			for (int i = 0; i < size; i++) {
				//FIXME 
				float pixel1 = (float)pixelInfo[i];
				float pixel2 = (float)pixelInfo2[i];
				pixel1 /= 255;
				pixel2 /= 255;
				float pixelCombo = (1 - (1 - pixel1)*(1 - pixel2)) * 255;
				pixelCombined[i] = (unsigned char)pixelCombo;
			}
			break;
			//one channel from each image
		case 5:
			cout << "Color channels for the images 1,2,3 to collect" << endl;
			cout << "1. Red" << endl;
			cout << "2. Green" << endl;
			cout << "3. Blue" << endl;
			cin >> colorChannel;
			cin >> colorChannel2;
			cin >> colorChannel3;
			int index;
			switch (colorChannel) {
			case 1:
				//BGR
				pictureOne = new unsigned char [size / 3];
				index = 0;
				for (int i = 2; i < size; i += 3) {
					pictureOne[index] = pixelInfo[i];
					index++;
				}
				RGBs.emplace("Red", pictureOne);
				break;
			case 2:
				pictureOne = new unsigned char[size / 3];
				index = 0;
				for (int i = 1; i < size; i += 3) {
					pictureOne[index] = pixelInfo[i];
					index++;
				}
				RGBs.emplace("Green", pictureOne);
				break;
			case 3:
				pictureOne = new unsigned char[size / 3];
				index = 0;
				for (int i = 0; i < size; i += 3) {
					pictureOne[index] = pixelInfo[i];
					index++;
				}
				RGBs.emplace("Blue", pictureOne);
				break;
			default:
				pictureOne = pixelInfo;
				break;
			}
			switch (colorChannel2) {
			case 1:
				//BGR
				pictureTwo = new unsigned char[size / 3];
				index = 0;
				for (int i = 2; i < size; i += 3) {
					pictureTwo[index] = pixelInfo2[i];
					index++;
				}
				RGBs.emplace("Red", pictureTwo);
				break;
			case 2:
				pictureTwo = new unsigned char[size / 3];
				 index = 0;
				for (int i = 1; i < size; i += 3) {
					pictureTwo[index] = pixelInfo2[i];
					index++;
				}
				RGBs.emplace("Green", pictureTwo);
				break;
			case 3:
				pictureTwo = new unsigned char[size / 3];
				index = 0;
				for (int i = 0; i < size; i += 3) {
					pictureTwo[index] = pixelInfo2[i];
					index++;
				}
				RGBs.emplace("Blue", pictureTwo);
				break;
			default:
				pictureTwo = pixelInfo;
				break;
			}
			switch (colorChannel3) {
			case 1:
				//BGR
				pictureThree = new unsigned char[size / 3];
				index = 0;
				for (int i = 2; i < size; i += 3) {
					pictureThree[index] = pixelInfo3[i];
					index++;
				}
				RGBs.emplace("Red", pictureThree);
				break;
			case 2:
				pictureThree = new unsigned char[size / 3];
				index = 0;
				for (int i = 1; i < size; i += 3) {
					pictureThree[index] = pixelInfo3[i];
					index++;
				}
				RGBs.emplace("Green", pictureTwo);
				break;
			case 3:
				pictureThree = new unsigned char[size / 3];
				index = 0;
				for (int i = 0; i < size; i += 3) {
					pictureThree[index] = pixelInfo3[i];
					index++;
				}
				RGBs.emplace("Blue", pictureThree);
				//FIXME??
				break;
			default:
				pictureThree = pixelInfo;
				break;
			}
			

			count = 0;
			for (int i = height - 1; i >= 0; i--) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)RGBs.at("Red")[count], (int)RGBs.at("Green")[count], (int)RGBs.at("Blue")[count]));
					count++;
				}
			}
			ReleaseDC(myconsole, mydc);
			
		}
		cout << "Image manipulation options for the combined image from one and two and now the third image?" << endl;
		alterImages();
		cout << "5. Do nothing" << endl;
		cin >> imageAdjustment;
		switch (imageAdjustment) {
			//multiply method 
		case 1:
			for (int i = 0; i < size; i++) {
				//FIXME 
				float pixel1 = (float)pixelCombined[i];
				float pixel2 = (float)pixelInfo3[i];
				pixel1 /= 255;
				pixel2 /= 255;
				float pixelCombo = pixel1 * pixel2 * 255;
				pixelCombined[i] = (unsigned char)pixelCombo;
			}
			count = 0;
			for (int i = height - 1; i >= 0; i--) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
					count += 3;
				}
			}
			ReleaseDC(myconsole, mydc);
			break;
			//subtract method 
		case 2:
			for (int i = 0; i < size; i++) {
				float pixel1 = (float)pixelCombined[i];
				float pixel2 = (float)pixelInfo3[i];
				int pixelCombo = pixel1 - pixel2;
				pixelCombo = overFlow(pixelCombo);
				pixelCombined[i] = (unsigned char)pixelCombo;

			}
			count = 0;
			for (int i = height - 1; i >= 0; i--) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
					count += 3;
				}
			}
			ReleaseDC(myconsole, mydc);
			break;
			//overlay blending 
		case 3:
			float pixelCombo;
			for (int i = 0; i < size; i++) {
				float pixel1 = (float)pixelCombined[i];
				float pixel2 = (float)pixelInfo3[i];
				pixel1 /= 255;
				pixel2 /= 255;
				if (pixel2 <= .5) {
					pixelCombo = 2 * pixel1*pixel2 * 255;
					pixelCombo = overFlow(pixelCombo);
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
				else {
					pixelCombo = 1 - 2 * (1 - pixel1)*(1 - pixel2);
					pixelCombo *= 255;
					pixelCombo = overFlow(pixelCombo);
					pixelCombined[i] = (unsigned char)pixelCombo;
				}
			}
			count = 0;
			for (int i = height - 1; i >= 0; i--) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
					count += 3;
				}
			}
			ReleaseDC(myconsole, mydc);
			break;
			//screen blending 
		case 4:
			for (int i = 0; i < size; i++) {
				//FIXME 
				float pixel1 = (float)pixelCombined[i];
				float pixel2 = (float)pixelInfo3[i];
				pixel1 /= 255;
				pixel2 /= 255;
				float pixelCombo = (1-(1-pixel1)*(1-pixel2)) * 255;
				pixelCombined[i] = (unsigned char)pixelCombo;
			}
			count = 0;
			for (int i = height - 1; i >= 0; i--) {
				for (int j = 0; j < width; j++) {
					SetPixel(mydc, j, i, RGB((int)pixelCombined[count + 2], (int)pixelCombined[count + 1], (int)pixelCombined[count]));
					count += 3;
				}
			}
			ReleaseDC(myconsole, mydc);
			break;
		case 5:
			break;
		default:
			break;
		}
	}
    return 0;
}

