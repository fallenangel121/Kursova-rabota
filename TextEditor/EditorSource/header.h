#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define SIZE 32
#define MAX_SIZE 1000

__declspec(dllexport) int executable_function(const char* text);
extern void keyboard_input(const char* file_name, const char* text_input);
extern void transliterate(const char* another_file, const char* third_file);
extern void uppercase(const char* file_name, const char* result_file);