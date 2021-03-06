#include <cv.h>
#include <highgui.h>

using namespace cv;

int main( int argc, char** argv )
{
   cv::Mat img = imread( argv[1], 1 );


   if( argc != 2 || !img.data ) {
      printf( "No image data \n" );
      return -1;
   }

   unsigned char block[3*img.rows*img.cols];
   int c =0; 
   for(int i=0; i<img.rows; i++) {
      for(int j=0; j<img.cols; j+=3)  {
         // Sticks each cv::Vec3b into the block array to be sent
         block[c++] = img.at<cv::Vec3b>(i,j)[0];
         block[c++] = img.at<cv::Vec3b>(i,j)[1];
         block[c++] = img.at<cv::Vec3b>(i,j)[2];
      }
   }


   cv:Mat newImg = Mat(img.rows, img.cols, CV_8UC3, 0); 
   c = 0;
   for(int i=0; i<img.rows; i++) {
      for(int j=0; j<img.cols; j+=3)  {
         newImg.at<cv::Vec3b>(i,j)[0] = block[c];
         newImg.at<cv::Vec3b>(i,j)[1] = block[c++];
         newImg.at<cv::Vec3b>(i,j)[2] = block[c++];
      }
   }

   
   
   imshow( "Display Image", newImg );

return 0;
}

