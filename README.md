Batch_Cropping
==============

>**Designer:** Junbo Zhao, Wuhan University, Working in Tsinghua National lab of intelligent images and documents processing.   
**Email:** zhaojunbo1992chasing@gmail.com	 +86-18672365683

**Introduction:**    
This package is written in C++/OpenCV and is named after "Batch_Cropping". As we all know, for computer vision researchers and engineers, high quality samples are of vital importance. For example, those ones who focus on pedestrian detection would need a dataset of pedestrians, of different poses and directions, before the training phase.   
Admittedly, there are some famous datasets, like INRIA, being widely adopted. Nevertheless, in some cases concerning about specific applications, we have to build our own datasets.    
At this point, this package would help you a lot. For example, if you have some images contained in HOST_DIR (the first macro definition), then you should set your SAMPLE_PATH (the second definition), where you would like to contain your cropped sample images. Thereafter, pictures in the HOST_DIR would consecutively appear above the command line (That is why I call this program “batch”), you can just work like you are accustomed to working by PHOTOSHOP, clicking the left mouse button and moving to the end point of selected sample. A green rectangle would appear in the image and that part inside the rectangle would be saved in the SAMPLE_PATH. Sample images are named after "1.jpg", "2.jpg"... The third macro definition of START_POINT defines the starting name of the samples. Moreover, you can crop several samples in one image in HOST_DIR, by drawing several rectangles. 

**Usage:**     
1. You should configure your OpenCV correctly. I only use the functions and definitions of OpenCV 1.0, and thus you won't worry too much about the version being incompatible.   
2. According your requirements and specific cases, set the three macro definitions in batch_cropping.cpp.   
3. Run.

**Notice:**    
Btw, this program is finished on Win7, 32 bit, VS2010 + OpenCV 2.3.1. I cannot guarantee it is compatible on other platforms. If you have successfully compiled this project under other environments or configurations, please feel free to contact me.

