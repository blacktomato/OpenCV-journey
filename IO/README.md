<h1>IO</h1>

<h3>File</h3>
* [IO.cpp](#io)


* * *

<h3>Detail</h3>

<h4 id = "io">IO.cpp</h4>

Some basic operation of reading in and showing images. `namedWindow()` sets the information of a window, and `imshow()` shows the image.

    //WINDOW_NORMAL   user can make the window manually-resizable
    //WINDOW_AUTOSIZE the size of the window will be same as the image

    string title = "Resizable";
    namedWindow(title, CV_WINDOW_NORMAL );
    imshow(title, img1);
