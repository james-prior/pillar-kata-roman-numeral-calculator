#!/usr/bin/env sh

# Run this in the same directory that this file is in.
# Works for ubuntu 14.04.5.

# Unless given --no-test-loop option on command line,
# automatically (re)runs tests at end.

set -v

# prerequisites
sudo apt-get update
sudo add-apt-repository universe
sudo apt-get update
sudo apt-get -y install autoconf
sudo apt-get -y install check
sudo apt-get -y install libtool libtool-doc
sudo apt-get -y install inotify-tools
# following line works for Ubuntu 16.04 instead of line above
# sudo apt-get -y install libtool libtool-bin libtool-doc

autoreconf --install
cp -pi build-aux/install-sh .
./configure
make
make check
sudo make install
sudo ldconfig
sudo cp src/roman.h /usr/local/include/

if [ x"$1" != x"--no-test-loop" ]; then
    # The following loop automatically (re)runs the tests
    # when any file changes in the src or tests directories.
    while inotifywait -r -e modify src tests; do
        make
        make check
        cat tests/test-suite.log
    done
fi
