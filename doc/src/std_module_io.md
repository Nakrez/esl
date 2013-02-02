% Input/Output interactions
% Baptiste Covolato
% February 1, 2013

Introduction
============

IO module allows you to interact with the user. With it, you can read from the
standard input and write on the standard/erreur output.
The module also introduce a type named File, that allows you to read/write in
a file.
To use this module you must add it in your programm. To do so, you have to add
this line at the beggining of your script

    import "io"

Use Standard IO
===============

`Io.print(...)`
:   Print everything passed as parameters on the standard input.

`Io.print_newline(...)`
:   Print everything passed as parameters on the standard input and insert a
    new line after them.


Interaction with files
=======================

First of all to use a file you must first instanciate a File object that will
represent your file :

    var = new file()

Now, you are able to use every File related method.

file->`open(name, [mode])`
:   Open a file named `name`. You can also specified a mode. The available
    mode are:

    - `r` : open the file in read mode
    - `w` : open the file in write mode
    - `a` : append the file
    - `b` : open the file in binary mode

    You can combine mode (for exemple : `wab`).
    This function return 1 if the operation is a success, 0 else.
    If no `mode` is sepcified to the function then the file is open with 
    `mode = r`.

file->`is_open()`
:   Test if the file is open. Return 1 if the file is open successfully, 0 else.

file->`read_all()`
:   Read the all content of a file and returns it. The file MUST be open with
    `read` mode

file->`read_line()`
:   

file->`write(val)`
:   

file->`write_newline(val)`
:   

file->`close()`
:   Close an open file.

A little example that prints the content of a file:

    import "io"
    my_file = new file()
    my_file->open("test.esl")
    if my_file->is_open() then
        content = my_file->read_all();
        Io.print_newline(content)
        my_file->close()
    else
        Io.print_newline("Error while opening file.")
    end
