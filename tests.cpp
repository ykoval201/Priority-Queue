/// @file tests.cpp
/// @date March 17, 2023

/// 
/// TODO

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023


// Google Test Framework Testing
#include <gtest/gtest.h>
#include "priorityqueue.h"
#include <string>


//Milestone 1 testing
//Milestone one tests enqueue, size, and constructor of the priority queue
TEST(priorityQueue, Constructor) {

    priorityqueue<int> pq;
    priorityqueue<double> pq1;
    priorityqueue<string> pq2;

    EXPECT_EQ(0, pq.Size());
    EXPECT_EQ(0, pq1.Size());
    EXPECT_EQ(0, pq2.Size());
    
}

TEST(priorityQueue, Enqueue) {

    //testing enqueue with ints
    priorityqueue<int> pq;
    pq.enqueue(1, 9);
    pq.enqueue(2, 8);
    pq.enqueue(3, 7);
    EXPECT_EQ(3, pq.Size());

    //testing enqueue with doubles
    priorityqueue<double> pq1;
    pq1.enqueue(1.1, 9);
    pq1.enqueue(2.2, 8);
    pq1.enqueue(3.3, 7);
    EXPECT_EQ(3, pq1.Size());

    //testing enqueue with strings
    priorityqueue<string> pq2;
    pq2.enqueue("one", 9);
    pq2.enqueue("two", 8);
    pq2.enqueue("three", 7);
    EXPECT_EQ(3, pq2.Size());

}


