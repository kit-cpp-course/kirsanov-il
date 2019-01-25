#include "MyImage.h"

void PrintHelp()	//если введено неверное количество аргументов то нужно распечатать help и завершить работу
{
	std::cout <<
		"\t\t How to use program:\n"
		"\t\t program input_file.bmp blur\n"
		"\t\t\t input_file.bmp - input image file name\n"
		"\t\t\t blur - double blur"
		<< std::endl;
}

bool file_exists(const char* name)
{
	std::ifstream f(name);
	return f.good();
}

int main(int argc, char* argv[])	//получаем 5 аргументов: имя программы, первый именованный аргумент (name), имя файла, второй именованный аргумент (blur), степень размытия
{
	if (argc < 5)
	{
		PrintHelp();	//распечатаем сообщение об ошибке
		return 0;	//завершим нашу программу
	}
	else if (strcmp(argv[1], "blur") == 0)
	{
		argv[3] = argv[2];
		argv[2] = argv[4];
		argv[4] = argv[3];
	}
	char full_path[255];
	strcpy(full_path, argv[2]);
	if (argc > 5)	//так как аргументы разделяются пробелами, то имя "example image.bmp" будет считаться как 2 аргумента, поэтому их надо собрать в одну переменную
	{
		for (size_t i = 3; i < argc - 1; i++)
		{
			strcat(full_path, " ");
			strcat(full_path, argv[i]);
		}
	}
	if (!file_exists(full_path))
	{
		std::cout << "Can't open file " << full_path << std::endl;
		return 0;
	}
	try
	{
		//передадим на вход нашего класса имя файла и степень размытия и обработаем файл с последующим сохранением
		MyImage image(full_path, std::stod(argv[argc - 1]));
	}
	catch (const std::invalid_argument& ia)	//если число не удалось распознать перехватим исключение
	{
		std::cerr << "Invalid blur parametr" << std::endl;
	}
	catch (...)	//перехватим все остальные исключения
	{
		std::cerr << "Error during image processing." << std::endl;
	}
	return 0;
}
