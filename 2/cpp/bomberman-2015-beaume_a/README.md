# Bomberman

Bomberman is an Epitech project made by second year students.

## Compilation

The compilation is in release mode by default. The client and the server are both compilated in default target (`all`).

Release compilation (-Wall, -Wextra, -Werror):

    $ ./configure
    $ make

Development compilation (remove -Werror)

    $ ./configure --dev
    $ make

Debug compilation (remove -Werror, add -g3 and -DDEBUG_ENABLE, use GDL GL in debug mode)

    $ ./configure --debug
    $ make

## Dev Tips

Clean the project (except the binary files):

    $ ./configure --clean

Clean all the project:

    $ ./configure --fclean

## Try it!

    $ ./configure
    $ make
    $ ./Bomberman

    # Create the Makefile
    # Compile
    # Enjoy the game!

## Development

This project is hosted on [Github.com](https://github.com/abeaumet/Bomberman/). You can see who is contributing on this project in the AUTHORS file.
