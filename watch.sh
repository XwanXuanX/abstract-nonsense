#!/bin/bash
# This file implements a simple terminal stop watch to track my time spend on a problem

time=""
# The stop watch function
function stopwatch() {
    local start=$(date +%s)
    while true; do
        time="$(( $(date +%s) - $start))"
        printf '%s\r' "$(date -u -jf %s "$time" +%H:%M:%S)"
        sleep 0.1
    done
}

# Handle Ctrl-C SIGINT signal from user
function sigint_handler() {
    echo # skip the line with ^C
    echo "Congrats! You finished the problem in: $(date -u -jf %s "$time" +%H:%M:%S)"
    exit 0
}

trap sigint_handler INT
stopwatch
