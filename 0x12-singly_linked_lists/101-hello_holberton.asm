section .data
	hello: db "Hello, Holberton",0

section .text
	global main
	extern printf

main:
	push hello
	call printf
	add esp, 4

	mov eax, 0x60
	xor edi, edi
	syscall

