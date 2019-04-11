#!/bin/bash

  ./p6 &

echo "pid of last process is " $!
for (( i = 0; i < 2; i++ )); do
  sleep 5s
  echo "kill -SIGUSR1 $!"
done
