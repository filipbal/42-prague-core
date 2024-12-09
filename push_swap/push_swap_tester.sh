#!/bin/bash

test_error_handling() {
    echo "=== Testing Error Handling ==="
    
    # Test non-numeric input
    echo -n "Testing non-numeric input: "
    output=$(./push_swap "1 2 a 4" 2>&1)
    if [ "$output" = "Error" ]; then
        echo "OK"
    else
        echo "FAIL (expected 'Error', got '$output')"
    fi
    
    # Test duplicate numbers
    echo -n "Testing duplicates: "
    output=$(./push_swap "1 2 2 3" 2>&1)
    if [ "$output" = "Error" ]; then
        echo "OK"
    else
        echo "FAIL (expected 'Error', got '$output')"
    fi
    
    # Test out of INT range
    echo -n "Testing INT overflow: "
    output=$(./push_swap "2147483648 1 2" 2>&1)
    if [ "$output" = "Error" ]; then
        echo "OK"
    else
        echo "FAIL (expected 'Error', got '$output')"
    fi
    
    # Test empty input
    echo -n "Testing empty input: "
    output=$(./push_swap 2>&1)
    if [ -z "$output" ]; then
        echo "OK"
    else
        echo "FAIL (expected empty output, got '$output')"
    fi
    
    echo "---"
}

check_operations() {
    local size=$1
    local max_ops=$2
    local nums=$3
    
    echo "Input: $nums"
    local ops=$(./push_swap $nums | wc -l)
    local sorted_nums=$(./push_swap $nums | ./checker_linux $nums 2>/dev/null)
    
    echo "Test for $size numbers:"
    echo "Operations: $ops (limit: $max_ops)"
    echo "Checker result: $sorted_nums"
    echo "Within limit: $([ $ops -le $max_ops ] && echo "YES" || echo "NO")"
    
    echo "Memory check:"
    valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./push_swap $nums >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "No memory leaks detected"
    else
        echo "Memory leaks found!"
    fi
    echo "---"
}

check_graded_operations() {
    local size=$1
    local limits=($2)
    local nums=$3
    local nums_array=($nums)
    
    if [ $size -le 5 ]; then
        echo "Input: $nums"
    else
        echo "Input: ${nums_array[0]} ${nums_array[1]} ... ${nums_array[-2]} ${nums_array[-1]}"
    fi
    
    local ops=$(./push_swap $nums | wc -l)
    local sorted_nums=$(./push_swap $nums | ./checker_linux $nums 2>/dev/null)
    
    echo "Test for $size numbers:"
    echo "Operations: $ops"
    echo "Checker result: $sorted_nums"
    
    if [ $ops -lt ${limits[0]} ]; then
        echo "Grade: 5/5 (< ${limits[0]})"
    elif [ $ops -lt ${limits[1]} ]; then
        echo "Grade: 4/5 (< ${limits[1]})"
    elif [ $ops -lt ${limits[2]} ]; then
        echo "Grade: 3/5 (< ${limits[2]})"
    elif [ $ops -lt ${limits[3]} ]; then
        echo "Grade: 2/5 (< ${limits[3]})"
    elif [ $ops -lt ${limits[4]} ]; then
        echo "Grade: 1/5 (< ${limits[4]})"
    else
        echo "Failed (exceeded ${limits[4]})"
    fi
    
    echo "Memory check:"
    valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./push_swap $nums >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "No memory leaks detected"
    else
        echo "Memory leaks found!"
    fi
    echo "---"
}

# Start testing
echo "=== Push_swap Tester ==="

# Error handling tests
test_error_handling

# Test 3 numbers
ARG3=$(seq 1 3 | shuf | tr '\n' ' ')
check_operations 3 3 "$ARG3"

# Test 5 numbers
ARG5=$(seq 1 5 | shuf | tr '\n' ' ')
check_operations 5 12 "$ARG5"

# Test 100 numbers
ARG100=$(seq 1 100 | shuf | tr '\n' ' ')
check_graded_operations 100 "700 900 1100 1300 1500" "$ARG100"

# Test 500 numbers
ARG500=$(seq 1 500 | shuf | tr '\n' ' ')
check_graded_operations 500 "5500 7000 8500 10000 11500" "$ARG500"