.model small

.data
buffer db 6, ?, 6 dup(0)
a_number dw ?
c_number dw ?
d_number dw ?
enter_a_number_message db 'Enter A number: $'
enter_c_number_message db 'Enter C number: $'
enter_d_number_message db 'Enter D number: $'
input_is_not_a_number_error_message db 'Input string is not a numeric!$'

.code
public _main
_main proc
	mov ax, @data
	mov ds, ax
	
	lea dx, enter_a_number_message
	mov ah, 09h
	int 21h

	call _read_string_and_length
	call _string_is_numeric
	test ax, ax
	jnz string_read_error
	call _string_to_number
	mov a_number, ax
	
	
	lea dx, enter_c_number_message
	mov ah, 09h
	int 21h

	call _read_string_and_length
	call _string_is_numeric
	test ax, ax
	jnz string_read_error
	call _string_to_number
	mov c_number, ax

	
	lea dx, enter_d_number_message
	mov ah, 09h
	int 21h

	call _read_string_and_length
	call _string_is_numeric
	test ax, ax
	jnz string_read_error
	call _string_to_number
	mov d_number, ax

	mov ax, 0600h
	mov bh, 7
	mov cx, 0
	mov dx, 184fh
	int 10h

	mov bx, a_number
	mov cx, c_number
	mov dx, d_number
	push dx
	push cx
	push bx
	call _calculate
	pop bx
	pop cx
	pop dx

	call _print_ax

	jmp exit

string_read_error:
	lea dx, input_is_not_a_number_error_message
	mov ah, 09h
	int 21h

exit:
	ret
_main endp

; RETURN
; si - string
; cx - string length
_read_string_and_length proc
	mov ah, 0ah
	lea dx, buffer
	int 21h

	mov si, offset buffer + 2
	mov bx, offset buffer + 1
	mov al, [bx]
	cbw
	mov cx, ax
_read_string_and_length endp

; ARGUMENTS
; si - string
; cx - string length
_string_is_numeric proc
	push cx
	xor bx, bx
	xor dx, dx

string_check_loop:
	mov dl, [si+bx]
	cmp dl, '0'
	jl string_check_error

	cmp dl, '9'
	jg string_check_error
	
	inc bx
	loop string_check_loop

	mov ax, 0
	jmp string_check_exit

string_check_error:
	mov ax, 1

string_check_exit:
	pop cx
	ret
_string_is_numeric endp


_string_to_number proc
	push cx
	xor bx, bx
	xor ax, ax
string_convert_loop:
	push cx

	push ax
	mov al, [si+bx]
	cbw
	sub ax, '0'
	mov cx, ax
	pop ax

	push bx
	mov bx, 10
	mul bx
	pop bx

	add ax, cx

	pop cx
	inc bx
	loop string_convert_loop
	
	pop cx
	ret
_string_to_number endp


_print_ax proc
	push ax
	push bx
	push cx
	push dx

	xor cx, cx
	mov bx, 10
	
print_ax_loop_1:
	xor dx, dx
	inc cx
	div bx
 	push dx

	cmp ax, 0
	jnz print_ax_loop_1

print_ax_loop_2:
	pop dx
	add dx, '0'
	mov ah, 02h
	int 21h

	loop print_ax_loop_2
	
 	pop dx
 	pop cx
 	pop bx
 	pop ax
	ret  
_print_ax endp


_calculate proc
	push bp			; сохранили bp в стек
	mov bp, sp		; скопировали sp в bp

					; A * 2
	mov ax, 4[bp]	; достали первый параметр A из стека
	mov bx, 2		; присвоили bx = 2
	mul bx			; знаково помножили ax на bx
	push ax			; сохранили результат в стек

					; C * 3
	mov ax, 6[bp]	; достали второй параметр C
	mov bx, 3		; присвоили bx = 3
	mul bx			; знаково помножили ax на bx
	mov bx, ax		; скопировали результат в bx

	pop ax			; достали сохраненный результат A * 2 в ax
	add ax, bx		; сложили ax и bx
	push ax			; сохранили результат в стек
	
					; A + D - 1
	mov ax, 4[bp]	; достали первый параметр A в ax
	add ax, 8[bp]	; сложили ax и третий параметр D
	dec ax			; уменьшили ax на 1
	cwd

	mov bx, ax		; скопировали ax в bx
	pop ax			; достали сохраненный результат A * 2 + C * 3 в ax
	div bx			; поделили первый результат на второй
	
	pop bp			; вернули bp из стека

	ret
_calculate endp
end
