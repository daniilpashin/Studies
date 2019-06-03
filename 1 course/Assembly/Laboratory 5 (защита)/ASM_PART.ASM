.8087
.model small

.code
public _calculate
x_add dw 200

_calculate proc
	push bp
	mov bp, sp
	sub sp, 4

	finit
	fld dword ptr [bp+4]
	fmul st(0), st(0)
	fmul st(0), st(0)

	fld dword ptr [bp+4]
	fild x_add
	faddp st(1), st(0)

	fdivp
	

	mov sp, bp
	pop bp
	ret
_calculate endp
end