	; Fibonacci Series : 0 1 1 2 3 5 8 13 ....

	extern scanf
	extern printf
section .data
	input: db "enter a number : ",10,0
	int : db "%d",0
	out : db "%d",10,0
	output : db "%dth number in fibonacci is : %d",10,0
	
section .text
	global  main
main:
	push ebp
	mov ebp,esp

	push input
	call printf

	lea eax,[ebp-0x4]		; to take input from user
	push eax	
	push int
	call scanf

	mov dword[ebp-0xc],0x0		; taken as i
	mov dword[ebp-0x8],0x1		; taken as j
	mov dword[ebp-0x10],0x3		; counter is initialized
	
	cmp dword[ebp-0x4],0x1		
	jg loop		
	mov dword[ebp-0x8],0x0		; for 1st term
	jmp exit

loop:
	mov eax,dword[ebp-0x8]		
	mov dword[ebp-0x14],eax		; [ebp-0x14] is taken as temp variable >> temp = j
	mov ebx,dword[ebp-0xc]		; ebx = i
	add dword[ebp-0x8],ebx		; j += ebx i.e j = j + i
	mov eax,dword[ebp-0x14]		
	mov dword[ebp-0xc],eax		; i = temp

	add dword[ebp-0x10],0x1		; counter is incremented
	mov eax,dword[ebp-0x4]
	cmp dword[ebp-0x10],eax		
	jle loop
			
exit:	push dword[ebp-0x8]		; [ebp-0x8] contains the nth term of fibonacci series
	push dword[ebp-0x4]		; value of 'n'
	push output
	call printf
	leave
	ret
