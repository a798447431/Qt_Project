#! /bin/bash
chk_lock_test=$( ldd $1 | awk '{if (match($3,"/")){ print $3}}' )
cp -L -n $chk_lock_test $2
