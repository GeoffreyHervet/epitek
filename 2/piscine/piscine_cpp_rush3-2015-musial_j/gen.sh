#!/bin/zsh

qmake-qt4 -project **/*.cpp -Wall && qmake-qt4

sed -e 's/\(^LIBS.\+\)/\1 -lncurses/' -i Makefile
sed -e 's/^MKDIR.\+/&\n\nifeq ($(debug),1)\nCXXFLAGS	+=	-g3\nelse\nCXXFLAGS	+=	-Werror\nendif\n\nifeq ($(trace),1)\nCXXFLAGS	+=	-D TRACE\nendif\n/' -i Makefile

echo >> Makefile
echo -e "fclean: clean\n\t\$(DEL_FILE) \$(TARGET)\n" >> Makefile
echo >> Makefile
echo -e "re: fclean  \$(TARGET)\n" >> Makefile

echo "Makefile generated!"

exit 0
