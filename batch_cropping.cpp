#include <stdio.h>
#include <highgui.h>
#include <cv.h>
#include <string.h>
#include <vector>
#include "dirent.h"

#define HOST_DIR "C:\\vs\\train_samples\\INRIAPerson\\70X134H96\\Test\\pos"
#define SAMPLE_PATH "C:\\1023\\"
#define START_NUM 100

using namespace std;
using namespace cv;

bool check_line_state=false; 
IplImage* workImg; 
IplImage* imgshow; 
CvRect ROI_rect;
int temp;
char flag;
int i = START_NUM;				
IplImage* result=NULL;
IplImage* result1=NULL;

void on_mouse(int event, int x,int y,int flags,void* param) 
{ 
	int thickness=1; 
	CvPoint p1,p2; 
	char* samplepath = SAMPLE_PATH;
	string path;
	char temppath[256];
	char* filename = new char[256];
	if(event==CV_EVENT_LBUTTONDOWN) 
	{ 
		x=MAX(0,x);
		y=MAX(0,y);
		x=MIN(x,workImg->width);
		y=MIN(y,workImg->height);
		ROI_rect.x=x; 
		ROI_rect.y=y; 
		check_line_state=true; 
	} 
	else if(check_line_state&&event==CV_EVENT_MOUSEMOVE) 
	{ 
		cvCopy(workImg,imgshow);
		x=MAX(0,x);
		y=MAX(0,y);
		x=MIN(x,workImg->width);
		y=MIN(y,workImg->height);
		p1=cvPoint(ROI_rect.x,ROI_rect.y); 
		p2=cvPoint(x,y); 
		ROI_rect.width=abs(x-ROI_rect.x);
		ROI_rect.height=abs(y-ROI_rect.y);
		cvRectangle(imgshow,p1,p2,CV_RGB(0,255,150),thickness,CV_AA,0); 
		cvShowImage("image",imgshow); 
	} 
	else if(check_line_state&&event==CV_EVENT_LBUTTONUP) 
	{ 
		check_line_state=false; 
		if(ROI_rect.x>x)
		{
			temp = ROI_rect.x;
			ROI_rect.x = x;
			x = temp;
		}
		if(ROI_rect.y>y)
		{
			temp = ROI_rect.y;
			ROI_rect.y = y;
			y = temp;
		}
		memset(temppath,'\0',256*sizeof(char));
		memset(filename,'\0',256*sizeof(char));
		sprintf(temppath,"%d.jpg",i);
		int len = strlen(temppath); 
		string temp1 = temppath;
		path = samplepath + temp1 ;
		path.copy(filename,256,0);				
		*(filename+256)='\0';
		cvSetImageROI(workImg,ROI_rect);
		result=cvCreateImage(cvGetSize(workImg), workImg->depth, workImg->nChannels );
		cvCopy(workImg,result);
		result1=cvCreateImage(cvSize(128,128),result->depth,result->nChannels);
		cvResize(result,result1,CV_INTER_LINEAR);
		cvResetImageROI(workImg);
		cvSaveImage(filename,result1); 
		i++;
		cvReleaseImage(&result);
		cvReleaseImage(&result1);
	} 
} 

int main() 
{ 
	char* host_folder = HOST_DIR;					
	DIR *pDIR;
	struct dirent *entry;
	if( pDIR=opendir(host_folder) )
	{
		while(entry = readdir(pDIR))
		{	
			if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
			{
				char input_image_path[256];
				sprintf(input_image_path, "%s\\%s", host_folder, entry->d_name);
				workImg = cvLoadImage(input_image_path,CV_LOAD_IMAGE_COLOR); 
				imgshow = cvCreateImage(cvSize(workImg->width,workImg->height),workImg->depth,workImg->nChannels); 
				cvCopy(workImg,imgshow); 
				ROI_rect.x=ROI_rect.y=0; 
				cvNamedWindow("image",CV_WINDOW_AUTOSIZE); 
				cvShowImage("image",imgshow);
				cvSetMouseCallback("image",on_mouse); 
				cvWaitKey(0);
			}
		}
	}
	cvDestroyWindow("image"); 
	return 0;
}
