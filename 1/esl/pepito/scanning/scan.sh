while read login
do
	ip=`./ns_who -nh $login | sed -nre 's/^.* (([0-9]{1,3}\.){3}[0-9]{1,3}).*$/\1/p'`
	if [ -n "$ip" ] ;then
		nmap=`nmap $ip -p 31337 | grep open`
		if [ -n "$nmap" ] ;then
			printf "%-20s%-24s`date`\n" "$login" "$ip"
		fi
	fi
done
