/*************************************************************
 * File Name : Add.cpp
 * Purpose : Adding Image together
 * Creation Date : Wed 15 Feb 2017 03:54:00 PM CST
 * Last Modified : Thu 29 Jun 2017 01:30:03 AM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<string>
#include<time.h>
#include<opencv2/opencv.hpp>
#include<X11/Xlib.h>

using namespace std;
using namespace cv;

void show_image(string, Mat);

//To have screen height and width
Display* d = XOpenDisplay(NULL);
Screen*  s = DefaultScreenOfDisplay(d);

double col = 0, row = 0;

int main(int argc, char** argv)
{
    Mat img1, img2, img3, img4, img5;
    if (argc != 3)
    {
        cerr << "Error: need two images as the inputs..." << endl;
        return 0;
    }
    img1 = imread(argv[1], IMREAD_COLOR);
    img2 = imread(argv[2], CV_LOAD_IMAGE_UNCHANGED);
	
	if (img1.size() == img2.size())
	{
		add(img1, img2, img3);
		add(img1, Scalar(20), img4);
		//same as img4 = img1 + 20;
		addWeighted(img1, 0.5, img2, 0.5, 0, img5);
		
		//imshow(const string& winname, InputArray mat)
		show_image("img1", img1);
		show_image("img2", img2);
		show_image("img1+img2", img3);
		show_image("img1+20", img4);
		show_image("(img1+img2)/2", img5);
	} 
	else 
	{
		cerr << endl << "The size of two images are not the same:" << endl;
		cerr << "img1: " << img1.size() << endl;
		cerr << "img2: " << img2.size() << endl << endl;

		unsigned seed;
		seed = (unsigned)time(NULL);
		srand(seed);
		
		int position_w = floor(rand() % (img1.cols - img2.cols));
		int position_h = floor(rand() % (img1.rows - img2.rows));
		Mat imgROI = img1(Rect(position_w, position_h, img2.cols, img2.rows));
		addWeighted(imgROI, 0.5, img2, 0.5, 0, imgROI);
		show_image("img1", img1);
		show_image("img2", img2);
	} 
    
    while(true)
        if(waitKey(10) == 27) break; //ESC
    return 0;
}

void show_image(string img_name, Mat img)
{
    namedWindow(img_name, CV_WINDOW_AUTOSIZE );
    moveWindow(img_name, col, row);
    imshow(img_name, img);
	if ( (col += img.cols) > s->width )
	{
		col = 0;
		row += img.rows;
	}
}
