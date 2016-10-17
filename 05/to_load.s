.text
.globl _start
_start:
	# make the syscall funny
	movq $1, %rdi
	movq $2, %rsi
	movq $3, %rdx
	movq $4, %r10
	movq $5, %r8
	movq $6, %r9
loop:
	movq X(%rip), %rax
	syscall
	addq $1, X(%rip)
	jmp loop

.data
.align 8
X:
	.quad 10000
