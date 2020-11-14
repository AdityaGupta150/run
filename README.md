# Run

A simpler shorter way to `Compile & Run` a .cpp file

Very useful 'command line tool' specially for learners, doing many throwaway project or stuff

# Examples -

Instead of ->  and many a times, like or worse than 

So what this utility does is ->
* 1st case - 
```sh
# Instead of
g++ try.cpp && ./a.out

#use
run try.cpp
```

* 2nd case - 
```sh
# Instead of 
g++ try.cpp --std=c++20 -o try && ./try

# use
run try.cpp 20
```

* 3rd case - 
```sh
# Instead of 
g++ try.cpp --std=c++20 -o try && ./try adi

# use
run try.cpp 20 -- adi
```

The important plus point is, you can use auto-completetion for file names, so many a times you just need to just type `run a<tab>`

# Compile

```sh
g++ run.cpp -o run
```
Then add the `run` file to your /usr/bin (or add current path to PATH)
> On Windows -> Add the folder to your PATH

# Other Features -

This is the command format ->
```sh
run <filename> <compiler_args> <cpp_version> -- <program_args>
```
> Only the `filename` is mandatory

* `<filename>` -> File name, for eg. 'try.cpp'
* `<compiler_args>` -> Like ```-g -o try``` etc. \[Defaults - ''\]
* `<cpp_version>` -> Just a number, eg. 17 20 will be understood as --std=c++17 and --std=c++20 repectively  \[Default - 17\]
* `<program_args>` -> As per your program's needs

# Future Ideas ->

I may not be working on this **for now**, i have what i wanted ( this was not meant to spend an hour initially anyways :D )

> Add "run --help" support too, maybe use an arg parser

1. `run dbg try.cpp` -> Adds '-g' compiler flag, and executes `gdb` on compiled file
2. `run cleaner` -> For eg, a directory has `try.cpp` `delete.cpp` `a.cpp`, then it should delete `try` `delete` `a` (sometimes i need this) if present
3. `run` -> Should run the last command it ran (may need storing in an output file)
4. MSVC cl command support


If anymore queries feel free to open an issue, or dm me on twitter

Whatever doubt you have even if why `g++ main.cpp` doesn't work in multifile projects, you can contact directly :D