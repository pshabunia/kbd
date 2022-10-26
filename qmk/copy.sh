#!/bin/bash
PS34=$( ~/Downloads | grep ps34 | grep json | sort | tail -n 1)
cp -f $PS34 ps34.json