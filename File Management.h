#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = filesystem;


string ext(string path)
{
	ifstream CFile(path);
	string ext = "";
	size_t size = path.size();
	size_t lastPos = size;
	char letter;
	bool ThereIsDot = false;
	for (size_t i = 0; i < size; i++)
	{
		letter = path[i];
		if (letter == '.')
		{
			lastPos = i;
			ThereIsDot = true;
		}
	}
	if (ThereIsDot)
	{
		for (size_t i = lastPos; i < size; i++)
		{
			letter = path[i];
			ext += letter;
		}
		return ext;
	}
	else
	{
		return "ERROR";
	}
	
}

void printTypes(vector<string> paths)
{
	size_t size = paths.size();
	vector<string> text;
	vector<string> image;
	vector<string> audio;
	vector<string> video;
	vector<string> other;
	string types[12] = { ".doc",".docx",".txt",".bmp",".jpg",".png",".avi",".mpg",".flv",".mp4",".wav",".mp3" };
	string file, type;
	size_t sType = 12;
	size_t lastPos;
	bool Found;
	for (size_t i = 0; i < size; i++)
	{
		Found = false;
		file = paths[i];
		type = ext(file);
		for (size_t j = 0; j < sType; j++)
		{
			if (type == types[j])
			{
				lastPos = j;
				Found = true;
				break;
			}
		}

		if (Found)
		{
			if (lastPos == 0 or lastPos == 1 or lastPos == 2)
			{
				text.push_back(file);
			}
			else if (lastPos == 3 or lastPos == 4 or lastPos == 5)
			{
				image.push_back(file);
			}
			else if (lastPos == 6 or lastPos == 7 or lastPos == 8 or lastPos == 9)
			{
				video.push_back(file);
			}
			else
			{
				audio.push_back(file);
			}
		}
		else
		{
			other.push_back(file);
		}

	}
	size_t sizeText = text.size();
	size_t sizeImage = image.size();
	size_t sizeVideo = video.size();
	size_t sizeAudio = audio.size();
	size_t sizeOther = other.size();

	cout << "Text Files : \n";
	for (size_t i = 0; i < sizeText; i++)
	{
		cout << text[i] << "\n";
	}
	cout << "\n";

	cout << "Image Files : \n";
	for (size_t i = 0; i < sizeImage; i++)
	{
		cout << image[i] << "\n";
	}
	cout << "\n";

	cout << "Video Files : \n";
	for (size_t i = 0; i < sizeVideo; i++)
	{
		cout << video[i] << "\n";
	}
	cout << "\n";

	cout << "Audio Files : \n";
	for (size_t i = 0; i < sizeAudio; i++)
	{
		cout << audio[i] << "\n";
	}
	cout << "\n";

	cout << "Other Files : \n";
	for (size_t i = 0; i < sizeOther; i++)
	{
		cout << other[i] << "\n";
	}
	cout << "\n";
}

string name(string path)
{
	ifstream file(path);
	size_t size = path.size();
	size_t lastPos;
	string name = "";
	char symbol;
	bool hasName = false;
	for (size_t i = 0; i < size; i++)
	{
		symbol = path[i];
		if (symbol == '\\')
		{
			hasName = true;
			lastPos = i;
		}
	}
	if (hasName)
	{
		for (size_t i = lastPos + 1; i < size; i++)
		{
			symbol = path[i];
			if (symbol == '.')
			{
				break;
			}
			name += symbol;
		}
		return name;
	}
	else
	{
		return "ERROR";
	}
}



class fileManager
{
private:

	string path, format;
	ifstream file;
	vector<string> paths;

public:

	void attach(string input)
	{
		path = input;
		format = ext(path);
		file.open(path);
		paths.push_back(path);
	}

	bool Opened()
	{
		size_t size = paths.size();
		bool worked = true;
		for (size_t i = 0; i < size; i++)
		{
			file.open(paths[i]);
			if (!file.is_open())
			{
				worked = false;
			}
		}
		return worked;
	}

	void show()
	{
		printTypes(paths);
	}

	void CreateDirectory(string path)
	{
		size_t size = paths.size();
		vector<string> text;
		vector<string> image;
		vector<string> audio;
		vector<string> video;
		vector<string> other;
		string types[12] = { ".doc",".docx",".txt",".bmp",".jpg",".png",".avi",".mpg",".flv",".mp4",".wav",".mp3" };
		string file, type;
		size_t sType = 12;
		size_t lastPos;
		bool Found;
		for (size_t i = 0; i < size; i++)
		{
			Found = false;
			file = paths[i];
			type = ext(file);
			for (size_t j = 0; j < sType; j++)
			{
				if (type == types[j])
				{
					lastPos = j;
					Found = true;
					break;
				}
			}

			if (Found)
			{
				if (lastPos == 0 or lastPos == 1 or lastPos == 2)
				{
					text.push_back(file);
				}
				else if (lastPos == 3 or lastPos == 4 or lastPos == 5)
				{
					image.push_back(file);
				}
				else if (lastPos == 6 or lastPos == 7 or lastPos == 8 or lastPos == 9)
				{
					video.push_back(file);
				}
				else
				{
					audio.push_back(file);
				}
			}
			else
			{
				other.push_back(file);
			}

		}


		size_t sizeText = text.size();
		size_t sizeImage = image.size();
		size_t sizeVideo = video.size();
		size_t sizeAudio = audio.size();
		size_t sizeOther = other.size();

		fs::create_directories(path);


		fs::create_directories(path + "\\Text Files");
		for (size_t i = 0; i < sizeText; i++)
		{
			string result = path + "\\Text Files\\" + name(text[i]) + ext(text[i]);
			ofstream text(result);
			text.close();
		}


		fs::create_directories(path + "\\Image Files");
		for (size_t i = 0; i < sizeImage; i++)
		{
			string result = path + "\\Image Files\\" + name(image[i]) + ext(image[i]);
			ofstream image(result);
			image.close();
		}

		fs::create_directories(path + "\\Video Files");
		for (size_t i = 0; i < sizeVideo; i++)
		{
			string result = path + "\\Video Files\\" + name(video[i]) + ext(video[i]);
			ofstream video(result);
			video.close();
		}

		fs::create_directories(path + "\\Audio Files");
		for (size_t i = 0; i < sizeAudio; i++)
		{
			string result = path + "\\Audio Files\\" + name(audio[i]) + ext(audio[i]);
			ofstream audio(result);
			audio.close();
		}

		fs::create_directories(path + "\\Other Files");
		for (size_t i = 0; i < sizeOther; i++)
		{
			string result = path + "\\Other Files\\" + name(other[i]) + ext(other[i]);
			ofstream other(result);
			other.close();
		}
	}
};