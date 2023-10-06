#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

/**
 * print_elf_info - Print ELF header information.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_info(Elf64_Ehdr *header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n",
		   (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		   (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", get_osabi_name(header->e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", get_type_name(header->e_type));
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * get_osabi_name - Get OS/ABI name.
 * @osabi: OS/ABI identifier.
 * Return: OS/ABI name.
 */
char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_SYSV:
		return "UNIX - System V";
	case ELFOSABI_HPUX:
		return "HP-UX";
	case ELFOSABI_NETBSD:
		return "NetBSD";
	case ELFOSABI_LINUX:
		return "Linux";
	case ELFOSABI_SOLARIS:
		return "Solaris";
	case ELFOSABI_AIX:
		return "AIX";
	case ELFOSABI_IRIX:
		return "IRIX";
	case ELFOSABI_FREEBSD:
		return "FreeBSD";
	case ELFOSABI_TRU64:
		return "Compaq TRU64 UNIX";
	case ELFOSABI_ARM:
		return "ARM";
	case ELFOSABI_STANDALONE:
		return "Standalone App";
	default:
		return "<unknown>";
	}
}

/**
 * get_type_name - Get ELF type name.
 * @type: ELF type identifier.
 * Return: ELF type name.
 */
char *get_type_name(uint16_t type)
{
	switch (type)
	{
	case ET_NONE:
		return "NONE (None)";
	case ET_REL:
		return "REL (Relocatable file)";
	case ET_EXEC:
		return "EXEC (Executable file)";
	case ET_DYN:
		return "DYN (Shared object file)";
	case ET_CORE:
		return "CORE (Core file)";
	default:
		return "<unknown>";
	}
}

/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Exit status.
 */
int main(int argc, char *argv[])
{
	const char *elf_filename;
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	elf_filename = argv[1];
	fd = open(elf_filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		close(fd);
		return (98);
	}

	/* Check if it's a valid ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file.\n");
		close(fd);
		return (98);
	}

	print_elf_info(&header);

	close(fd);
	return (0);
}
