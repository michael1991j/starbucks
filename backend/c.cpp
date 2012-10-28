#include "cv.h"
#include "highgui.h"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <boost/thread.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
using namespace cv;
using namespace std;
    cv::VideoCapture vcap;
    cv::Mat img;
void task1() {
    while(1)
{


}
}



int main(int, char**) {





    const std::string videoStreamAddress = "http://192.168.1.90/mjpg/video.mjpg";
    /* it may be an address of an mjpeg stream,
    e.g. "http://user:pass@cam_address:8081/cgi/mjpg/mjpg.cgi?.mjpg" */

    //open the video stream and make sure it's opened

//  HOGDescriptor hog;
  //  hog.setSVMDetector(HOGDescriptor::getPeopleDetector64x128());




    if(!vcap.open(videoStreamAddress)) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }
 using namespace boost;
vcap >> img;
Mat src, asrc, src_gray, dst,save;
  int kernel_size = 3;
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  src = img;
  GaussianBlur( src, save, Size(3,3), 0, 0, BORDER_DEFAULT );

  /// Convert the image to grayscale
 // cvtColor( src, save, CV_RGB2GRAY );

  /// Create window

  /// Apply Laplace function
  Mat abs_dst;

  //Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
  //convertScaleAbs( dst, save );
    thread thread_1 = thread(task1);
    for(;;) {

        vcap >> img;

    //    if(!vcap.read(img))
//{
  //          std::cout << "No frame" << std::endl;
    //        cv::waitKey();
      //  }


//        fflush(stdout);
//        vector<Rect> found, found_filtered;
//        double t = (double)getTickCount();
//        // run the detector with default parameters. to get a higher hit-rate
//        // (and more false alarms, respectively), decrease the hitThreshold and
//        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
//        hog.detectMultiScale(img, found, 1, Size(8,8), Size(32,32), 1.05, 2);
//        t = (double)getTickCount() - t;
//        printf("tdetection time = %gms\n", t*1000./cv::getTickFrequency());
//        size_t i, j;
//        for( i = 0; i < found.size(); i++ )
//        {
//            Rect r = found[i];
//            for( j = 0; j < found.size(); j++ )
//                if( j != i && (r & found[j]) == r)
//                    break;
//            if( j == found.size() )
//                found_filtered.push_back(r);
//        }
//        for( i = 0; i < found_filtered.size(); i++ )
//        {
//            Rect r = found_filtered[i];
//            // the HOG detector returns slightly larger rectangles than the real objects.
//            // so we slightly shrink the rectangles to get a nicer output.
//            r.x += cvRound(r.width*0.1);
//            r.width = cvRound(r.width*0.8);
//            r.y += cvRound(r.height*0.07);
//            r.height = cvRound(r.height*0.8);
//            rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
//        }
        src = img;
        GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );


        /// Convert the image to grayscale
     //   cvtColor( src, src_gray, CV_RGB2GRAY );

        /// Create window

        /// Apply Laplace function
        Mat abs_dst;

        //Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
        //convertScaleAbs( dst, abs_dst );
         absdiff(img, save,dst);
        cv::imshow("Output Window",dst);

        if(cv::waitKey(1) >= 0) break;
    }
}
