section .data
	hello db "Hello, Holberton",0
	newline db 10,0

section .text
	global main
	extern printf

main:
	push rdi
	mov rdi, hello
	call printf
	pop rdi

	push rdi
	mov rdi, newline
	call printf
	pop rdi

	mov eax, 0x60
	xor edi, edi
	syscall

