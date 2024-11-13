cmake_minimum_required(VERSION 3.27)
project(Poker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Poker main.cpp
        Deck.h
        Card.h
        HandEvaluator.h)
