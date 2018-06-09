#!/bin/bash

read cc
if [ $cc == "Y" ] || [ $cc == "y" ]
then
  echo "YES"
else
  echo "NO"
fi
