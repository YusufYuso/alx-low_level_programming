#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// ELF Header structure
typedef struct
{
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} ElfHeader;

// Function to display ELF header information
void displayElfHeader(const ElfHeader *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", header->e_ident[4] == 1 ? "ELF32" : "ELF64");

	printf("  Data:                              2's complement, %s\n", header->e_ident[5] == 1 ? "little endian" : "big endian");

	printf("  Version:                           %d (current)\n", header->e_version);

	printf("  OS/ABI:                            %d\n", header->e_ident[7]);

	printf("  ABI Version:                       %d\n", header->e_ident[8]);

	printf("  Type:                              0x%x\n", header->e_type);

	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return 98;
	}

	// Read and validate ELF magic number
	unsigned char magic[4];
	if (read(fd, magic, 4) != 4 || magic[0] != 0x7f || magic[1] != 'E' || magic[2] != 'L' || magic[3] != 'F')
	{
		fprintf(stderr, "%s is not an ELF file\n", filename);
		close(fd);
		return 98;
	}

	// Seek to the beginning of the ELF header
	lseek(fd, 0, SEEK_SET);

	ElfHeader header;
	if (read(fd, &header, sizeof(ElfHeader)) != sizeof(ElfHeader))
	{
		perror("Error reading ELF header");
		close(fd);
		return 98;
	}

	// Display ELF header information
	displayElfHeader(&header);

	close(fd);
	return 0;
}
