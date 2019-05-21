.model small

.code
public _calculate
_calculate proc
	push bp			; сохранили bp в стек
	mov bp, sp		; скопировали sp в bp

					; A * 54
	mov ax, 0
	mov al, 4[bp]	; достали первый параметр A из стека
	mov bl, 54		; присвоили bl = 54
	imul bl			; знаково помножили al на bl
	push ax			; сохранили результат в стек

					; C * 3
	mov al, 6[bp]	; достали второй параметр C
	mov bl, 3		; присвоили bl = 3
	imul bl			; знаково помножили al на bl
	mov bl, al		; скопировали результат в bl

	pop ax			; достали сохраненный результат A * 54 в ax
	add al, bl		; сложили al и bl
	push ax			; сохранили результат в стек
	
					; A + D - 1
	mov al, 4[bp]	; достали первый параметр A в al
	add al, 8[bp]	; сложили al и третий параметр D
	dec al			; уменьшили al на 1
	cbw

	mov bx, ax		; скопировали al в bl
	pop ax			; достали сохраненный результат A * 54 + C * 3 в ax
	idiv bx			; поделили первый результат на второй
	
	pop bp			; вернули bp из стека

	ret
_calculate endp
end
