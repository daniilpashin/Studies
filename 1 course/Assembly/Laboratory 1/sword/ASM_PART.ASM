.model small

.code
public _calculate
_calculate proc
	push bp			; сохранили bp в стек
	mov bp, sp		; скопировали sp в bp

					; A * 2
	mov ax, 4[bp]	; достали первый параметр A из стека
	mov bx, 2		; присвоили bx = 2
	imul bx			; знаково помножили ax на bx
	push ax			; сохранили результат в стек

					; C * 3
	mov ax, 6[bp]	; достали второй параметр C
	mov bx, 3		; присвоили bx = 3
	imul bx			; знаково помножили ax на bx
	mov bx, ax		; скопировали результат в bx

	pop ax			; достали сохраненный результат A * 2 в ax
	add ax, bx		; сложили ax и bx
	push ax			; сохранили результат в стек
	
					; A + D - 1
	mov ax, 4[bp]	; достали первый параметр A в ax
	add ax, 8[bp]	; сложили ax и третий параметр D
	dec ax			; уменьшили ax на 1
	cwd

	mov bx, ax		; скопировали ax в bx
	pop ax			; достали сохраненный результат A * 2 + C * 3 в ax
	idiv bx			; поделили первый результат на второй
	
	pop bp			; вернули bp из стека

	ret
_calculate endp
end
