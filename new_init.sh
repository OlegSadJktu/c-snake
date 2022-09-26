# gcc -Wall -g new_sn/*.c -o ./build/new_snake.out -lm -lcursesw
# # shift
# ./build/new_snake.out 
# exit 0
if ! res=$(cmake -B build); then
    echo $res
    exit 1
fi
 
if ! res=$(make -C build); then
    echo $res   
    exit 1
fi

build/snake
exit 0

echo $a 

echo \n\n\n
make -C build
build/new_snake.out
