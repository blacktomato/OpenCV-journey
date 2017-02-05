<h1>IO</h1>

<h3>File</h3>
* [IO.cpp](#io)


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

