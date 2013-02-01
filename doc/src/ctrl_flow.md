% 2. Control Flow
% Baptiste Covolato
% February 1, 2013

2.1 `if` Statements
===================

Maybe the most known statement in programming langage. Let see an exemple of it in ESL:

    var = Io.input_readline()->to_int()
    if var < 0 then
        Io.print_newline("Input is negative")
    elif var == 0 then
        Io.print_newline("Input is null")
    else
        Io.print_newline("Input is positive")
    end

You can have 0 or more `elif` part, `else` part is optional. The keyword `elif` is short for 'else if'.

2.2 `while` Statements
======================

This statement is also a well known statement, that allows you to perform a loop while the condition is true.
Lets consider this example :

    i = 0
    while i < 10 do
        Io.print_newline(i)
        i = i + 1
    end

This little example will print all numbers between 0 and 9 (included) on a new line.
So, while the condition between the keyword `while` and `do` is true, the code between the keyword `do` and `end` will be executed.

2.3 `until` Statements
======================

This statement is like the `while` statement except that the loop runs until the condition is true.
This exemple below is the same as the one in the `while` statement but with an `until` statement.

    i = 0
    until i == 10 do
        Io.print_newline(i)
        i = i + 1
    end

2.4 Functions
=============

Declaration
-----------

We create a function that print the n first integer :

    function print_int (n)
        i = 0
        while i <= n do
            Io.print_newline(i)
            i = i + 1
        end
    end

The keyword `function` introduces a function declaration. Then, you have to name your function.
You must specify the parameters list between paranthesis (If no parameters let it empty). The
body of the function is between the argument list and the keyword `end` that indicate the end
of the declared function.

ESL also supports recursive function. This is a little example of a function
that calculates x power n.

    function power (x, n)
        if n <= 0 then
            return 1
        end
        return x * power (x, n - 1)
    end

After the declaration of a function you are able to use it from anywhere. Even from
a function that you declared above.

As you may noticed : the `return` statement returns a value from a function. If
no value is precised, then the function returns 0.

Usage
-----

The execution of a function introduce a temporary symbol table that is used inside the
function only. So that, all variables declared in the function body will not affect
the main execution state.

In ESL, all functions return a value, even if there is no `return` statement reached
during the execution of the function. In fact, these functions return 0.

To call a function, you just have to indicate the name of the function, and
it arguments, as shown in the following example

    power(4, 5) # return 4 power 5
    print_int(power(2,3)) # print the 2 power 3 (8) first integer
