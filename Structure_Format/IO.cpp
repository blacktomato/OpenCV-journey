/*************************************************************
 * File Name : IO.cpp
 * Purpose : IO in the OpenCV
 * Creation Date : Sun 29 Jan 2017 05:53:47 PM CST
 * Last Modified : Mon 30 Jan 2017 12:03:29 AM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<string>
#include<opencv2/core.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    //create a Matrix size 10x20
    //U means unsigned S means signed
    
    Mat img1;
    img1 = imread(argv[1], IMREAD_COLOR);

    string title = "Resizable";
    
    //WINDOW_NORMAL   user can make the window manually-resizable
    //WINDOW_AUTOSIZE the size of the window will be same as the image
    
    namedWindow(title, CV_WINDOW_NORMAL );
    imshow(title, img1);
    namedWindow("not " + title, CV_WINDOW_AUTOSIZE );
    imshow("not " + title, img1);
    waitKey(0); 

    return 0;
}
