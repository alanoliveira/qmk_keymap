# My QMK Firmwares

This repo contains my QMK firmwares for my keyboards.

## Building and Flashing

1. Assure to add the udev rules for the keyboard. See [QMK Docs](https://docs.qmk.fm/#/faq_build?id=linux-udev-rules)
2. Install [Docker](https://docs.docker.com/get-docker/) or [Podman](https://podman.io/getting-started/installation)
3. Clone this repo
4. Run the `docker_run.sh` script to compile the firmware
5. Select the firmware you want to flash from the menu

### Flashing using Docker

Some keyboards have problems flashing using the container, for example the Keychron Q4:
```
Download        [===============          ]  63%        30720 bytesdfu-util: Error during special command "ERASE_PAGE" get_status
make[1]: *** [platforms/chibios/flash.mk:98: flash] Error 74
make[1]: Leaving directory '/qmk_firmware'
Make finished with errors
make: *** [Makefile:392: keychron/q4/ansi_v1:mine:flash] Error 1
```
On this case is better to flash outside the container:

1. Install [QMK](https://docs.qmk.fm/#/newbs_getting_started)
    - `yay -S qmk-lite`
2. Flash it using `qmk flash target/<keyboard_name>_mine.[hex|bin]`

## Formatting
- the `keymap.c` files are formatted using https://github.com/codethread/qmk.nvim

## Troubleshooting

### Waiting for /dev/ttyACM0 ....

Be sure to add the udev rules for the keyboard. See [qmk docs](https://github.com/qmk/qmk_firmware/blob/master/docs/faq_build.md#linux-udev-rules-idlinux-udev-rules).
Not sure if it's needed, but also install the `dfu-util` and `dfu-programmer` packages.
