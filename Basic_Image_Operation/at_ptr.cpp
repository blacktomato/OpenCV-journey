/*************************************************************
 * File Name : at_ptr.cpp
 * Purpose : way to scan through the pixels
 * Creation Date : Wed 22 Feb 2017 04:47:04 PM CST
 * Last Modified : Thu 29 Jun 2017 08:38:18 PM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<string>
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
	Mat img1, img2, img3, img4;
    img1 = imread(argv[1], IMREAD_COLOR);

	int widthLimit = img1.channels() * img1.cols;
	img1.copyTo(img2);
	img1.copyTo(img3);
	img1.copyTo(img4);
	
	//at< datatype >(int row, int col)
	for(int height=0; height < img2.rows; height++){
		for(int width=0; width < widthLimit; width++)
			img2.at<uchar>(height, width) += 20;
	}

	//ptr< datatype >(int row)
	for(int height=0; height < img3.rows; height++){
		uchar *data = img3.ptr<uchar>(height);
		for(int width=0; width < widthLimit ; width++)
			data[width] += 20;
	}

    //iterator
    if(img4.channels()==1){
        Mat_<uchar>::iterator it = img4.begin<uchar>();
        Mat_<uchar>::iterator itend = img4.end<uchar>();
        for(;it!=itend;it++){
            (*it) = (*it) + 20;
        }
    }
    if(img4.channels()==3){
        Mat_<Vec3b>::iterator it = img4.begin<Vec3b>();
        Mat_<Vec3b>::iterator itend = img4.end<Vec3b>();
        for(;it!=itend;it++){
            (*it)[0] = (*it)[0] + 20;
            (*it)[1] = (*it)[1] + 20;
            (*it)[2] = (*it)[2] + 20;
        }
    }

	show_image("original",   img1);
	show_image("at()",       img2);
	show_image("ptr()",      img3);
	show_image("iterator()", img4);

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
