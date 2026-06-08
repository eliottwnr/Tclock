# Tclock 

A fast and lightweight terminal clock written in C with an ncurses-based TUI, designed for efficiency and low resource usage.

![tclock](images/tclock.jpeg) 
![tclock with b and s options](images/tclock_b_s.jpeg) 

## Installation 

Clone the project from github 
```bash
git clone https://github.com/eliottwnr/Tclock.git
```

Or from gitlab
```bash
git clone https://gitlab.com/eliott.wnr/tclock.git
```

Go to the project's root and run `makepkg` 
```bash
cd tclock && makepkg -si
```

Everything in one command
```bash
git clone https://gitlab.com/eliott.wnr/tclock.git && cd tclock && makepkg -si
```


## Usage

Simply run `./tClock` with `s` option to display seconds and/or `b` to display bold numbers.
> To display both bold numbers and seconds: `./tClock b s`


Run `./tClock` with `o` option for one-shot mode, which displays the time directly in the console. 
> `o` option will ignore all others

**Hit `q` or `Q` to quit.**


### Chronometer

`./tClock t` combined with `s` and/or `b` option runs tClock on chronometer mode. Hit the spacebar in order to start/stop the chronometer. 


# Compiling from source

After cloning the repo (see [installation](#installation) section)

Use your favorite compiler (here cc):
```sh
cc src/main.c src/display.c src/timer.c -o tClock -lncurses
```
in the project's root directory.
