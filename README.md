# My QMK Firmwares

This repo contains my QMK firmwares for my keyboards.

## Building and Flashing

1. Assure to add the udev rules for the keyboard. See [QMK Docs](https://docs.qmk.fm/#/faq_build?id=linux-udev-rules)
2. Install [Docker](https://docs.docker.com/get-docker/) or [Podman](https://podman.io/getting-started/installation)
3. Install [QMK](https://docs.qmk.fm/#/newbs_getting_started)
    - `yay -S qmk-lite`
4. Clone this repo
5. Run the `docker_run.sh` script to compile the firmware
6. Flash it using `qmk flash keychron_q4/target/keychron_q4_ansi_v1_mine.bin`

### Flashing using Docker

Theoretically it is possible to flash the firmware using Docker, but 99% of the time it fails with 
the following error:

```
Download        [===============          ]  63%        30720 bytesdfu-util: Error during special command "ERASE_PAGE" get_status
make[1]: *** [platforms/chibios/flash.mk:98: flash] Error 74
make[1]: Leaving directory '/qmk_firmware'
Make finished with errors
make: *** [Makefile:392: keychron/q4/ansi_v1:mine:flash] Error 1
```

## Formatting
- the `keymap.c` files are formatted using https://github.com/codethread/qmk.nvim
