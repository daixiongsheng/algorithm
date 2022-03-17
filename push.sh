#! /bin/bash
git config user.email daixiongsheng@gmail.com
git add .
date=$(date "+%Y-%m-%d-%H:%M:%S")
git commit -m "$date $1"
git pull origin master
git push origin master
