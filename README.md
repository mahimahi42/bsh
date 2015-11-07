BSH
===

BSH is a toy shell written in C. It is mostly based off of the excellent tutorial by [Stephen Brennan](http://stephen-brennan.com/), the code for which can be found at [his GitHub](https://github.com/brenns10/lsh). BSH is mostly for me to try out new things in C and GNU tools, so don't expect a POSIX-compliant shell anytime soon.

#### Dependencies

```bash
libc
gcc
make
doxygen # (for documentation)
vagrant # (for easy development)
```

#### Running bsh

```bash
git clone https://github.com/mahimahi42/bsh.git
cd bsh
make
make doc # Optional
bin/bsh
```
