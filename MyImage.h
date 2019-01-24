#pragma once
#include "CImg.h" //сторонн€€ библиотека дл€ обработки изображений
//дл€ простоты реализации и удобства приложение работает только с файлами в формате bmp

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class MyImage
{
private:
	cimg_library::CImg<unsigned char> image;	//экземпл€р объЄкта CImg соответствующий входному файлу
	char name[255];	//им€ входного файла
	double blur;	//степень размыти€
	void SaveImage() const;	//метод дл€ сохранени€ преобразованного изображени€ в файл
	void BlurImage(double blur);	//метод дл€ размыти€ изображени€
public:
	MyImage(const char* name, double blur);	//публичный конструктор, который принимает на вход им€ файла и степень размыти€
};