push  %ebp
mov   %esp,%ebp
xor   %eax,%eax
xor   %ebx,%ebx
xor   %ecx,%ecx
xor   %edx,%edx
movb  $16,%dl
push  $0x0a67726f
push  $0x2e6d726f
push  $0x74732d6e
push  $0x6e656873
movl  %esp,%ecx
movb  $0x1,%bl
movb  $0x4,%al
int   $0x80
leave
ret
