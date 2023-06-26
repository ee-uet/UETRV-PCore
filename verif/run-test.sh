# !bin/bash

set -e
error=0

riscof -v debug run --config=config.ini \
           --suite=riscv-arch-test/riscv-test-suite/ \
           --env=riscv-arch-test/riscv-test-suite/env \
           --no-browser

if grep -rniq riscof_work/report.html -e '>0failed<'
then
    echo "Test successful!"
    exit 0
else
    echo "Test FAILED!"
    exit 1
fi
