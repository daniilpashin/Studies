.model small

.code
public _calculate
_calculate proc
	push bp			; сохранили bp в стек
	mov bp, sp		; скопировали sp в bp

					; A * 54
	mov ax, 4[bp]	; достали первый параметр A из стека
	mov bx, 54		; присвоили bx = 54
	mul bx			; знаково помножили ax на bx
	push ax			; сохранили результат в стек

					; C * 3
	mov ax, 6[bp]	; достали второй параметр C
	mov bx, 3		; присвоили bx = 3
	mul bx			; знаково помножили ax на bx
	mov bx, ax		; скопировали результат в bx

	pop ax			; достали сохраненный результат A * 54 в ax
	add ax, bx		; сложили ax и bx
	push ax			; сохранили результат в стек
	
					; A + D - 1
	mov ax, 4[bp]	; достали первый параметр A в ax
	add ax, 8[bp]	; сложили ax и третий параметр D
	dec ax			; уменьшили ax на 1
	cwd

	mov bx, ax		; скопировали ax в bx
	pop ax			; достали сохраненный результат A * 54 + C * 3 в ax
	div bx			; поделили первый результат на второй
	
	pop bp			; вернули bp из стека

	ret
_calculate endp
end
