#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_elf_header(Elf64_Ehdr *elf_header);

int main(int argc, char *argv[]) 
{
	int fd;
	Elf64_Ehdr elf_header;
	
	if (argc != 2) 
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		dprintf(STDERR_FILENO, "Error: Cannot open ELF file\n");
		exit(98);
	}
	
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
	close(fd);
	exit(98);
	}

	close(fd);

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	display_elf_header(&elf_header);

	return (0);
}

void display_elf_header(Elf64_Ehdr *elf_header) 
{
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
			elf_header->e_ident[EI_MAG0],
			elf_header->e_ident[EI_MAG1],
			elf_header->e_ident[EI_MAG2],
			elf_header->e_ident[EI_MAG3]);
	printf("  Class:                             %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "2's complement, big-endian");
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", elf_header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" : "Other (unknown type)");
	printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}
