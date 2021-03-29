#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test
##

test1()
{
    echo -ne "" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_valid44
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test EOF \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test EOF \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "1\n1\n" | ./matchstick $1 $2 PVE &> data
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test valid matches and input arguments \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test valid matches and input arguments \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

test2()
{
    echo -ne "a\n" | ./matchstick $1 $2  PVE &> data
    diff -q data tests/output/test_invalidline1
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid line: a \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid line: a \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "0\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidline2
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid line: 0 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid line: 0 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "-1\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidline1
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid line: -1 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid line: -1 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "20\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidline2
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid line: not exist \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid line: not exist \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "1\na\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidmatches1
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid match: a \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid match: a \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "1\n0\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidmatches2
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid match: 0 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid match: 0 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "1\n20\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidmatches3
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid match: too much \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid match: too much \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "1\n3\n" | ./matchstick $1 $2 PVE &> data
    diff -q data tests/output/test_invalidmatches4
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test invalid match: not enough \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid match: not enough \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

test3()
{
    echo -ne "1\n1\n" | ./matchstick 1 1 PVE >/dev/null
    if [[ $? == 2 ]]
    then
        echo -e "\E[0;32m Test Lose \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test Lose \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "2\n3\n" | ./matchstick 2 3 PVE &> data
    if [[ $? == 1 ]]
    then
        echo -e "\E[0;32m Test Win \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test Win \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

testerror()
{
    echo -ne "" | ./matchstick "a" "5" PVE 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test invalid arg 1 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid arg 1 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "" | ./matchstick "10" "0" PVE 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test invalid arg 2 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid arg 2 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "" | ./matchstick "0" "1" PVE 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test invalid arg 3 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid arg 3 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "" | ./matchstick "4" "-1" PVE 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test valid arg (-) \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test valid arg (-) \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "" | ./matchstick 2>/dev/null 
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test no arguments \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test no arguments \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    echo -ne "" | ./matchstick "100" "3" PVE 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test too big map \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test too big map \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

echo -e "\E[0m \e[90m\e[1m TEST Initial display of 4x4 board \e\e[0m"
test1 "4" "4"
echo -e "\n\E[0m \e[90m\e[1m TEST Bad inputs \e\e[0m"
test2 "4" "10"
echo -e "\n\E[0m \e[90m\e[1m TEST Full game \e\e[0m"
test3
echo -e "\n\E[0m \e[90m\e[1m TEST ERROR HANDLING \e\e[0m"
testerror

rm -f data