#include "MyImage.h"

void PrintHelp()	//���� ������� �������� ���������� ���������� �� ����� ����������� help � ��������� ������
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

int main(int argc, char* argv[])	//�������� 3 ���������: ��� ���������, ��� ����� � ������� ��������
{
	if (argc < 3)
	{
		PrintHelp();	//����������� ��������� �� ������
		return 0;	//�������� ���� ���������
	}
	char full_path[255];
	strcpy(full_path, argv[1]);
	if (argc > 3)	//��� ��� ��������� ����������� ���������, �� ��� "example image.bmp" ����� ��������� ��� 2 ���������, ������� �� ���� ������� � ���� ����������
	{
		for (size_t i = 2; i < argc - 1; i++)
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
		//��������� �� ���� ������ ������ ��� ����� � ������� �������� � ���������� ���� � ����������� �����������
		MyImage image(full_path, std::stod(argv[argc - 1]));
	}
	catch (const std::invalid_argument& ia)	//���� ����� �� ������� ���������� ���������� ����������
	{
		std::cerr << "Invalid blur parametr" << std::endl;
	}
	catch (...)	//���������� ��� ��������� ����������
	{
		std::cerr << "Error during image processing." << std::endl;
	}
	return 0;
}
