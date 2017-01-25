/*************************************************************
 * File Name : Mat.cpp
 * Purpose : Learning to use Mat
 * Creation Date : Wed 25 Jan 2017 12:01:53 AM CST
 * Last Modified : Wed 25 Jan 2017 03:01:00 PM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    //create a Matrix size 10x20
    //U means unsigned S means signed
    Mat img1(10, 20, CV_8U);
    cout << "img1 = " << endl << img1 << endl << endl; 
    Mat img2(10, 20, CV_8U, Scalar(100));
    cout << "img2 = " << endl << img2 << endl << endl; 

    //C3 means there are 3 channel
    Mat img3(10, 20, CV_8UC3, Scalar(200,100,0));
    cout << "img3 = " << endl << img3 << endl << endl; 


    //reassign the memory size and type
    img1.create(30, 40, CV_8S);
    cout << "img1 = " << endl << img1 << endl << endl; 
   
   

    //Following content is from the official website 
    /*************************************************************************************************/
    Mat A, C;                                 // creates just the header parts
    A = imread(argv[1], CV_LOAD_IMAGE_COLOR); // here we'll know the method used (allocate matrix)

    Mat B(A);                                 // 1. Use the copy constructor

    C = A;                                    // 2. Assignment operator
    
    //making a modification using any of them will affect all the other ones as well.
    //works like pointer
    /*************************************************************************************************/

    return 0;
}
