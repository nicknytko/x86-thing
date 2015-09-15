[GLOBAL pic_remap]0

	PIC1_BASE equ 0x20
	PIC2_BASE equ 0xA0
	PIC1_COM  equ PIC1_BASE
	PIC2_COM  equ PIC2_BASE
	PIC1_DATA equ PIC1_BASE+1
	PIC2_DATA equ PIC2_BASE+2

	PIC_EOI   equ 0x20

pic_sendEOI:			; [esp+4] - irq number
	pop ebx
	pop eax
	push ebx

	cmp eax, 8
	jl _pic_sendEOI_pic1

	mov al, PIC_EOI
	out PIC2_COM, al

_pic_sendEOI_pic1:
	mov al, PIC_EOI
	out PIC1_COM, al

	ret

pic_remap:

	mov al, 0x11		;initialize both pics
	out PIC1_COM, al
	out PIC2_COM, al

	mov al, 0x20		;remap pic1 to interrupt 32
	out PIC1_DATA, al

	mov al, 0x28		;remap pic2 to interrupt 40
	out PIC2_DATA, al

	mov al, 4		;tell pic 1 that pic 2 is at irq2
	out PIC1_DATA, al

	mov al, 2		;tell pic 2 cascade identity
	out PIC2_DATA, al

	mov al, 1		;8086/8088 mode
	out PIC1_DATA, al
	out PIC2_DATA, al
 
	ret
