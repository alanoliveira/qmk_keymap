#!/usr/bin/env bash

# Allow $RUNTIME to be overridden by the user as an environment variable
# Else check if either podman or docker exit and set them as runtime
# if none are found error out
if [ -z "$RUNTIME" ]; then
	if command -v podman >/dev/null 2>&1; then
		RUNTIME="podman"
	elif command -v docker >/dev/null 2>&1; then
		RUNTIME="docker"
	else
		echo "Error: no compatible container runtime found."
		echo "Either podman or docker are required."
		echo "See https://podman.io/getting-started/installation"
		echo "or https://docs.docker.com/install/#supported-platforms"
		echo "for installation instructions."
		exit 2
	fi
fi

$RUNTIME build -t qmk_firmware .

# IF we are using docker on non Linux and docker-machine isn't working print an error
# ELSE set usb_args
if [ ! "$(uname)" = "Linux" ] && [ "$RUNTIME" = "docker" ] && ! docker-machine active >/dev/null 2>&1; then
    errcho "Error: target requires docker-machine to work on your platform"
    errcho "See http://gw.tnode.com/docker/docker-machine-with-usb-support-on-windows-macos"
    exit 3
else
    usb_args="--privileged -v /dev:/dev"
fi

if [ "$RUNTIME" = "docker" ]; then
	uid_arg="--user $(id -u):$(id -g)"
fi

cmd="build"
if [ "$1" = "flash" ]; then
  cmd="flash"
fi

dir_src=$(pwd -W 2>/dev/null) || dir_src=$PWD  # Use Windows path if on Windows
dir_dst='/qmk_firmware/keyboards/keychron/q4/ansi_v1/keymaps/mine'

podman run --rm -it \
  $uid_arg \
  $usb_args \
	-v "$dir_src/keychron_q4":"$dir_dst" \
  -w "/qmk_firmware/" \
	qmk_firmware \
  make -e BUILD_DIR="$dir_dst/target/" "keychron/q4/ansi_v1:mine:$cmd"
