#!/bin/sh 

find . -type f -print0 | xargs -0 sed -i 's/'$1'/'$2'/g'
mv $1.cbp $2.cbp
mv $1.workspace $2.workspace
