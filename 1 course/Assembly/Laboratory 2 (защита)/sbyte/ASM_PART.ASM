.model small

.code
public _calculate
_calculate proc
	push bp
	mov bp, sp

	xor dx, dx
	mov al, 4[bp]
	cbw

	cmp ax, 0
	jl less
	jge moree

less:
	add ax, 200
	jmp func_end
	
moree:
	mov bx, 2
	idiv bx

func_end:
	pop bp
	ret
_calculate endp
end
