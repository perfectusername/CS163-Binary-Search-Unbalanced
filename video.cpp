#include "video.h"

using std::endl;
using std::cout;


Length::Length()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}



Length::Length(int& incomingHours, int& incomingMinutes, int& incomingSeconds)
{
	hours = incomingHours;
	minutes = incomingMinutes;
	seconds = incomingSeconds;
}



Length::Length(Length& incomingLength)
{
	hours = incomingLength.hours;
	minutes = incomingLength.minutes;
	seconds = incomingLength.seconds;
}



Video::Video()
{
	_videoName = nullptr;
	_className = nullptr;
	_videoDescription = nullptr;
	_videoLength = nullptr;
	_nextVideoName = nullptr;
}



Video::Video(const char videoName[],
	const char className[],
	const char videoDescription[],
	const Length& videoLength,
	const char nextVideoName[])
{
	_videoName = nullptr;
	_className = nullptr;
	_videoDescription = nullptr;
	_videoLength = nullptr;
	_nextVideoName = nullptr;
	
	createVideo(videoName, className, videoDescription, videoLength, nextVideoName);
}




Video::Video(Video& aVideo)
{
	_videoName = nullptr;
	_className = nullptr;
	_videoDescription = nullptr;
	_videoLength = nullptr;
	_nextVideoName = nullptr;

	createVideo(aVideo._videoName,
			aVideo._className, 
			aVideo._videoDescription, 
			*aVideo._videoLength,
			aVideo._nextVideoName);
}


Video::~Video()
{
	deleteVideo();
}



int Video::deleteVideo()
{
	int successValue = 0;

	if (_videoName != nullptr)
	{
		delete[] _videoName;
		_videoName = nullptr;
	}
	if (_className != nullptr)
	{
		delete[] _className;
		_className = nullptr;
	}
	if (_videoDescription != nullptr)
	{
		delete[] _videoDescription;
		_videoDescription = nullptr;
	}
	if (_videoLength != nullptr)
	{
		delete _videoLength;
		_videoLength = nullptr;
	}
	if (_nextVideoName != nullptr)
	{
		delete[] _nextVideoName;
		_nextVideoName = nullptr;
	}

	if ((_videoName == nullptr) &&
		(_className == nullptr) &&
		(_videoDescription == nullptr) &&
		(_videoLength == nullptr) &&
		(_nextVideoName == nullptr))
	{
		successValue = 1;
	}

	return successValue;
}


int Video::createVideo(const char videoName[], const char className[], const char videoDescription[], const Length& videoLength, const char nextVideoName[])
{
	int successValue = 0;
	
	successValue = deleteVideo();

	if (successValue  != 0)
	{
		_videoName = new char[strlen(videoName) + 1];
		strcpy(_videoName, videoName);

		_className = new char[strlen(className) + 1];
		strcpy(_className, className);

		_videoDescription = new char[strlen(videoDescription) + 1];
		strcpy(_videoDescription, videoDescription);


		int hours = videoLength.hours;
		int minutes = videoLength.minutes;
		int seconds = videoLength.seconds;

		_videoLength = new Length(hours, minutes, seconds);

		_nextVideoName = new char[strlen(nextVideoName) + 1];
		strcpy(_nextVideoName, nextVideoName);
	}

	return successValue;
}




int Video::copyVideo(Video& sourceVideo)
{
	int successValue = 0;

	if ((sourceVideo._videoName != nullptr) &&
		(sourceVideo._className != nullptr) &&
		(sourceVideo._videoDescription != nullptr) &&
		(sourceVideo._videoLength != nullptr) &&
		(sourceVideo._nextVideoName != nullptr))
	{
		createVideo(sourceVideo._videoName,
				sourceVideo._className,
				sourceVideo._videoDescription,
				*sourceVideo._videoLength,
				sourceVideo._nextVideoName);

		successValue = 1;
	}

	return successValue;
}



int Video::displayVideo()
{
	int successValue = 0;

	if ((_videoName != nullptr) &&
		(_className != nullptr) &&
		(_videoDescription != nullptr) &&
		(_videoLength != nullptr) &&
		(_nextVideoName != nullptr))
	{
		cout << "Video name: " << _videoName << endl;
		cout << "Class name: " << _className << endl;
		cout << "Description: "	<< _videoDescription << endl;
		cout << "Length: " << _videoLength->hours << " hour(s), "
					<< _videoLength->minutes << " minutes, and "
					<< _videoLength->seconds << " seconds" << endl;
		cout << "Next video in playlist: " << _nextVideoName << endl;
		cout << endl;
	
		successValue = 1;
	}

	return successValue;
}



int  compareVideoNames(const char nameToCompare[])
{
	int successValue = 0;

	return successValue;
}




int Video::compareVideoNames(const Video& aVideoToCompare)
{

	return strcmp(_videoName, aVideoToCompare._videoName);
}


int Video::compareVideoNames(const char aVideoName[])
{
	return strcmp(aVideoName, _videoName);
}


int Video::compareClassNames(const Video& aVideoToCompare)
{
	return strcmp(_className, aVideoToCompare._className);
}

int Video::compareClassNames(const char aClassName[])
{
	return strcmp(aClassName, _className);
}


int Video::classNameSize()
{
	return strlen(_className);
}


int Video::copyClassName(char nameToCopy[])
{
	int successValue = 0;
	if (_className != nullptr)
	{
		strcpy(nameToCopy, _className);
		successValue = 1;
	}
	return successValue;
}
