#!/bin/bash

res_pwd=$0

cd ${res_pwd}/..

echo "Compilando..."
make build > /dev/null 2>&1
echo "Compilación terminada"

r[0]=$(make one)
r[1]=$(make two)
r[2]=$(make three)
r[3]=$(make four)
r[4]=$(make five)
r[5]=$(make six)
r[6]=$(make seven)

succesfull="succesfully"
passed=0
total=7

for i in "${r[@]}"
do
    if [[ "$i" == *"$succesfull"* ]]
    then
      echo -e "Test ${i[0]} \033[0;32m passed \033[0m";
      let passed++
    else
      echo -e "Test ${i[0]} \033[0;31m fail \033[0m"
    fi
done

echo -e "\nPassed ${passed}/${total}"

make clean > /dev/null 2>&1


