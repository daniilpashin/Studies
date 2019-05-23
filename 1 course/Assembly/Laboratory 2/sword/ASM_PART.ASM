.model small

.code
public _calculate
_calculate proc
	push bp
	mov bp, sp

	mov ax, 4[bp]
	mov bx, 6[bp]
	cmp ax, bx
	jg more
	jl less
	jmp equal

less:
	add ax, 12
	mov bx, 12
	idiv bx
	jmp func_end
	
more:
	xchg ax, bx
	idiv bx
	add ax, 126
	jmp func_end

equal:
	mov ax, -44

func_end:
	pop bp

	ret
_calculate endp
end
