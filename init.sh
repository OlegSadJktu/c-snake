# name=${1%.c}
# gcc -Wall -g ./$1 -o ./build/$name.out $(ncursesw6-config --cflags --libs) -lm -lcursesw
gcc -Wall -g ./main.c -lm -lncursesw -o build/main.out
# ./build.sh $1
# shift
./build/main.out
