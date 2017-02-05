/*************************************************************
 * File Name : IO.cpp
 * Purpose : IO in the OpenCV
 * Creation Date : Sun 29 Jan 2017 05:53:47 PM CST
 * Last Modified : Sun 05 Feb 2017 11:45:23 PM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool outputJPG(string, int, Mat&);

int main(int argc, char** argv)
{
    Mat img1, img2;
    img1 = imread(argv[1], IMREAD_COLOR);
    img2 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    //CV_LOAD_IMAGE_GRAYSCALE == 0
    //CV_LOAD_IMAGE_UNCHANGED == -1
    //CV_LOAD_IMAGE_COLOR     == 1

    string title = "Resizable";
    
    //WINDOW_NORMAL   user can make the window manually-resizable
    //WINDOW_AUTOSIZE the size of the window will be same as the image
    
    //imshow(const string& winname, InputArray mat)
    namedWindow(title, CV_WINDOW_NORMAL );
    imshow(title, img1);
    namedWindow("not " + title, CV_WINDOW_AUTOSIZE );
    imshow("not " + title, img2);
    
    while(true)
        if(waitKey(10) == 27) break; //ESC

    outputJPG("95", 95, img1);
    outputJPG("70", 70, img1);
    outputJPG("50", 50, img1);
    outputJPG("20", 20, img1);
    outputJPG("10", 10, img1);
    outputJPG( "5",  5, img1);
    outputJPG( "4",  4, img1);
    outputJPG( "3",  3, img1);
    outputJPG( "2",  2, img1);
    outputJPG( "1",  1, img1);

    return 0;
}

bool outputJPG(string filename, int percentage, Mat& img)
{
    vector<int> quality;
    quality.push_back(CV_IMWRITE_JPEG_QUALITY);
    quality.push_back(percentage);
    return imwrite (filename + ".jpg", img, quality);
}
