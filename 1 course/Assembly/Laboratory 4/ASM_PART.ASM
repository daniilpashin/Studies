.model small

.data
array_size  dw 10
array dw 5, 10, -25, -10, -20, -25, -50, 100, -100, 0

.code
public _main
_main proc
	lea bx, array
	mov cx, array_size
	
	push -10
	push -50
	push cx
	push bx
	call _get_num_between
	call _print_ax_number
	
	pop bx
	pop cx
	add sp, 4
	ret
_main endp

_get_num_between proc
	push bp
	mov bp, sp
	
	xor ax, ax
	mov bx, [bp+4]
	mov cx, [bp+6]

array_loop:
	mov dx, [bx]
	test dx, dx
	jns array_loop_tag
	
	cmp dx, [bp+8]
	jl array_loop_tag
	
	cmp dx, [bp+10]
	jg array_loop_tag

	inc ax

array_loop_tag:
	add bx, 2
	loop array_loop
	
	pop bp
	ret
_get_num_between endp

_print_ax_number proc
	push bx
	push cx
	push dx

	mov cx, 10
	mov bx, ax

div_loop:
	div cx
	add dx, '0'
	
	push ax
	mov ah, 02h
	int 21h
	pop ax
	cmp ax, 0
	jg div_loop

	mov ax, bx

	pop dx
	pop cx
	pop bx
	ret
_print_ax_number endp
end