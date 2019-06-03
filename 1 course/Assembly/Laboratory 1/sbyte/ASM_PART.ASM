.model small

.code
public _calculate
_calculate proc
	push bp			; сохранили bp в стек
	mov bp, sp		; скопировали sp в bp

					; A * 2
	mov al, 4[bp]	; достали первый параметр A из стека
	mov bl, 2		; присвоили bl = 2
	imul bl			; знаково помножили al на bl
	mov cl, al		; сохранили al в cl

					; C * 3
	mov al, 6[bp]	; достали второй параметр C
	mov bl, 3		; присвоили bl = 3
	imul bl			; знаково помножили al на bl
	add al, cl		; сложили al и cl
	
					; A + D - 1
	mov bl, 4[bp]	; достали первый параметр A в bl
	add bl, 8[bp]	; сложили bl и третий параметр D
	dec bl			; уменьшили bl на 1
	
	cbw
	idiv bl			; знаково поделили первый результат на второй
	
	pop bp			; вернули bp из стека
	ret
_calculate endp
end
