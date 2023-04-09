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

TEST(priorityQueue, enqueue) {

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
    pq1.enqueue(4.4, 7);
    EXPECT_EQ(4, pq1.Size());

    //testing enqueue with strings
    priorityqueue<string> pq2;
    pq2.enqueue("one", 9);
    pq2.enqueue("two", 8);
    pq2.enqueue("three", 7);
    EXPECT_EQ(3, pq2.Size());

}

//Milestone 2 testing (toString)

//Sample output for toString:
//“1 value: Ben\n
//2 value: Jen\n
//2 value: Sven\n
//3 value: Gwen\n”
TEST(priorityQueue, toString){


    priorityqueue<string> pq;
    pq.enqueue("Ben", 1);
    pq.enqueue("Jen", 2);
    pq.enqueue("Sven", 2);
    pq.enqueue("Gwen", 3);
    EXPECT_EQ("1 value: Ben\n2 value: Jen\n2 value: Sven\n3 value: Gwen\n", pq.toString());

    priorityqueue<string> pq1;
    pq1.enqueue("Dolores", 5);
    pq1.enqueue("Bernard", 4);
    pq1.enqueue("Arnold", 8);
    pq1.enqueue("William", 5);
    pq1.enqueue("Teddy", 5);
    pq1.enqueue("Ford", 2);
    EXPECT_EQ("2 value: Ford\n4 value: Bernard\n5 value: Dolores\n5 value: William\n5 value: Teddy\n8 value: Arnold\n", pq1.toString());
}

//Milestone 3 testing (clear())

TEST(priorityQueue, clear){

    priorityqueue<string> pq;
    pq.enqueue("Ben", 1);
    pq.enqueue("Jen", 2);
    pq.enqueue("Sven", 2);
    pq.enqueue("Gwen", 3);
    EXPECT_EQ(4, pq.Size());
    pq.clear();
    EXPECT_EQ(0, pq.Size());

    priorityqueue<string> pq1;
    pq1.enqueue("Dolores", 5);
    pq1.enqueue("Bernard", 4);
    pq1.enqueue("Arnold", 8);
    pq1.enqueue("William", 5);
    pq1.enqueue("Teddy", 5);
    pq1.enqueue("Ford", 2);
    EXPECT_EQ(6, pq1.Size());
    pq1.clear();
    EXPECT_EQ(0, pq1.Size());
}

//Milestone 4 testing (equals operator)

TEST(priorityQueue, asignmentOperator){

    priorityqueue<string> pq;
    pq.enqueue("Ben", 1);
    pq.enqueue("Jen", 2);
    pq.enqueue("Sven", 2);
    pq.enqueue("Gwen", 3);

    priorityqueue<string> pq1;
    pq1 = pq;
    EXPECT_EQ("1 value: Ben\n2 value: Jen\n2 value: Sven\n3 value: Gwen\n", pq1.toString());

    priorityqueue<string> pq2;
    pq2.enqueue("Dolores", 5);
    pq2.enqueue("Bernard", 4);
    pq2.enqueue("Arnold", 8);
    pq2.enqueue("William", 5);
    pq2.enqueue("Teddy", 5);
    pq2.enqueue("Ford", 2);
    pq2.enqueue("Dolores", 1);

    priorityqueue<string> pq3;
    pq3 = pq2;
    EXPECT_EQ("1 value: Dolores\n2 value: Ford\n4 value: Bernard\n5 value: Dolores\n5 value: William\n5 value: Teddy\n8 value: Arnold\n", pq3.toString());

    pq3 = pq; 
    EXPECT_EQ("1 value: Ben\n2 value: Jen\n2 value: Sven\n3 value: Gwen\n", pq3.toString());

    pq3 = pq3;
    EXPECT_EQ("1 value: Ben\n2 value: Jen\n2 value: Sven\n3 value: Gwen\n", pq3.toString());

}

//Milestone 5 testing (begin and next functions)

TEST(priorityQueue, beginAndNext){

    priorityqueue<string> pq;
    pq.enqueue("Ben", 4);
    pq.enqueue("Jen", 2);
    pq.enqueue("Sven", 2);
    pq.enqueue("Gwen", 1);
    
    EXPECT_EQ("1 value: Gwen\n2 value: Jen\n2 value: Sven\n4 value: Ben\n", pq.toString());

    pq.begin();
    int priority;
    string value;
    pq.next(value, priority);
    EXPECT_EQ(1, priority);
    EXPECT_EQ("Gwen", value);
    pq.next(value, priority);
    EXPECT_EQ(2, priority);
    EXPECT_EQ("Jen", value);
    pq.next(value, priority);
    EXPECT_EQ(2, priority);
    EXPECT_EQ("Sven", value);
    pq.next(value, priority);
    EXPECT_EQ(4, priority);
    EXPECT_EQ("Ben", value);
    
}

TEST(priorityQueue, beginAndNext2){

    priorityqueue<string> pq1;
    pq1.enqueue("Dolores", 5);
    pq1.enqueue("Bernard", 4);
    pq1.enqueue("Arnold", 8);
    pq1.enqueue("William", 5);
    pq1.enqueue("Teddy", 5);
    pq1.enqueue("Ford", 2);

    EXPECT_EQ("2 value: Ford\n4 value: Bernard\n5 value: Dolores\n5 value: William\n5 value: Teddy\n8 value: Arnold\n", pq1.toString());

    pq1.begin();
    int priority;
    string value;
    pq1.next(value, priority);
    EXPECT_EQ(2, priority);
    EXPECT_EQ("Ford", value);
    pq1.next(value, priority);
    EXPECT_EQ(4, priority);
    EXPECT_EQ("Bernard", value);
    pq1.next(value, priority);
    EXPECT_EQ(5, priority);
    EXPECT_EQ("Dolores", value);
    pq1.next(value, priority);
    EXPECT_EQ(5, priority);
    EXPECT_EQ("William", value);
    pq1.next(value, priority);
    EXPECT_EQ(5, priority);
    EXPECT_EQ("Teddy", value);
    
}

//Milestone 6 testing (dequeue)

TEST(priorityQueue, dequeue){

    priorityqueue<string> pq;
    pq.enqueue("Ben", 4);
    pq.enqueue("Jen", 2);
    pq.enqueue("Sven", 2);
    pq.enqueue("Gwen", 1);
    
    EXPECT_EQ("1 value: Gwen\n2 value: Jen\n2 value: Sven\n4 value: Ben\n", pq.toString());

    EXPECT_EQ("Gwen", pq.dequeue());
    EXPECT_EQ("Jen", pq.dequeue());
    EXPECT_EQ(2, pq.Size());
    
    
}

TEST(priorityQueue, dequeue2){

    priorityqueue<string> pq1;
    EXPECT_EQ("", pq1.dequeue());

    priorityqueue<int> pq2;
    EXPECT_EQ(0, pq2.dequeue());

    priorityqueue<string> pq3;
    pq3.enqueue("Dolores", 5);
    pq3.enqueue("Bernard", 4);
    EXPECT_EQ("Bernard", pq3.dequeue());

}

TEST(priorityQueue, dequeue3){
    priorityqueue<double> pq;
    pq.enqueue(1.1, 4);
    pq.enqueue(2.2, 2);
    pq.enqueue(3.7, 8);
    pq.enqueue(4.4, 5);
    pq.enqueue(5.5, 1);
    pq.enqueue(6.6, 5);
    pq.enqueue(7.7, 2);
    EXPECT_EQ(5.5, pq.dequeue());
    EXPECT_EQ(2.2, pq.dequeue());
    EXPECT_EQ(7.7, pq.dequeue());

}

//Milestone 7 testing (peek)
    