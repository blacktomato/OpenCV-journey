<h1>Structure and Format</h1>

<h3>File</h3>
* [Makefile](#makefile)
* [Mat.cpp](#mat)
* [basic\_structure.cpp](#basic)
    * [Point](#point)
    * [Size](#size)
    * [Rect](#rect)
    * [rRect](#rrect)
    * [Scalar](#scalar)


* * *

<h3>Detail</h3>

<h4 id = "makefile">Makefile</h4>

In the makefile, the main difference is adding a **LIB link** after each compile command: 

    CVLIB = `pkg-config opencv --cflags --libs`

Using `make`generates binary files for each **.cpp** files. 
Besides,`$+` means the dependency, `$@` means the target file. 
Using `make clean` cleans up all the binary filess. 

<h4 id = "mat">Mat.cpp</h4>

Before main function, we need to include the OpenCV library and use namespace cv

    #include<opencv2/core.hpp>
    #include<opencv2/opencv.hpp>

    using namespace cv;

`Mat` is the datatype used for the Matrix in OpenCV, which is basically a class with two data parts: 

1. ***Matrix header***: containing informations,  such as the **size** of the matrix, 
the **method used for storing**, at which **address** is the matrix stored, and so on

2. ***Pointer***: pointing to the matrix containing the pixel values,and taking any dimensionality depending on the method chosen for storing) .

There are difference ways to build a Mat.

*   First, we can simply use a **constructer**, `Mat(int, int, int, Scalar)`.

        Mat img1(int rows, int cols, int type, const cv::Scalar &s)
        Mat img1(10, 20, CV_8U);

    In the **pixel-depth** parameter `CV_8U`, **8** means the bit to represent a value of a pixel, 
**U** means unsigned integer. On the other hand, **S** means signed integer.
Besides, the Mat objects can be showed by `cout`.

        Mat img3(10, 20, CV_8UC3, Scalar(200,100,0));
    
    In the `CV_8UC3`, **C3** means the number of channel is 3, which represents the three channels, **BGR**, filled by 200, 100, 0 respectively. 

*   Using `create(int, int, int Scalar)` to reassign the memory size and type of a Mat,

        Mat img1;
        img1.create(3, 4, CV_8S);

    and using `release()` to return the memory.
        
        img1.release();

    What's more `ones()` and `zeros()` can reassign the size of matrices and set all the element to 1 or 0,
    and `eye()` can return an identity matrix.

        img1 = img1.ones(5, 3, CV_8U);
        img1 = img1.zeros(3, 7, CV_8S);
        img1 = img1.eye(5, 5, CV_8S);
    
*   Use **copy constructor** or **assign** operator.

        Mat A, C;
        A = imread(argv[1], IMREAD_COLOR); 
        Mat B(A);
        C = A;  

    However, the copy operators will **only copy the headers and the pointer to the large matrix, not the data itself**. 
    All the above objects, in the end, point to the **same single data matrix**. 
    Their headers are different, and making a modification using any of them will **affect all the other ones as well**.
    
*   Use `copyTo()` or `clone()` member function.

        Mat D = A.clone(); 
        Mat F;
        A.copyTo(F);

    The method above really copy the whole data.

<h4 id = "basic">basic_structure.cpp</h4>

There several different basic datatype in the OpenCV.

*   <p id = "point" >Point</p>

    Point is a datatype consisting of numbers to represent a point in coordinate, and there are different types of Point.

    * Point: input 2 **integer**.
    * Point2f: input 2 **float**.
    * Point3i: input 3 **integer**.
    * Point3f: input 3 **float**.
    * Point3d: input 3 **double**.

    `cout` can be used to show the information of Point, and there are data member `x`, `y`, and `z` able to be changed. ( ex: point.x = 12; )

*   <p id = "size" >Size</p>

    Size is a datatype consisting of two integers to represent size of a matrix or a picture, and there is a member function, `area()`, returning the product of two integer.

        Size size1;
        size1.width = 150;
        size1.height = 100;
        int myArea = size1.area(); // 15000
    
*   <p id = "rect" >Rect</p>

    In Rect, it takes first two integer to specify the position of the **up-left** corner of the Rect,
    and the rest two integer shows the size of the rect.
    
        //Rect(int x, int y, int width, int height)
        Rect rect1;
        rect1.x = 20;    // the coordinate of the up-left corner
        rect1.y = 30;
        rect1.width = 150;
        rect1.height = 100;

    and there is also a member function, `area()`, returning the area of the Rect.

*   <p id = "rrect" >rRect ( RotatedRect )</p>

    In rRect, it takes a `Point2f` to be a **center**, a `Size2f` to specify **size**, and a `float` to be the spin **angle**.
    The `Point2f` array, `vertices`,  shows the position of the four corners of the rRect.

        RotatedRect rRect1; 
        rRect1.center = Point2f(150,150);
        rRect1.size = Size2f(100,50);
        rRect1.angle = 30.0;
        Point2f vertices[4];
        rRect1.points(vertices);

*   <p id = "scalar" >Scalar</p>

    Scalar is usually used to represent colors and the value of elements in matrices.
    Besides, the order of the color is **BGR**.
    
        //Scalar(a, b, c)
        //       B  G  R
        //Scalar(a)
        //       Grey-Scale
        Scalar color(12, 3, 50);


