# EPSILON: BASIC SDL BASED FUNCTIONS!
### ⚠️WARNING: STILL UNDER DEVELOPMENT!
###### AND VERY UNDOCUMENTED AT THE MOMENT  
<br>

# QUICK START

If you already have all requierements, try building it.



### 1. CLONE THE REPOSITORY
Download the .zip or .tar.gz file or do a simple `git clone`



### 2. INSTALL DEPENDENCIES (Linux only)
Requiered dependencies are:  

Debian based distributions (officially supported): 
~~~
libsdl3-dev libsdl3-image-dev libsdl3-mixer-dev libsdl3-ttf-dev
~~~
RHEL based distributions:
~~~
SDL3-devel SDL3_image-devel SDL3_mixer-devel ttf-devel
~~~

Arch based distributions:
~~~
sdl3 sdl3_image sdl3_mixer sdl3_ttf
~~~
###### It probably works on other distributions too.



### 3. INSTALL A COMPILER

#### Windows:
You need [MinGW](https://www.mingw-w64.org/) to build anything, specially GCC and Make.

### linux:
You need to download `GCC` and `Make` on your system.



### 4. COMPILE
###### (i think Make on windows command was "mingw-w64-make")

If everything was correctly installed, a simple Make command should result in a functional executable on the bin/ folder:
~~~
make
~~~

If you want to quick test there's a command designed for that:
~~~
make test
~~~

###### A refferences list will be added soon,
