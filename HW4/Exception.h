//
// Created by Bar Kalandarov on 10/01/2023.
//

#ifndef EX4_MAIN_EXCEPTION_H
#define EX4_MAIN_EXCEPTION_H
#include "stdexcept"
#include <string>

const std::string DECK_EXCEPTION_GENERAL = "Deck File Error: ";
const std::string DECK_EXCEPTION_NOT_FOUND = "File not found";
const std::string DECK_EXCEPTION_SIZE = "Deck size is invalid";
const std::string DECK_EXCEPTION_FORMAT = "File format error in line ";

class DeckException : public std::runtime_error{
public:
    explicit DeckException(const std::string& what) :
            std::runtime_error(std::string(DECK_EXCEPTION_GENERAL ) + what)
    {}
};

class DeckFileNotFound : public DeckException {
public:
    explicit DeckFileNotFound() : DeckException(DECK_EXCEPTION_NOT_FOUND) {}
};

class DeckFileInvalidSize : public DeckException {
public:
    explicit DeckFileInvalidSize() : DeckException(DECK_EXCEPTION_SIZE) {}
};

class DeckFileFormatError : public DeckException {
public:
    explicit DeckFileFormatError(int line) : DeckException(DECK_EXCEPTION_FORMAT + std::to_string(line)) {}
};

#endif //EX4_MAIN_EXCEPTION_H
