#define BOOST_TEST_MODULE boost_test_card
#include <boost/test/included/unit_test.hpp>
#include "../../card.cpp"

BOOST_AUTO_TEST_CASE(test_card) {
    Card card = Card(Value::Ace, Suit::Clubs);
    BOOST_TEST(
        static_cast<int>(card.value) == static_cast<int>(Value::Ace), 
        "Initialized " << toString(Value::Ace) << toString(Suit::Clubs) << ". " << card << " created."
    );
}