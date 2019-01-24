#include "MyImage.h"

void MyImage::SaveImage() const	//����� ��� ���������� ���������������� ����������� � ����
{
	std::string outputName (this->name);
	outputName.insert(outputName.length() - 4,"-output");	//������� � ����� ����� ��������� ����� "-output", outputName.length() - 4 ����� ��� ����, ����� �������� "-output" ����� ����������� .bmp
	image.save(outputName.c_str());
}

void MyImage::BlurImage(double blur)	//����� ��� �������� �����������
{
	this->image.blur(blur, true);
	//��� ����� CImg<T>& vanvliet(const float sigma, const unsigned int order, const char axis='x',const bool boundary_conditions = true) �� ������������� ����� CImg.h ������ 35892
}

MyImage::MyImage(const char* name, double blur) :blur(blur)	//��������� �����������, ������� ��������� �� ���� ��� ����� � ������� ��������
{
	strcpy(this->name, name);
	image.assign(this->name);
	this->BlurImage(this->blur);
	this->SaveImage();
}