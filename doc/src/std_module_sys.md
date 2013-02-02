% Operating System interactions
% Baptiste Covolato
% February 1, 2013

Introduction
============

Sys module allows you to interact with your operating system and performs some
operations such as : rename files, execute a process, get environnement
variables, ...
To use this module you must add it in your programm. To do so, you have to add
this line at the beggining of your script

    import "sys"

Process parameters
==================

`Sys.getcwd()`

`Sys.chdir(path)`

`Sys.getenv(var)`

`Sys.setenv(var, value)`

Process management
==================

`Sys.exit(code)`

`Sys.fork()`

`Sys.vfork()`

Files and directories
===========

This part will introduce all functions related to files and directories interation.

`Sys.rename(old, new)`
:   This function allows you to rename a file/directory.
    If the path of `old` and `new` are not located in the same directory then
    a call to `Sys.rename` will move the `old` file/directory. It return 1 if it
    sucessfully renamed the file/directory, 0 else.

`Sys.remove(name, [force])`
:   This function allows you to delete a file or an empty directory named `name`.
    If a directory is not empty and you want to delete it, you MUST set force to 1,
    for all other operation, do not precise force, or set it to 0. It return 1
    if it sucessfully delete the file/directory, 0 else.
