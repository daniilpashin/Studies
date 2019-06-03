.model small

.code
public _calculate
_calculate proc
	push bp
	mov bp, sp
	
	mov al, [bp+4]
	cbw
	mov bx, 200
	add bx, ax

	mov al, [bp+4]
	cbw
	mov cx, -2
	imul cx

	xor dx, dx
	xchg ax, bx
	idiv bx

	pop bp
	ret
_calculate endp
end
