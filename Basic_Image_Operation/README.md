<h1>IO</h1>

<h3>File</h3>

* [IO.cpp](#io)
* [Add.cpp](#add)


* * *

<h3>Detail</h3>

<h4 id = "io">IO.cpp</h4>

1. ***Reading in the Images***

    Using `imread`() to read in a image to a `Mat`,
    and the flags in imread() designs the color depth.

        Mat img1, img2;
        img1 = imread(argv[1], IMREAD_COLOR);
        img2 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    |  Imread Flags           |         Meaning       |
    |-------------------------|:---------------------:|
    | IMREAD_COLOR            | Original color        |
    | CV_LOAD_IMAGE_GRAYSCALE | Read in ad Gray image |
    | CV_LOAD_IMAGE_UNCHANGED | Original color        |
    | CV_LOAD_IMAGE_COLOR     | BGR color image       |


2. ***Establish Windows***

    Before showing images, `namedWindow()` sets the information of a window,
    such as whether it is **resizable** and its **name**.

        //void namedWindow(const string& winname, int flags=WINDOW_AUTOSIZE)
        string title = "Resizable";
        namedWindow(title, CV_WINDOW_NORMAL );
        imshow(title, img1);

    |  Window Flags   |         Meaning       |
    |-----------------|:---------------------:|
    | WINDOW_NORMAL   |  manually-resizable   |
    | WINDOW_AUTOSIZE |  fixed-sized to image |

3. ***Showing the Images***
    
    `imshow()` specifies the window it will use and shows the image.
    However, it needs the function `waitKey(int delay)` to stop the program,
    which makes us to see the windows.

        //void imshow(const string& winname, InputArray mat)
        imshow(title, img1);
        while(true)
            if(waitKey(10)==27) break;
            //keep showing windows until press ESC

4. ***Exporting the Images***

    To output the image, we use `imwrite()` to specify the type of image by parameter `filename`,
    and we can specify the **compression quality** of it (default for JPEG is 95 on the scale 0~100)

        //bool imwrite(const string& filename, InputArray img, const vector& params)
        vector<int> quality;
        quality.push_back(CV_IMWRITE_JPEG_QUALITY);
        quality.push_back(percentage);
        imwrite (filename, img, quality);
    
    In the IO.cpp, we can produce JPEG images with different compression quality.

<h4 id = "add">Add.cpp</h4>

First, because I want to spread the window, instead of them being squeezed together,
I use following code to get the resolution of the screen. When compiling the .cpp file, I need to add the library link `-lX11`.
(In the `./Makefile`)

    #include<X11/Xlib.h>

    //To have screen height and width
    Display* d = XOpenDisplay(NULL);
    Screen*  s = DefaultScreenOfDisplay(d);

There are two function for adding ,`add()` and `addWeighted()`, and both of them could **only** deal with two images **having the same size**.

* `alpha` (`beta`): weight of src1 (src2)
* `gamma`: scalar added to each sum


    //void add(InputArray src1, InputArray src2, OutputArray dst, InputArray mask=noArray(), int dtype=-1)
    //void addWeighted(InputArray src1, double alpha, InputArray src2, double beta, double gamma, OutputArray dst, int dtype=-1)

    add(img1, img2, img3);
    
    add(img1, Scalar(20), img4);
    //same as img4 = img1 + 20;

    addWeighted(img1, 0.5, img2, 0.5, 0, img5);

If we want to add a smaller image to the bigger one, we should use the **ROI** (Region of Interest) technique.

    //with different sizes
    Mat imgROI = img1(Rect(position_w, position_h, img2.cols, img2.rows));
    addWeighted(imgROI, 0.5, img2, 0.5, 0, imgROI);
    
* P.S. First two parameter`Rect()` is the coordinates of the up-left point.
