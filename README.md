# pipex

## Final grade 115/100
  
## Description
  Solo – about 70 hours

This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

## Table of Contents

- [Installation](#installation)
- [Mandatory](#Mandatory)
- [Bonus](#Bonus)

## Installation

Clone this repository using the following command.

    git clone https://github.com/andonimarz/pipex.git

## Mandatory

Your program will be executed as follows:

    ./pipex file1 cmd1 cmd2 file2

It must take 4 arguments:

- file1 and file2 are file names.

- cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:

    $> < file1 cmd1 | cmd2 > file2

## Bonus

You will get extra points if you:

- Handle multiple pipes.

This:

    $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Should behave like:

    < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

- Support « and » when the first parameter is "here_doc".

This:

    $> ./pipex here_doc LIMITER cmd cmd1 file

Should behave like:

    cmd << LIMITER | cmd1 >> file
    
