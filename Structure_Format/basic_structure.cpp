/*************************************************************
 * File Name : basic_structure.cpp
 * Purpose : Usage of Point, Size, Rect, and so on 
 * Creation Date : Wed 25 Jan 2017 09:28:45 PM CST
 * Last Modified : Fri 27 Jan 2017 05:07:28 PM CST
 * Created By : SL Chung
**************************************************************/
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    //2 dimension
    //Point(int x, int y);
    Point pt1(10,20);
    cout << "pt1= " << pt1 << endl << endl;
    Point pt2;
    pt2.x = 20;
    pt2.y = 30;
    cout << "pt2= " << pt2 << endl << endl;

    //float point
    Point2f  pt3(2.556, 1.345);
    cout << "pt3= " << pt3 << endl << endl;

    //3 dimension
    Point3i pti(1, 2, 4);               //integer
    Point3f ptf(1.2, 3.4, 5.6);         //float
    Point3d ptd(1.234, 3.456, 7.890);   //double
    cout << "pti= " << pti << endl << endl;
    cout << "ptf= " << ptf << endl << endl;
    cout << "ptd= " << ptd << endl << endl;

    //Size(int width, int height)
    Size size1;
    size1.width = 150;
    size1.height = 100;
    int myArea = size1.area();
    cout << "size1= " << size1 << endl << endl;
    cout << "myArea= " << myArea << endl << endl;

    //Rect(int x, int y, int width, int height)
    Rect rect1;
    rect1.x = 20;    // the coordinate of the up-left corner
    rect1.y = 30;
    rect1.width = 150;
    rect1.height = 100;
    cout << "rect1= " << rect1 << endl << endl;
    //rect1.area(); 
    
    //RotatedRect(const Point2f &center, const Size2f &size, float angle)
    RotatedRect rRect1; 
    rRect1.center = Point2f(150,150);
    rRect1.size = Size2f(100,50);
    rRect1.angle = 30.0;
    Point2f vertices[4];
    rRect1.points(vertices);
    cout << "rRect1 vertices= " << endl;
    cout << vertices[0] << endl << vertices[1] << endl << vertices[2] << endl << vertices[3] << endl << endl;
    
    //Scalar(a, b, c)
    //       B  G  R
    //Scalar(a)
    //       Grey-Scale
    Scalar color(12, 3, 50);
    cout << "color= " << color << endl << endl;
    return 0;
}

