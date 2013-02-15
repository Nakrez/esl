% 3.1 Integer
% Baptiste COVOLATO
% 11 Feb 2013

Boolean Operations
==================

ESL considers that every value different from 0 is `true`, else it is `false`.
Boolean operations always returns `false` or `true`, but you can also test those
results with 0 or 1.

These are the boolean operations available in ESL

Operation   Result                        Alias
---------- ----------------------------- --------
x `and` y  if x is false, then y, else x x `&&` y
x `or`  y  if x is false, then x, else y x `||` y
not (soon)                                  !x
---------- ----------------------------- --------
