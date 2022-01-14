#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

// ghi vao file
void Write_To_File(string fileName, string content);

// tach 1 noi dung thanh nhieu noi dung khac nhau
vector<string> Divided_Content(string content, int count_f);

// tao ten file co cau truc
int Create_Name_File(string fileName, int num);

// tach file
void Divided(string fileName,int count_f);

// doc file
string Read_From_File(string filename);

// gop file
void Join(string fileName, int count_f);
