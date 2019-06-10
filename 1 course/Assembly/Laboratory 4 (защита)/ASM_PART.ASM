.model small

.data
array_size  dw 10
array dw 5, 10, -25, -10, -20, -25, -50, 100, -100, 0

.code
public _main
_main proc
	lea bx, array
	mov cx, array_size
	
	push cx
	push bx
	call _get_positive_count
	call _print_ax_number
	
	pop bx
	pop cx
	ret
_main endp

_get_positive_count proc
	push bp
	mov bp, sp
	
	xor ax, ax
	mov bx, [bp+4]
	mov cx, [bp+6]

array_loop:
	mov dx, [bx]
	cmp dx, 0
	jl array_loop_tag
	
	add ax, dx

array_loop_tag:
	add bx, 2
	loop array_loop
	
	pop bp
	ret
_get_positive_count endp


_print_ax_number proc
print_ax_mark:
 	push ax
 	push bx
 	push cx
 	push dx

	mov ah, 0
 	cmp ax, 0
 	je print_ax_number_done
 	mov dl, 10
 	div dl
 	call print_ax_mark
 	mov al, Ah
 	add al, 30h
 	mov ah, 0eh
 	int 10h

print_ax_number_done:
 	pop dx
 	pop cx
 	pop bx
 	pop ax
	ret  
_print_ax_number endp
end