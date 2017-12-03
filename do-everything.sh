#!/usr/bin/env sh

set -v

cd library
./do-everything.sh --no-test-loop
cd -

cd demo-program
./do-everything.sh --no-test-loop
cd -
