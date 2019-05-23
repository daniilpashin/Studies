.model small

.code
public _calculate
_calculate proc
	push bp
	mov bp, sp

	mov ax, 4[bp]
	test ax, ax
	jns ax_absolute
	neg ax

ax_absolute:
	mov bx, 6[bp]
	test bx, bx
	jns bx_absolute
	neg bx

bx_absolute:
	cmp ax, bx
	jg more
	jl less
	jmp equal

less:
	add ax, 12
	mov bx, 12
	div bx
	jmp func_end
	
more:
	xchg ax, bx
	div bx
	add ax, 126
	jmp func_end

equal:
	mov ax, -44

func_end:
	pop bp
	ret
_calculate endp
end
