#include "header.h"

int executable_function(const char* text)
{
	const char* file_name = "text_data.txt";
	const char* another_file = "updated_data.txt";
	const char* third_file = "cyrillic_data.txt";

	keyboard_input(file_name, text);
	uppercase(file_name, another_file);
	transliterate(another_file, third_file);

	return 0;
}
