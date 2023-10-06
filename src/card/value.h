#pragma once

enum class Value {
    NO = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
    Ace = 14
};

std::string toString(Value value) {
    switch (value) {
        case Value::Two:
            return "2";
            break;
        case Value::Three:
            return "3";
            break;
        case Value::Four:
            return "4";
            break;
        case Value::Five:
            return "5";
            break;
        case Value::Six:
            return "6";
            break;
        case Value::Seven:
            return "7";
            break;
        case Value::Eight:
            return "8";
            break;
        case Value::Nine:
            return "9";
            break;
        case Value::Ten:
            return "10";
            break;
        case Value::Jack:
            return "J";
            break;
        case Value::Queen:
            return "Q";
            break;
        case Value::King:
            return "K";
            break;
        case Value::Ace:
            return "A";
            break;
        default:
            return "X";
    }
}