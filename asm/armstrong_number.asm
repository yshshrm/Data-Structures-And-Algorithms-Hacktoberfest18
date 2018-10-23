extern scanf
	extern printf
section .data
	des : db "******Amstrong Number******",10,10,0
	input : db "enter a number",10,0
	int : db "%d",0
	out : db "%d",10,0
	amstrong : db "%d is an amstrong number",10,0
	result : db "%d is not an amstrong number",10,0
	x : db 0
	
section .text
	global main
main:
	push ebp
	mov ebp,esp
	
	push des
	call printf

	push input 
	call printf

	lea eax,[ebp-0x04]
	push eax
	push int
	call scanf

	mov dword[ebp-0x14],0x2
	
	mov eax,dword[ebp-0x4]
	mov [x],eax
	mov dword[ebp-0x08],eax		;input

	mov dword[ebp-0x0c],0		;sum
	

	
loop:	mov eax,dword[ebp-0x08]		; will change
	xor edx,edx
	mov ebx,10
	div ebx
	mov dword[ebp-0x08],eax
	mov dword[ebp-0x10],edx			;dword[ebp-0x8]  = quotient
						;dword[ebp-0x10] = remainder

	mov dword[ebp-0x00],0			;counter upto 3
	mov dword[ebp-0x04],1			;product

mult:	mov eax,dword[ebp-0x04]
	mul dword[ebp-0x10]	
	mov dword[ebp-0x04],eax
	
	inc dword[ebp-0x00]
	
	cmp dword[ebp-0x00],3
	jne mult
	mov eax,dword[ebp-0x0c]
	add eax,dword[ebp-0x04]		
	mov dword[ebp-0x0c],eax
	
	cmp dword[ebp-0x08],0
	jne loop

	mov eax,[x]
	cmp dword[ebp-0x0c],eax
	je yes
	push eax
	push result 
	call printf
	jmp exit

yes:	
	push dword[ebp-0x0c]
	push amstrong
	call printf

exit:	leave	
	ret
