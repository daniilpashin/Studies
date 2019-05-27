.model small

.code
public _get_num_between
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
end