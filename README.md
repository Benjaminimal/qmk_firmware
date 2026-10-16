# Personal Corne QMK configuration

Build and flash the `benjaminimal` keymap from this fork on Fedora KDE. The keymap
lives in [`keyboards/crkbd/keymaps/benjaminimal/`](keyboards/crkbd/keymaps/benjaminimal/).

These instructions assume a Corne rev1 with ATmega32U4 / Pro Micro-compatible
controllers. If you installed RP2040 or other replacement controllers, adjust the
build target before compiling or flashing.

## First-time setup

### 1. Install uv, the compiler, and flashing tools

```sh
sudo dnf install git python3 uv make \
    avr-binutils avr-gcc avr-gcc-c++ avr-libc avrdude \
    diffutils unzip zip
```

This installs the AVR tools for this keyboard, not the toolchains for every
keyboard supported by QMK.

### 2. Open this repository and initialize submodules

Use the existing checkout rather than cloning another copy:

```sh
cd ~/path/to/qmk_firmware
git submodule update --init --recursive
```

### 3. Install QMK with uv

Create an isolated Python environment outside the repository, activate it, and
install the QMK CLI and this fork's Python dependencies:

```sh
uv venv ~/.local/share/venvs/qmk
source ~/.local/share/venvs/qmk/bin/activate
uv pip install qmk -r requirements.txt
```

Tell QMK to use the current checkout:

```sh
qmk config user.qmk_home="$PWD"
```

### 4. Allow flashing without sudo

From the repository directory, install QMK's USB permission rules:

```sh
sudo cp util/udev/50-qmk.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

Unplug and reconnect the keyboard afterward. Do not run `qmk flash` with `sudo`.

### 5. Check the environment

```sh
qmk doctor
```

Resolve errors about AVR tools, Python dependencies, or missing submodules before continuing.

## Compile the firmware

From the repository directory, with the QMK environment activated:

```sh
qmk compile -kb crkbd/rev1 -km benjaminimal
```

Wait for successful completion, including the firmware-size check. Do not flash if
compilation fails.

## Flash both halves

**Disconnect USB before inserting or removing the cable between the halves.
Never connect or disconnect a TRRS interconnect while either half has USB power.**

For each half:

1. With USB disconnected, disconnect the interconnect cable.
2. Connect that half directly to the computer with a data-capable USB cable.
3. Run:

    ```sh
    qmk flash -kb crkbd/rev1 -km benjaminimal
    ```

4. When QMK waits for the bootloader, press that half's physical reset button.
   Depending on the bootloader, you may need two quick presses.
5. Wait until flashing finishes successfully and the keyboard restarts.
6. Disconnect USB, then repeat for the other half.

Keep both halves on matching firmware. With both halves unpowered, reconnect the
interconnect cable, then connect USB normally.

`qmk flash` builds the firmware automatically before flashing. The separate
`qmk compile` step is useful for checking the build but is not required for every
update.

## Check German character input

On Fedora, select the standard **English (UK)** layout. On the symbol layer, try
the four configured character keys:

- Without Shift: `ä ö ü ß`
- With Shift: `Ä Ö Ü ß`

The firmware selects native input sequences based on the detected OS. It expects
standard UK layouts on Linux and Windows, or the British input source on macOS.
Windows Alt codes also depend on the Windows-1252 ANSI code page and application
support. OS detection is heuristic; character output needs verification on each
computer. If detection is unknown, these keys emit nothing.

## Later updates

Activate the environment, open the repository, and flash each half using the
procedure above:

```sh
source ~/.local/share/venvs/qmk/bin/activate
cd ~/Projects/personal/qmk_firmware
qmk flash -kb crkbd/rev1 -km benjaminimal
```

## References

- [QMK environment setup](docs/newbs_getting_started.md)
- [Fedora toolchain installer](util/install/fedora.sh)
- [uv environments](https://docs.astral.sh/uv/pip/environments/)
- [uv package installation](https://docs.astral.sh/uv/pip/packages/)
