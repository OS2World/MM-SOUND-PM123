;  1 "synth_sse_float.S"
;  1 "<built-in>"
;  1 "<command line>"
;  1 "synth_sse_float.S"
;  9 "synth_sse_float.S"
;  1 "mangle.h" 1
;  13 "mangle.h"
;  1 "config.h" 1
;  14 "mangle.h" 2
;  1 "intsym.h" 1
;  15 "mangle.h" 2
;  10 "synth_sse_float.S" 2
;  26 "synth_sse_float.S"
section .data

align 32
_scale_sse:
 dd 939524096
 dd 939524096
 dd 939524096
 dd 939524096
section .text
align 16
global	_INT123_synth_1to1_real_sse_asm
_INT123_synth_1to1_real_sse_asm:
	push	dword ebp
	mov	dword ebp, esp
	push	dword ebx
	push	dword esi

	mov	dword ebx, [ebp+8]
	mov	dword edx, [ebp+12]
	mov	dword esi, [ebp+16]
	mov	dword eax, [ebp+20]
	shl	dword eax, 2

	lea	dword ebx, [ebx+64]
	sub	dword ebx, eax

	mov	dword ecx, 4

align 4
Loop_start_1:
	movups	xmm0, [ebx]
	movups	xmm1, [ebx+16]
	movups	xmm2, [ebx+32]
	movups	xmm3, [ebx+48]
	movups	xmm4, [ebx+128]
	movups	xmm5, [ebx+144]
	movups	xmm6, [ebx+160]
	movups	xmm7, [ebx+176]
	mulps	xmm0, [edx+0]
	mulps	xmm1, [edx+16]
	mulps	xmm2, [edx+32]
	mulps	xmm3, [edx+48]
	mulps	xmm4, [edx+64]
	mulps	xmm5, [edx+80]
	mulps	xmm6, [edx+96]
	mulps	xmm7, [edx+112]
	addps	xmm0, xmm1
	addps	xmm2, xmm3
	addps	xmm4, xmm5
	addps	xmm6, xmm7
	addps	xmm0, xmm2
	addps	xmm4, xmm6
	movaps	xmm5, xmm4
	movaps	xmm4, xmm0

	lea	dword ebx, [ebx+256]
	lea	dword edx, [edx+128]

	movups	xmm0, [ebx]
	movups	xmm1, [ebx+16]
	movups	xmm2, [ebx+32]
	movups	xmm3, [ebx+48]
	movups	xmm6, [ebx+128]
	movups	xmm7, [ebx+144]
	mulps	xmm0, [edx]
	mulps	xmm1, [edx+16]
	mulps	xmm2, [edx+32]
	mulps	xmm3, [edx+48]
	mulps	xmm6, [edx+64]
	mulps	xmm7, [edx+80]
	addps	xmm0, xmm1
	addps	xmm2, xmm3
	addps	xmm6, xmm7
	movups	xmm1, [ebx+160]
	movups	xmm3, [ebx+176]
	mulps	xmm1, [edx+96]
	mulps	xmm3, [edx+112]
	addps	xmm0, xmm2
	addps	xmm1, xmm3
	addps	xmm6, xmm1
	movaps	xmm7, xmm6
	movaps	xmm6, xmm0

	lea	dword ebx, [ebx+256]
	lea	dword edx, [edx+128]

	movaps	xmm0, xmm4
	movaps	xmm1, xmm6
	unpcklps	xmm4, xmm5
	unpcklps	xmm6, xmm7
	unpckhps	xmm0, xmm5
	unpckhps	xmm1, xmm7
	movaps	xmm2, xmm4
	movaps	xmm3, xmm0
	movlhps	xmm4, xmm6
	movhlps	xmm6, xmm2
	movlhps	xmm0, xmm1
	movhlps	xmm1, xmm3
	subps	xmm4, xmm6
	subps	xmm0, xmm1
	addps	xmm0, xmm4

	movups	xmm1, [esi]
	movups	xmm2, [esi+16]
	mulps	xmm0, [_scale_sse]
	shufps	xmm1, xmm2, 0xdd
	movaps	xmm2, xmm0
	unpcklps	xmm0, xmm1
	unpckhps	xmm2, xmm1
	movups	[esi], xmm0
	movups	[esi+16], xmm2

	lea	dword esi, [esi+32]
	dec	dword ecx
	jnz	Loop_start_1

	mov	dword ecx, 4

align 4
Loop_start_2:
	movups	xmm0, [ebx]
	movups	xmm1, [ebx+16]
	movups	xmm2, [ebx+32]
	movups	xmm3, [ebx+48]
	movups	xmm4, [ebx+128]
	movups	xmm5, [ebx+144]
	movups	xmm6, [ebx+160]
	movups	xmm7, [ebx+176]
	mulps	xmm0, [edx+0]
	mulps	xmm1, [edx+16]
	mulps	xmm2, [edx+32]
	mulps	xmm3, [edx+48]
	mulps	xmm4, [edx+-64]
	mulps	xmm5, [edx+-48]
	mulps	xmm6, [edx+-32]
	mulps	xmm7, [edx+-16]
	addps	xmm0, xmm1
	addps	xmm2, xmm3
	addps	xmm4, xmm5
	addps	xmm6, xmm7
	addps	xmm0, xmm2
	addps	xmm4, xmm6
	movaps	xmm5, xmm4
	movaps	xmm4, xmm0

	lea	dword ebx, [ebx+256]
	lea	dword edx, [edx+-128]

	movups	xmm0, [ebx]
	movups	xmm1, [ebx+16]
	movups	xmm2, [ebx+32]
	movups	xmm3, [ebx+48]
	movups	xmm6, [ebx+128]
	movups	xmm7, [ebx+144]
	mulps	xmm0, [edx]
	mulps	xmm1, [edx+16]
	mulps	xmm2, [edx+32]
	mulps	xmm3, [edx+48]
	mulps	xmm6, [edx+-64]
	mulps	xmm7, [edx+-48]
	addps	xmm0, xmm1
	addps	xmm2, xmm3
	addps	xmm6, xmm7
	movups	xmm1, [ebx+160]
	movups	xmm3, [ebx+176]
	mulps	xmm1, [edx+-32]
	mulps	xmm3, [edx+-16]
	addps	xmm0, xmm2
	addps	xmm1, xmm3
	addps	xmm6, xmm1
	movaps	xmm7, xmm6
	movaps	xmm6, xmm0

	lea	dword ebx, [ebx+256]
	lea	dword edx, [edx+-128]

	movaps	xmm0, xmm4
	movaps	xmm1, xmm6
	unpcklps	xmm4, xmm5
	unpcklps	xmm6, xmm7
	unpckhps	xmm0, xmm5
	unpckhps	xmm1, xmm7
	movaps	xmm2, xmm4
	movaps	xmm3, xmm0
	movlhps	xmm4, xmm6
	movhlps	xmm6, xmm2
	movlhps	xmm0, xmm1
	movhlps	xmm1, xmm3
	addps	xmm4, xmm6
	addps	xmm0, xmm1
	addps	xmm0, xmm4

	movups	xmm1, [esi]
	movups	xmm2, [esi+16]
	mulps	xmm0, [_scale_sse]
	shufps	xmm1, xmm2, 0xdd
	movaps	xmm2, xmm0
	unpcklps	xmm0, xmm1
	unpckhps	xmm2, xmm1
	movups	[esi], xmm0
	movups	[esi+16], xmm2

	lea	dword esi, [esi+32]
	dec	dword ecx
	jnz	Loop_start_2

	xor	dword eax, eax

	pop	dword esi
	pop	dword ebx
	mov	dword esp, ebp
	pop	dword ebp

        ret


