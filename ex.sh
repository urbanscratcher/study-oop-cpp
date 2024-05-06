OUTPUT_ARG=$2
OUTPUT="${OUTPUT_ARG:=merkelex}"
g++ $1.cpp -o $OUTPUT
./$OUTPUT