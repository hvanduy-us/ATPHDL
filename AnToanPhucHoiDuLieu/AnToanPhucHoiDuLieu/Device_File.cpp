#include "Device_File.h"

// Ghi vao file
void Write_To_File(string fileName, string content)
{
	fstream file;
	file.open(fileName + ".txt", ios::out);
	file << content;
	file.close();
}

string Read_From_File(string filename)
{
	string content = "";
	ifstream file;

	file.open(filename + ".txt");

	if (file.fail()) {
		cerr << "Error: file not opened." << endl;
		return content;
	}

	string temp;
	while (!file.eof())
	{
		getline(file, temp);
		content += temp;
	}

	file.close();

	return content;
}

//chia noi dung thanh nhieu phan
vector<string> Divided_Content(string content, int count_f)
{
	vector<string> list_content;

	// khich thuoc tung file
	int size = content.length() / (count_f - 1);
	
	int k = 0;
	// lay ra n - 1 doan du lieu
	for (int i = 0; i < count_f - 1; i++)
	{
		list_content.push_back(content.substr(k, size));
		k += size;
	}

	// kiem tra neu con thi ghi vao file tiep 
	if (k < content.length())
	{
		list_content.push_back(content.substr(k, content.length() - k));
	}

	return list_content;
}

// tao ten file
int Create_Name_File(string fileName, int num)
{
	int result;

	// bien doi 1 ki tu thanh 1 ki tu khac
	// cong thuc: a+2num mod 122
	for (int i = 0; i < fileName.length(); i++)
	{
		result = ((int)(fileName[i]) * num*2 % (122) );
	}
	return result;
}

// doc file
void Divided(string fileName,int count_f)
{
	string content;
	vector<string> list_content;
	string filename_new = "";

	content = Read_From_File(fileName);
	cout << content;
	// lay noi dung file
	list_content = Divided_Content(content, count_f);

	int k;
	for (int i = 2, k = 0; i <= count_f + 1; i++,k++)
	{
		filename_new = to_string(Create_Name_File(fileName, i));
		Write_To_File(filename_new, list_content[k]);
	}

}

// gop fil laij
void Join(string fileName, int count_f)
{
	string content;
	vector<string> list_content, l_NameFile;
	string filename_new = "";


	for (int i = 2; i <= count_f + 1; i++)
	{
		l_NameFile.push_back(to_string(Create_Name_File(fileName, i)));
	}

	for (int i = 0; i < count_f; i++)
	{
		content += Read_From_File(l_NameFile[i]);
	}

	Write_To_File(fileName + "Join", content);

}

