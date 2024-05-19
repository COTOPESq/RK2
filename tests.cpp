#include <gtest/gtest.h>
#include <memory>
#include "ConceptualExample.cpp"

using namespace ConceptualExample;

TEST(Motivation01Test, CowBehavior) {
    Motivation01::Cow cow;
    EXPECT_EQ(cow.see(), "cow");
    EXPECT_EQ(cow.say(), "moo");
}

TEST(Motivation01Test, SeeAndSayFunction) {
    std::shared_ptr<Motivation01::IAnimal> animal = std::make_shared<Motivation01::Cow>();
    testing::internal::CaptureStdout();
    Motivation01::seeAndSay(animal);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The cow says 'moo' :).\n");
}

TEST(Motivation01Test, ClientCode) {
    testing::internal::CaptureStdout();
    Motivation01::clientCode();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "The cow says 'moo' :).\n"
                           "The pig says 'oink' :).\n"
                           "The dog says 'woof' :).\n";
    EXPECT_EQ(output, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
