#!/bin/bash

find . -type f -print0 | xargs -0 sed -i 's/'$1'/'$2'/g'
shopt -s globstar
rename 's/'$1'/'$2'/' **
