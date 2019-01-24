#include "MyImage.h"

void MyImage::SaveImage() const	//метод для сохранения преобразованного изображения в файл
{
	std::string outputName (this->name);
	outputName.insert(outputName.length() - 4,"-output");	//добавим в конец имени выходного файла "-output", outputName.length() - 4 нужно для того, чтобы вставить "-output" перед расширением .bmp
	image.save(outputName.c_str());
}

void MyImage::BlurImage(double blur)	//метод для размытия изображения
{
	this->image.blur(blur, true);
	//это метод CImg<T>& vanvliet(const float sigma, const unsigned int order, const char axis='x',const bool boundary_conditions = true) из заголовочного файла CImg.h строка 35892
}

MyImage::MyImage(const char* name, double blur) :blur(blur)	//публичный конструктор, который принимает на вход имя файла и степень размытия
{
	strcpy(this->name, name);
	image.assign(this->name);
	this->BlurImage(this->blur);
	this->SaveImage();
}