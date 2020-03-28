#!/bin/sh
./autogen.sh && ./configure && make -j4 && src/main
