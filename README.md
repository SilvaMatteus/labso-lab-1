# Xeu

Software to practice operating systems concepts, the Xeu is a command interpreter
developed by @silvamatteus and @ffosilva.
_Note: the initial command parser code was written by @thiagomanel._

## Features

The following features are implemented by Xeu:

- Navigations between directories;
- Pipes;
- Running programs installed on the machine;
- Redirect out(">");

## How to build and run the code

Run the following commands:

```bash
make # builds the binary
./xeu # runs the binary
```

Using debug mode:

```bash
CXXFLAGS="-DDEBUG" make # builds the binary with debug mode enabled
```
