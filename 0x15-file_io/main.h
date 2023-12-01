#ifndef main_h
#define main_h

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void close_and_exit(int fd, int exit_code);

struct elf_header {
       	uint32_t magic;
	uint8_t class;
	uint8_t data;
	uint8_t version;
	uint8_t OS_ABI;
	uint8_t ABIVersion;
	uint16_t type;
	uint64_t entrypointaddress;
    };
int read_elf_header(const char *filename, struct elf_header *elf);
void print_elf_header(const struct elf_header *elf);

#endif
