.model small

.code
public _calculate
_calculate proc
	push bp
	mov bp, sp
	
	mov al, [bp+4]
	cbw
	test ax, ax
	jns @next1
	neg ax

@next1:
	mov bx, 200
	add bx, ax

	mov al, [bp+4]
	cbw
	mov cx, -2
	mul cx
	test ax, ax
	jns @next2
	neg ax

@next2:
	xor dx, dx
	xchg ax, bx
	div bx

	pop bp
	ret
_calculate endp
end
