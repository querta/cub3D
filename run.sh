#!/bin/bash

# make re > /dev/null
make re
# printf "\e[32myour program output: \e[0m\n"
# if $1
# then
printf "\e[1;32mprogram output: \e[0m\n"
	# @printf "\e[1;36mLib \e[1;32m'libmlx.dylib' \e[1;36mcreated\e[0m\n"
./cub3D map$1.cub
# else
# gcc test.c libftprintf.a && ./a.out
# fi