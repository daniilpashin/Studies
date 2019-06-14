
global _start
extern printf
extern scanf
extern exit

section .text
_start:

	push enter_a_number_message
	call printf
	add esp, 4
	push a_number
	push integer_scanf_format
	call scanf
	
	add esp, 8
	
	push enter_c_number_message
	call printf
	add esp, 4
	push c_number
	push integer_scanf_format
	call scanf
	
	add esp, 8
	
	push enter_d_number_message
	call printf
	add esp, 4
	push d_number
	push integer_scanf_format
	call scanf
	
	add esp, 8

								; A * 2
	mov eax, dword [a_number]	; достали первый параметр A из стека
	mov ebx, 2					; присвоили bx = 2
	mul ebx						; знаково помножили ax на bx
	push eax					; сохранили результат в стек

								; C * 3
	mov eax, dword [c_number]	; достали второй параметр C
	mov ebx, 3					; присвоили bx = 3
	mul ebx						; знаково помножили ax на bx
	mov ebx, eax				; скопировали результат в bx

	pop eax						; достали сохраненный результат A * 2 в ax
	add eax, ebx				; сложили ax и bx
	push eax					; сохранили результат в стек
	
								; A + D - 1
	mov eax, dword [a_number]	; достали первый параметр A в ax
	mov ebx, dword [d_number]	; сложили ax и третий параметр D
	add eax, ebx
	dec eax						; уменьшили ax на 1

	mov ebx, eax				; скопировали ax в bx
	pop eax						; достали сохраненный результат A * 2 + C * 3 в ax
	div ebx						; поделили первый результат на второй


	push eax
	push integer_printf_format
	call printf
	add esp, 8

	push dword 0
	call exit

	
section .data
a_number times 4 db 0
c_number times 4 db 0
d_number times 4 db 0

enter_a_number_message :  db "Enter A number: ", 0
enter_c_number_message : db "Enter C number: ", 0
enter_d_number_message : db "Enter D number: ", 0

integer_scanf_format : db "%i", 0
integer_printf_format : db "%i", 0xa, 0