name=${1%.c}
gcc -Wall -g ./$1 -o ./build/$name.out $(ncursesw6-config --cflags --libs) -lm -lcursesw
# ./build.sh $1
shift
./build/$name.out $@
