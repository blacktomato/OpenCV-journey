/*************************************************************
 * File Name : Mat.cpp
 * Purpose : Learning to use Mat
 * Creation Date : Wed 25 Jan 2017 12:01:53 AM CST
 * Last Modified : Fri 27 Jan 2017 10:53:02 PM CST
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
    img1.create(3, 4, CV_8S);
    cout << "img1 = " << endl << img1 << endl << endl; 
    //delete the matrix
    img1.release();
    cout << "img1 = " << endl << img1 << endl << endl; 
    //set the matrix all ones
    img1 = img1.ones(5, 3, CV_8U);
    cout << "img1 = " << endl << img1 << endl << endl; 
    //set the matrix all zeros
    img1 = img1.zeros(3, 7, CV_8S);
    cout << "img1 = " << endl << img1 << endl << endl; 
    //set the matrix identity
    img1 = img1.eye(5, 5, CV_8S);
    cout << "img1 = " << endl << img1 << endl << endl; 
   

    //Following content is from the official website 
    /*************************************************************************************************/
    Mat A, C;                                 // creates just the header parts
    A = imread(argv[1], IMREAD_COLOR);        // here we'll know the method used (allocate matrix)

    Mat B(A);                                 // 1. Use the copy constructor
                                              // the copy operators will only copy the headers 
                                              // and the pointer to the large matrix, not the data itself.

    C = A;                                    // 2. Assignment operator
    
    //making a modification using any of them will affect all the other ones as well.
    //which works like pointer

    //However, if need to really copy the whole of the data, we can use following two ways
    Mat D = A.clone(); //1. some = target.clone()
    Mat F;             //2. target.copyTo( some  )
    A.copyTo(F);
    /*************************************************************************************************/

    return 0;
}
