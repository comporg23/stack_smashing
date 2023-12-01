when you call a function with "call" (in assembly), the return address gets pushed to stack.
return address is the address of the next instruction in memory.
so when you enter the function, the top of the stack contains that return address.

then, however, different things happen.

see [here](https://github.com/comporg23/BBS/blob/main/notes/functions/notes)

and [here](https://github.com/comporg23/BBS/blob/main/notes/functions/notes64)

(let me say it now, but you'll understand why i say it later: you can notice that in principle you could get the address of return address by using the passed to the function arguments, they could be also in the stack in case of x86 architecture)


if you compile this program now by typing "make", and execute it

```
./test
```

it will print

```
1
```

because the function named "function" returns to the point in memory
where the hexadecimal instructions for  "x = 1" reside.

change the function "function" in a way
that the return address of the function contains address of "printf",
instead of the address of "x = 1" which it contains.
(c allows such nasty things)
(i know you may not know c well, that is not necessary, just tinker. also i already wrote those parts that sort of require sort of knowledge of c.)

then by compiling and running the program you would get

```
0
```

and therefore the task will be completed.

tips:
* type `make` and disassemble the program.

```
  objdump -D test | less
```

there are several ways of solving this.
during the class i used the ret variable. so in principle you don't need to introduce a new variable.

however it might be very useful to introduce a new variable. not sure.

* you may want to look at your stack.
when you'll do gdb test, then set the breakpoint `break function` then do `run`, then do `n` or `si`, you can also dump the stack.

(* at this point you should know how to use gdb, but if you don't feel comfortable there are lots of manuals on the net. yeah, i know, hard to understand. that's our craft folks, nobody promised that it will be easy.  also it only feels "hard" first couple of times. then you get used to it. *)

take a look at this: https://jvns.ca/blog/2021/05/17/how-to-look-at-the-stack-in-gdb/

have fun.

p. s. i understand that you may feel that's too much for you. but that isn't. it only feels too much for some time. you can even solve this by brute forcing, in worst case scenario. բայց պէտք չի։

p. p. s.

we have that -fno-stack-protector in the makefile.
why?
we learned about canary protection. or check it out on the net.

