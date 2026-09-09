# Tclock 

A fast and lightweight terminal clock written in C with an ncurses-based TUI, designed for efficiency and low resource usage.

![tclock](images/tclock.jpeg) 
![tclock with b and s options](images/tclock_b_s.jpeg) 

## Installation 

Clone the project from GitLab:
```bash
git clone https://gitlab.com/eliott.wnr/tclock.git
cd tclock
```

Or from GitHub:
```bash
git clone https://github.com/eliottwnr/Tclock.git
cd Tclock
```

### Method 1: Using Make (Universal)

Build and install to `/usr/local/bin`:
```bash
make
sudo make install
```

To uninstall:
```bash
sudo make uninstall
```

### Method 2: Using makepkg (Arch Linux)

Build and install package via `pacman`:
```bash
makepkg -si
```

To uninstall:
```bash
sudo pacman -R tclock
```


## Usage

Simply run `tclock` (or `./tclock`) with `s` option to display seconds and/or `b` to display bold numbers.
> To display both bold numbers and seconds: `tclock b s`


Run `tclock` with `o` option for one-shot mode, which displays the time directly in the console. 
> `o` option will ignore all others

**Hit `q` or `Q` to quit.**


### Chronometer

`tclock t` combined with `s` and/or `b` option runs tClock on chronometer mode. Hit the spacebar in order to start/stop the chronometer. 

