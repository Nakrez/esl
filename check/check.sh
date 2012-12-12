#! /bin/bash

echo "Starting tests"

./check/print/print_check.sh
./check/arith/arith_check.sh
./check/control/control_check.sh
./check/loops/loops_check.sh
./check/mix/mix_check.sh
