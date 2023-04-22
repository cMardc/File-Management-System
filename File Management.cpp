#include "File Management.h"
using namespace std;
namespace fs = filesystem;

int main()
{
	fileManager files;
	string path;
	int count;
	cout << "\nEnter Count Of Files : ";
	cin >> count;
	for (int i = 1; i <= count; i++)
	{
		cout << "\nEnter " << i << ". Path : ";
		cin.ignore();
		getline(cin, path);
		files.attach(path);
	}
	string dirPath;
	cout << "\nEnter Manager Path : ";
	getline(cin, dirPath);
	files.CreateDirectory(dirPath);
	return 0;
}

