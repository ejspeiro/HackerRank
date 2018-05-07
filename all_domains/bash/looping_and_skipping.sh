#!/bin/bash

counter=1
while [ $counter -lt 100 ]
do
  let test=$counter%2
  if [ $test -gt 0 ]
  then
    echo $counter
  fi
  ((counter++))
done
