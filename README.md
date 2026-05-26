# EPSILON: BASIC SDL BASED FUNCTIONS!
### ⚠️WARNING: STILL UNDER DEVELOPMENT!
###### AND VERY UNDOCUMENTED AT THE MOMENT  
<br>

[please check the wiki](documents/index.md)

# QUICK START

If you already have all requierements, try building it.

<br>

### 1. CLONE THE REPOSITORY
Download the .zip or .tar.gz file or do a simple `git clone`

<br>

### 2. INSTALL A COMPILER

#### Windows:
You need [MinGW](https://www.mingw-w64.org/) to build anything, specially GCC and Make.

### linux:
You need to download `GCC` and `Make` on your system.

<br>

### 3. COMPILE
###### (i think Make on windows command was "mingw-w64-make")

If everything was correctly installed, a simple Make command should result in a functional executable on the bin/ folder:
~~~
make
~~~

If you want to quick test there's a command designed for that:
~~~
make test
~~~


#### TARGETS
Targets are meant to make cross-compiling simpler and faster, runing make without any target with default to your OS.


you can compile to windows from linux by setting `TARGET=Windows` ,you need the g++-mingw-w64 compiler:
~~~
make TARGET=Windows
~~~

<br>

you can also compile to web assembly, you need [Emscripten](https://emscripten.org/) on your system, specifically the **emsdk**:
~~~
make TARGET=Web
~~~
this will compile a web build into the bin-web folder (also creates that folder if it doesn't exist), remember that web assembly games requieres a host (local or not) to work.


###### A refferences list will be added soon.
