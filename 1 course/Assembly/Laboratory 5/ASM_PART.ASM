.8087
.model small

.code
public _calculate
a_multiplier dw 54
c_multiplier dw 3
d_reducer dw 1

_calculate proc
	push bp
	mov bp, sp
	sub sp, 4

	finit
	fild a_multiplier			; st(0) = 54
	fmul dword ptr [bp+4]		; st(0) = 54 * arg0

	fild c_multiplier			; st(1) = 54 * arg0; 
								; st(0) = 3
	fmul dword ptr [bp+8]		; st(1) = 54 * arg0;
								; st(0) = 3 * arg1
	faddp						; st(0) = st(1) + st(0)

	fld dword ptr [bp+12]		; st(1) = ...
								; st(0) = arg2
	fadd dword ptr [bp+4]		; st(1) = ...
								; st(0) = arg2 + arg0
	fild d_reducer				; st(2) = ...
								; st(1) = arg2 + arg0
								; st(0) = 1
	fsubp st(1), st(0)			; st(1) = ...
								; st(0) = st(1) - st(0)
	fdivp

	mov sp, bp
	pop bp
	ret
_calculate endp
end