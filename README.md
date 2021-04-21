# vciph
## Origin
This repo holds a c rewrite of a cipher program that I wrote in high
school. My original code was not easy to follow or understandable for that
matter. I also am using this to learn more about how the command line
is parsed in C, as well as how to write to files.

Please don't use this for anything important. All it does is
encrypt said string with a vigerene cipher using a given keyword, and
optinally can reverse the word.

I'd like to make it use the message for encryption too.

Currently there are some bugs when trying to decrypt encrypted messages;
I get the wrong result it seems.

**NOTE**
One limitation of the program in it's current state is that it can only
encrypt messages that consist of solely capital letters. There is no
support for lowercase letters or any other character on the keyboard.

## todo
- update the command line parsing to handle spaces
- support reading in a message from standard in

## Dependencies
* make
* c99 compiler

To build, run `make`

## Usage: (I don't advise using this)

If you want to encrypt a message with a specfic key, run:
```
./ciph -kKEY -mYOURMESSAGE -e
```

If you want to decrypt a message that uses a specific key, run:
```
./ciph -kKEY -mENCMESSAGE -d
```

Optionally, you can include the `-oOUTFILE` to save the result into a file
because by default, it is printed to stdout.

**NOTE:** Right now decryption is in a half working state. Some keys it will work
while others don't. This is an issue I am working to solve.

If you want to reverse the message as well, you can add the `-r` flag, and it will
reverse the input string.
