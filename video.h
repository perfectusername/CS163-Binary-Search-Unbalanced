#include <iostream>
#include <cstring>
#include "utilities.h"


struct Length
{
        Length();
        Length(int& incomingHours, int& incomingMinutes, int& incomingSeconds);
        Length(Length& incomingLength);

        int     hours;
        int     minutes;
        int     seconds;
};




class Video
{
public:
        Video();
        Video(const char videoName[],
                        const char className[],
                        const char videoDescription[],
                        const Length& videoLength,
                        const char nextVideoName[]);
        Video(Video& aVideo);
        ~Video();

        int createVideo(const char videoName[],
                        const char className[],
                        const char videoDescription[],
                        const Length& videoLength,
                        const char nextVideoName[]);
        int copyVideo(Video& sourceVideo);

        int displayVideo();
        int deleteVideo();

        int compareVideoNames(const Video& aVideoToCompare);
        int compareVideoNames(const char aVideoName[]);
        int compareClassNames(const Video& aVideoToCompare);
        int compareClassNames(const char aVideoName[]);
        int classNameSize();
        int copyClassName(char nameToCopy[]);
	
private:
        char*   _videoName;        // Name of the video
        char*   _className;        // Name of the class the video is for
        char*   _videoDescription; // Description of the video
        Length* _videoLength;      // Length of the video
        char*   _nextVideoName;    // Name of the next video you should watch.
};
