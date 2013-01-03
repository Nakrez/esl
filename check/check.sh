#! /bin/bash

echo "Starting tests"

./check/io/io_check.sh
./check/arith/arith_check.sh
./check/bool/bool_check.sh
./check/strings/strings_check.sh
./check/control/control_check.sh
./check/loops/loops_check.sh
./check/functions/functions_check.sh
./check/array/array_check.sh
./check/comment/comment_check.sh
./check/mix/mix_check.sh
