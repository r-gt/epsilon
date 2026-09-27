# EPSILON: BASIC SDL BASED TOOLKIT!
### WARNING: STILL UNDER DEVELOPMENT!
<br>

[please check the wiki](documents/index.md)

# QUICK START
<br>

## REQUIREMENTS

### Epsilon only needs:
**A working C compiler (GCC by default) and GNU make:**
- **Windows:** [MinGW](https://www.mingw-w64.org/) distrubutions offers pre-compiled GCC and Make binaries.
- **Linux:** Process might differ between distributions, generally, you just need to install  `gcc` and `make` from your package manager.

**Optionally:**
- **emsdk:** The [Emscripten SDK](https://emscripten.org/), only needed to compile Epsilon to a web based platform.
- **gcc-mingw-w64:** This special distribution of MinGW native for Linux, only needed to cross-compile your project from Linux to Windows. 

<br>




## 1. CLONE THE REPOSITORY
Download the .zip or .tar.gz archives or do a simple `git clone`

<br>



## 2. COMPILE
###### (I think Make on windows command was "mingw-w64-make" or just "make")

If everything was correctly installed, a simple Make command should result in a functional executable on the `bin/` folder:
~~~
make
~~~

If you want to quick test there's a command designed for that:
~~~
make test
~~~
<br>



### TARGETS
Targets are meant to make cross-compiling simpler and faster, runing make without any target with default to your OS.

To cross compile from Linux to Windows:
~~~
make TARGET=Windows
~~~

<br>

To compile for Web browsers:
~~~
make TARGET=Web
~~~
This will compile a web build into the bin-web folder (automatically creates that folder if it doesn't exist).
