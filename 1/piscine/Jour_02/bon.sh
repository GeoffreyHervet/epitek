cat /afs/epitech.net/users/all/astek/public/passwd | cut -d: -f5 | grep -iE ' bon$' | wc -l