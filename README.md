Informatics IIb - Assignment 5
==============================

> This is the public repo for the assignment 5 at Informatics IIb as a reference.

It's just the same blahblah as ever.


Use
---

* As a starting point you should clone this repository on its initial state through:

  ```shell
  > git clone git://github.com/rkoch/uzh-inf02b-a5.git
  > cd uzh-inf02b-a5
  > git checkout initial
  ```

  or by downloading a tarball of the initial project setup:

  [Download Tarball of Tag `initial`](https://github.com/rkoch/uzh-inf02b-a5/archive/initial.zip)

  of course you can create your own fork ;-)
* On the master branch you will usually find my finished code to take a look at if you're stuck. But please (for your own sake), do try those assignments by yourself and don't just copy my solutions.
* After cloning/downloading this repository you can import the project located in the subfolders `Task_B` to `Task_D` into Eclipse CDT via `File -> Import -> Existing Projects into Workspace`


Use under Windows
--------------

As I work on a Mac the default Tool Chain in the provided eclipse projects is `MacOSX GCC`. If you work under Windows I recommend installing the [MinGW compiler](http://www.mingw.org/) (Remember to add `<mingw-path>/bin` to your PATH). To build and run those projects you need to change the default Tool Chain for both `Debug` and `Release` configurations.

This can be done in the project settings of each project:
* Right-click on the project root
* `Properties` -> `C/C++ Build` -> `Tool Chain Editor` -> `Current toolchain` -> `MinGW GCC` (Do that in all build configurations)

__Notice:__ If Eclipse still marks your code as invalid you may need to rebuild your index (the path, eclipse gets its libraries from) after changing the toolchain. This can be done with the following actions: `Right-click on the project root` -> `Index` -> `Rebuild`. After that you may need to restart eclipse in order to get everything work correctly again.

__Second notice:__ I just found that sometimes after importing a project, Eclipse loses it's dependencies to the std lib. This issue can be resolved by enabling the checkbox `Enable language settings providers for this project` under the project settings (`Right-click on the project root` -> `Properties`) in the location `C/C++ General` -> `Preprocessor Include Paths, Macros, etc.` -> `Providers`
Don't forget to rebuild your index afterwards.

__Another notice:__ Sometimes Eclipse fails to rebuild your index after changing the Language Providers. If this is the case, just restart Eclipse and rebuild the index. This may also happen on Mac OS X.

The same steps can be applied to Linux/Ubuntu but the names will probably be different. If someone can provide me with a working configuration, I'd be happy to publish it here.


Repo Structure
--------------

* Each assignment task is in its own subfolder from (`Task_A` to `Task_D`)
* In each task folder you will find all relevant eclipse project settings and a makefile in order to build this task. Of course the source code is located in the sub-folder `src/`.
* ~~I usually do not provide the original source code in the initial commit and initial tag (`initial`) so you have to copy-paste the provided sources for each task by yourself.~~ Screw it. Just checkout the `initial` tag and start hacking with the provided source files.


Disclaimer
----------

I do not guarantee that the solutions provided in this repository are the correct ones. So do not sue me if I make mistakes. Better send me a pull request to fix the broken stuff.


License
-------

hahahaha. [WTFPL](http://www.wtfpl.net/) or whatever you wish.


tl;dr
-----

Blahblah and RTFMD.

