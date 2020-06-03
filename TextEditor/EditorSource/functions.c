#include "header.h"

void keyboard_input(const char* file_name, const char* text_input)
{
	FILE* out_file;
	out_file = fopen(file_name, "w");

	if (out_file == NULL)
	{
		printf("Could not open file");
		exit(1);
	}

	fprintf(out_file, "%s", text_input);

	fclose(out_file);
}

void uppercase(const char* file_name, const char* result_file)
{
	int i = 0;
	FILE* read_file, * result;
	FILE* errors_file;
	char str[MAX_SIZE] = { 0 };
	int errors = 0;

	read_file = fopen(file_name, "r");
	result = fopen(result_file, "w");
	errors_file = fopen("errors.txt", "w");
	if (errors_file == NULL) {
		printf("Could not open file");
		exit(1);
	}
	if (read_file == NULL)
	{
		printf("Could not open file");
		exit(1);
	}
	else if (result == NULL)
	{
		printf("Could not open file");
		exit(1);
	}
	else
	{
		while (fgets(str, sizeof(str), read_file) != NULL)
		{
			char* p = str;
			if (*p >= 97 && *p <= 122) {
				fprintf(errors_file, "Was: %s", str);
				*p = toupper(*p);
				fprintf(errors_file, "Is: %s", str);
				errors++;
				if (errors % 10 == 0) {
					fseek(errors_file, 0, SEEK_SET);
				}
			}


			for (; *p; p++)
			{
				if (*p == '.')
				{
					p++;
					while (*p == ' ')
					{
						p++;
					}
					fprintf(errors_file, "Was: %s", str);
					*p = toupper(*p);
					fprintf(errors_file, "Is: %s", str);
					errors++;
					if (errors % 10 == 0) {
						fseek(errors_file, 0, SEEK_SET);
					}
				}
			}

			fprintf(result, "%s", str);

		}
	}
	fclose(read_file);
	fclose(result);
	fclose(errors_file);
}

void transliterate(const char* another_file, const char* third_file)
{
	system("chcp 1251\n");
	setlocale(LC_ALL, "UTF8");
	int test = 0;

	FILE* read_file = fopen(another_file, "r"),
		* result = fopen(third_file, "w");
	char str[MAX_SIZE];

	if (read_file == NULL)
	{
		printf("Could not open file");
		exit(1);
	}
	else if (result == NULL)
	{
		printf("Could not open file");
		exit(1);
	}
	else
	{
		while (fgets(str, sizeof(str), read_file) != NULL)
		{

			for (char* p = str; *p; p++)
			{
				if (*p == 'a') fprintf(result, "%c", '\u0430');
				//else if (*p == 'a') fprintf(result, "%c", '\u044A');
				else if (*p == 'A') fprintf(result, "%c", '\u0410');
				else if (*p == 'b') fprintf(result, "%c", '\u0431');
				else if (*p == 'B') fprintf(result, "%c", '\u0411');
				else if (*p == 'v') fprintf(result, "%c", '\u0432');
				else if (*p == 'V') fprintf(result, "%c", '\u0412');
				else if (*p == 'g') fprintf(result, "%c", '\u0433');
				else if (*p == 'G') fprintf(result, "%c", '\u0413');
				else if (*p == 'd') fprintf(result, "%c", '\u0434');
				else if (*p == 'D') fprintf(result, "%c", '\u0414');
				else if (*p == 'e') fprintf(result, "%c", '\u0435');
				else if (*p == 'E') fprintf(result, "%c", '\u0415');

				else if (*p == 'z')
				{
					if (*(p + 1) == 'h')
					{
						fprintf(result, "%c", '\u0436');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0437');
					}
				}
				else if (*p == 'Z') {
					if (*(p + 1) == 'h')
					{
						fprintf(result, "%c", '\u0416');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0417');
					}

				}
				else if (*p == 'i') fprintf(result, "%c", '\u0438');
				else if (*p == 'I') fprintf(result, "%c", '\u0418');
				else if (*p == 'k') fprintf(result, "%c", '\u043A');
				else if (*p == 'K') fprintf(result, "%c", '\u041A');
				else if (*p == 'l') fprintf(result, "%c", '\u043B');
				else if (*p == 'L') fprintf(result, "%c", '\u041B');
				else if (*p == 'm') fprintf(result, "%c", '\u043C');
				else if (*p == 'M') fprintf(result, "%c", '\u041C');
				else if (*p == 'n') fprintf(result, "%c", '\u043D');
				else if (*p == 'N') fprintf(result, "%c", '\u041D');
				else if (*p == 'o') fprintf(result, "%c", '\u043E');
				else if (*p == 'O') fprintf(result, "%c", '\u041E');
				else if (*p == 'p') fprintf(result, "%c", '\u043F');
				else if (*p == 'P') fprintf(result, "%c", '\u041F');
				else if (*p == 'r') fprintf(result, "%c", '\u0440');
				else if (*p == 'R') fprintf(result, "%c", '\u0420');
				else if (*p == 'u') fprintf(result, "%c", '\u0443');
				else if (*p == 'U') fprintf(result, "%c", '\u0423');
				else if (*p == 'f') fprintf(result, "%c", '\u0444');
				else if (*p == 'F') fprintf(result, "%c", '\u0424');
				else if (*p == 'h') fprintf(result, "%c", '\u0445');
				else if (*p == 'H') fprintf(result, "%c", '\u0425');
				else if (*p == 't')
				{
					if (*(p + 1) == 's')
					{
						fprintf(result, "%c", '\u0446');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0442');
					}
				}
				else if (*p == 'T')
				{
					if (*(p + 1) == 's')
					{
						fprintf(result, "%c", '\u0426');
						p++;
					}
					else if ((*(p + 1) != 's'))
					{
						fprintf(result, "%c", '\u0422');
					}
				}
				else if (*p == 'c')
				{
					if (*(p + 1) == 'h')
					{
						fprintf(result, "%c", '\u0447');
						p++;
					}
					if (*p == 'C')
					{
						if (*(p + 1) == 'h')
						{
							fprintf(result, "%c", '\u0427');
							p++;
						}
					}
				}
				else if (*p == 's')
				{
					if (*(p + 1) == 'h' && *(p + 2) == 't')
					{
						fprintf(result, "%c", '\u0449');
						p += 2;
					}
					else if (*(p + 1) == 'h')
					{
						fprintf(result, "%c", '\u0448');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0441');
					}
				}
				else if (*p == 'S')
				{
					if (*(p + 1) == 'h' && *(p + 2) == 't')
					{
						fprintf(result, "%c", '\u0429');
						p += 2;
					}
					else if (*(p + 1) == 'h')
					{
						fprintf(result, "%c", '\u0428');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0421');
					}
				}

				else if (*p == 'y')
				{
					if (*(p + 1) == 'u')
					{
						fprintf(result, "%c", '\u044E');
						p++;
					}
					else if (*(p + 1) == 'a')
					{
						fprintf(result, "%c", '\u044F');
						p++;
					}
					else
					{
						fprintf(result, "%c", '\u0439');
					}
				}
				if (*p == 'Y')
				{
					if (*(p + 1) == 'u')
					{
						fprintf(result, "%c", '\u042E');
						p++;
					}
					else if (*(p + 1) == 'a')
					{
						fprintf(result, "%c", '\u042F');
						p++;
					}
				}
				else if (*p == ' ') fprintf(result, "%c", ' ');
				else if (*p == '.') fprintf(result, "%c", '.');
			}
			fprintf(result, "\n");
		}
		fclose(read_file);
		fclose(result);
	}
}
