gcc -Wall -g new_sn/*.c -o ./build/new_snake.out -lm -lcursesw
# # shift
./build/new_snake.out 
exit 0
cmake -B build
echo \n\n\n
make -C build
build/new_snake.out
