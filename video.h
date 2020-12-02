/*

	video.h

	Manage video object

	Author: Brooke Czerwinski
	Date: 12/1/2020
	Class: CS 163
	Program #4

*/


#include <iostream>
#include <cstring>
#include "utilities.h"


// Length struct
struct Length
{
	// Default constructor
	Length();



	// Constructor with arguments
	/*
		INPUT:	- incomingHours - int - the hours for the length
			- incomingMinutes - int - the minutes for the length
			- incomingSeconds - int - the seconds for the length
	*/
	Length(int& incomingHours, int& incomingMinutes, int& incomingSeconds);



	// Constructor with arguments
	// Creates an item with the given details
	/*
		INPUT:	- incomingLength - Length object - item whose details to copy 
							   into the calling object
	*/
	Length(Length& incomingLength);


	int	hours;    // The hours for the length
	int	minutes;  // The minutes for the length
	int	seconds;  // The seconds for the length
};




// Video class
class Video
{
public:
	// Default constructor
	Video();



	// Constructor with arguments
	// Creates a video with the given details
	/*
		INPUT:	- videoName - cstring - the video name
			- className - cstring - the academic class the video belongs to
			- videoDescription - cstring - the description of the video
			- videoLength - Length object - the length of the video
			- nextVideoName - the name of the next video to watch after this one
	*/
	Video(const char videoName[],
                        const char className[],
                        const char videoDescription[],
                        const Length& videoLength,
                        const char nextVideoName[]);


	// Constructor with arguments
	// Creates a video with the given details
	/*
		INPUT:	- aVideo - Video object - video whose details to copy into the calling video
	*/
	Video(Video& aVideo);



	//Destructor
	~Video();



	// Allocate and fill in video with given details
	/*
		INPUT:	- videoName - cstring - the video name
			- className - cstring - the academic class the video belongs to
			- videoDescription - cstring - the description of the video
			- videoLength - Length object - the length of the video
			- nextVideoName - the name of the next video to watch after this one

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int createVideo(const char videoName[],
			const char className[],
			const char videoDescription[],
			const Length& videoLength,
			const char nextVideoName[]);



	// Allocate and fill in with the given Video's details
	/*
		INPUT:	- sourceVideo - Video object - video whose details to copy in the calling video

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int copyVideo(Video& sourceVideo);



	// Copy calling className into argument cstring
	/*
		INPUT:	- nameToCopy - cstring - cstring that will hold the copied className

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int copyClassName(char nameToCopy[]);



	// Returns the strlen of the className of the calling object
	/*
		OUTPUT:	- returns int - value determined by the strlen of calling className
	*/
	int classNameSize();



	// Compare argument and calling videoNames
	/*
		INPUT:	- aVideoToCompare - Video Object - Video to compare against

		OUTPUT:	- returns int
				- 0 if video names match
				- negative if calling name is less than argument name
				- positive if calling nae is greater than argument name
	*/
	int compareVideoNames(const Video& aVideoToCompare);



	// Compare argument and calling videoName
	/*
		INPUT:	- aVideoName - cstring - name to compare against

		OUTPUT:	- returns int
				- 0 if  names match
				- negative if calling name is less than argument name
				- positive if calling nae is greater than argument name
	*/
	int compareVideoNames(const char aVideoName[]);



	// Compare argument and calling classNames
	/*
		INPUT:	- aVideoToCompare - Video Object - Video to compare against

		OUTPUT:	- returns int
				- 0 if class names match
				- negative if calling name is less than argument name
				- positive if calling nae is greater than argument name
	*/
	int compareClassNames(const Video& aVideoToCompare);



	// Compare argument and calling className
	/*
		INPUT:	- aClassName - cstring - name to compare against

		OUTPUT:	- returns int
				- 0 if  names match
				- negative if calling name is less than argument name
				- positive if calling nae is greater than argument name
	*/
	int compareClassNames(const char aClassName[]);



	// Display all the details of the called Video
	/*
		OUTPUT:	- returns int - 0 for failure, 1 for success
			- Outputs all of the details of the video
	*/
	int displayVideo();



	// Deallocates and deletes all dynamic memory of the Video
	/*
		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteVideo();
	

private:
	char* 	_videoName;        // Name of the video
	char* 	_className;	   // Name of the class the video is for
	char* 	_videoDescription; // Description of the video
	Length* _videoLength;	   // Length of the video
	char* 	_nextVideoName;    // Name of the next video you should watch.
};
