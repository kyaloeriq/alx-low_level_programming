#ifndef main_h
#define main_h

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void close_and_exit(int fd, int exit_code);

struct elf_header {
       	int magic;
	int class;
	int data;
	int version;
	int OS_ABI;
	int ABIVersion;
	int type;
	int entrypointaddress;
    };
void read_elf_header(struct elf_header *elf);

#endif
