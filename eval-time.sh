#!/bin/bash

prog1=containers_tests_std
prog2=containers_tests

tests_per_unit=1
number_of_tests=40


test_return=0
test_unit()
{
    START=$(gdate +%s%N)

    for i in $(seq $tests_per_unit) ; do 
        ./$1 1>/dev/null 2>/dev/null
    done

    END=$(gdate +%s%N)
    test_return=$(echo "$END - $START" | bc)
}

echo "testing $prog1 execution time over $prog2"

average=0
for i in $(seq $number_of_tests) ; do 

    test_unit $prog1
    DIFF_FT=$test_return

    test_unit $prog2
    DIFF_STD=$test_return

    TOTAL_DIFF=$(echo "$DIFF_STD - $DIFF_FT" | bc -l)

   # echo "$TOTAL_DIFF\n$DIFF_FT\n$DIFF_STD"

    if [ $TOTAL_DIFF -gt 0 ]
    then
        printf "\033[1;32m FASTER (%.4fs faster than %s, %.4fx faster)\n" \
                                    $(echo "$TOTAL_DIFF / 1000000000" | bc -l) \
                                    $prog2 \
                                    $(echo "$TOTAL_DIFF / $DIFF_FT" | bc -l) ;
       
        average=$(echo "$average + ($TOTAL_DIFF / $DIFF_FT)" | bc -l) ;
    else 
        printf "\033[1;31m SLOWER (%.4fs slower than %s, %.4fx slower)\n" \
                                    $(echo "($TOTAL_DIFF * -1) / 1000000000" | bc -l) \
                                    $prog2 \
                                    $(echo "($TOTAL_DIFF*-1) / $DIFF_STD" | bc -l);

        average=$(echo "$average + ($TOTAL_DIFF / $DIFF_STD)" | bc -l) ;
    fi
done

average=$(echo "($average / $number_of_tests)" | bc -l)
if [ $(echo "$average > 0" | bc) -eq 1 ]
then
    average=$(echo "$average" | bc -l);
    printf "\033[0maverage: %.4fx faster than %s" $average $prog2
else
    average=$(echo "scale=4; $average * -1" | bc -l)
    printf "\033[0maverage: %.4fx slower than %s" $average $prog2
fi