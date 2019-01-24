#pragma once
#include "CImg.h" //��������� ���������� ��� ��������� �����������
//��� �������� ���������� � �������� ���������� �������� ������ � ������� � ������� bmp

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class MyImage
{
private:
	cimg_library::CImg<unsigned char> image;	//��������� ������� CImg ��������������� �������� �����
	char name[255];	//��� �������� �����
	double blur;	//������� ��������
	void SaveImage() const;	//����� ��� ���������� ���������������� ����������� � ����
	void BlurImage(double blur);	//����� ��� �������� �����������
public:
	MyImage(const char* name, double blur);	//��������� �����������, ������� ��������� �� ���� ��� ����� � ������� ��������
};