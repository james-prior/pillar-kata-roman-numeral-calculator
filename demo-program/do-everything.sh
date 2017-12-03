#!/usr/bin/env sh

# Run this in the same directory that this file is in.
# Works for ubuntu 14.04.5.

# Unless given --no-test-loop option on command line,
# automatically (re)runs tests at end.

# The library must already be installed.

set -v

make
make check

src/computator I II III IV V VI -XX MMMCMXCVIII I
# The above command should show output like below
# I I
# II III
# III VI
# IV X
# V XV
# VI XXI
# -XX I
# MMMCMXCVIII MMMCMXCIX
# I ERRATUM

if [ x"$1" != x"--no-test-loop" ]; then
    # The following loop automatically (re)runs the tests
    # when any file changes in the src or tests directories.
    while inotifywait -r -e modify src tests; do
        make
        make check
    done
fi
