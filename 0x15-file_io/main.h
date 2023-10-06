#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void print_elf_header_info(Elf64_Ehdr *header);
char *get_osabi_name(unsigned char osabi);
char *get_type_name(uint16_t type);
int is_elf_file(Elf64_Ehdr *header);

#define ERR_USAGE 98
#define ERR_OPEN  98
#define ERR_READ  98
#define ERR_NOT_ELF 98

#endif
