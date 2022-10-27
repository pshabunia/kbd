#!/bin/bash
PS34=$(find ~/Downloads -type f -print | grep ps34 | grep json | sort | tail -n 1)
cp -f $PS34 ps34.json

# fix QK_BOOT
sed -i '' -e 's/QK_BOOT/RESET/g' ps34.json
